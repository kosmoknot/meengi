#include "TemplateParser.h"
#include "FileHelpers.h"

Template::Template(vector<int> argOrder, vector<string> contentSalami) : ArgsOrder(argOrder), ContentSalami(contentSalami)
{
}

Template::Template()
{
}

// First content salami slice + ArgOrder[0]th argument + second content salami slice + ArgOrder[1]th argument ...
// If less arguments are passed then rest are assumed to be empty
// If more arguments are passed then extra are ignored
string Template::Parse(const vector<string> &inputArgs)
{
    string ret = ContentSalami[0];

    int n = (ArgsOrder.size() > inputArgs.size()) ? inputArgs.size() : ArgsOrder.size();
    int i;
    for (i = 0; i < n; i++)
    {
        ret += inputArgs[ArgsOrder[i]];
        ret += ContentSalami[i + 1];
    }

    // Less than required arguments were given
    i++;
    while (i < (int)ContentSalami.size())
        ret += ContentSalami[i++];

    return ret;
}

string TemplateParser::Parse(const string &iLine)
{
    auto pos_start = iLine.find("$");

    string ret = iLine;

    if (pos_start != string::npos)
    {
        string templateName = ExtractBetween(iLine, "$", "(");
        vector<string> argsList = TokenizeBetween(iLine, ",()");
        string newText = ParseTemplate(templateName, argsList);
        auto pos_end = iLine.find(")");
        return ret.replace(pos_start, pos_end - pos_start + 1, newText);
    }
    else
        return iLine + " \n ";
}

TemplateParser::TemplateParser()
{
    auto Lines = GetLinesFromFile("./content/templates.md");

    bool foundTemplate = false;
    vector<string> args = vector<string>();

    string title;
    string templateText;

    for (auto line : Lines)
    {
        if (line.find("#") != string::npos)
        {
            if (!foundTemplate)
            {
                ReadTemplateTitle(line, title, args);
                foundTemplate = true;
            }
            else
            {
                // Add template to the template map
                vector<int> argsOrder;
                vector<string> salamiSlices;

                ReadTemplateText(templateText, args, argsOrder, salamiSlices);

                TemplateMap[title] = Template(argsOrder, salamiSlices);

                templateText = "";
                foundTemplate = false;
            }
        }
        else if (foundTemplate)
        {
            templateText += line;
            // We might want to change the newline character to <br> instead
            // Or we can put a optional parameter in template.md if need arises
            templateText += " \n ";
        }
    }
}

string TemplateParser::ParseTemplate(const string &name, const vector<string> &inputArgs)
{
    string output;

    auto temp = TemplateMap.find(name);

    if (temp != TemplateMap.end())
    {
        output = (temp->second).Parse(inputArgs);
    }

    return output;
}
