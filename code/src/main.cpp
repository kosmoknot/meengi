#include <iostream>
#include "LayoutParser.h"
#include "PageRenderer.h"
#include "FileHelpers.h"

int main()
{
    std::cout << "Starting Meengi" << std::endl;

    ClearPreviousWarnings();

    Node start = LayoutParser::GetStartNode();

    PageRenderer::Render(start);

    return 0;
}