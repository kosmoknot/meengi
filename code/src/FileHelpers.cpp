#include "FileHelpers.h"
#include <iostream>
#include <cstdarg>

vector<string> GetLinesFromFile(const string &path, bool ignore_comments)
{
    fstream file;
    vector<string> ret = vector<string>();
    file.open(path.c_str(), ios::in);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            bool isComment = false;

            if (ignore_comments && line.size() > 1)
            {
                string lineStart = line.substr(0, 2);
                if (lineStart == "//")
                    isComment = true;
            }
            if (!isComment)
                ret.push_back(line);
        }
    }
    file.close();
    return ret;
}

string ExtractBetween(const string &target, const string &start, const string &end)
{
    string ret = "";
    size_t p_start, p_end;
    p_start = target.find(start);
    if (p_start != string::npos)
    {
        if (end == "\n")
        {
            p_end = target.size();
        }
        else
            p_end = target.find(end, p_start);

        if (p_end != string::npos)
            ret = target.substr(p_start + start.size(), p_end - p_start - start.size());
    }
    return ret;
}

vector<string> TokenizeBetween(const string &target, int n, ...)
{
    // just use find first of no need of variadics
    vector<string> ret;
    ret.push_back(target);

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
    {
        const char *token = va_arg(args, char *);
    }
}
vector<string> TokenizeForSingleToken(const vector<string> &input, const char *token)
{
}

void warn(const string &warning)
{
    ofstream warningfile;
    warningfile.open("warnings.txt", ios::app);
    warningfile << warning << '\n';
    warningfile.close();
}

bool toInt(const string &str, int &out)
{
    bool success = true;
    int val;

    try
    {
        val = stoi(str);
    }
    catch (std::exception *e)
    {
        warn("Caught Failure in toInt while converting  " + str);
        success = false;
    }
    if (success)
    {
        out = val;
    }
    return success;
}

void ClearPreviousWarnings()
{
    ofstream warningfile;
    warningfile.open("warnings.txt", ios::in | ios::out);
    warningfile << "Meengi encountered following warning: " << '\n';
    warningfile.close();
}

LineTypes SalamiSlice(const string &iLine, string &templateName, vector<string> &argsList, vector<string> salamiSlices)
{
    if (iLine.size() < 1)
    {

        return NoInfo;
    }

    auto hash_pos = iLine.find("#");
    if (hash_pos != string::npos)
    {
    }
    return NoInfo;
}

bool ReadTemplateTitle(const string &iLine, string &templateName, vector<string> &argsList)
{
    templateName = ExtractBetween(iLine, "$", "(");
}