#include "../include/Tree.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
Tree::Tree()
{
    this->root = new Node();
    this->root.name="root";
}

void Tree::addNode(string name,bool isFile,string pwd)
{
    size_t pos=0;
    string delimiter = "\\";
    string token;
    Node *inserter = new Node();
    Node *aux;
    inserter->name=name;
    inserter->isFile=isFile;
    aux=&this->root;
    pos = pwd.find(delimiter);
    token = pwd.substr(0,pos);
    pwd.erase(0,pos + delimiter.length());
    if((pos = pwd.find(delimiter)) == string::npos)
    {
        inserter->parrent=aux;
        if(aux->names.find(name) == string::npos)
        {
            aux->childs.push_back(inserter);
            aux->names.append(name);
            aux->names.append(" ");
        }
        else
        {

            cout << "The directory already exists" << endl;
        }
    }
    else
    {
        while((pos = pwd.find(delimiter)) != string::npos)
        {
            token = pwd.substr(0,pos);
            pwd.erase(0,pos + delimiter.length());
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(token) == 0)
                {
                    aux=aux->childs[i];
                    cout << token << endl;
                }
            }

        }
        inserter->parrent=aux;
        if(aux->names.find(name) == string::npos)
        {
            aux->childs.push_back(inserter);
            aux->names.append(name);
            aux->names.append(" ");
        }
        else
        {

            cout << "The directory already exists" << endl;
        }
    }

}

void Tree::deleteNode(string name, bool everything,string pwd)
{
    size_t pos=0;
    string delimiter = "\\";
    string token;
    Node *aux;
    Node *aux2;
    aux=&root;
    aux2=aux;
    pos = pwd.find(delimiter);
    token = pwd.substr(0,pos);
    pwd.erase(0,pos + delimiter.length());
    if((pos = pwd.find(delimiter)) == string::npos)
    {
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    aux=aux->childs[i];
                }
            }
            if(aux->childs.size() > 0 && everything)
            {
                size_t pos = aux2->name.find(name);
                if (pos != std::string::npos)
                {
                    aux2->names.erase(pos, name.length()+1);
                    cout << "Bla bla";
                }
                delete aux;
                //aux2->childs.erase(remove(aux2->childs.begin(), aux2->childs.end(), name), aux2->childs.end());

            }
            else if (aux->childs.size() == 0)
            {
                size_t pos = aux2->names.find(name);
                if (pos != std::string::npos)
                {
                    aux2->names.erase(pos, name.length()+1);

                }
                delete aux;
                //aux2->childs.erase(remove(aux2->childs.begin(), aux2->childs.end(), name), aux2->childs.end());

            }
            else
            {
                cout << "The directory has sub-directories, use -r if you want to remove everything"<<endl;
            }
        }
        else
        {

            cout << "The directory " << name << " doesn't exits" << endl;
        }
    }
    else
    {
        while((pos = pwd.find(delimiter)) != string::npos)
        {
            token = pwd.substr(0,pos);
            pwd.erase(0,pos + delimiter.length());
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(token) == 0)
                {
                    aux=aux->childs[i];
                    aux2=aux;
                }
            }
        }
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    aux=aux->childs[i];
                }
            }
            if(aux->childs.size() > 0 && everything == true)
            {
                size_t pos = aux2->name.find(name);
                if (pos != std::string::npos)
                {
                    aux2->names.erase(pos, name.length()+1);
                    cout << "Bla bla";
                }
                delete aux;
                //aux2->childs.erase(remove(aux2->childs.begin(), aux2->childs.end(), name), aux2->childs.end());

            }
            else if (aux->childs.size() == 0)
            {
                size_t pos = aux2->names.find(name);
                if (pos != std::string::npos)
                {
                    aux2->names.erase(pos, name.length()+1);
                    cout << "Bla bla";

                }
                delete aux;
                //aux2->childs.erase(remove(aux2->childs.begin(), aux2->childs.end(), name), aux2->childs.end());

            }
            else
            {
                cout << "The directory has sub-directories, use -r if you want to remove everything"<<endl;
            }
        }
        else
        {

            cout << "The directory " << name << " doesn't exits" << endl;
        }

    }

}

void Tree::getChilds(string pwd)
{
    size_t pos=0;
    string delimiter = "\\";
    string token;
    Node *aux;
    aux=&root;
    pos = pwd.find(delimiter);
    token = pwd.substr(0,pos);
    pwd.erase(0,pos + delimiter.length());
    if((pos = pwd.find(delimiter)) == string::npos)
    {
        cout << aux->names << endl;
    }
    else
    {
        while((pos = pwd.find(delimiter)) != string::npos)
        {
            token = pwd.substr(0,pos);
            pwd.erase(0,pos + delimiter.length());
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(token)==0 && aux->childs[i]->isFile == false)
                {
                    aux=aux->childs[i];
                }
            }
        }
        cout << aux->names << endl;

    }

}

