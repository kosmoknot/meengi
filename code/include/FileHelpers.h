#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> GetLinesFromFile(const string &path, bool ignore_comments = true);
vector<string> GetWordsFromFile(const string &path);
string ExtractBetween(const string &target, const string &start, const string &end);

// writes out warnings to warnings.txt
void warn(const string &warning);

// uses try catch block to avoid crashing
bool toInt(const string &str, int &out);
