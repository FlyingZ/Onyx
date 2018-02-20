#include "../include/Node.h"
#include <string>
Node::Node(bool isFile)
{
    this->isFile = isFile;
}
Node::Node(){

}

Node::Node(string name){
    this->name=name;
    this->isFile = false;
}

Node::Node(string name,bool isFile){
    this->name = name;
    this->isFile = true;
}


