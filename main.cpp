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
#include "goalkeeper.h"
#include "outfieldplayer.h"

int main() {

std::ifstream fin("date.txt");
int nrOfPlayers = 16;
int nrOfBadges = 4;
int nrOfManagers = 4;
int nrP, nrB, nrM;
int id, ovr, pac, sho, pas, dri, def, phy, div, han, kic, ref, spe, posi;

std::string playerName, playerTeam, playerPosition, playerQuality, badgeQuality, managerQuality, badgeName, managerName, managerLeague;
std::vector<std::shared_ptr<player>> playersPool;
std::vector<badge> badgesPool;
std::vector<manager> managersPool;

    for (int i = 0; i < nrOfPlayers; ++i) {
        fin >> id >> playerName >> playerTeam >> playerPosition >> playerQuality >> ovr;
        if (playerPosition == "GK")
        {
            fin >> div >> han >> kic >> ref >> spe >> posi;
            goalkeeper gkp{id, playerName, playerTeam, playerPosition, playerQuality, ovr, div, han, kic, ref, spe, posi};
            playersPool.push_back(std::make_shared<goalkeeper>(gkp));
        }
        else
        {
            fin >> pac >> sho >> pas >> dri >> def >> phy;
            outfieldplayer ofp{id, playerName, playerTeam, playerPosition, playerQuality, ovr, pac, sho, pas, dri, def, phy};
            playersPool.push_back(std::make_shared<outfieldplayer>(ofp));
        }

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

std::vector<std::shared_ptr<player>> emptyPlayers;
std::vector<badge> emptyBadges;
std::vector<manager> emptyManagers;

collection col{emptyPlayers, emptyBadges, emptyManagers};
balance blnc{100000};
//pack goldPack{1000, 7, emptyPlayers, emptyBadges, emptyManagers};
//goldPack.open(blnc, playersPool, badgesPool, managersPool);
//std::cout << "Ai mai ramas cu atatia bani: " << '\n';
//std::cout << blnc << '\n';
//std::cout << "Din pachet ai obtinut: " << '\n';
//std::cout << goldPack << '\n';
//
//if(!goldPack.getPlayers().empty())
//{
//    col.addPlayer(goldPack.getPlayers()[0]); //aici cred ca trebuie make_shared
//    if(goldPack.getPlayers().size()>=2) blnc.sellPlayer( goldPack.getPlayers()[1]); //daca avem cel putin 2 jucatori in pachet
//                                                                                                // il vindem pe al doilea
//}
//if(!goldPack.getManager().empty())
//{
//    col.addManager(goldPack.getManager()[0]);
//    if(goldPack.getManager().size()>=2) blnc.sellManager(goldPack.getManager()[1]); //daca avem cel putin 2 manageri in pack
//                                                                                                    // il vindem pe al doilea
//}
//if(!goldPack.getBadges().empty())
//{
//    blnc.sellBadge(goldPack.getBadges()[0]);
//    if(goldPack.getBadges().size()>=2) col.addBadge(goldPack.getBadges()[1]); //daca avem cel putin 2 badge-uri in pack
//                                                                                            // il adaugam in colectie pe al doilea
//}
//
//std::cout << "Colectia ta dupa ce ai adaugat: \n";
//std::cout << col << '\n';
//std::cout << "Cati bani ai dupa ce ai vandut: \n";
//std::cout << blnc << '\n';

    int input, inputSellAddAll, nrOrdine, decizie;
    pack goldPack{1000, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};
do
{
    system("cls");
    std::cout << "Balance: " << blnc << '\n' << '\n';
    std::cout << "Apasa tasta corespunzatoare pentru a dschide pachetul dorit" << '\n' << '\n';
    std::cout << "Apasa tasta 9 pentru a vedea colectia" << '\n' << '\n';
    std::cout << "Apasa tasta 0 pentru a iesi" << '\n' << '\n';
    std::cout << "1. Gold Pack - 5 jucatori, 1 badge si 1 manager - pret: " << goldPack.getPrice() << '\n' << '\n';
    std::cin >> input;

    if (input == 9)
    {
        std::cout << col << '\n';
        system("pause");
    }
    else if (input == 1)
    {
        system("cls");
        goldPack.open(blnc, playersPool, badgesPool, managersPool);
        nrP = goldPack.getNrOfPlayers();
        nrB = goldPack.getNrOfBadges();
        nrM = goldPack.getNrOfManagers();
        std::cout << "Ai mai ramas cu atatia bani: " << '\n';
        std::cout << blnc << '\n' << '\n';
        std::cout << "Din pachet ai obtinut: " << '\n';

        do {
            system("cls");
            std::cout << goldPack << '\n' << '\n';
            std::cout << "Apasa tasta 1 pentru a vinde toate itemele" << '\n' << '\n';
            std::cout << "Apasa tasta 2 pentru a adauga toate itemele la colectie" << '\n' << '\n';
            std::cout
                    << "Apasa tasta 3, introdu numarul de ordine al item-ului si cifra 1 sau 2 pentru a-l vinde, respectiv a-l adauga la colectie"
                    << '\n' << '\n';
            std::cin >> inputSellAddAll;
            if (inputSellAddAll == 1)
            {
                for (unsigned long long i = 0; i < goldPack.getPlayers().size(); ++i) {
                    blnc.sellPlayer(goldPack.getPlayers()[i]);
                }

                for (unsigned long long i = 0; i < goldPack.getBadges().size(); ++i) {
                    blnc.sellBadge(goldPack.getBadges()[i]);
                }

                for (unsigned long long i = 0; i < goldPack.getManagers().size(); ++i) {
                    blnc.sellManager(goldPack.getManagers()[i]);
                }

                goldPack.clearPack();

            }
            else if (inputSellAddAll == 2) {
                for (unsigned long long i = 0; i < goldPack.getPlayers().size(); ++i) {
                    col.addPlayer(goldPack.getPlayers()[i]);
                }

                for (unsigned long long i = 0; i < goldPack.getBadges().size(); ++i) {
                    col.addBadge(goldPack.getBadges()[i]);
                }

                for (unsigned long long i = 0; i < goldPack.getManagers().size(); ++i) {
                    col.addManager(goldPack.getManagers()[i]);
                }

                goldPack.clearPack();

            }
            else if (inputSellAddAll == 3)
            {
                std::cin >> nrOrdine >> decizie;
                if (decizie == 1)
                {
                    if (nrOrdine >= 1 && nrOrdine <= nrP)
                    {
                        blnc.sellPlayer(goldPack.getPlayers()[nrOrdine - 1]);
                        goldPack.popPlayer(nrOrdine - 1);
                        nrP--;
                    }
                    else if (nrOrdine > nrP && nrOrdine <= nrP + nrB)
                    {
                        blnc.sellBadge(goldPack.getBadges()[nrOrdine - nrP - 1]);
                        goldPack.popBadge(nrOrdine - nrP - 1);
                        nrB--;
                    }
                    else if (nrOrdine > nrP + nrB &&
                               nrOrdine <= nrP + nrB + nrM)
                    {
                        blnc.sellManager(goldPack.getManagers()[nrOrdine - nrP - nrB-1]);
                        goldPack.popManager(nrOrdine - nrP - nrB - 1);
                        nrM--;
                    }
                }
                else if ( decizie == 2)
                {
                    if (nrOrdine >= 1 && nrOrdine <= nrP)
                    {
                        col.addPlayer(goldPack.getPlayers()[nrOrdine - 1]);
                        goldPack.popPlayer(nrOrdine - 1);
                        nrP--;
                    }
                    else if (nrOrdine > nrP && nrOrdine <= nrP + nrB)
                    {
                        col.addBadge(goldPack.getBadges()[nrOrdine - nrP - 1]);
                        goldPack.popBadge(nrOrdine - nrP- 1);
                        nrB--;
                    }
                    else if (nrOrdine > nrP + nrB && nrOrdine <= nrP + nrB + nrM)
                    {
                        col.addManager(goldPack.getManagers()[nrOrdine - nrP - nrB -1]);
                        goldPack.popManager(nrOrdine - nrP - nrB - 1);
                        nrM--;
                    }
                }
            }
        }while(!goldPack.getPlayers().empty() || !goldPack.getBadges().empty() || !goldPack.getManagers().empty());
        system("pause");
    }

}while(input != 0);

    return 0;
}