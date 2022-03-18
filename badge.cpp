

#include "badge.h"

const std::string &badge::getQuality() const {return quality; }

badge::badge(int id_, const std::string &name_, const std::string &quality_) :id{id_}, name{name_}, quality{quality_} {

//        std::cout << "constructor de initializare badge\n";
}

badge::badge() {}

std::ostream &operator<<(std::ostream &os, const badge &badge) {
    os << "name: " << badge.name << " quality: " << badge.quality << " id: " << badge.id <<'\n';
    return os;
}
