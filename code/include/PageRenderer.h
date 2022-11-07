#pragma once
#include "LayoutParser.h"
#include <fstream>

class PageRenderer
{
private:
    PageRenderer();
    static std::string GetInputPath(Node *node);
    static std::string GetOutputPath(Node *node);

public:
    static void Render(Node startNode);
};
