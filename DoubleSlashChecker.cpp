//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#include "DoubleSlashChecker.h"

DoubleSlashChecker::DoubleSlashChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators) :
        BalanceChecker::BalanceChecker(ignore, blockIgnore, previousChar, pairs, operators){}

DoubleSlashChecker::~DoubleSlashChecker() {
    BalanceChecker::~BalanceChecker();//call the destructor of the parent.
}

char DoubleSlashChecker::analyzeCharacter(char c, int line) {
    if (!*blockIgnore && BalanceChecker::operators->size() > 0 && (BalanceChecker::operators->top() != '\"' || BalanceChecker::operators->top() != '\'')) {
        if (*previousChar != '\0') {
            if (*previousChar == '/') {
                if (c == '/') {
                    *BalanceChecker::ignore = true;
                }
            }
        }
    }
    BalanceChecker::analyzeCharacter(c, line); //set the previous character to this one
    return c;
}