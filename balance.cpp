
#include "balance.h"

balance::balance(int bal) : bal(bal) {
//        std::cout << "constructor balance\n";
}

std::ostream &operator<<(std::ostream &os, const balance &balance) {
    os << "bal: " << balance.bal;
    return os;
}

bool balance::pay(int price) {
    if (price > bal) {std::cout << "Fonduri insuficiente\n"; return false;}
    else { this->bal = this->bal - price; return true;}
}

void balance::sellPlayer(const player& pulledPlayer) {
    if(pulledPlayer.getQuality() == "Bronze") this->bal += 30 * pulledPlayer.getOvr();
    else if(pulledPlayer.getQuality() == "Silver") this->bal += 50 * pulledPlayer.getOvr();
    else this->bal += 100 * pulledPlayer.getOvr();
//        pulledPlayers.erase(pulledPlayers.begin()+i);
}

void balance::sellBadge(const badge& pulledBadge) {
    if(pulledBadge.getQuality() == "Bronze") this->bal += 300;
    else if(pulledBadge.getQuality() == "Silver") this->bal += 500;
    else this->bal += 1000;
//        pulledBadges.erase(pulledBadges.begin()+i);
}

void balance::sellManager(const manager& pulledManager) {
    if(pulledManager.getQuality() == "Bronze") this->bal += 400;
    else if(pulledManager.getQuality() == "Silver") this->bal += 800;
    else this->bal += 1500;
//        pulledManagers.erase(pulledManagers.begin()+i);
}
