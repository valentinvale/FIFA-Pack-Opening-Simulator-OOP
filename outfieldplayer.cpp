//
// Created by valus on 10.04.2022.
//

#include "outfieldplayer.h"

outfieldplayer::outfieldplayer(int id, const std::string &name, const std::string &team, const std::string &pos,
                               const std::string &quality, int ovr, int pac, int sho, int pas, int dri, int def,
                               int phy) : player(id, name, team, pos, quality, ovr), pac(pac), sho(sho), pas(pas),
                                          dri(dri), def(def), phy(phy) {}

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


