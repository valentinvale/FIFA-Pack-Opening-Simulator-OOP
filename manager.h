#include <vector>
#include <string>
#include <iostream>
#include "error.h"

#ifndef OOP_MANAGER_H
#define OOP_MANAGER_H


class manager{
    int id = 0;
    std::string name;
    std::string quality;
    std::string league;


public:
//    const std::string& getName() const {return name; }
//    const std::string& getLeague() const {return league; }
    const std::string& getQuality() const;
//    int getId() const {return id; }

    manager(int id_, const std::string& name_, const std::string& quality_, const std::string & league_);

    manager();

//    manager(const manager& other) : name{other.name}, quality{other.quality}, league{other.league}, id{other.id} {
//
//        std::cout << "constructor de copiere manager\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const manager& manager);

    int getId() const;

};


#endif //OOP_MANAGER_H
