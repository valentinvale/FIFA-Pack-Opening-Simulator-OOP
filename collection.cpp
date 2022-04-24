//
// Created by valus on 18.03.2022.
//

#include "collection.h"

collection::collection(const std::vector<std::shared_ptr <player>> &players_, const std::vector<badge> &badges_,
                       const std::vector<manager> &managers_) : players{players_}, badges{badges_}, managers{managers_} {

//        std::cout << "constructor de initializare collection\n";
}

std::ostream &operator<<(std::ostream &os, const collection &collection) {
    int cc = 1;
    os << "players:\n";

    for (const auto & player : collection.players) {
        os << cc <<". " << *player;
        os << '\n';
        cc++;
    }

    os << "badges:\n";
    for (const auto & badge : collection.badges) {
        os << cc << ". " << badge;
        os << '\n';
        cc++;
    }
    os << "managers:\n";
    for (const auto & manager : collection.managers) {
        os << cc << ". " << manager;
        os << '\n';
        cc++;
    }
    return os;
}

void collection::addPlayer(std::shared_ptr<player> pulledPlayer) {
    this->players.push_back(pulledPlayer);
//        pulledPlayers.erase(pulledPlayers.begin()+i);
}

void collection::addBadge(const badge& pulledBadge) {
    this->badges.push_back(pulledBadge);
//        pulledBadges.erase(pulledBadges.begin()+i);
}

void collection::addManager(const manager& pulledManager) {
    this->managers.push_back(pulledManager);
//        pulledManagers.erase(pulledManagers.begin()+i);
}

const std::vector<std::shared_ptr<player>> &collection::getPlayers() const {
    return players;
}

const std::vector<badge> &collection::getBadges() const {
    return badges;
}

const std::vector<manager> &collection::getManagers() const {
    return managers;
}

void collection::popPlayer(int i) {
    this->players.erase(this->players.begin()+i);
}

void collection::popBadge(int i) {
    this->badges.erase(this->badges.begin()+i);
}

void collection::popManager(int i) {
    this->managers.erase(this->managers.begin()+i);
}


