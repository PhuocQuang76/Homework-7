#ifndef HW_7_BALANCECHECKER_H
#define HW_7_BALANCECHECKER_H

#include <string>
#include <stack>
#include <queue>

class BalanceChecker {
private:
    std::string a = "//";
protected:
    bool *ignore; //this status is for all subclasses and instances of BalanceChecker.
    bool *blockIgnore; //this status is for all subclasses and instances of BalanceChecker.
    char *previousChar; //this status is for all subclasses and instances of BalanceChecker.
    std::queue<std::string> *pairs;
    std::stack<char> *operators;
public:
    BalanceChecker(bool *ignore, bool *blockIgnore, char *previousChar, std::queue<std::string> *pairs, std::stack<char> *operators);
    virtual ~BalanceChecker();
    virtual char analyzeCharacter(char c, int line);
    void resetIgnore();
    bool isNotQuoteBalancedInLine();
    char topCharacter();
    void displayMatches();
};


#endif //HW_7_BALANCECHECKER_H
