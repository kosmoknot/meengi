#include <queue>
#include <vector>
#include <stdio.h>
#include "PageRenderer.h"
#include "FileHelpers.h"

using namespace std;

TemplateParser PageRenderer::templateParser = TemplateParser();

string PageRenderer::GetInputPath(Node *node) { return "./content/" + node->name + ".md"; }

string PageRenderer::GetOutputPath(Node *node) { return "./site/" + node->name + ".html"; }

std::string PageRenderer::InterpretLine(const std::string &iLine)
{
    // We might want to change the newline character to <br> instead
    // Or we can put a optional parameter in template.md if need arises
    // Same thing happens at TemplateParser::TemplateParser()
    return templateParser.Parse(iLine, set<string>()) + "\n";
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
        // Clear previously generated files
        string opath = GetOutputPath(cur);
        remove(opath.c_str());
        output.open(opath, ios::app);

        if (output.is_open())
        {
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
}
