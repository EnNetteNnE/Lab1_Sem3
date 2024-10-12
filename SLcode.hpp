#ifndef SLIST_MENU
#define SLIST_MENU
#include "SL.hpp"
#include "Fin.hpp"
#include "Fout.hpp"

const string SLIST_SECTION = "Slist";

void slistMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "SLPUSHBACK") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        SList<string> Slist = readSlist(nameArr);
        Slist.pushBack(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    } 
    
    else if (command == "SLPUSHFRONT") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        SList<string> Slist = readSlist(nameArr);
        Slist.pushForward(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    } 
    
    else if (command == "SLDELBACK") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> Slist = readSlist(nameArr);
        Slist.removeBack();
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    } 
    
    else if (command == "SLDELFRONT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> Slist = readSlist(nameArr);
        Slist.removeForward();
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    } 
    
    else if (command == "SLDELVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        SList<string> Slist = readSlist(nameArr);
        Slist.removeValue(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    } 
    
    else if (command == "SLGET") {
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

        SList<string> Slist = readSlist(nameArr);
        cout << Slist.get(index) << endl;
    } 
    
    else if (command == "SLFINDVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        SList<string> Slist = readSlist(nameArr);
        int index = Slist.findByValue(element);

        if (index != -1) {
            cout << index << endl;
        } 
        else {
            throw runtime_error("not found");
        }
    } 
    
    else if (command == "SLPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> Slist = readSlist(nameArr);
        cout << Slist << endl;
    }
}

#endif