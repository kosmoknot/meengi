#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

class Node;

using namespace std;

// First content salami slice + ArgOrder[0]th argument + second content salami slice + ArgOrder[1]th argument ...
class Template
{
private:
    vector<int> ArgsOrder;
    vector<string> ContentSalami;

public:
    Template();
    Template(const vector<int> &argOrder, const vector<string> &contentSalami);
    string Parse(const vector<string> &inputArgs);
};

class TemplateParser
{
private:
    unordered_map<string, Template> TemplateMap;
    string ParseTemplate(const string &name, const vector<string> &inputArgs);

    // Special Parsing functions
    string ParseChildList(Node *node);
    string ParseNavigList(Node *node);
    string PasrseTreeMap(Node *node);
    string ParseTreeMapLevel(Node *node, int lvl);

public:
    TemplateParser();
    string Parse(const string &iLine, set<string> already_encountered);
};
