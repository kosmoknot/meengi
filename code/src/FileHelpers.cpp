#include "FileHelpers.h"
#include <iostream>

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

vector<string> GetWordsFromFile(const string &path)
{
    fstream file;
    vector<string> ret = vector<string>();
    file.open(path.c_str(), ios::in);
    if (file.is_open())
    {
        string word;
        while (file >> word)
            ret.push_back(word);
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

void warn(const string &warning)
{
    ofstream warningfile;
    warningfile.open("warnings.txt", ios::app);
    warningfile << warning;
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
    catch (std::exception e)
    {
        warn("Caught Failure in toInt while converting  " + str);
        success = false;
    }
    if (success)
    {
        out = val;
    }
}