#ifndef VECTORMENU_H
#define VECTORMENU_H

#include "M.hpp"
#include "Fin.hpp"
#include "Fout.hpp"

const string ARRAY_SECTION = "Array";

void vectorMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "MPUSH") {

        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        Vector<string> array = readArray(name);
        array.pushBack(element);
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } 
    
    else if (command == "MLEN") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);

        Vector<string> array = readArray(name);
        cout << array.size() << endl;
    } 
    
    else if (command == "MPUSHI") {
        if (arguments.size() != 4) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not number");
        }
        string value = arguments.get(3);

        Vector<string> array = readArray(name);

        array.pushBack(array.get(array.size() - 1));

        for (int i = array.size() - 1; i > index; i--) {
            try {
                array.set(i, array.get(i - 1));
            } 
            catch (invalid_argument& e) {
                throw runtime_error("not index");
            }
        }

        try {
            array.set(index, value);
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not index");
        }

        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } 
    
    else if (command == "MSET") {
        if (arguments.size() != 4) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not number");
        }
        string value = arguments.get(3);

        Vector<string> array = readArray(name);
        try {
            array.set(index, value);
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } 

    else if (command == "MDEL") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not number");
        }

        Vector<string> array = readArray(name);
        try {
            array.remove(index);
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } 
    
    else if (command == "MGET") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } 
        catch (invalid_argument& e) {
            throw runtime_error("not number");
        }

        Vector<string> array = readArray(name);
        cout << array.get(index) << endl;
    }

    else if (command == "MPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);

        Vector<string> array = readArray(name);
        for (int i = 0; i < array.size(); i++) {
            cout << array.get(i) << " ";
        }
        cout << endl;
    }
}

#endif