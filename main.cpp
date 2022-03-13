// structura claselor
// functia de deschidere pachet
// functia de adaugat jucatori la colectie
// functia de vanzare jucatori
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "efl/random.hpp"
using Random = effolkronium::random_static;



class player{
    int id;
    std::string name;
    std::string team;
    std::string pos;
    std::string quality;
    int ovr;
    int pac;
    int sho;
    int pas;
    int dri;
    int def;
    int phy;

public:
//    const std::string& getName() const {return name; }
//    const std::string& getTeam() const {return team; }
//    const std::string& getPos() const {return pos; }
    const std::string& getQuality() const {return quality; }
//    int getId() const {return id; }
    int getOvr() const {return ovr; }
//    int getPac() const {return pac; }
//    int getSho() const {return sho; }
//    int getPas() const {return pas; }
//    int getDri() const {return dri; }
//    int getDef() const {return def; }
//    int getPhy() const {return phy; }

    player(int id_, const std::string& name_, const std::string& team_, const std::string& pos_, const std::string& quality_,
            int ovr_, int pac_, int sho_, int pas_, int dri_, int def_, int phy_) :id{id_}, name{name_}, team{team_}, pos{pos_}, quality{quality_},
            ovr{ovr_}, pac{pac_}, sho{sho_}, pas{pas_}, dri{dri_}, def{def_}, phy{phy_} {

//        std::cout << "constructor de initializare player\n";
    }

    player(){}

    player(const player& other) : id{other.id}, name{other.name}, team{other.team}, pos{other.pos}, quality{other.quality},
                                   ovr{other.ovr}, pac{other.pac}, sho{other.sho}, pas{other.pas},
                                  dri{other.dri}, def{other.def}, phy{other.phy} {

//        std::cout << "constructor de copiere player\n";
    }

    player& operator=(const player& other) {
        name = other.name;
        team = other.team;
        pos = other.pos;
        quality = other.quality;
        id = other.id;
        ovr = other.ovr;
        pac = other.pac;
        sho = other.sho;
        pas = other.pas;
        dri = other.dri;
        def = other.def;
        phy = other.phy;

//        std::cout << "operator= copiere player\n";
        return *this;
    }

    ~player() {
//        std::cout << "destructor player\n";
    }


    friend std::ostream &operator<<(std::ostream& os, const player& pl) {
        os << "name: " << pl.name << " team: " << pl.team << " pos: " << pl.pos << " quality: "
           << pl.quality << " id: " << pl.id << " ovr: " << pl.ovr << " pac: " << pl.pac << " sho: "
           << pl.sho << " pas: " << pl.pas << " dri: " << pl.dri << " def: " << pl.def << " phy: "
           << pl.phy <<'\n';
        return os;
    }



};

class badge{
    int id;
    std::string name;
    std::string quality;


public:
//    const std::string& getName() const {return name; }
    const std::string& getQuality() const {return quality; }
//    int getId() const {return id; }

    badge(int id_, const std::string& name_, const std::string& quality_) :id{id_}, name{name_}, quality{quality_} {

//        std::cout << "constructor de initializare badge\n";
    }

    badge(){}

//    badge(const badge& other) : name{other.name}, quality{other.quality}, id{other.id} {
//
//        std::cout << "constructor de copiere badge\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const badge& badge) {
        os << "name: " << badge.name << " quality: " << badge.quality << " id: " << badge.id <<'\n';
        return os;
    }


};

class manager{
    int id;
    std::string name;
    std::string quality;
    std::string league;


public:
//    const std::string& getName() const {return name; }
//    const std::string& getLeague() const {return league; }
    const std::string& getQuality() const {return quality; }
//    int getId() const {return id; }

    manager(int id_, const std::string& name_, const std::string& quality_, const std::string & league_) :id{id_}, name{name_},
    quality{quality_}, league{league_} {

//        std::cout << "constructor de initializare manager\n";
    }

    manager(){}

//    manager(const manager& other) : name{other.name}, quality{other.quality}, league{other.league}, id{other.id} {
//
//        std::cout << "constructor de copiere manager\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const manager& manager) {
        os << "name: " << manager.name << " quality: " << manager.quality << " league: " << manager.league << " id: "
           << manager.id << '\n';
        return os;
    }



};

class balance{
    int bal;

public:
    explicit balance(int bal) : bal(bal) {
//        std::cout << "constructor balance\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const balance &balance) {
        os << "bal: " << balance.bal;
        return os;
    }

    bool pay(int price)
    {
        if (price > bal) {std::cout << "Fonduri insuficiente\n"; return false;}
        else { this->bal = this->bal - price; return true;}
    }

