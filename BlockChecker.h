#ifndef HW_7_BLOCKCHECKER_H
#define HW_7_BLOCKCHECKER_H


#include <queue>
#include <stack>
#include "BalanceChecker.h"

class BlockChecker : public BalanceChecker{
protected:
    std::stack<int> *lineDiscovered;
    char startChar;
    char endChar;
public:
    BlockChecker(char startChar, char endChar, bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    ~BlockChecker();
    char analyzeCharacter(char c, int line);
    int getLastLineDiscovered();
};

#endif //HW_7_BLOCKCHECKER_H
