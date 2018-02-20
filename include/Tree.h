#ifndef TREE_H
#define TREE_H
#include "../include/Node.h"

class Tree
{
    public:
        Tree();
        virtual ~Tree();
        void addNode(string name,bool isFile,string pwd);
        void deleteNode(string name,bool everything, string pwd);
        void showName();
        void getChilds(string pwd);
        bool exitsChild(string name,string pwd);
        void writeFile(string name,string text,string pwd);
        string getText(string name,int n,string pwd);
        Node root;

    protected:

    private:

};

#endif // TREE_H
