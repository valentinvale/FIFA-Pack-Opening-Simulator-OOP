

#include "badge.h"

const std::string &badge::getQuality() const {return quality; }

badge::badge(int id_, const std::string &name_, const std::string &quality_) :id{id_}, name{name_}, quality{quality_} {

            if(id_ < 0) throw invalidId("ID invalid");
//        std::cout << "constructor de initializare badge\n";
}

badge::badge() {}

std::ostream &operator<<(std::ostream &os, const badge &badge) {
    os << "Name: " << badge.name << " Id: " << badge.id <<" Quality: " << badge.quality <<'\n';
    return os;
}

int badge::getId() const {
    return id;
}



