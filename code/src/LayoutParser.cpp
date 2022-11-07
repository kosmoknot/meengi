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

LayoutParser *LayoutParser::GetInstance()
{
    if (instance == nullptr)
        instance = new LayoutParser("./content/layout.md");

    return instance;
}

Node LayoutParser::GetStartNode()
{
    return LayoutParser::GetInstance()->StartNode;
}

std::map<std::string, Node *> LayoutParser::GetMap() const
{
    return NodeMap;
}

Node *LayoutParser::FindNode(const std::string &name)
{
    auto search = LayoutParser::GetInstance()->GetMap().find(name);
    return search->second;
}

void LayoutParser::SaveInMap(Node *node, const std::string str)
{
    if (node == nullptr)
        return;

    NodeMap[str] = node;
}

LayoutParser::LayoutParser(const std::string &path)
{
    auto lines = GetLinesFromFile(path);
    Node *currentParent = nullptr;
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
            string numcolstr = ExtractBetween(line, "(", ")");
            int numcol;
            if (toInt(numcolstr, numcol))
            {
                Node *current = NodeMap[name];

                if (current == nullptr)
                {
                    if (StartNode.numcol == -1)
                    {
                        StartNode.name = name;
                        StartNode.numcol = numcol;
                        SaveInMap(&StartNode, name);
                        currentParent = &StartNode;
                    }
                    else
                    {
                        // Parent needs to be encountered as a child before unless it is the homeTitle
                        string warning = "In layout, " + name + " is used as PageTitle without listing it first under a PageTitle. Hence ignored";
                        warn(warning);
                    }
                }
                else
                {
                    currentParent = current;
                    currentParent->numcol = numcol;
                }
            }
        }
        else if (isChild)
        {
            string name = ExtractBetween(line, "#", "\n");

            auto current = NodeMap[name];

            if (current == nullptr)
            {
                current = new Node(name, -1);
                SaveInMap(current, name);
            }

            // Child must not have been initiated before to avoid possible circular references
            else
            {
                string warning = "In layout, " + name + " Is listed under multiple PageTitles. Hence ignored after first encounter. Avoid listing single page under multiple pageTitles";
                warn(warning);
            }
            if (currentParent != nullptr)
                currentParent->AddChild(current);
        }
    }
}
