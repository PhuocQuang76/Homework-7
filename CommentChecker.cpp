//
// Created by Sangalang, Emmanuel on 3/24/18.
//

#include "CommentChecker.h"

CommentChecker::CommentChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs,
                               std::stack<char> *operators) : BalanceChecker::BalanceChecker(ignore, blockIgnore,
                               previousChar, pairs, operators) {
    CommentChecker::blockIgnoreStartLine = new std::stack<int>();
}

CommentChecker::~CommentChecker() {
    delete(blockIgnoreStartLine);
    //BalanceChecker::~BalanceChecker();
}

char CommentChecker::analyzeCharacter(char c, int line) {
    if (*blockIgnore) {//check if currently on block comment mode
        if (*previousChar == '*') {
            if (c == '/') {
                *blockIgnore = false;
                blockIgnoreStartLine->pop();
                BalanceChecker::pairs->push("pair matching /* and */");
            }
        }
    } if (*ignore) {//check if on line comment mode
        //do nothing
    } else if (*previousChar == '/') {
        if (BalanceChecker::operators->size() > 0 && (BalanceChecker::operators->top() != '\"' || BalanceChecker::operators->top() != '\'')) {
            //do nothing
        } else if (c == '*') {
                *blockIgnore = true;
                blockIgnoreStartLine->push(line);
        } else if (c == '/') {
            *ignore = true;
        }
    }
    BalanceChecker::analyzeCharacter(c, line);
    return c;
}