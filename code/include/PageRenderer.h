#pragma once
#include <fstream>

#include "LayoutParser.h"
#include "TemplateParser.h"

class PageRenderer
{
private:
    static TemplateParser tempParser;

    PageRenderer();
    static std::string GetInputPath(Node *node);
    static std::string GetOutputPath(Node *node);
    static std::string InterpretLine(const std::string &iLine);

public:
    static void Render(Node startNode);
};
