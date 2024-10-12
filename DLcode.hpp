#ifndef DLIST_MENU
#define DLIST_MENU
#include "DL.hpp"
#include "Fin.hpp"
#include "Fout.hpp"

const string DLIST_SECTION = "Dlist";

void dlistMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "DLPUSHBACK") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        Dlist<string> dlist = readDlist(nameArr);
        dlist.pushBack(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } 
    
    else if (command == "DLPUSHFRONT") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        Dlist<string> dlist = readDlist(nameArr);
        dlist.pushForward(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } 
    
    else if (command == "DLDELBACK") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeBack();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } 
    
    else if (command == "DLDELFRONT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeForward();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } 
    
    else if (command == "DLDELVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeValue(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } 
    
    else if (command == "DLGET") {
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

        Dlist<string> dlist = readDlist(nameArr);
        cout << dlist.get(index) << endl;
    } 
    
    else if (command == "DLFINDVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        Dlist<string> dlist = readDlist(nameArr);
        int index = dlist.findByValue(element);

        if (index != -1) {
            cout << index << endl;
        } 
        else {
            throw runtime_error("not found");
        }
    } 
    
    else if (command == "DLPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        cout << dlist << endl;
    }
}

#endif