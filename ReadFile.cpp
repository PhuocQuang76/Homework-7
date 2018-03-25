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

    ignore = new bool();
    *ignore = false;
    blockIgnore = new bool();
    *blockIgnore = false;
    previousChar = new char();
    *previousChar= '\0';

    pairs = new std::queue<string>();
    operators = new std::stack<char>();

    ReadFile::singleQuoteChecker = new SingleQuoteChecker(ignore, blockIgnore, previousChar, pairs, operators);
    ReadFile::commentChecker = new CommentChecker(ignore, blockIgnore, previousChar, pairs, operators);
    ReadFile::doubleQuoteChecker = new DoubleQuoteChecker(ignore, blockIgnore, previousChar, pairs, operators);
    ReadFile::squareBlockChecker = new BlockChecker('[', ']', ignore, blockIgnore, previousChar, pairs, operators);
    ReadFile::parenthesisBlockChecker = new BlockChecker('(', ')', ignore, blockIgnore, previousChar, pairs, operators);
    ReadFile::curlyBraceBlockChecker = new BlockChecker('{', '}', ignore, blockIgnore, previousChar, pairs, operators);
}
ReadFile::~ReadFile() {
    delete(ReadFile::singleQuoteChecker);
    delete(ReadFile::commentChecker);

    for (;ReadFile::operators->size() > 0;) {
        operators->pop();
    }
    delete(ReadFile::operators);
    for (;ReadFile::pairs->size() > 0;) {
        ReadFile::pairs->pop();
    }

    delete(ignore);
    delete(blockIgnore);
    delete(previousChar);
    delete(pairs);
    delete(operators);
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
                        break;
                    case '\"':
                        balanceChecker = ReadFile::doubleQuoteChecker;
                        break;
                    case '{':
                    case '}':
                        balanceChecker = ReadFile::curlyBraceBlockChecker;
                        break;
                    case '[':
                    case ']':
                        balanceChecker = ReadFile::squareBlockChecker;
                        break;
                    case '(':
                    case ')':
                        balanceChecker = ReadFile::parenthesisBlockChecker;
                        break;
                    default:
                        balanceChecker = ReadFile::singleQuoteChecker;
                }

                cout << balanceChecker->analyzeCharacter(c, lineNumber);
            }
            cout << endl;
            balanceChecker->resetIgnore();
            if (balanceChecker->isNotQuoteBalancedInLine()) {
                balanceChecker->displayMatches();
                char c = balanceChecker->topCharacter();
                if (c == '\'') {
                    cout << "unbalance quote \' on line " << lineNumber;
                } else if (c == '\"') {
                    cout << "unbalance double quote \" on line " << lineNumber;
                }
                break;
            }
        }
        balanceChecker->displayMatches();
        ReadFile::checkForUnclosedBlocks();
        isValid = balanceChecker->topCharacter() == '\0';
    }else{
        cout <<"Error opening file"<< endl;
    }
    inFile.close();
    return  isValid;
}

void ReadFile::checkForUnclosedBlocks() {
    char top = this->singleQuoteChecker->topCharacter();
    std::string message = "unbalanced ";
    bool displayMessage = false;
    switch(top) {
        case '{':
            displayMessage = true;
            message.append("{ on line ");
            message.append(std::to_string(ReadFile::curlyBraceBlockChecker->getLastLineDiscovered()));
            break;
        case '[':
            displayMessage = true;
            message.append("{ on line ");
            message.append(std::to_string(ReadFile::squareBlockChecker->getLastLineDiscovered()));
            break;
        case '(':
            displayMessage = true;
            message.append("{ on line ");
            message.append(std::to_string(ReadFile::parenthesisBlockChecker->getLastLineDiscovered()));
            break;
    }
    if (displayMessage) std::cout<<message<<std::endl;
}
