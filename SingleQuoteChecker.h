#ifndef HW_7_SINGLEQUOTECHECKER_H
#define HW_7_SINGLEQUOTECHECKER_H


#include "BalanceChecker.h"

class SingleQuoteChecker : public BalanceChecker {
public:
    SingleQuoteChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    ~SingleQuoteChecker();
    char analyzeCharacter(char c, int line);
};


#endif //HW_7_SINGLEQUOTECHECKER_H
