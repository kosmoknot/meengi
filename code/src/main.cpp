#include <iostream>
#include <vector>
#include <string>
#include "LayoutParser.h"

using namespace std;

int main()
{

    cout << "Starting Meengi" << endl;
    Node start = LayoutParser::GetStartNode();
    start.Print();
}