//
// Created by valus on 10.04.2022.
//

#include "outfieldplayer.h"

outfieldplayer::outfieldplayer(int id, const std::string &name, const std::string &team, const std::string &pos,
                               const std::string &quality, int ovr, int pac, int sho, int pas, int dri, int def,
                               int phy) : player(id, name, team, pos, quality, ovr), pac(pac), sho(sho), pas(pas),
                                          dri(dri), def(def), phy(phy) {}

std::ostream &operator<<(std::ostream &os, const outfieldplayer &outfieldplayer) {
    os << static_cast<const player &>(outfieldplayer) << " pac: " << outfieldplayer.pac << " sho: "
       << outfieldplayer.sho << " pas: " << outfieldplayer.pas << " dri: " << outfieldplayer.dri << " def: "
       << outfieldplayer.def << " phy: " << outfieldplayer.phy;
    return os;
}


