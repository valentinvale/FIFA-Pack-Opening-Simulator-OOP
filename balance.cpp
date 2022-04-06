
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

void balance::sellPlayer(std::vector<player> pulledPlayers, unsigned long long int i) {
    if(pulledPlayers[i].getQuality() == "Bronze") this->bal += 30 * pulledPlayers[i].getOvr();
    else if(pulledPlayers[i].getQuality() == "Silver") this->bal += 50 * pulledPlayers[i].getOvr();
    else this->bal += 100 * pulledPlayers[i].getOvr();
//        pulledPlayers.erase(pulledPlayers.begin()+i);
}

void balance::sellBadge(std::vector<badge> pulledBadges, unsigned long long int i) {
    if(pulledBadges[i].getQuality() == "Bronze") this->bal += 300;
    else if(pulledBadges[i].getQuality() == "Silver") this->bal += 500;
    else this->bal += 1000;
//        pulledBadges.erase(pulledBadges.begin()+i);
}

void balance::sellManager(std::vector<manager> pulledManagers, unsigned long long int i) {
    if(pulledManagers[i].getQuality() == "Bronze") this->bal += 400;
    else if(pulledManagers[i].getQuality() == "Silver") this->bal += 800;
    else this->bal += 1500;
//        pulledManagers.erase(pulledManagers.begin()+i);
}
