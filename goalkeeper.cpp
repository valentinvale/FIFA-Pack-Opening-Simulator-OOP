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
    const auto& gk = *this;
    os <<" div: " << gk.div << " han: " << gk.han
       << " kic: " << gk.kic << " ref: " << gk.ref << " spe: " << gk.spe << " pos: "
       << gk.posi << '\n';
}

void goalkeeper::chemistryStyle() {
    this->div += 2;
    this->han += 2;

}

goalkeeper::~goalkeeper() {

}

std::shared_ptr<player> goalkeeper::clone() const {
    return std::make_shared <goalkeeper>(*this);
}

goalkeeper &goalkeeper::operator=(const goalkeeper &other) {
    name = other.name;
    team = other.team;
    pos = other.pos;
    quality = other.quality;
    id = other.id;
    ovr = other.ovr;
    han = other.han;
    kic = other.kic;
    div = other.div;
    ref = other.ref;
    spe = other.spe;
    posi = other.posi;

    return *this;
}

goalkeeper::goalkeeper(const goalkeeper &other) : player{other}, div{other.div}, han{other.han}, kic{other.kic},
ref{other.ref}, spe{other.spe}, posi{other.posi} {}

