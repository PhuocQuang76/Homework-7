#include "BlockChecker.h"

BlockChecker::BlockChecker(char startChar, char endChar, bool *ignore, bool *blockIgnore, char *previousChar,
                           std::queue<std::string> *pairs, std::stack<char> *operators) :
        BalanceChecker::BalanceChecker(ignore, blockIgnore, previousChar, pairs, operators) {
    BlockChecker::startChar = startChar;
    BlockChecker::endChar = endChar;
    BlockChecker::lineDiscovered = new std::stack<int>();
}

BlockChecker::~BlockChecker() {
    delete(BlockChecker::lineDiscovered);
}


char BlockChecker::analyzeCharacter(char c, int line) {
    if (!(*ignore || *blockIgnore)) {
        long size = BalanceChecker::operators->size();
        char top = '\0';
        if (size > 0) {
            top = BalanceChecker::operators->top();
        }
        if (top == '\"' || top == '\'') {
            //ignore, you are inside a string declaration
        } else if (c == startChar) {
            BalanceChecker::operators->push(startChar);
            BlockChecker::lineDiscovered->push(line);
        } else if (c == endChar) {
            if (BalanceChecker::operators->size() > 0 && BalanceChecker::operators->top() == startChar) {
                BalanceChecker::operators->pop();
                std::string message = "pair matching ";
                message.append(1, startChar);
                message.append(" and ");
                message.append(1, endChar);
                BalanceChecker::pairs->push(message);
                BlockChecker::lineDiscovered->pop();
            }
        }
    }
    return BalanceChecker::analyzeCharacter(c, line);
}

int BlockChecker::getLastLineDiscovered() {
    if (BlockChecker::lineDiscovered->size() > 0) {
        return BlockChecker::lineDiscovered->top();
    } else return 0;
}