#include <iostream>
#include <string>
#include <stdio.h>
#include "include/ProcessCommand.h"
#include "include/Tree.h"
using namespace std;

int main()
{
    string userName,command;
    ProcessCommand *processer = new ProcessCommand();
    cout << "Username: ";
    getline(cin,userName);
    while(userName.empty())
    {
        cout<< endl <<"Please enter a username:";
        getline(cin,userName);
    }
    for (int i=0; i<25; i++)
    {
        cout << endl<<endl;

    }
    cout << "Welcome to Onyx, " << userName << endl;
    while (true)
    {
        cout << "Onyx shell > ";
        getline(cin,command);
        processer->setCommand(command);
        processer->divideCommand(command);
        processer->checkCommand();
        processer->resetCommand();
    }

    return 0;
}
