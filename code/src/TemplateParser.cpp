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
        }
    }
}

string TemplateParser::Parse(const string &name, const vector<string> &inputArgs)
{
    return "";
}

bool TemplateParser::CheckForTemplate(const string &iLine, string &oName, vector<string> &oInputArgs)
{
    return true;
}