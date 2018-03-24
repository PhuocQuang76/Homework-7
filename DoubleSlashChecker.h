//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#ifndef HW_7_DOUBLESLASHCHECKER_H
#define HW_7_DOUBLESLASHCHECKER_H


#include "BalanceChecker.h"
class DoubleSlashChecker : public BalanceChecker {
private:

public:
    DoubleSlashChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    ~DoubleSlashChecker();
    char analyzeCharacter(char c, int line);
};


#endif //HW_7_DOUBLESLASHCHECKER_H
