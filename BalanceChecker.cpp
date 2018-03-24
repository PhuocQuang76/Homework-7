//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#include "BalanceChecker.h"

BalanceChecker::BalanceChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators) {
    BalanceChecker::previousChar = previousChar;
    BalanceChecker::blockIgnore = blockIgnore;
    BalanceChecker::ignore = ignore;
    BalanceChecker::operators = operators;
    BalanceChecker::pairs = pairs;
}

BalanceChecker::~BalanceChecker() {
    for (;BalanceChecker::operators->size() > 0;) {
        operators->pop();
    }
    delete(BalanceChecker::operators);
    for (;BalanceChecker::pairs->size() > 0;) {
        BalanceChecker::pairs->pop();
    }
    delete(BalanceChecker::pairs);
    delete(previousChar);
    delete(ignore);
}

char BalanceChecker::analyzeCharacter(char c, int line) {
    //set the previous character.
    *previousChar = c;
}

void BalanceChecker::resetIgnore() {
    *ignore = false;
}