#pragma once
#include <fstream>

#include "LayoutParser.h"
#include "TemplateParser.h"

class PageRenderer
{
private:
    static TemplateParser templateParser;
    static Node *currentNode;

    PageRenderer();
    static std::string GetInputPath(Node *node);
    static std::string GetOutputPath(Node *node);
    static std::string InterpretLine(const std::string &iLine);

public:
    static void Render(Node *startNode);
    static Node *GetCurrent();
};