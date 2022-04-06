#include <vector>
#include <string>
#include <iostream>

#ifndef OOP_BADGE_H
#define OOP_BADGE_H


class badge {
    int id;
    std::string name;
    std::string quality;


public:
//    const std::string& getName() const {return name; }
    const std::string& getQuality() const;
//    int getId() const {return id; }

    badge(int id_, const std::string& name_, const std::string& quality_);

    //badge();

//    badge(const badge& other) : name{other.name}, quality{other.quality}, id{other.id} {
//
//        std::cout << "constructor de copiere badge\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const badge& badge);


};


#endif //OOP_BADGE_H
