#include <queue>
#include <vector>
#include "PageRenderer.h"
#include "FileHelpers.h"

using namespace std;

string PageRenderer::GetInputPath(Node *node) { return "./content/" + node->name + ".md"; }

string PageRenderer::GetOutputPath(Node *node) { return "./site/" + node->name + ".html"; }

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
                output << line;
            }
        }
        output.close();
    }
}
