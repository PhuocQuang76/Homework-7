//
// Created by phuoc quang on 3/19/18.
//

#ifndef CHECKBALANCE_READFILE_H
#define CHECKBALANCE_READFILE_H

#include <string>
#include <stack>
#include "SingleQuoteChecker.h"
#include "CommentChecker.h"

using namespace std;

class ReadFile {
private:
    string inputFile;
    SingleQuoteChecker *singleQuoteChecker;
    CommentChecker *commentChecker;
public:
    ReadFile(string fileName);
    ~ReadFile();
    string getInputFile();
    void setInputFile(string inputFile);
    bool readFile(string fileName);
};


#endif //CHECKBALANCE_READFILE_H
