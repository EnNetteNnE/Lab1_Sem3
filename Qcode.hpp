#ifndef QUEUEMENU_H
#define QUEUEMENU_H

#include "Q.hpp"
#include "Fin.hpp"
#include "Fout.hpp"

const string QUEUE_SECTION = "Queue";

void queueMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "QPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error("not element");
        }

        Queue<string> queue = readQueue(nameArr);
        queue.enqueue(element);
        save(QUEUE_SECTION, nameArr, nameArr + " " + queue.data().join(','));
    } 
    
    else if (command == "QPOP") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Queue<string> queue = readQueue(nameArr);
        cout << "Popped: " << queue.dequeue() << endl;
        save(QUEUE_SECTION, nameArr, nameArr + " " + queue.data().join(','));
    } 
    
    else if (command == "QPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("not arguments");
        }
        string nameArr = arguments.get(1);

        Queue<string> queue = readQueue(nameArr);
        cout << queue << endl;
    }

    else if (command == "QGET") {
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

        Queue<string> queue = readQueue(nameArr);
        
        cout << queue.get(index) << endl;
    }
}

#endif