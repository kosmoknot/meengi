#pragma once
#include <vector>
#include <string>

class Node
{
public:
    std::vector<Node> children;
    int numcol;
    std::string name;

    Node();
    Node(std::string name, int numcol);
    void AddChild(Node child);
};

class LayoutParser
{
private:
    static LayoutParser *instance;
    Node StartNode;

    LayoutParser(std::string path);

public:
    // static LayoutParser *GetInstance();
};