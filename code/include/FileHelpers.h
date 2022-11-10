#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum LineTypes
{
    TemplateTitleLine,
    TemplateContent,
    NoInfo
};

vector<string> GetLinesFromFile(const string &path, bool ignore_comments = true);
string ExtractBetween(const string &target, const string &start, const string &end);
// variadic funbction : n = number of arguments passed
vector<string> TokenizeBetween(const string &target, int n, ...);
vector<string> TokenizeForSingleToken(const vector<string> &input, const char *token);

// writes out warnings to warnings.txt
void warn(const string &warning);

// uses try catch block to avoid crashing
bool toInt(const string &str, int &out);

void ClearPreviousWarnings();

LineTypes SalamiSlice(const string &iLine, string &templateName, vector<string> &argsList, vector<string> salamiSlices);
bool ReadTemplateTitle(const string &iLine, string &templateName, vector<string> &argsList);