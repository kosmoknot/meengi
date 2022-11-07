#include <iostream>
#include "LayoutParser.h"
#include "PageRenderer.h"

int main()
{
    std::cout << "Starting Meengi" << std::endl;
    Node start = LayoutParser::GetStartNode();
    PageRenderer::Render(start);
    return 0;
}