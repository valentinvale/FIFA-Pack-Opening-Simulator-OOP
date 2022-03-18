// structura claselor
// functia de deschidere pachet
// functia de adaugat jucatori la colectie
// functia de vanzare jucatori
// v1.0
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "player.h"
#include "badge.h"
#include "manager.h"
#include "balance.h"
#include "pack.h"
#include "collection.h"

int main() {

std::ifstream fin("date.txt");
int nrOfPlayers = 16;
int nrOfBadges = 4;
int nrOfManagers = 4;
int id;
int ovr;
int pac;
int sho;
int pas;
int dri;
int def;
int phy;
std::string playerName, playerTeam, playerPosition, playerQuality, badgeQuality, managerQuality, badgeName, managerName, managerLeague;
std::vector<player> playersPool;
std::vector<badge> badgesPool;
std::vector<manager> managersPool;

    for (int i = 0; i < nrOfPlayers; ++i) {
        fin >> id >> playerName >> playerTeam >> playerPosition >> playerQuality >> ovr >> pac >> sho >> pas >> dri >> def >> phy;
        player pl{id, playerName, playerTeam, playerPosition, playerQuality, ovr, pac, sho, pas, dri, def, phy};
        playersPool.push_back(pl);
    }

    for (int i = 0; i < nrOfBadges; ++i) {
        fin >> id >> badgeName >> badgeQuality;
        badge bdg{id, badgeName, badgeQuality};
        badgesPool.push_back(bdg);
    }

    for (int i = 0; i < nrOfManagers; ++i) {
        fin >> id >> managerName >> managerQuality >> managerLeague;
        manager mngr{id, managerName, managerQuality, managerLeague};
        managersPool.push_back(mngr);
    }

std::vector<player> emptyPlayers;
std::vector<badge> emptyBadges;
std::vector<manager> emptyManagers;

collection col{emptyPlayers, emptyBadges, emptyManagers};
balance blnc{100000};
pack goldPack{1000, 7, emptyPlayers, emptyBadges, emptyManagers};
goldPack.open(blnc, playersPool, badgesPool, managersPool);
std::cout << "Ai mai ramas cu atatia bani: " << '\n';
std::cout << blnc << '\n';
std::cout << "Din pachet ai obtinut: " << '\n';
std::cout << goldPack << '\n';

if(!goldPack.getPlayers().empty())
{
    col.addPlayer(goldPack.getPlayers(), 0);
    if(goldPack.getPlayers().size()>=2) blnc.sellPlayer(goldPack.getPlayers(), 1); //daca avem cel putin 2 jucatori in pachet
                                                                                                // il vindem pe al doilea
}
if(!goldPack.getManager().empty())
{
    col.addManager(goldPack.getManager(), 0);
    if(goldPack.getManager().size()>=2) blnc.sellManager(goldPack.getManager(), 1); //daca avem cel putin 2 manageri in pack
                                                                                                    // il vindem pe al doilea
}
if(!goldPack.getBadges().empty())
{
    blnc.sellBadge(goldPack.getBadges(), 0);
    if(goldPack.getBadges().size()>=2) col.addBadge(goldPack.getBadges(), 1); //daca avem cel putin 2 badge-uri in pack
                                                                                            // il adaugam in colectie pe al doilea
}

std::cout << "Colectia ta dupa ce ai adaugat: \n";
std::cout << col << '\n';
std::cout << "Cati bani ai dupa ce ai vandut: \n";
std::cout << blnc << '\n';

    return 0;
}