//
// Created by phuoc quang on 3/19/18.
//

#include <iostream>
#include "ReadFile.h"
#include <sstream>
#include <fstream>
#include "Balance_Checking.h"


using namespace std;
ReadFile::ReadFile(string filename) {
    ReadFile::inputFile = filename;
    //ReadFile::symbols = new stack(char);
}
ReadFile::~ReadFile() {

}

string ReadFile::getInputFile(){
    return ReadFile::inputFile;
}

void ReadFile::setInputFile(string inputFile) {
    ReadFile::inputFile = inputFile;
}


bool ReadFile::readFile(string fileName){
    ifstream inFile(fileName);
    bool isValid = true;
    if(inFile.is_open()){
        stack<char> symbols;
        string line;
        int lineNumber = 0;
        char c;
        bool ignore = false;
        while (getline(inFile, line)) {
            ignore = false;
            lineNumber++;
            cout << lineNumber << "\t";
            istringstream iss(line);
            //char comment ;
            while (iss.get(c)) {
                cout << c;
                // Check if symbols are: "//"
                if(c == '/') {
                    iss.get(c);
                    if(c == '/'){
                        ignore = check_Slash_Slash(&symbols,c);
                    }
//                    else if (c == '*'){
//                        ignore = check_Slash_Asterish(&symbols,c);
//                        while (getline(inFile,line)){
//                            ignore = true;
//                            cout << endl;
//                            lineNumber++;
//                            cout << lineNumber << "\t";
//                            while(iss.get(c)){
//                                cout << c;
//                                if(c == '*'){
//                                    iss.get(c);
//                                    cout << c;
//
//                                    if(c == '/'){
//                                        cout << c;
//                                        ignore = false;
//                                        break;
//                                    }
//                                }
//                            }
//
//                        }
//
//                    }
                    else{
                        cout << c;
                    }
                }


//                if(c == '*'){
//                    char first = c;
//                    iss.get(c);
//                    if(c != '/'){
//                        cout << c;
//                        if (!checkBalance(&symbols, first)) {
//                            isValid = false;
//                            break;
//                        }
//                        if (!checkBalance(&symbols, c)) {
//                            isValid = false;
//                            break;
//                        }
//                    }else{
//                        cout << c;
//                    }
//                }

                //Check parentheses '(' '{' '['
                if (!ignore) {
                   isValid = check_Parentheses(&symbols, c);
                }
            }
            cout << endl;
        }
        if(!symbols.empty()){
            isValid = false;
        }
    }else{
        cout <<"Error opening file"<< endl;
    }
    inFile.close();
    return  isValid;
 }

bool ReadFile::checkBalance(stack<char> *myStack, char ch) {
    //Check if stack is empty
    if(myStack->empty()){
        return false;
    }

    //Remove matching symbols from stack
    char topCharacter;
    topCharacter = myStack->top();
    myStack->pop();

    return ((topCharacter == '(') && (ch == ')')) || ((topCharacter == '[' ) && (ch == ']')) ||
           ((topCharacter == '{') && (ch == '}'));
}

bool ReadFile::check_Parentheses(stack<char> *myStack, char c){
    bool flag = true;
    if ((c == '(') || (c == '{') || (c == '[')) {
        myStack->push(c);        //push symbols(, {, [ into the stack
    } else if ((c == ')') || (c == '}') || (c == ']')) {
        if (!checkBalance(myStack, c)) {
            flag =  false;
        }
    }
    return flag;
}

bool ReadFile::check_Slash_Slash(stack<char> *myStack, char c) {
    //bool flag = false;
    //if (c == '/') {
        cout << c;
        //flag = true;
//    }else if (c == '*'){
//        cout << c;
//        myStack->push('/');
//        myStack->push('*');
//        //ignore = true;
    //}else{
       // cout << c;
        //ignore = true;
    //}
    return true;
}

//bool ReadFile::check_Slash_Asterish(stack<char> *myStack, char c) {
////    bool flag = false;
////    if(c == '*'){
//        cout << c;
//        myStack->push('/');
//        myStack->push('*');
////        flag = true;
////    }
//    return true;
//}

//bool REadFile::check_Asterish(stack<char> *myStack, char c){
//    bool flag = true;
//        char first = c;
//        iss->get(c);
//        if(c != '/'){
//            cout << c;
//            if (!checkBalance(myStack, first)) {
//                flag = false;
//                exit(1);
//            }
//            if (!checkBalance(myStack, c)) {
//                flag = false;
//                exit(1);
//            }
//        }else{
//            cout << c;
//
//        }
//    return flag;
//}

bool ReadFile::check_Single_Comment(stack<char> *myStack, char c){
    bool flag = false;
    if(c == '\''){
    }
}
