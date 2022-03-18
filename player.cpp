#include <vector>
#include <string>
#include <iostream>


#include "player.h"


player::player(int id_, const std::string &name_, const std::string &team_, const std::string &pos_,
               const std::string &quality_, int ovr_, int pac_, int sho_, int pas_, int dri_, int def_, int phy_) :
               id{id_}, name{name_}, team{team_}, pos{pos_}, quality{quality_},
               ovr{ovr_}, pac{pac_}, sho{sho_}, pas{pas_}, dri{dri_}, def{def_}, phy{phy_} {
//        std::cout << "constructor de initializare player\n";
}

player::player() {}

player::player(const player &other) : id{other.id}, name{other.name}, team{other.team}, pos{other.pos}, quality{other.quality},
                                      ovr{other.ovr}, pac{other.pac}, sho{other.sho}, pas{other.pas},
                                      dri{other.dri}, def{other.def}, phy{other.phy} {

//        std::cout << "constructor de copiere player\n";
}

player &player::operator=(const player &other) {
    name = other.name;
    team = other.team;
    pos = other.pos;
    quality = other.quality;
    id = other.id;
    ovr = other.ovr;
    pac = other.pac;
    sho = other.sho;
    pas = other.pas;
    dri = other.dri;
    def = other.def;
    phy = other.phy;

//        std::cout << "operator= copiere player\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const player &pl) {
    os << "name: " << pl.name << " team: " << pl.team << " pos: " << pl.pos << " quality: "
       << pl.quality << " id: " << pl.id << " ovr: " << pl.ovr << " pac: " << pl.pac << " sho: "
       << pl.sho << " pas: " << pl.pas << " dri: " << pl.dri << " def: " << pl.def << " phy: "
       << pl.phy <<'\n';
    return os;
}

player::~player() {
//        std::cout << "destructor player\n";
}

const std::string &player::getQuality() const {return quality; }

int player::getOvr() const {return ovr; }

//const std::string &player::getName() const {return name; }
//
//const std::string &player::getTeam() const {return team; }
//
//const std::string &player::getPos() const {return pos; }
//
//int player::getId() const {return id; }
//
//int player::getPac() const {return pac; }
//
//int player::getSho() const {return sho; }
//
//int player::getPas() const {return pas; }
//
//int player::getDri() const {return dri; }
//
//int player::getDef() const {return def; }
//
//int player::getPhy() const {return phy; }



