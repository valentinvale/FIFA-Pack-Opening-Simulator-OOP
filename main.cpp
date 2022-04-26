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
#include "rlutil.h"
#include "error.h"

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

    player* b = new outfieldplayer(0, "baza", "baza", "ST", "Gold", 0, 0, 0, 0, 0, 0, 0);
    try
    {
        [[maybe_unused]]auto& der1 = dynamic_cast<outfieldplayer&>(*b);
    }
    catch (std::bad_cast& err)
    {
        std::cout << err.what() << '\n';
    }

    auto* der2 = dynamic_cast<goalkeeper*>(b);
    if(der2 != nullptr)
    {
        der2->chemistryStyle();
    }
    else
    {
        std::cout << "Nu a reusit conversia cu pointer\n";
    }
    delete b;

    for (int i = 0; i < nrOfPlayers; ++i) {
        try
        {
            fin >> id >> playerName >> playerTeam >> playerPosition >> playerQuality >> ovr;
            if(id < 0) throw (invalidId{"Invalid id"});
        }
        catch(std::exception& err)
        {
            std::cout << err.what() << '\n';
        }
        if (playerPosition == "GK")
        {
            fin >> div >> han >> kic >> ref >> spe >> posi;
            try
            {   if(ovr < 0 || div < 0 || han < 0 || kic < 0 || ref < 0 || spe < 0 || posi < 0) throw (invalidStat{"Invalid stat"});
                else
                {
                    goalkeeper gkp{id, playerName, playerTeam, playerPosition,playerQuality, ovr, div, han, kic, ref,spe, posi};
                    playersPool.push_back(gkp.clone());
                }
            }
            catch(std::exception& err)
            {
                std::cout << err.what() << '\n';
            }
        }
        else
        {
            fin >> pac >> sho >> pas >> dri >> def >> phy;
            try
            {
                if(ovr < 0 || pac < 0 || sho < 0 || pas < 0 || dri < 0 || def < 0 || phy < 0) throw (invalidStat{"Invalid stat"});
                else
                {
                    outfieldplayer ofp{id, playerName, playerTeam, playerPosition, playerQuality, ovr, pac, sho, pas, dri, def, phy};
                    playersPool.push_back(ofp.clone());
                }
            }
            catch(std::exception& err)
            {
                std::cout << err.what() << '\n';
            }
        }

    }

    for (int i = 0; i < nrOfBadges; ++i) {
        fin >> id >> badgeName >> badgeQuality;
        try
        {
            if(id < 0) throw (invalidId{"Id invalid"});
            else
            {
                badge bdg{id, badgeName, badgeQuality};
                badgesPool.push_back(bdg);
            }
        }
        catch(std::exception& err)
        {
            std::cout << err.what() << '\n';
        }
    }

    for (int i = 0; i < nrOfManagers; ++i) {
        fin >> id >> managerName >> managerQuality >> managerLeague;
        try
        {
            if(id < 0) throw (invalidId{"Id invalid"});
            else
            {
                manager mngr{id, managerName, managerQuality, managerLeague};
                managersPool.push_back(mngr);
            }
        }
        catch(std::exception& err)
        {
            std::cout << err.what() << '\n';
        }
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

    int input, inputSellAddAll, nrOrdine, decizie, inpCol;
    pack goldPack{1000, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};

    do
    {
        //system("cls");
        //rlutil::cls();
        std::cout << "Balance: " << blnc << '\n' << '\n';
        std::cout << "Apasa tasta corespunzatoare pentru a dschide pachetul dorit" << '\n' << '\n';
        std::cout << "Apasa tasta 9 pentru a vedea colectia" << '\n' << '\n';
        std::cout << "Apasa tasta 0 pentru a iesi" << '\n' << '\n';
        std::cout << "1. Gold Pack - 5 jucatori, 1 badge si 1 manager - pret: " << goldPack.getPrice() << '\n' << '\n';
        std::cin >> input;

        if (input == 9)
        {
            do
            {
                rlutil::cls();
                std::cout << col << '\n';
                std::cout << '\n';
                //system("pause");
                //std::cout << '\n' <<"Press any key to continue" <<'\n';
                //rlutil::anykey();
                std::cout << "Apasa tasta 3, introdu numarul de ordine al item-ului si cifra 1 sau 2 pentru a-l vinde, respectiv a-i aplica un boost in schimbul a 1000 de coins\n" << '\n';
                std::cout << "Apasa tasta 9 pentru a reveni la meniul principal\n" << '\n';
                std::cin >> inpCol;

                if(inpCol == 3)
                {
                    std::cin >> nrOrdine >> decizie;
                    int nrPCol = col.getPlayers().size();
                    int nrBCol = col.getBadges().size();
                    int nrMCol = col.getManagers().size();
                    if(decizie == 1)
                    {
                        if (nrOrdine >= 1 && nrOrdine <= nrPCol)
                        {
                            blnc.sellPlayer(col.getPlayers()[nrOrdine - 1]);
                            col.popPlayer(nrOrdine - 1);
                            nrPCol--;
                        }
                        else if (nrOrdine > nrPCol && nrOrdine <= nrPCol + nrBCol)
                        {
                            blnc.sellBadge(col.getBadges()[nrOrdine - nrPCol - 1]);
                            col.popBadge(nrOrdine - nrPCol - 1);
                            nrBCol--;
                        }
                        else if (nrOrdine > nrPCol + nrBCol &&
                                 nrOrdine <= nrPCol + nrBCol + nrMCol)
                        {
                            blnc.sellManager(col.getManagers()[nrOrdine - nrPCol - nrBCol-1]);
                            col.popManager(nrOrdine - nrPCol - nrBCol - 1);
                            nrMCol--;
                        }
                    }
                    else if(decizie == 2)
                    {
                        if (nrOrdine >= 1 && nrOrdine <= nrPCol)
                        {
                            if(blnc.pay(1000))
                                col.getPlayers()[nrOrdine - 1]->chemistryStyle();
                            else
                                std::cout << "Nu s-a putut aplica boost-ul\n";
                        }
                        else
                        {
                            std::cout << "Nu se poate aplica boost unui manager/badge\n";
                        }
                    }
                }
            }while(inpCol != 9);
            rlutil::anykey();



        }
        else if (input == 1)
        {
            //system("cls");
            rlutil::cls();
            goldPack.open(blnc, playersPool, badgesPool, managersPool);
            nrP = goldPack.getNrOfPlayers();
            nrB = goldPack.getNrOfBadges();
            nrM = goldPack.getNrOfManagers();
            std::cout << "Ai mai ramas cu atatia bani: " << '\n';
            std::cout << blnc << '\n' << '\n';
            std::cout << "Din pachet ai obtinut: " << '\n';

            do {
                //system("cls");
                rlutil::cls();
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
            //system("pause");
            //std::cout << '\n' <<"Press any key to continue" <<'\n';
            rlutil::anykey();
        }

    }while(input != 0);



        return 0;
}