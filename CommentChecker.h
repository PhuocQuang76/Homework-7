#ifndef HW_7_COMMENTCHECKER_H
#define HW_7_COMMENTCHECKER_H

#include <stack>
#include "BalanceChecker.h"

class CommentChecker : public BalanceChecker {
protected:
    std::stack<int> *blockIgnoreStartLine;
public:
    CommentChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    ~CommentChecker();
    char analyzeCharacter(char c, int line);
};


#endif //HW_7_COMMENTCHECKER_H
