
#include "pack.h"

const std::vector<std::shared_ptr <player>> &pack::getPlayers() const {return players; }

const std::vector<badge> &pack::getBadges() const {return badges; }

const std::vector<manager> &pack::getManager() const {return managers; }

pack::pack(int price_, int nrOfItems_, const std::vector<std::shared_ptr <player>> &players_, const std::vector<badge> &badges_,
           const std::vector<manager> &managers_) : price{price_}, nrOfItems{nrOfItems_}, players{players_},
                                                    badges{badges_}, managers{managers_} {

//        std::cout << "constructor de initializare pack\n";
}

std::ostream &operator<<(std::ostream &os, const pack &pack) {
    os << "price: " << pack.price << " nrOfItems: " << pack.nrOfItems << '\n';
    os << "players:\n";

    for (const auto & player : pack.players) {
        os << player;
        os << '\n';
    }

    os << "badges:\n";
    for (const auto & badge : pack.badges) {
        os << badge;
        os << '\n';
    }
    os << "managers:\n";
    for (const auto & manager : pack.managers) {
        os << manager;
        os << '\n';
    }
    return os;
}

void pack::open(balance &blnc, std::vector<std::shared_ptr <player>> poolPl, std::vector<badge> poolBdg, std::vector<manager> poolMngr) {
    //daca ne ajung banii
    if(blnc.pay(price))
    {
        for (int i = 0; i < this->nrOfItems; ++i)
        {
            auto val = Random::get(0, 23);
            if(val >= 0 && val <= 15) this->players.push_back(poolPl[val]);
            else if(val > 15 and val <= 19) this->badges.push_back(poolBdg[val%4]);
            else this->managers.push_back(poolMngr[val%4]);

        }
    }

        //daca nu ne ajung banii
    else std::cout << "Nu s-a putut deschide pachetul\n";

}
