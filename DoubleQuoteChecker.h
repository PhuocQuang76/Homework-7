#ifndef HW_7_DOUBLEQUOTECHECKER_H
#define HW_7_DOUBLEQUOTECHECKER_H

#include <queue>
#include <stack>
#include "BalanceChecker.h"

class DoubleQuoteChecker : public BalanceChecker {

public:
    DoubleQuoteChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    ~DoubleQuoteChecker();
    char analyzeCharacter(char c, int line);
};


#endif //HW_7_DOUBLEQUOTECHECKER_H
