#include <vector>
#include <string>
#include <iostream>
#include "error.h"

#ifndef OOP_BADGE_H
#define OOP_BADGE_H

class badge {
    int id = 0;
    std::string name;
    std::string quality;


public:
//    const std::string& getName() const {return name; }
//    const T& getQuality() const;
//    const std::string& getQuality() const;
    const std::string &getQuality() const;

//    int getId() const {return id; }

    badge(int id, const std::string &name, const std::string &quality);

    badge();

//    badge(const badge& other) : name{other.name}, quality{other.quality}, id{other.id} {
//
//        std::cout << "constructor de copiere badge\n";
//    }
    friend std::ostream& operator<<(std::ostream& os, const badge& badge);

    int getId() const;

};


#endif //OOP_BADGE_H
