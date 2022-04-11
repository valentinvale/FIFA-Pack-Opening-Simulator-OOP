
#include "pack.h"

const std::vector<std::shared_ptr <player>> &pack::getPlayers() const {return players; }

const std::vector<badge> &pack::getBadges() const {return badges; }

const std::vector<manager> &pack::getManagers() const {return managers; }

pack::pack(int price_, int nrOfPlayers_, int nrOfBadges_, int nrOfManagers_, const std::vector<std::shared_ptr <player>> &players_, const std::vector<badge> &badges_,
           const std::vector<manager> &managers_) : price{price_}, nrOfPlayers{nrOfPlayers_}, nrOfBadges{nrOfBadges_} , nrOfManagers{nrOfManagers_}, players{players_},
                                                    badges{badges_}, managers{managers_} {

//        std::cout << "constructor de initializare pack\n";
}

std::ostream &operator<<(std::ostream &os, const pack &pack) {
    int cc = 1;
    //os << "price: " << pack.price << " nrOfItems: " << pack.nrOfItems << '\n';
    os << "players:\n";

    for (const auto & player : pack.players) {
        os << cc <<". "<< *player;
        os << '\n';
        cc++;
    }

    os << "badges:\n";
    for (const auto & badge : pack.badges) {
        os << cc << ". " << badge;
        os << '\n';
        cc++;
    }
    os << "managers:\n";
    for (const auto & manager : pack.managers) {
        os << cc << ". " << manager;
        os << '\n';
        cc++;
    }
    return os;
}

void pack::open(balance &blnc, std::vector<std::shared_ptr <player>> poolPl, std::vector<badge> poolBdg, std::vector<manager> poolMngr) {
    //daca ne ajung banii
    if(blnc.pay(price))
    {
        for (int i = 0; i < this->nrOfPlayers; ++i)
        {
            auto randomIt = Random::get(poolPl.begin(), poolPl.end());
            this->players.push_back(*randomIt);
        }

        for (int i = 0; i < this->nrOfBadges; ++i)
        {
            auto randomIt = Random::get(poolBdg.begin(), poolBdg.end());
            this->badges.push_back(*randomIt);
        }

        for (int i = 0; i < this->nrOfManagers; ++i)
        {
            auto randomIt = Random::get(poolMngr.begin(), poolMngr.end());
            this->managers.push_back(*randomIt);
        }
    }

        //daca nu ne ajung banii
    else std::cout << "Nu s-a putut deschide pachetul\n";

}

void pack::clearPack() {
    this->players.clear();
    this->managers.clear();
    this->badges.clear();
}

int pack::getPrice() const {
    return price;
}

int pack::getNrOfPlayers() const {
    return nrOfPlayers;
}

int pack::getNrOfBadges() const {
    return nrOfBadges;
}

int pack::getNrOfManagers() const {
    return nrOfManagers;
}

void pack::popPlayer(int i) {
    this->players.erase(this->players.begin()+i);
}

void pack::popBadge(int i) {
    this->badges.erase(this->badges.begin()+i);
}

void pack::popManager(int i) {
    this->managers.erase(this->managers.begin()+i);
}
