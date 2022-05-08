// structura claselor
// functia de deschidere pachet
// functia de adaugat jucatori la colectie
// functia de vanzare jucatori
// v1.0
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

    std::string line;
    std::string word;

    std::ifstream fin("date.txt");
    int nrOfPlayers = 19239;
    int nrOfBadges = 4;
    int nrOfManagers = 4;
    int nrP, nrB, nrM;
    int id, pac, sho, pas, dri, def, phy, div, han, kic, ref, spe, posi;

    std::string playerName, playerTeam, playerPosition, playerQuality, badgeQuality, managerQuality, badgeName, managerName, managerLeague;
    std::vector<std::shared_ptr<player>> playersPool, playersPoolGold;
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
        int ovr = 0;
        std::getline(fin, line);

        std::stringstream str(line);

        std::getline(str, word, ',');
        id = std::stoi(word);
        std::getline(str, word, ',');
        playerName = word;
        std::getline(str, word, ',');
        playerTeam = word;
        std::getline(str, word, ',');
        playerPosition = word;
        std::getline(str, word, ',');
        playerQuality = word;
        std::getline(str, word, ',');
        ovr = std::stoi(word);
        try
        {
            //fin >> id >> playerName >> playerTeam >> playerPosition >> playerQuality >> ovr;
            if(id < 0) throw (invalidId{"Invalid id"});
        }
        catch(std::exception& err)
        {
            std::cout << err.what() << '\n';
        }
        if (playerPosition == "GK")
        {
            std::getline(str, word, ',');
            div = std::stoi(word);
            std::getline(str, word, ',');
            han = std::stoi(word);
            std::getline(str, word, ',');
            kic = std::stoi(word);
            std::getline(str, word, ',');
            ref = std::stoi(word);
            std::getline(str, word, ',');
            spe = std::stoi(word);
            std::getline(str, word, ',');
            posi = std::stoi(word);

            //fin >> div >> han >> kic >> ref >> spe >> posi;
            try
            {   if(ovr < 0 || div < 0 || han < 0 || kic < 0 || ref < 0 || spe < 0 || posi < 0) throw (invalidStat{"Invalid stat"});
                else
                {
                    goalkeeper gkp{id, playerName, playerTeam, playerPosition,playerQuality, ovr, div, han, kic, ref,spe, posi};
                    if(playerQuality == "Gold")
                        playersPoolGold.push_back(gkp.clone());
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
            std::getline(str, word, ',');
            pac = std::stoi(word);
            std::getline(str, word, ',');
            sho = std::stoi(word);
            std::getline(str, word, ',');
            pas = std::stoi(word);
            std::getline(str, word, ',');
            dri = std::stoi(word);
            std::getline(str, word, ',');
            def = std::stoi(word);
            std::getline(str, word, ',');
            phy = std::stoi(word);

            //fin >> pac >> sho >> pas >> dri >> def >> phy;
            try
            {
                if(ovr < 0 || pac < 0 || sho < 0 || pas < 0 || dri < 0 || def < 0 || phy < 0) throw (invalidStat{"Invalid stat"});
                else
                {
                    outfieldplayer ofp{id, playerName, playerTeam, playerPosition, playerQuality, ovr, pac, sho, pas, dri, def, phy};
                    if(playerQuality == "Gold")
                        playersPoolGold.push_back(ofp.clone());
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
        std::getline(fin, line);

        std::stringstream str(line);

        std::getline(str, word, ',');
        id = std::stoi(word);
        std::getline(str, word, ',');
        badgeName = word;
        std::getline(str, word, ',');
        badgeQuality = word;

        //fin >> id >> badgeName >> badgeQuality;
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
        std::getline(fin, line);

        std::stringstream str(line);

        std::getline(str, word, ',');
        id = std::stoi(word);
        std::getline(str, word, ',');
        managerName = word;
        std::getline(str, word, ',');
        managerQuality = word;
        std::getline(str, word, ',');
        managerLeague = word;

        //fin >> id >> managerName >> managerQuality >> managerLeague;
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

    fin.close();

    std::vector<std::shared_ptr<player>> emptyPlayers;
    std::vector<badge> emptyBadges;
    std::vector<manager> emptyManagers;

    collection col{emptyPlayers, emptyBadges, emptyManagers};
    balance blnc;

    std::string input=" ", nrOrdine=" ", decizie=" ", inpCol=" ";
    std::string inputSellAddAll=" ";
    pack goldPack{7500, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};

    do
    {
        //system("cls");
        rlutil::cls();
        std::cout << "Balance: " << blnc << '\n' << '\n';
        std::cout << "Apasa tasta corespunzatoare pentru a dschide pachetul dorit" << '\n' << '\n';
        std::cout << "Apasa tasta 9 pentru a vedea colectia" << '\n' << '\n';
        std::cout << "Apasa tasta 0 pentru a iesi" << '\n' << '\n';
        std::cout << "1. Gold Pack - 5 jucatori de calitate Gold, 1 badge si 1 manager - pret: " << goldPack.getPrice() << '\n' << '\n';
        std::cin >> input;

        try
        {
            if (input == "9") {
                do {
                    rlutil::cls();
                    std::cout << col << '\n';
                    std::cout << '\n';
                    //system("pause");
                    //std::cout << '\n' <<"Press any key to continue" <<'\n';
                    //rlutil::anykey();
                    std::cout
                            << "Apasa tasta 3, introdu numarul de ordine al item-ului si cifra 1 sau 2 pentru a-l vinde, respectiv a-i aplica un boost in schimbul a 1000 de coins\n"
                            << '\n';
                    std::cout << "Apasa tasta 9 pentru a reveni la meniul principal\n" << '\n';
                    std::cin >> inpCol;

                    try
                    {
                        if (inpCol == "3") {
                            std::cin >> nrOrdine >> decizie;
                            int nrPCol = col.getPlayers().size();
                            int nrBCol = col.getBadges().size();
                            int nrMCol = col.getManagers().size();
                            try {
                                if (decizie == "1") {
                                    try {
                                        if (atoi(nrOrdine.c_str()) > nrPCol + nrMCol + nrBCol || atoi(nrOrdine.c_str()) <= 0)
                                            throw (invalidInput{"Numar de ordine invalid"});
                                        else if (atoi(nrOrdine.c_str()) <= nrPCol) {
                                            balance::sellPlayer(col.getPlayers()[atoi(nrOrdine.c_str()) - 1]);
                                            col.popPlayer(atoi(nrOrdine.c_str()) - 1);
                                            nrPCol--;
                                        } else if (atoi(nrOrdine.c_str()) <= nrPCol + nrBCol) {
                                            balance::sellBadge(col.getBadges()[atoi(nrOrdine.c_str()) - nrPCol - 1]);
                                            col.popBadge(atoi(nrOrdine.c_str()) - nrPCol - 1);
                                            nrBCol--;
                                        } else if (atoi(nrOrdine.c_str()) <= nrPCol + nrBCol + nrMCol) {
                                            balance::sellManager(col.getManagers()[atoi(nrOrdine.c_str()) - nrPCol - nrBCol - 1]);
                                            col.popManager(atoi(nrOrdine.c_str()) - nrPCol - nrBCol - 1);
                                            nrMCol--;
                                        }
                                    }
                                    catch (std::exception &err) {
                                        std::cout << err.what() << '\n';
                                        rlutil::anykey();
                                    }
                                } else if (decizie == "2") {
                                    try {
                                        if (atoi(nrOrdine.c_str()) > nrPCol || atoi(nrOrdine.c_str()) <= 0)
                                            throw (invalidInput{"Numar de ordine invalid"});
                                        else if (atoi(nrOrdine.c_str()) <= nrPCol) {
                                            if (blnc.pay(1000))
                                                col.getPlayers()[atoi(nrOrdine.c_str()) - 1]->chemistryStyle();
                                            else
                                                std::cout << "Nu s-a putut aplica boost-ul\n";
                                        } else {
                                            std::cout << "Nu se poate aplica boost unui manager/badge\n";
                                        }
                                    }
                                    catch (std::exception &err) {
                                        std::cout << err.what() << '\n';
                                        rlutil::anykey();
                                    }
                                } else {
                                    throw (invalidInput{"Input invalid"});
                                }
                            }
                            catch (std::exception &err) {
                                std::cout << err.what() << '\n';
                                rlutil::anykey();
                            }
                        }
                        else
                        {
                            if (inpCol != "9") throw (invalidInput{"Input invalid"});
                        }
                    }
                    catch (std::exception &err) {
                        std::cout << err.what() << '\n';
                        rlutil::anykey();
                    }
                } while (inpCol != "9");
                rlutil::anykey();


            } else if (input == "1") {
                //system("cls");
                rlutil::cls();
                goldPack.open(blnc, playersPoolGold, badgesPool, managersPool);
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
                    try {
                        if (inputSellAddAll == "1") {
                            for (unsigned long long i = 0; i < goldPack.getPlayers().size(); ++i) {
                                balance::sellPlayer(goldPack.getPlayers()[i]);
                            }

                            for (unsigned long long i = 0; i < goldPack.getBadges().size(); ++i) {
                                balance::sellBadge(goldPack.getBadges()[i]);
                            }

                            for (unsigned long long i = 0; i < goldPack.getManagers().size(); ++i) {
                                balance::sellManager(goldPack.getManagers()[i]);
                            }

                            goldPack.clearPack();

                        } else if (inputSellAddAll == "2") {
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

                        } else if (inputSellAddAll == "3") {
                            std::cin >> nrOrdine >> decizie;
                            try {
                                if (decizie == "1") {
                                    try
                                    {
                                        if(atoi(nrOrdine.c_str()) > nrP + nrB + nrM || atoi(nrOrdine.c_str()) <= 0) throw (invalidInput{"Numar de ordine invalid"});
                                        else
                                            if (atoi(nrOrdine.c_str()) <= nrP) {
                                                balance::sellPlayer(goldPack.getPlayers()[atoi(nrOrdine.c_str()) - 1]);
                                                goldPack.popPlayer(atoi(nrOrdine.c_str()) - 1);
                                                nrP--;
                                            } else if (atoi(nrOrdine.c_str()) <= nrP + nrB) {
                                                balance::sellBadge(goldPack.getBadges()[atoi(nrOrdine.c_str()) - nrP - 1]);
                                                goldPack.popBadge(atoi(nrOrdine.c_str()) - nrP - 1);
                                                nrB--;
                                            } else if (atoi(nrOrdine.c_str()) <= nrP + nrB + nrM) {
                                                balance::sellManager(goldPack.getManagers()[atoi(nrOrdine.c_str()) - nrP - nrB - 1]);
                                                goldPack.popManager(atoi(nrOrdine.c_str()) - nrP - nrB - 1);
                                                nrM--;
                                            }
                                    }
                                    catch(std::exception& err)
                                    {
                                        std::cout << err.what() << '\n';
                                        rlutil::anykey();
                                    }
                                } else if (decizie == "2") {
                                    try
                                    {
                                        if (atoi(nrOrdine.c_str()) > nrP + nrM + nrB || atoi(nrOrdine.c_str()) <= 0) throw (invalidInput{"Numar de ordine invalid"});
                                        if (atoi(nrOrdine.c_str()) <= nrP) {
                                            col.addPlayer(goldPack.getPlayers()[atoi(nrOrdine.c_str()) - 1]);
                                            goldPack.popPlayer(atoi(nrOrdine.c_str()) - 1);
                                            nrP--;
                                        } else if (atoi(nrOrdine.c_str()) <= nrP + nrB) {
                                            col.addBadge(goldPack.getBadges()[atoi(nrOrdine.c_str()) - nrP - 1]);
                                            goldPack.popBadge(atoi(nrOrdine.c_str()) - nrP - 1);
                                            nrB--;
                                        } else if (atoi(nrOrdine.c_str()) <= nrP + nrB + nrM) {
                                            col.addManager(goldPack.getManagers()[atoi(nrOrdine.c_str()) - nrP - nrB - 1]);
                                            goldPack.popManager(atoi(nrOrdine.c_str()) - nrP - nrB - 1);
                                            nrM--;
                                        }
                                    }
                                    catch(std::exception& err)
                                    {
                                        std::cout << err.what() << '\n';
                                        rlutil::anykey();
                                    }
                                }
                                else throw (invalidInput{"Input invalid"});
                            }
                            catch(std::exception& err)
                            {
                                std::cout << err.what() << '\n';
                                rlutil::anykey();
                            }
                        }
                        else throw (invalidInput{"Input invalid"});
                    }
                    catch(invalidInput& err)
                    {

                        std::cout << err.what() << '\n';
                        rlutil::anykey();

                    }
                } while (!goldPack.getPlayers().empty() || !goldPack.getBadges().empty() ||
                         !goldPack.getManagers().empty());
                //system("pause");
                //std::cout << '\n' <<"Press any key to continue" <<'\n';
                rlutil::anykey();
            }
            else
            {
                if(input != "0") throw (invalidInput{"Input invalid"});
            }

        }
        catch(std::exception& err)
        {
            std::cout << err.what() << '\n';
            rlutil::anykey();

        }

    }while(input != "0");



        return 0;
}