#include <iostream>
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

void Node::Print()
{
    std::cout << name << " : { " << std::endl;
    if (children.size() != 0)
    {
        for (auto child : children)
        {
            child.Print();
            std::cout << " , " << std::endl;
        }
    }
    std::cout << " } " << std::endl;
}

LayoutParser *LayoutParser::instance = nullptr;

LayoutParser *LayoutParser::GetInstance()
{
    if (instance == nullptr)
        instance = new LayoutParser("../content/layout.md");

    return instance;
}

Node LayoutParser::GetStartNode()
{
    return LayoutParser::GetInstance()->StartNode;
}

LayoutParser::LayoutParser(std::string path)
{
}
