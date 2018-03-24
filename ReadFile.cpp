//
// Created by phuoc quang on 3/19/18.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>
#include <queue>
#include "ReadFile.h"
#include "BalanceChecker.h"

using namespace std;
ReadFile::ReadFile(string filename) {
    ReadFile::inputFile = filename;
    bool *ignore = new bool();
    *ignore = false;
    bool *blockIgnore = new bool();
    *blockIgnore = false;
    char *previousChar = new char();
    *previousChar= '\0';
    std::queue<string> *pairs = new std::queue<string>();
    std::stack<char> *operators = new std::stack<char>();
    ReadFile::singleQuoteChecker = new SingleQuoteChecker(ignore, blockIgnore, previousChar, pairs, operators);
    ReadFile::commentChecker = new CommentChecker(ignore, blockIgnore, previousChar, pairs, operators);
    //ReadFile::symbols = new stack(char);
}
ReadFile::~ReadFile() {
    delete(ReadFile::singleQuoteChecker);
    delete(ReadFile::commentChecker);
}

string ReadFile::getInputFile(){
    return ReadFile::inputFile;
}

void ReadFile::setInputFile(string inputFile) {
    ReadFile::inputFile = inputFile;
}


bool ReadFile::readFile(string fileName){
    ifstream inFile(fileName);
    BalanceChecker *balanceChecker = nullptr;
    bool isValid = true;
    if(inFile.is_open()){
        stack<char> symbols;
        string line;
        int lineNumber = 0;
        char c;
        while (getline(inFile, line)) {
            lineNumber++;
            cout << lineNumber << "\t";
            istringstream iss(line);
            //char comment ;
            while (iss.get(c)) {
                switch(c) {
                    case '/' :
                    case '*':
                        balanceChecker = ReadFile::commentChecker;
                        break;
                    case '\'':
                        balanceChecker = ReadFile::singleQuoteChecker;
                }

                cout << balanceChecker->analyzeCharacter(c, lineNumber);
            }
            cout << endl;
        }
        if(!symbols.empty()){
            isValid = false;
        }
    }else{
        cout <<"Error opening file"<< endl;
    }
    inFile.close();
    return  isValid;
}
