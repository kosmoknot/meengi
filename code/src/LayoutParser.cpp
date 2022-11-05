#include <iostream>
#include "LayoutParser.h"
#include "FileHelpers.h"

Node::Node(std::string name, int numcol) : name(name), numcol(numcol)
{
    children = std::vector<Node *>();
}

void Node::AddChild(Node *child)
{
    children.push_back(child);
}

Node::Node() : name("Uninitialised"), numcol(-1)
{
    children = std::vector<Node *>();
}

void Node::Print() const
{
    std::cout << name << "( " << numcol << ")"
              << " -> { " << std::endl;
    if (children.size() != 0)
    {
        for (auto child : children)
        {
            child->Print();
            std::cout << " , " << std::endl;
        }
    }
    std::cout << " } " << std::endl;
}

// Initialise the static variables
LayoutParser *LayoutParser::instance = nullptr;
std::map<std::string, Node *> LayoutParser::NodeMap = std::map<std::string, Node *>();

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

Node *LayoutParser::FindNode(const std::string &name)
{
    auto search = LayoutParser::NodeMap.find(name);
    if (search != NodeMap.end())
        return search->second;
    else
        return nullptr;
}

LayoutParser::LayoutParser(const std::string &path)
{
    auto lines = GetLinesFromFile(path);
    Node *currentParent;
    for (auto line : lines)
    {
        bool isParent = false;
        bool isChild = false;

        auto pos = line.find("#");
        if (pos != string::npos)
        {
            if (line[pos + 1] == '#')
            {
                isParent = true;
            }
            else
                isChild = true;
        }
        if (isParent)
        {
            string name = ExtractBetween(line, "##", "(");
            int numcol = stoi(ExtractBetween(line, "(", ")"));
            auto current = LayoutParser::FindNode(name);
            if (current == nullptr)
            {
                if (StartNode.numcol == -1)
                {
                    StartNode.name = name;
                    StartNode.numcol = numcol;
                }
                else
                {
                    string error = "In layout, " + name + " is used as PageTitle without listing it first under a PageTitle.";
                    throw std::runtime_error(error);
                }
            }
        }
        else if (isChild)
        {
            string name = ExtractBetween(line, "##", "(");
            int numcol = stoi(ExtractBetween(line, "(", ")"));
            auto current = LayoutParser::FindNode(name);
            if (current == nullptr)
                current = new Node(name, numcol);
        }
    }
}
