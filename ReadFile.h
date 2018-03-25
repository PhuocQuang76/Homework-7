//
// Created by phuoc quang on 3/19/18.
//

#ifndef CHECKBALANCE_READFILE_H
#define CHECKBALANCE_READFILE_H

#include <string>
#include <stack>
#include "SingleQuoteChecker.h"
#include "CommentChecker.h"
#include "DoubleQuoteChecker.h"
#include "BlockChecker.h"
using namespace std;

class ReadFile {
private:
    bool *ignore;
    bool *blockIgnore;
    char *previousChar;

    void checkForUnclosedBlocks();

protected:
    string inputFile;
    SingleQuoteChecker *singleQuoteChecker;
    CommentChecker *commentChecker;
    DoubleQuoteChecker *doubleQuoteChecker;
    BlockChecker *squareBlockChecker;
    BlockChecker *parenthesisBlockChecker;
    BlockChecker *curlyBraceBlockChecker;

    std::queue<string> *pairs;
    std::stack<char> *operators;
public:
    ReadFile(string fileName);
    ~ReadFile();
    string getInputFile();
    void setInputFile(string inputFile);
    bool readFile(string fileName);
};


#endif //CHECKBALANCE_READFILE_H
