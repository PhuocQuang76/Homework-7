//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#ifndef HW_7_BLOCKCOMMENTCHECKER_H
#define HW_7_BLOCKCOMMENTCHECKER_H


#include "BalanceChecker.h"

class BlockCommentChecker : public BalanceChecker {
protected:
    int blockIgnoreStartLine;
public:
    BlockCommentChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    ~BlockCommentChecker();
    char analyzeCharacter(char c, int line);
};


#endif //HW_7_BLOCKCOMMENTCHECKER_H
