//
// Created by valus on 10.04.2022.
//

#include "goalkeeper.h"

goalkeeper::goalkeeper(int id, const std::string &name, const std::string &team, const std::string &pos,
                       const std::string &quality, int ovr, int div, int han, int kic, int ref, int spe, int posi)
        : player(id, name, team, pos, quality, ovr), div(div), han(han), kic(kic), ref(ref), spe(spe), posi(posi) {}

std::ostream &operator<<(std::ostream &os, const goalkeeper &goalkeeper) {
    goalkeeper.afis(os);
    return os;
}

void goalkeeper::afis(std::ostream &os) const {
    player::afis(os);
    os <<" div: " << this->div << " han: " << this->han
       << " kic: " << this->kic << " ref: " << this->ref << " spe: " << this->spe << " posi: "
       << this->posi << '\n';
}
