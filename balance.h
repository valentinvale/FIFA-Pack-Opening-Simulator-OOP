#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <utility>

#include "player.h"
#include "badge.h"
#include "manager.h"

#ifndef OOP_BALANCE_H
#define OOP_BALANCE_H

class balance{
    static int bal;

public:
    //explicit balance(int bal);

    friend std::ostream &operator<<(std::ostream &os, const balance &balance);

    bool pay(int price);

    //Metoda pentru a vinde jucator, luam jucatorul de pe pozitia i din vectorul de jucatori obtinuti din pachet
    //la fel si pentru manageri si badge-uri
    static void sellPlayer(std::shared_ptr<player> pulledPlayer);

    static void sellBadge(const badge& pulledBadge);

    static void sellManager(const manager& pulledManager);

};


#endif //OOP_BALANCE_H
