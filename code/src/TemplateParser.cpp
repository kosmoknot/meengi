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

TemplateParser::TemplateParser()
{
    auto Lines = GetLinesFromFile("./content/directives/templates.md");

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

                // Remove extra \n added at the end
                ReadTemplateText(templateText.substr(0, templateText.size() - 1), args, argsOrder, salamiSlices);

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
            // Same thing happens at PageRenderer::InterpretLine

            // Need to remove extra \n added at the end
            templateText += "\n";
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

string TemplateParser::Parse(const string &iLine, set<string> already_encountered)
{
    auto pos_start = iLine.find("$");
    string ret = iLine;

    if (pos_start != string::npos)
    {
        auto pos_end = iLine.find("$", pos_start + 1);
        if (pos_end != string::npos)
        {
            string temp = iLine.substr(pos_start, pos_end - pos_start);

            string templateName = ExtractBetween(temp, "$", "(");

            if (already_encountered.find(templateName) == already_encountered.end())
            {
                vector<string> argsList = TokenizeBetween(temp, ",()");
                string newText = ParseTemplate(templateName, argsList);
                already_encountered.insert(templateName);
                return TemplateParser::Parse(ret.replace(pos_start, pos_end - pos_start + 1, newText), already_encountered);
            }
        }
    }
    return ret;
}