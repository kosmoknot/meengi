#include <queue>
#include <vector>
#include "PageRenderer.h"
#include "FileHelpers.h"

using namespace std;

TemplateParser PageRenderer::templateParser = TemplateParser();

string PageRenderer::GetInputPath(Node *node) { return "./content/" + node->name + ".md"; }

string PageRenderer::GetOutputPath(Node *node) { return "./site/" + node->name + ".html"; }

std::string PageRenderer::InterpretLine(const std::string &iLine)
{
    return templateParser.Parse(iLine);
}

void PageRenderer::Render(Node startNode)
{
    ofstream output;
    queue<Node *> q;
    q.push(&startNode);

    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        auto children = cur->children;
        if (children.size() != 0)
        {
            for (auto child : children)
                q.push(child);
        }

        output.open(GetOutputPath(cur), ios::app);
        auto inputLines = GetLinesFromFile(GetInputPath(cur));

        if (inputLines.size() > 0 && output.is_open())
        {
            for (auto line : inputLines)
            {
                output << InterpretLine(line);
            }
        }
        output.close();
    }
}