    //Metoda pentru vindere de jucator, luam jucatorul de pe pozitia i din vectorul de jucatori obtinuti din pachet
    //la fel si pentru manageri si badge-uri
    void sellPlayer(std::vector<player> pulledPlayers, unsigned long long i)
    {
        if(pulledPlayers[i].getQuality() == "Bronze") this->bal += 30 * pulledPlayers[i].getOvr();
            else if(pulledPlayers[i].getQuality() == "Silver") this->bal += 50 * pulledPlayers[i].getOvr();
                else this->bal += 100 * pulledPlayers[i].getOvr();
//        pulledPlayers.erase(pulledPlayers.begin()+i);
    }

    void sellBadge(std::vector<badge> pulledBadges, unsigned long long i)
    {
        if(pulledBadges[i].getQuality() == "Bronze") this->bal += 300;
        else if(pulledBadges[i].getQuality() == "Silver") this->bal += 500;
        else this->bal += 1000;
//        pulledBadges.erase(pulledBadges.begin()+i);
    }

    void sellManager(std::vector<manager> pulledManagers, unsigned long long i)
    {
        if(pulledManagers[i].getQuality() == "Bronze") this->bal += 300;
        else if(pulledManagers[i].getQuality() == "Silver") this->bal += 500;
        else this->bal += 1000;
//        pulledManagers.erase(pulledManagers.begin()+i);
    }

};

class pack{
    int price;
    int nrOfItems;
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
//    int getPrice() const {return price; }
//    int getnrOfItems() const {return price; }
    const std::vector<player>& getPlayers() const {return players; }
    const std::vector<badge>& getBadges() const {return badges; }
    const std::vector<manager>& getManager() const {return managers; }

    pack(int price_, int nrOfItems_, const std::vector<player>& players_, const std::vector<badge>& badges_,
         const std::vector<manager>& managers_) : price{price_}, nrOfItems{nrOfItems_}, players{players_},
         badges{badges_}, managers{managers_} {

//        std::cout << "constructor de initializare pack\n";
    }

//    pack(pack& other) : price{other.price}, nrOfItems{other.nrOfItems}, players{other.players},
//                                                  badges{other.badges}, managers{other.managers} {
//
//        std::cout << "constructor de copiere pack\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const pack& pack) {
        os << "price: " << pack.price << " nrOfItems: " << pack.nrOfItems << '\n';
        os << "players:\n";

        for (const auto & player : pack.players) {
            os << player;
            os << '\n';
        }
        
        os << "badges:\n";
        for (const auto & badge : pack.badges) {
            os << badge;
            os << '\n';
        }
        os << "managers:\n";
        for (const auto & manager : pack.managers) {
            os << manager;
            os << '\n';
        }
        return os;
    }

    //metoda deschidere pachet
    void open(balance &blnc, std::vector<player> poolPl, std::vector<badge> poolBdg, std::vector<manager> poolMngr)
    {
        //daca ne ajung banii
        if(blnc.pay(price))
        {
            for (int i = 0; i < this->nrOfItems; ++i)
            {
                auto val = Random::get(0, 23);
                if(val >= 0 && val <= 15) this->players.push_back(poolPl[val]);
                    else if(val > 15 and val <= 19) this->badges.push_back(poolBdg[val%4]);
                        else this->managers.push_back(poolMngr[val%4]);

            }
        }

        //daca nu ne ajung banii
        else std::cout << "Nu s-a putut deschide pachetul\n";

    }

};


class collection{
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
    collection(const std::vector<player>& players_, const std::vector<badge>& badges_,
         const std::vector<manager>& managers_) : players{players_}, badges{badges_}, managers{managers_} {

//        std::cout << "constructor de initializare collection\n";
    }


    friend std::ostream& operator<<(std::ostream& os, const collection& collection) {
        os << "players:\n";

        for (const auto & player : collection.players) {
            os << player;
            os << '\n';
        }

        os << "badges:\n";
        for (const auto & badge : collection.badges) {
            os << badge;
            os << '\n';
        }
        os << "managers:\n";
        for (const auto & manager : collection.managers) {
            os << manager;
            os << '\n';
        }
        return os;
    }

    //metode pentru adaugat la colectie
    void addPlayer(std::vector<player> pulledPlayers, unsigned long long i)
    {
        this->players.push_back(pulledPlayers[i]);
//        pulledPlayers.erase(pulledPlayers.begin()+i);
    }

    void addBadge(std::vector<badge> pulledBadges, unsigned long long i)
    {
        this->badges.push_back(pulledBadges[i]);
//        pulledBadges.erase(pulledBadges.begin()+i);
    }

    void addManager(std::vector<manager> pulledManagers, unsigned long long i)
    {
        this->managers.push_back(pulledManagers[i]);
//        pulledManagers.erase(pulledManagers.begin()+i);
    }

};



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
