#ifndef NODE_H
#define NODE_H
#include <vector>
#include <string>
using namespace std;
class Node
{
    public:
        Node();
        Node(bool isFile);
        Node(string name);
        Node(string name,bool isFile);
        friend class Tree;
        bool isFile;
        vector<Node*> childs;
        string name;
        string text;
        Node *parrent;
        string names;

    protected:

    private:



};

#endif // NODE_H
