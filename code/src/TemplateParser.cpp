#include "TemplateParser.h"

Template::Template(vector<int> argOrder, vector<string> contentSalami) : ArgOrder(argOrder), ContentSalami(contentSalami)
{
}

string Template::Parse(const vector<string> &inputArgs)
{
    return "";
}

TemplateParser::TemplateParser()
{
}

string TemplateParser::Parse(const string &name, const vector<string> &inputArgs)
{
    return "";
}

bool TemplateParser::CheckForTemplate(const string &iLine, string &oName, vector<string> &oInputArgs)
{
    return true;
}