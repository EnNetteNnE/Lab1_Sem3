#include <iostream>
#include "M.hpp"
#include "str.hpp"
#include "Mcode.hpp"
#include "Scode.hpp"
#include "Qcode.hpp"
#include "DLcode.hpp"
#include "SLcode.hpp"
#include "Hcode.hpp"

using namespace std;

int main() {
    string str;

    while (true) {
        cout << "./dbms --file file.data --query ";
        getline(cin, str);

        Vector<string> splitedStr = split(str, ' ');
        string command = splitedStr.get(0);


        if (command.substr(0, 2) == "DL") {
            try {
                dlistMenu(splitedStr);
            } 
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } 
        
        else if (command.substr(0, 2) == "SL") {
            try {
                slistMenu(splitedStr);
            } 
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } 
        
        else if (command[0] == 'M') {
            try {
                vectorMenu(splitedStr);
            } 
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } 
        
        else if (command[0] == 'Q') {
            try {
                queueMenu(splitedStr);
            } 
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } 
        
        else if (command[0] == 'S') {
            try {
                stackMenu(splitedStr);
            } 
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } 
        
        else if (command[0] == 'H') {
            try {
                mapMenu(splitedStr);
            } 
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } 
        
        else {
            cerr << "Unknown command" << endl;
        }
    }

    return 0;
}