#include <iostream>
#include <vector>
#include <string>
#include "LayoutParser.h"
#include "FileHelpers.h"

using namespace std;

int main()
{
    Warnings::warn("testing");
    cout << "Starting Meengi" << endl;
    Node start = LayoutParser::GetStartNode();
    start.Print();
}