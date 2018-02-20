#include "../include/ProcessCommand.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <algorithm>
using namespace std;
ProcessCommand::ProcessCommand()
{
    files.addNode("folder1",false,pwd);
    files.addNode("folder2",false,pwd);
    files.addNode("fisier1",true,pwd);
    files.writeFile("fisier1","ceva1",pwd);
    files.writeFile("fisier1","ceva2",pwd);
    files.writeFile("fisier1","ceva3",pwd);
}

ProcessCommand::~ProcessCommand()
{
}

void ProcessCommand::setCommand(string command)
{
    _command = command;
}

void ProcessCommand::printCommand()
{
    // cout << _command;

}

void ProcessCommand::divideCommand(string command)
{
    size_t pos=0;
    string delimiter = " ";
    string token;
    while((pos = command.find(delimiter)) != string::npos)
    {
        token = command.substr(0,pos);
        _arg.push_back(token);
        command.erase(0,pos + delimiter.length());
    }
    if((pos = command.find(delimiter)) == string::npos)
    {
        _arg.push_back(command);
    }
}


void ProcessCommand::checkCommand()
{
    bool hasOperator = false;
    if (find(_arg.begin(), _arg.end(), ">") != _arg.end())
    {
        hasOperator = true;
    }
    if(_arg[0].compare("clear") == 0)
    {
        this->clearCommand();
    }
    else if(_arg[0].compare("pwd") == 0)
    {
        if(hasOperator == true)
        {
            int index;
            for(int i = 0; i < _arg[0].size(); i++)
            {
                if(_arg[i].compare(">") == 0)
                {
                    index = i + 1;
                    break;
                }
            }
            this->files.writeFile(_arg[index],pwd,pwd);
        }
        else
        {
            this->pwdCommand();
        }
    }
    else if(_arg[0].compare("exit")== 0 )
    {
        exit(0);
    }
    else if(_arg[0].compare("mkdir") == 0)
    {
        this->files.addNode(_arg[1],false,this->pwd);
    }
    else if(_arg[0].compare("rmdir") == 0)
    {
        bool everything = false;
        if(find(_arg.begin(), _arg.end(), "-r") != _arg.end())
        {
            everything = true;
        }
        this->files.deleteNode(_arg[1],everything,this->pwd);
    }
    else if(_arg[0].compare("ls") == 0)
    {
        this->files.getChilds(pwd);
    }
    else if(_arg[0].compare("cd") == 0)
    {
        this->changeDirectory();
    }
    else if(_arg[0].compare("pwd")== 0)
    {
        cout << pwd << endl;
    }
    else if(_arg[0].compare("echo") == 0)
    {
        for(int i = 1; i<_arg.size(); i++)
        {
            cout <<_arg[i]<< " " ;
        }
        cout << endl;
    }
    else if (_arg[0].compare("head") == 0)
    {
        bool hasNumber;
        if (find(_arg.begin(), _arg.end(), ">") != _arg.end())
        {
            hasOperator = true;
        }
        if (hasOperator == false)
        {
            if (find(_arg.begin(), _arg.end(), "-n") != _arg.end())
            {
                try
                {
                    cout << this->files.getText(_arg[3],atoi(_arg[2].c_str()),pwd)<< endl;
                }
                catch(...)
                {
                    cout << "File doesn't exist"<<endl;
                }
            }
            else
            {
                try
                {
                    cout << this->files.getText(_arg[1],10,pwd)<<endl;
                }
                catch(...)
                {
                    cout << "File doesn't exist"<<endl;

                }
            }
        }
    }
    else if(_arg[0].compare("touch")==0){
        this->files.addNode(_arg[1],true,pwd);
    }
    else
    {
        cout <<"Command not recognized!"<< endl;
    }

}



void ProcessCommand::changeDirectory()
{
    if(_arg.size() > 2)
    {
        cout << "Too many arguments"<<endl;
    }
    else
    {
        if(_arg[1].compare("..") == 0)
        {
            string aux_pwd;
            aux_pwd=this->pwd;
            size_t pos=0;
            size_t saved_pos=0;
            string delimiter = "\\";
            string token;
            while((pos = aux_pwd.find(delimiter)) != string::npos)
            {
                token = aux_pwd.substr(0,pos);
                aux_pwd.erase(0,pos + delimiter.length());
            }
            pwd.erase(pwd.length()- token.length() - delimiter.length());
        }
        else if(this->files.exitsChild(_arg[1],pwd))
        {
            this->pwd.append(_arg[1]);
            this->pwd.append("\\");
        }
        else
        {
            cout << "Directory doesn't exist!" << endl;
        }
    }
}

void ProcessCommand::clearCommand()
{
    int i;
    for(i = 0; i<=25; i++)
    {
        cout << endl << endl;
    }

}

void ProcessCommand::pwdCommand()
{
    cout<<this->pwd << endl;
}

void ProcessCommand::resetCommand()
{

    _command.erase();
    _arg.clear();

}
