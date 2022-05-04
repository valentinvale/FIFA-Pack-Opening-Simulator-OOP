
#include "balance.h"

//balance::balance(int bal) : bal(bal) {
////        std::cout << "constructor balance\n";
//}

int balance::bal = 100000;

std::ostream &operator<<(std::ostream &os, const balance &balance) {
    os << balance.bal;
    return os;
}

bool balance::pay(int price) {
    if (price > bal) {std::cout << "Fonduri insuficiente\n"; return false;}
    else { this->bal = this->bal - price; return true;}
}

void balance::sellPlayer(std::shared_ptr<player> pulledPlayer) {
    if(pulledPlayer->getQuality() == "Bronze") balance::bal += 30 * pulledPlayer->getOvr();
    else if(pulledPlayer->getQuality() == "Silver") balance::bal += 50 * pulledPlayer->getOvr();
    else balance::bal += 100 * pulledPlayer->getOvr();
//        pulledPlayers.erase(pulledPlayers.begin()+i);
}

void balance::sellBadge(const badge& pulledBadge) {
    if(pulledBadge.getQuality() == "Bronze") balance::bal += 300;
    else if(pulledBadge.getQuality() == "Silver") balance::bal += 500;
    else balance::bal += 1000;
//        pulledBadges.erase(pulledBadges.begin()+i);
}

void balance::sellManager(const manager& pulledManager) {
    if(pulledManager.getQuality() == "Bronze") balance::bal += 400;
    else if(pulledManager.getQuality() == "Silver") balance::bal += 800;
    else balance::bal += 1500;
//        pulledManagers.erase(pulledManagers.begin()+i);
}
