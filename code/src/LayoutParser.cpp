#include "LayoutParser.h"

Node::Node(std::string name, int numcol) : name(name), numcol(numcol)
{
    children = std::vector<Node>();
}

void Node::AddChild(Node child)
{
    children.push_back(child);
}

Node::Node() : name("Uninitialised"), numcol(0)
{
    children = std::vector<Node>();
}

// LayoutParser *LayoutParser::GetInstance()
// {
//     if (instance == nullptr)
//         instance = new LayoutParser("../content/layout.md");

//     return instance;
// }

LayoutParser::LayoutParser(std::string path)
{
}
