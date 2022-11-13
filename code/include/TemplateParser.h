#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

// First content salami slice + ArgOrder[0]th argument + second content salami slice + ArgOrder[1]th argument ...
class Template
{
private:
    vector<int> ArgsOrder;
    vector<string> ContentSalami;

public:
    Template();
    Template(vector<int> argOrder, vector<string> contentSalami);
    string Parse(const vector<string> &inputArgs);
};

class TemplateParser
{
private:
    map<string, Template> TemplateMap;
    string ParseTemplate(const string &name, const vector<string> &inputArgs);

public:
    TemplateParser();
    string Parse(const string &iLine);
};
