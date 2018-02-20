#ifndef PROCESSCOMMAND_H
#define PROCESSCOMMAND_H
#include <string>
#include <vector>
#include "../include/Tree.h"
using namespace std;

class ProcessCommand
{
public:

    ProcessCommand();
    void setCommand(string command);
    void printCommand();
    void divideCommand(string command);
    virtual ~ProcessCommand();
    void checkCommand();
    void resetCommand();
    void clearCommand();
    void pwdCommand();
    void changeDirectory();

protected:

private:
    string _command;
    string pwd = "root\\";
    vector <string> _arg;
    Tree files;
};

#endif // PROCESSCOMMAND_H