bool Tree::exitsChild(string name,string pwd)
{
    size_t pos=0;
    string delimiter = "\\";
    string token;
    Node *aux;
    aux=&root;
    pos = pwd.find(delimiter);
    token = pwd.substr(0,pos);
    pwd.erase(0,pos + delimiter.length());
    if((pos = pwd.find(delimiter)) == string::npos)
    {
        if(aux->names.find(name)!= string::npos)
        {
            for(int i = 0; i<aux->names.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    if(aux->childs[i]->isFile)
                    {
                        return false;
                    }
                    return true;
                }
            }
        }
        else
            return false;
    }
    else
    {
        while((pos = pwd.find(delimiter)) != string::npos)
        {
            token = pwd.substr(0,pos);
            pwd.erase(0,pos + delimiter.length());
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(token) == 0 && aux->childs[i]->isFile == false)
                {
                    aux=aux->childs[i];
                }
            }
        }
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->names.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    if(aux->childs[i]->isFile)
                    {
                        return false;
                    }
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
    }

}

void Tree::writeFile(string name,string text,string pwd)
{
    size_t pos=0;
    string delimiter = "\\";
    string token;
    Node *aux;
    aux=&root;
    pos = pwd.find(delimiter);
    token = pwd.substr(0,pos);
    pwd.erase(0,pos + delimiter.length());
    if((pos = pwd.find(delimiter)) == string::npos)
    {
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->names.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    if(aux->childs[i]->isFile == true)
                    {
                        aux->childs[i]->text.append(text);
                        aux->childs[i]->text.append("\n");
                        break;
                    }
                    else
                    {
                        cout << "Not a file" << endl;
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "The file doesn't exist" << endl;
        }
    }
    else
    {
        while((pos = pwd.find(delimiter)) != string::npos)
        {
            token = pwd.substr(0,pos);
            pwd.erase(0,pos + delimiter.length());
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(token)==0 && aux->childs[i]->isFile == false)
                {
                    aux=aux->childs[i];
                }
            }
        }
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->names.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    if(aux->childs[i]->isFile == true)
                    {
                        aux->childs[i]->text.append(name);
                        aux->childs[i]->text.append("\n");
                    }
                    else
                    {
                        cout << "Not a file";
                    }
                }
                else
                {
                    cout << "The file doesn't exist";
                }
            }
        }
    }
}

string Tree::getText(string name,int n,string pwd)
{
    size_t pos=0;
    string delimiter = "\\";
    string headText;
    string token;
    Node *aux;
    aux=&root;
    pos = pwd.find(delimiter);
    token = pwd.substr(0,pos);
    pwd.erase(0,pos + delimiter.length());
    if((pos = pwd.find(delimiter)) == string::npos)
    {
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->names.size(); i++)
            {
                if(aux->childs[i]->name.compare(name) == 0)
                {
                    if(aux->childs[i]->isFile == true)
                    {
                        size_t pos=0;
                        string delimiter = "\n";
                        string token;
                        string theText;

                        theText.append(aux->childs[i]->text);
                        while((pos = theText.find(delimiter)) != string::npos && n >0)
                        {
                            token = theText.substr(0,pos);
                            headText.append(token);
                            headText.append("\n");
                            theText.erase(0,pos + delimiter.length());
                            n--;
                        }
                        if((pos = theText.find(delimiter)) == string::npos)
                        {
                            return headText;
                        }
                        break;
                    }
                    else
                    {
                        cout << "Not a file" << endl;
                        return headText;
                        break;
                    }
                }
            }

        }
        else
        {
            return "The file doesn't exist";
        }
        return headText;
    }
    else
    {
        while((pos = pwd.find(delimiter)) != string::npos)
        {
            token = pwd.substr(0,pos);
            pwd.erase(0,pos + delimiter.length());
            for(int i = 0; i<aux->childs.size(); i++)
            {
                if(aux->childs[i]->name.compare(token)==0 && aux->childs[i]->isFile == false)
                {
                    aux=aux->childs[i];
                }
            }
        }
        if(aux->names.find(name) != string::npos)
        {
            for(int i = 0; i<aux->names.size(); i++)
            {
                if(aux->childs[i]->isFile == true)
                {
                    size_t pos=0;
                    string delimiter = "\n";
                    string token;
                    string theText;

                    theText.append(aux->childs[i]->text);
                    while((pos = theText.find(delimiter)) != string::npos && n >0)
                    {
                        token = theText.substr(0,pos);
                        headText.append(token);
                        headText.append("\n");
                        theText.erase(0,pos + delimiter.length());
                    }
                    if((pos = theText.find(delimiter)) == string::npos)
                    {
                        return headText;
                    }
                    break;
                    return headText;

                }
                else
                {
                    cout << "Not a file" << endl;
                    break;
                }
            }
        }
        else
        {
            return "The file doesn't exist";
        }
    }
}


void Tree::showName()
{
    cout << this->root.name;

}
Tree::~Tree()
{

}
