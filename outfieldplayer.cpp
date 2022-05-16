//
// Created by valus on 10.04.2022.
//

#include "outfieldplayer.h"

outfieldplayer::outfieldplayer(int id, const std::string &name, const std::string &team, const std::string &pos,
                               const std::string &quality, int ovr, int pac, int sho, int pas, int dri, int def,
                               int phy) : player(id, name, team, pos, quality, ovr), pac(pac), sho(sho), pas(pas),
                                          dri(dri), def(def), phy(phy) {

    if(pac < 0 || sho < 0 || pas < 0 || dri < 0 || def < 0 || phy < 0) throw invalidStat("Stat invalid");
}

std::ostream &operator<<(std::ostream &os, const outfieldplayer &outfieldplayer) {
    outfieldplayer.afis(os);
    return os;
}

void outfieldplayer::afis(std::ostream &os) const {
    player::afis(os);
    const auto& opl = *this;
    os << " pac: " << opl.pac << " sho: "
       << opl.sho << " pas: " << opl.pas << " dri: " << opl.dri << " def: "
       << opl.def << " phy: " << opl.phy << '\n';
}

void outfieldplayer::chemistryStyle() {
    this->pas += 2;
    this->sho += 2;
}

outfieldplayer::~outfieldplayer() {

}

std::shared_ptr<player> outfieldplayer::clone() const {
    return std::make_shared <outfieldplayer>(*this);
}

outfieldplayer &outfieldplayer::operator=(const outfieldplayer &other) {
    name = other.name;
    team = other.team;
    pos = other.pos;
    quality = other.quality;
    id = other.id;
    ovr = other.ovr;
    pac = other.pac;
    sho = other.sho;
    dri = other.dri;
    pas = other.pas;
    def = other.def;
    phy = other.phy;

    return *this;
}

outfieldplayer::outfieldplayer(const outfieldplayer &other) : player{other}, pac{other.pac},
sho{other.sho}, pas{other.pas}, dri{other.dri}, def{other.def}, phy{other.phy} {}


