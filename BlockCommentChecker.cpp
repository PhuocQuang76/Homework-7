//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#include "BlockCommentChecker.h"

BlockCommentChecker::BlockCommentChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators) :
        BlockCommentChecker::BalanceChecker(ignore, blockIgnore, previousChar, pairs, operators) {}

BlockCommentChecker::~BlockCommentChecker() {
    BalanceChecker::~BalanceChecker();
}

char BlockCommentChecker::analyzeCharacter(char c, int line) {
    if (!*ignore) {
        if (*previousChar != '\0') {
            if (*previousChar == '/') {
                if (c == '*') {
                    *blockIgnore = true;
                    blockIgnoreStartLine = line;
                }
            } else if (*previousChar == '*' && blockIgnore) {
                if (c == '/') {
                    *BalanceChecker::blockIgnore = false;
                    BalanceChecker::pairs->push("pair matching '/* */");
                }
            }
        }
    }
    BalanceChecker::analyzeCharacter(c, line);
}