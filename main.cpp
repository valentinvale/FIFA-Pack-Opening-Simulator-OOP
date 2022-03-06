// tema 1 facut clasele cu constructori si restul de chestii pana la finalul saptamanii

#include <iostream>
#include <vector>
#include <string>

class player{
    std::string name;
    std::string team;
    std::string pos;
    std::string quality;
    int id;
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
//    const std::string& getQuality() const {return quality; }
//    int getId() const {return id; }
//    int getOvr() const {return ovr; }
//    int getPac() const {return pac; }
//    int getSho() const {return sho; }
//    int getPas() const {return pas; }
//    int getDri() const {return dri; }
//    int getDef() const {return def; }
//    int getPhy() const {return phy; }

    player(const std::string& name_, const std::string& team_, const std::string& pos_, const std::string& quality_,
           int id_, int ovr_, int pac_, int sho_, int pas_, int dri_, int def_, int phy_) : name{name_}, team{team_}, pos{pos_}, quality{quality_},
           id{id_}, ovr{ovr_}, pac{pac_}, sho{sho_}, pas{pas_}, dri{dri_}, def{def_}, phy{phy_} {

        std::cout << "constructor de initializare player\n";
    }

    player(const player& other) : name{other.name}, team{other.team}, pos{other.pos}, quality{other.quality},
                                  id{other.id}, ovr{other.ovr}, pac{other.pac}, sho{other.sho}, pas{other.pas},
                                  dri{other.dri}, def{other.def}, phy{other.phy} {

        std::cout << "constructor de copiere player\n";
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

        std::cout << "operator= copiere player\n";
        return *this;
    }

    ~player() {
        std::cout << "destructor player\n";
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
    std::string name;
    std::string quality;
    int id;

public:
//    const std::string& getName() const {return name; }
//    const std::string& getQuality() const {return quality; }
//    int getId() const {return id; }

    badge(const std::string& name_, const std::string& quality_, int id_) : name{name_}, quality{quality_}, id{id_} {

        std::cout << "constructor de initializare badge\n";
    }

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
    std::string name;
    std::string quality;
    std::string league;
    int id;

public:
//    const std::string& getName() const {return name; }
//    const std::string& getLeague() const {return league; }
//    const std::string& getQuality() const {return quality; }
//    int getId() const {return id; }

    manager(const std::string& name_, const std::string& quality_, const std::string & league_, int id_) : name{name_},
    quality{quality_}, league{league_}, id{id_} {

        std::cout << "constructor de initializare manager\n";
    }

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

class pack{
    int price;
    int nrOfItems;
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
//    int getPrice() const {return price; }
//    int getnrOfItems() const {return price; }
//    const std::vector<player>& getPlayers() const {return players; }
//    const std::vector<badge>& getBadges() const {return badges; }
//    const std::vector<manager>& getManager() const {return managers; }

    pack(int price_, int nrOfItems_, const std::vector<player>& players_, const std::vector<badge>& badges_,
         const std::vector<manager>& managers_) : price{price_}, nrOfItems{nrOfItems_}, players{players_},
         badges{badges_}, managers{managers_} {

        std::cout << "constructor de initializare pack\n";
    }

//    pack(pack& other) : price{other.price}, nrOfItems{other.nrOfItems}, players{other.players},
//                                                  badges{other.badges}, managers{other.managers} {
//
//        std::cout << "constructor de copiere pack\n";
//    }

    friend std::ostream& operator<<(std::ostream& os, const pack& pack) {
        os << "price: " << pack.price << " nrOfItems: " << pack.nrOfItems;
        os << " players:\n";

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

};


class collection{
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
    collection(const std::vector<player>& players_, const std::vector<badge>& badges_,
         const std::vector<manager>& managers_) : players{players_}, badges{badges_}, managers{managers_} {

        std::cout << "constructor de initializare collection\n";
    }


    friend std::ostream& operator<<(std::ostream& os, const collection& collection) {
        os << " players:\n";

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

};

//class balance{
//    int bal;
//};

int main() {
    std::cout << "Inainte de apel constructor\n";
    player pl{"Alexandru Mateiu", "Universitatea Craiova", "CM", "Silver",32, 66,
              69, 80, 71, 66, 50, 80};
    player pl2 = pl;
    badge bdg{"Universitatea Craiova", "Silver", 12};
    manager mngr{"Laurentiu Reghecampf", "Silver", "Liga 1", 19};
    std::cout << "Dupa apel constructor\n";
//    std::cout << pl.getName() << " " << pl.getPos() << " " << pl.getPac() <<'\n';

    std::vector<player> jucatori;
    std::vector<manager> manageri;
    std::vector<badge> steme;
    jucatori.push_back(pl);
    manageri.push_back(mngr);
    steme.push_back(bdg);
    pack pck{1200, 10, jucatori, steme, manageri};

    collection col{jucatori, steme, manageri};

//    std::cout << pck.getManager()[0].getName() <<'\n';
//    std::cout << pl2.getName() <<'\n';

//     std::cout << pl2 << pl;
     std::cout << pck;
    return 0;
}
