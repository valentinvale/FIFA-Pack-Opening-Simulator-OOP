#include <vector>
#include <string>
#include <iostream>

#include "player.h"
#include "badge.h"
#include "manager.h"

#ifndef OOP_BALANCE_H
#define OOP_BALANCE_H

class balance{
    int bal;

public:
    explicit balance(int bal);

    friend std::ostream &operator<<(std::ostream &os, const balance &balance);

    bool pay(int price);

    //Metoda pentru vindere de jucator, luam jucatorul de pe pozitia i din vectorul de jucatori obtinuti din pachet
    //la fel si pentru manageri si badge-uri
    void sellPlayer(const player& pulledPlayer);

    void sellBadge(const badge& pulledBadge);

    void sellManager(const manager& pulledManager);

};


#endif //OOP_BALANCE_H
