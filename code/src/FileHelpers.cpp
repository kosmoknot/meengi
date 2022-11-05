#include "FileHelpers.h"
#include <fstream>

vector<string> GetLinesFromFile(string path)
{
    fstream file;
    vector<string> ret = vector<string>();
    file.open(path.c_str(), ios::in);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
            ret.push_back(line);
    }
    file.close();
    return ret;
}

vector<string> GetWordsFromFile(string path)
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