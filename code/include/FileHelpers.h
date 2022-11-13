#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> GetLinesFromFile(const string &path, bool ignore_comments = true);
string ExtractBetween(const string &target, const string &start, const string &end);
string ExtractBetween(const string &target, const size_t &p_start, const string &end);
vector<string> TokenizeBetween(const string &target, const string &tokens);

// writes out warnings to warnings.txt
void warn(const string &warning);

// uses try catch block to avoid crashing
bool toInt(const string &str, int &out);

void ClearPreviousFiles();
void ClearPreviousWarnings();

void ReadTemplateTitle(const string &iLine, string &templateName, vector<string> &argsList);
void ReadTemplateText(const string &input, const vector<string> &argsList, vector<int> &argsOrder, vector<string> &salamiSlices);