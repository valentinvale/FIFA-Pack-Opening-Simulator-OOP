//
// Created by valus on 18.03.2022.
//

#include "collection.h"

collection::collection(const std::vector<player> &players_, const std::vector<badge> &badges_,
                       const std::vector<manager> &managers_) : players{players_}, badges{badges_}, managers{managers_} {

//        std::cout << "constructor de initializare collection\n";
}

std::ostream &operator<<(std::ostream &os, const collection &collection) {
    os << "players:\n";

    for (const auto & player : collection.players) {
        os << player;
        os << '\n';
    }

    os << "badges:\n";
    for (const auto & badge : collection.badges) {
        os << badge;
        os << '\n';
    }
    os << "managers:\n";
    for (const auto & manager : collection.managers) {
        os << manager;
        os << '\n';
    }
    return os;
}

void collection::addPlayer(std::vector<player> pulledPlayers, unsigned long long int i) {
    this->players.push_back(pulledPlayers[i]);
//        pulledPlayers.erase(pulledPlayers.begin()+i);
}

void collection::addBadge(std::vector<badge> pulledBadges, unsigned long long int i) {
    this->badges.push_back(pulledBadges[i]);
//        pulledBadges.erase(pulledBadges.begin()+i);
}

void collection::addManager(std::vector<manager> pulledManagers, unsigned long long int i) {
    this->managers.push_back(pulledManagers[i]);
//        pulledManagers.erase(pulledManagers.begin()+i);
}
