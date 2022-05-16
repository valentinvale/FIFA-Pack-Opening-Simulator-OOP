
#include "manager.h"

const std::string &manager::getQuality() const {return quality; }

manager::manager(int id_, const std::string &name_, const std::string &quality_, const std::string &league_) :id{id_}, name{name_},
                                                                                                              quality{quality_}, league{league_} {

            if(id_ < 0) throw invalidId("ID invalid");
//        std::cout << "constructor de initializare manager\n";
}

manager::manager() {}

std::ostream &operator<<(std::ostream &os, const manager &manager) {
    os << "Name: " << manager.name << " Id: " << manager.id <<" Quality: " << manager.quality << " League: " << manager.league << '\n';
    return os;
}
