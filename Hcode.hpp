#ifndef MAPMENU_H
#define MAPMENU_H

#include "H.hpp"
#include "Fin.hpp"
#include "Fout.hpp"

const string MAP_SECTION = "Map";

void mapMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "HPUSH") {
        if (arguments.size() != 4) {
            throw runtime_error("not arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);
        string value = arguments.get(3);

        if (key.find(",") != string::npos || value.find(",") != string::npos) {
            throw runtime_error("not value");
        } 
        else if (key.find(";") != string::npos || value.find(",") != string::npos) {
            throw runtime_error("not value");
        }

        Map<string> map = readMap(name);
        map.put(key, value);
        save(MAP_SECTION, name, name + " " + map.join());
    } 
    
    else if (command == "HDEL") {
        if (arguments.size() != 3) {
            throw invalid_argument("not arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        Map<string> map = readMap(name);
        map.remove(key);
        save(MAP_SECTION, name, name + " " + map.join());
    } 

    else if (command == "HGET") {
        if (arguments.size() != 3) {
            throw invalid_argument("not arguments");
        }
        string name = arguments.get(1);
        int index;
        string key = arguments.get(2);

        Map<string> map = readMap(name);
        cout << map.get(key) << endl;
        save(MAP_SECTION, name, name + " " + map.join());
    } 
    
    else if (command == "HPRINT") {
        if (arguments.size() != 2) {
            throw invalid_argument("not arguments");
        }
        string name = arguments.get(1);

        Map<string> map = readMap(name);
        cout << map << endl;
    }
}

#endif