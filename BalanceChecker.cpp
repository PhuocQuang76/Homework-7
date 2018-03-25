//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#include <iostream>
#include <string>
#include "BalanceChecker.h"

BalanceChecker::BalanceChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators) {
    std::cout<<"Calling BalanceChecker Destructor";
    BalanceChecker::previousChar = previousChar;
    BalanceChecker::blockIgnore = blockIgnore;
    BalanceChecker::ignore = ignore;
    BalanceChecker::operators = operators;
    BalanceChecker::pairs = pairs;
}

BalanceChecker::~BalanceChecker() {

}

char BalanceChecker::analyzeCharacter(char c, int line) {
    //set the previous character.
    *previousChar = c;
    return c;
}

void BalanceChecker::resetIgnore() {
    *ignore = false;
}

bool BalanceChecker::isNotQuoteBalancedInLine() {
    bool retValue = false;
    if (BalanceChecker::operators->size() > 0) {
        char top = BalanceChecker::operators->top();
        retValue = (top == '\'' || top == '\"');
    }
    return retValue;
}

char BalanceChecker::topCharacter() {
    if (BalanceChecker::operators->size() == 0) {
        return '\0';
    } else {
        return BalanceChecker::operators->top();
    }
}

void BalanceChecker::displayMatches() {
    for (;BalanceChecker::pairs->size() > 0;) {
        std::string match = BalanceChecker::pairs->front();
        BalanceChecker::pairs->pop();
        std::cout<<match<<std::endl;
    }
}