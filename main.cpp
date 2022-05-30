

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
#include "outfieldplayer_factory.h"
#include "rlutil.h"
#include "error.h"

template <typename T>
[[maybe_unused]] void mySort(std::vector<std::shared_ptr<T>>& vec){
    for(unsigned long long i = 0; i < vec.size()-1; i++)
        for(unsigned long long j = i+1; j < vec.size(); j++)
            if(vec[i] > vec[j]) {
                auto temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }

    for(unsigned long long i = 0; i < vec.size(); i++)
        std::cout << *vec[i] << '\n';
    std::cout << '\n';
}

void deschidePachet(pack pachet, balance &blnc, std::vector<std::shared_ptr <player>> poolPl, std::vector<badge> poolBdg, std::vector<manager> poolMngr, collection& col)
{
    std::string inputSellAddAll=" ";
    std::string nrOrdine=" ", decizie=" ";
    //system("cls");
    rlutil::cls();
    if(pachet.open(blnc, poolPl, poolBdg, poolMngr)) {
        int nrP, nrB, nrM;
        nrP = pachet.getNrOfPlayers();
        nrB = pachet.getNrOfBadges();
        nrM = pachet.getNrOfManagers();
        std::cout << "Ai mai ramas cu atatia bani: " << '\n';
        std::cout << blnc << '\n' << '\n';
        std::cout << "Din pachet ai obtinut: " << '\n';

        do {
            //system("cls");
            rlutil::cls();
            std::cout << pachet << '\n' << '\n';
            std::cout << "Apasa tasta 1 pentru a vinde toate itemele" << '\n' << '\n';
            std::cout << "Apasa tasta 2 pentru a adauga toate itemele la colectie" << '\n' << '\n';
            std::cout
                    << "Apasa tasta 3, introdu numarul de ordine al item-ului si cifra 1 sau 2 pentru a-l vinde, respectiv a-l adauga la colectie"
                    << '\n' << '\n';
            std::cin >> inputSellAddAll;
                if (inputSellAddAll == "1") {
                    for (const auto & i : pachet.getPlayers()) {
                        balance::sellPlayer(i);
                    }

                    for (const auto & i : pachet.getBadges()) {
                        balance::sellBadge(i);
                    }

                    for (const auto & i : pachet.getManagers()) {
                        balance::sellManager(i);
                    }

                    pachet.clearPack();

                } else if (inputSellAddAll == "2") {
                    for (const auto & i : pachet.getPlayers()) {
                        col.addPlayer(i);
                    }

                    for (const auto & i : pachet.getBadges()) {
                        col.addBadge(i);
                    }

                    for (const auto & i : pachet.getManagers()) {
                        col.addManager(i);
                    }

                    pachet.clearPack();

                } else if (inputSellAddAll == "3") {
                    std::cin >> nrOrdine >> decizie;
                        if (decizie == "1") {
                                if (std::stoi(nrOrdine) > nrP + nrB + nrM || std::stoi(nrOrdine) <= 0)
                                {
                                    std::cout << "Numar de ordine invalid" << '\n';
                                    rlutil::anykey();
                                }
                                else if (std::stoi(nrOrdine) <= nrP) {
                                    balance::sellPlayer(pachet.getPlayers()[std::stoi(nrOrdine) - 1]);
                                    pachet.popPlayer(std::stoi(nrOrdine) - 1);
                                    nrP--;
                                } else if (std::stoi(nrOrdine) <= nrP + nrB) {
                                    balance::sellBadge(pachet.getBadges()[std::stoi(nrOrdine) - nrP - 1]);
                                    pachet.popBadge(std::stoi(nrOrdine) - nrP - 1);
                                    nrB--;
                                } else if (std::stoi(nrOrdine) <= nrP + nrB + nrM) {
                                    balance::sellManager(pachet.getManagers()[std::stoi(nrOrdine) - nrP - nrB - 1]);
                                    pachet.popManager(std::stoi(nrOrdine) - nrP - nrB - 1);
                                    nrM--;
                                }
                        } else if (decizie == "2") {
                                if (std::stoi(nrOrdine) > nrP + nrM + nrB || std::stoi(nrOrdine) <= 0)
                                {
                                    std::cout << "Numar de ordine invalid" << '\n';
                                    rlutil::anykey();
                                }
                                if (std::stoi(nrOrdine) <= nrP) {
                                    col.addPlayer(pachet.getPlayers()[std::stoi(nrOrdine) - 1]);
                                    pachet.popPlayer(std::stoi(nrOrdine) - 1);
                                    nrP--;
                                } else if (std::stoi(nrOrdine) <= nrP + nrB) {
                                    col.addBadge(pachet.getBadges()[std::stoi(nrOrdine) - nrP - 1]);
                                    pachet.popBadge(std::stoi(nrOrdine) - nrP - 1);
                                    nrB--;
                                } else if (std::stoi(nrOrdine) <= nrP + nrB + nrM) {
                                    col.addManager(pachet.getManagers()[std::stoi(nrOrdine) - nrP - nrB - 1]);
                                    pachet.popManager(std::stoi(nrOrdine) - nrP - nrB - 1);
                                    nrM--;
                                }

                        } else {
                            std::cout << "Input invalid" << '\n';
                            rlutil::anykey();
                        }
                } else {
                    std::cout << "Input invalid" << '\n';
                    rlutil::anykey();
                }
            }

         while (!pachet.getPlayers().empty() || !pachet.getBadges().empty() ||
                 !pachet.getManagers().empty());
        //system("pause");
        //std::cout << '\n' <<"Press any key to continue" <<'\n';
        rlutil::anykey();
    }
    else rlutil::anykey();
}

