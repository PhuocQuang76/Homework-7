#include "DoubleQuoteChecker.h"
#include "BalanceChecker.h"

DoubleQuoteChecker::DoubleQuoteChecker(bool *ignore, bool *blockIgnore, char *previousChar,
                                       std::queue <std::string> *pairs, std::stack<char> *operators) : BalanceChecker::BalanceChecker(
        ignore, blockIgnore, previousChar, pairs, operators) {}

DoubleQuoteChecker::~DoubleQuoteChecker() {
    //do nothing
}

char DoubleQuoteChecker::analyzeCharacter(char c, int line) {
    if (!(*ignore || *blockIgnore)) {
        if (BalanceChecker::operators->size() > 0 && BalanceChecker::operators->top() == '\'') {
            //ignore: you're inside the first quote.
        } else if (c == '\"') {
            if (*previousChar != '\\') {
                if (BalanceChecker::operators->size() > 0 && BalanceChecker::operators->top() == '"') {
                    BalanceChecker::operators->pop();
                    BalanceChecker::pairs->push("pair matching \" and \"");
                } else {
                    BalanceChecker::operators->push('\"');
                }
            }
        }
    }
    return BalanceChecker::analyzeCharacter(c, line);
}