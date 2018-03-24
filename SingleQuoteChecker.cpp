//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#include "SingleQuoteChecker.h"

SingleQuoteChecker::SingleQuoteChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators) :
        BalanceChecker(ignore, blockIgnore, previousChar, pairs, operators) {}

SingleQuoteChecker::~SingleQuoteChecker() {
    BalanceChecker::~BalanceChecker();
}

char SingleQuoteChecker::analyzeCharacter(char c, int line) {
    if (!(*ignore && *blockIgnore)) {
        if (BalanceChecker::operators->size() > 0 && BalanceChecker::operators->top() == '\'') {
            BalanceChecker::operators->pop();
            BalanceChecker::pairs->push("pair matching \' and \'");
        } else {
            BalanceChecker::operators->push(c);
        }
    }
    BalanceChecker::analyzeCharacter(c, line);
    return c;
}