void openColection(collection &col, balance &blnc, std::string &nrOrdine, std::string &decizie, std::string &inpCol) {
    do {
        rlutil::cls();
        //mySort<player>(col.getPlayers());
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


            if (inpCol == "3") {
                std::cin >> nrOrdine >> decizie;
                int nrPCol = col.getPlayers().size();
                int nrBCol = col.getBadges().size();
                int nrMCol = col.getManagers().size();
                    if (decizie == "1") {
                            if (std::stoi(nrOrdine) > nrPCol + nrMCol + nrBCol || std::stoi(nrOrdine) <= 0)
                            {
                                std::cout << "Numar de ordine invalid" << '\n';
                                rlutil::anykey();
                            }
                            else if (std::stoi(nrOrdine) <= nrPCol) {
                                balance::sellPlayer(col.getPlayers()[std::stoi(nrOrdine) - 1]);
                                col.popPlayer(std::stoi(nrOrdine) - 1);
                            } else if (std::stoi(nrOrdine) <= nrPCol + nrBCol) {
                                balance::sellBadge(col.getBadges()[std::stoi(nrOrdine) - nrPCol - 1]);
                                col.popBadge(std::stoi(nrOrdine) - nrPCol - 1);
                            } else if (std::stoi(nrOrdine) <= nrPCol + nrBCol + nrMCol) {
                                balance::sellManager(col.getManagers()[std::stoi(nrOrdine) - nrPCol - nrBCol - 1]);
                                col.popManager(std::stoi(nrOrdine) - nrPCol - nrBCol - 1);
                            }
                    } else if (decizie == "2") {
                            if (std::stoi(nrOrdine) > nrPCol || std::stoi(nrOrdine) <= 0)
                            {
                                std::cout << "Numar de ordine invalid" << '\n';
                                rlutil::anykey();
                            }
                            else if (std::stoi(nrOrdine) <= nrPCol) {
                                if (blnc.pay(1000))
                                    col.getPlayers()[std::stoi(nrOrdine) - 1]->chemistryStyle();
                                else
                                    std::cout << "Nu s-a putut aplica boost-ul\n";
                            } else {
                                std::cout << "Nu se poate aplica boost unui manager/badge\n";
                            }

                    } else {
                        std::cout << "Input invalid" << '\n';
                        rlutil::anykey();
                    }
            }
            else
            {
                if (inpCol != "9") {
                    std::cout << "Input invalid" << '\n';
                    rlutil::anykey();
                }
            }
        }
     while (inpCol != "9");
    rlutil::anykey();
}

