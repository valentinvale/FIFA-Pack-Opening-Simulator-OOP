#include <vector>
#include <string>
#include <iostream>

#include "player.h"
#include "badge.h"
#include "manager.h"
#include "balance.h"

#ifndef OOP_COLLECTION_H
#define OOP_COLLECTION_H


class collection{
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
    collection(const std::vector<player>& players_, const std::vector<badge>& badges_,
               const std::vector<manager>& managers_);


    friend std::ostream& operator<<(std::ostream& os, const collection& collection);

    //metode pentru adaugat la colectie
    void addPlayer(std::vector<player> pulledPlayers, unsigned long long i);

    void addBadge(std::vector<badge> pulledBadges, unsigned long long i);

    void addManager(std::vector<manager> pulledManagers, unsigned long long i);

};


#endif //OOP_COLLECTION_H
