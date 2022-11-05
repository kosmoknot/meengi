#pragma once
#include <vector>
#include <string>

class Node
{
public:
    std::string name;
    int numcol;
    std::vector<Node> children;

    Node();
    Node(std::string name, int numcol);
    void AddChild(Node child);
    void Print();
};

class LayoutParser
{
private:
    static LayoutParser *instance;
    Node StartNode;

    LayoutParser(std::string path);
    LayoutParser(const LayoutParser &other);
    LayoutParser &operator=(const LayoutParser &other);

public:
    static LayoutParser *GetInstance();
    static Node GetStartNode();
};