int main() {

    std::string line = " ";
    std::string word = " ";

    std::ifstream fin("date.txt");
    int nrOfPlayers = 19239;
    int nrOfBadges = 4;
    int nrOfManagers = 4;
    int id, pac, sho, pas, dri, def, phy, div, han, kic, ref, spe, posi;

    std::string playerName, playerTeam, playerPosition, playerQuality, badgeQuality, managerQuality, badgeName, managerName, managerLeague;
    std::vector<std::shared_ptr<player>> playersPool, playersPoolGold, playersPoolSilver, playersPoolBronze, playersPoolPremium, playersPoolUltra;
    std::vector<badge> badgesPool;
    std::vector<manager> managersPool;

    player* b = new outfieldplayer(0, "baza", "baza", "ST", "Gold", 0, 0, 0, 0, 0, 0, 0);
    outfieldplayer ofpl1 = outfieldplayer_factory::ofp_liga1();
    outfieldplayer ofpl2 = outfieldplayer_factory::ofp_liga2();
    outfieldplayer ofpl3 = outfieldplayer_factory::ofp_liga3();

    try
    {
        [[maybe_unused]]auto& baza1 = static_cast<player&>(ofpl1);
        [[maybe_unused]]auto& baza2 = static_cast<player&>(ofpl2);
        [[maybe_unused]]auto& baza3 = static_cast<player&>(ofpl3);
    }
    catch (std::bad_cast& err)
    {
        std::cout << err.what() << '\n';
        rlutil::anykey();
    }

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
        int ovr;
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
            {

                    goalkeeper gkp{id, playerName, playerTeam, playerPosition,playerQuality, ovr, div, han, kic, ref,spe, posi};
                    if(playerQuality == "Gold") {
                        playersPoolGold.push_back(gkp.clone());
                        if(ovr >= 80)
                            playersPoolPremium.push_back(gkp.clone());
                        if(ovr >= 85)
                            playersPoolUltra.push_back(gkp.clone());
                    }
                    else if(playerQuality == "Silver")
                        playersPoolSilver.push_back(gkp.clone());
                    else
                        playersPoolBronze.push_back((gkp.clone()));
                    playersPool.push_back(gkp.clone());
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
                    outfieldplayer ofp{id, playerName, playerTeam, playerPosition, playerQuality, ovr, pac, sho, pas, dri, def, phy};
                    if(playerQuality == "Gold") {
                        playersPoolGold.push_back(ofp.clone());
                        if(ovr >= 80)
                            playersPoolPremium.push_back(ofp.clone());
                        if(ovr >= 85)
                            playersPoolUltra.push_back(ofp.clone());
                    }
                    else if(playerQuality == "Silver")
                        playersPoolSilver.push_back(ofp.clone());
                    else
                        playersPoolBronze.push_back((ofp.clone()));
                    playersPool.push_back(ofp.clone());

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

                badge bdg{id, badgeName, badgeQuality};
                badgesPool.push_back(bdg);

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
                manager mngr{id, managerName, managerQuality, managerLeague};
                managersPool.push_back(mngr);

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

//    collection col{emptyPlayers, emptyBadges, emptyManagers};
    collection_builder c;
    collection col = c.players(emptyPlayers).badges(emptyBadges).managers(emptyManagers).build();
    auto& blnc = balance::get_bal();

    std::string input=" ", nrOrdine=" ", decizie=" ", inpCol=" ";
    pack goldPack{7500, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};
    pack premiumGoldPack{15000, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};
    pack ultraPremiumGoldPack{50000, 10, 2, 2, emptyPlayers, emptyBadges, emptyManagers};
    pack silverPack{3000, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};
    pack bronzePack{1500, 5, 1, 1, emptyPlayers, emptyBadges, emptyManagers};

    do
    {
        //system("cls");
        rlutil::cls();
        std::cout << "Balance: " << blnc << '\n' << '\n';
        std::cout << "Apasa tasta corespunzatoare pentru a dschide pachetul dorit" << '\n' << '\n';
        std::cout << "Apasa tasta 9 pentru a vedea colectia" << '\n' << '\n';
        std::cout << "Apasa tasta 0 pentru a iesi" << '\n' << '\n';
        std::cout << "1. Gold Pack - 5 jucatori de calitate Gold, 1 badge si 1 manager - pret: " << goldPack.getPrice() << '\n' << '\n';
        std::cout << "2. Silver Pack - 5 jucatori de calitate Silver, 1 badge si 1 manager - pret: " << silverPack.getPrice() << '\n' << '\n';
        std::cout << "3. Bronze Pack - 5 jucatori de calitate Bronze, 1 badge si 1 manager - pret: " << bronzePack.getPrice() << '\n' << '\n';
        std::cout << "4. Premium Gold Pack - 5 jucatori de calitate Gold cu OVR de peste 80, 1 badge si 1 manager - pret: " << premiumGoldPack.getPrice() << '\n' << '\n';
        std::cout << "5. Ultra Premium Gold Pack - 10 jucatori de calitate Gold cu OVR de peste 85, 2 badge si 2 manager - pret: " << ultraPremiumGoldPack.getPrice() << '\n' << '\n';
        std::cin >> input;

            if (input == "9") {
                openColection(col, blnc, nrOrdine, decizie, inpCol);


            }
            else if (input == "1") {
                deschidePachet(goldPack, blnc, playersPoolGold, badgesPool, managersPool, col);
            }
            else if (input == "2") {
                deschidePachet(silverPack, blnc, playersPoolSilver, badgesPool, managersPool, col);
            }
            else if (input == "3"){
                deschidePachet(bronzePack, blnc, playersPoolBronze, badgesPool, managersPool, col);
            }
            else if (input == "4"){
                deschidePachet(premiumGoldPack, blnc, playersPoolPremium, badgesPool, managersPool, col);
            }
            else if (input == "5"){
                deschidePachet(ultraPremiumGoldPack, blnc, playersPoolUltra, badgesPool, managersPool, col);
            }
            else
            {
                if(input != "0") {
                    std::cout << "Input invalid" << '\n';
                    rlutil::anykey();
                }
            }

        }

    while(input != "0");


        return 0;
}