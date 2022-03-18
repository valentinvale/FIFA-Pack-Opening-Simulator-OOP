
#include "manager.h"

const std::string &manager::getQuality() const {return quality; }

manager::manager(int id_, const std::string &name_, const std::string &quality_, const std::string &league_) :id{id_}, name{name_},
                                                                                                              quality{quality_}, league{league_} {

//        std::cout << "constructor de initializare manager\n";
}

manager::manager() {}

std::ostream &operator<<(std::ostream &os, const manager &manager) {
    os << "name: " << manager.name << " quality: " << manager.quality << " league: " << manager.league << " id: "
       << manager.id << '\n';
    return os;
}
