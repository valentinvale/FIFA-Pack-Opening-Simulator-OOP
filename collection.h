#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <memory>

#include "player.h"
#include "badge.h"
#include "manager.h"
#include "balance.h"

#ifndef OOP_COLLECTION_H
#define OOP_COLLECTION_H


class collection{
    std::vector<std::shared_ptr <player>> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
    collection(const std::vector<std::shared_ptr <player>>& players_, const std::vector<badge>& badges_,
               const std::vector<manager>& managers_);


    friend std::ostream& operator<<(std::ostream& os, const collection& collection);

    //metode pentru adaugat la colectie
    void addPlayer(std::shared_ptr<player> pulledPlayer);

    void addBadge(const badge& pulledBadge);

    void addManager(const manager& pulledManager);

};


#endif //OOP_COLLECTION_H
