#include <iostream>
#include "ReadFile.h"
//#include "readFile.cpp"
#include <stack>


int main() {

   // cout << "Please enter filename for C++ code: " ;
    string fileName = "bad_balance2.txt";
    //cin >> fileName;
    ReadFile *readFile = new ReadFile(fileName);
    readFile->setInputFile(fileName);
    string file = readFile->getInputFile();
    bool check = readFile->readFile(file);
    cout <<"\ncheck is : " << check << endl;
    if(check){
        cout <<"File is valid."<< endl;
    }else{
        cout << " File is invalid." << endl;
    }


    return 0;
}