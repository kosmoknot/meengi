#pragma once
#include <vector>
#include <string>
#include <map>

class Node
{
public:
    std::string name;
    int numcol;
    std::vector<Node *> children;

    Node();
    Node(std::string name, int numcol);
    void AddChild(Node *child);
    void Print() const;
    Node Find(std::string name);
    void Clean();
};

class LayoutParser
{
private:
    static LayoutParser *instance;
    std::map<std::string, Node *> NodeMap;

    Node StartNode;

    void SaveInMap(Node *node, const std::string str);
    static LayoutParser *GetInstance();

    LayoutParser(const std::string &path);
    LayoutParser(const LayoutParser &other);
    LayoutParser &operator=(const LayoutParser &other);

public:
    std::map<std::string, Node *> GetMap() const;
    static Node GetStartNode();
    static Node *FindNode(const std::string &name);
};