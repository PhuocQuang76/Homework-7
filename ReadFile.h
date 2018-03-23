//
// Created by phuoc quang on 3/19/18.
//

#ifndef CHECKBALANCE_READFILE_H
#define CHECKBALANCE_READFILE_H

#include <string>
#include <stack>

using namespace std;

class ReadFile {
private:
    string inputFile;
    //std::stack<char> symbols;
public:
    ReadFile(string fileName);
    ~ReadFile();
    string getInputFile();
    void setInputFile(string inputFile);
    bool readFile(string fileName);
    bool checkBalance(stack<char> *myStack, char ch);
    bool check_Parentheses(stack<char> *myStack, char c);
    bool check_Slash_Slash(stack<char> *myStack, char c);
    bool check_Slash_Asterish(stack<char> *myStack, char c);
    bool check_Single_Comment(stack<char> *myStack, char c);
};


#endif //CHECKBALANCE_READFILE_H
