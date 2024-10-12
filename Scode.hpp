#ifndef STACKMENU_H
#define STACKMENU_H

#include "S.hpp"
#include "Fin.hpp"
#include "Fout.hpp"

const string STACK_SECTION = "Stack";

void stackMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "SPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        Stack<string> stack = readStack(nameArr);
        stack.push(element);
        save(STACK_SECTION, nameArr, nameArr + " " + stack.data().join(','));
    } 
    
    else if (command == "SPOP") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Stack<string> stack = readStack(nameArr);
        cout << "Popped: " << stack.pop() << endl;
        save(STACK_SECTION, nameArr, nameArr + " " + stack.data().join(','));
    } 
    
    else if (command == "SPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Stack<string> stack = readStack(nameArr);
        cout << stack << endl;
    }

    else if (command == "SGET") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        int index;
        try {
            index = stoi(arguments.get(2));
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not number");
        }

        Stack<string> stack = readStack(nameArr);
        cout << stack.get(index) << endl;
    }
}

#endif