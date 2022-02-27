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
    const std::string& getName() const {return name; }
    const std::string& getTeam() const {return team; }
    const std::string& getPos() const {return pos; }
    const std::string& getQuality() const {return quality; }
    int getId() const {return id; }
    int getOvr() const {return ovr; }
    int getPac() const {return pac; }
    int getSho() const {return sho; }
    int getPas() const {return pas; }
    int getDri() const {return dri; }
    int getDef() const {return def; }
    int getPhy() const {return phy; }

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


};

class badge{
    std::string name;
    std::string quality;
    int id;

public:
    const std::string& getName() const {return name; }
    const std::string& getQuality() const {return quality; }
    int getId() const {return id; }

    badge(const std::string& name_, const std::string& quality_, int id_) : name{name_}, quality{quality_}, id{id_} {

        std::cout << "constructor de initializare badge\n";
    }

    badge(const badge& other) : name{other.name}, quality{other.quality}, id{other.id} {

        std::cout << "constructor de copiere badge\n";
    }

};

class manager{
    std::string name;
    std::string quality;
    std::string league;
    int id;

public:
    const std::string& getName() const {return name; }
    const std::string& getLeague() const {return league; }
    const std::string& getQuality() const {return quality; }
    int getId() const {return id; }

    manager(const std::string& name_, const std::string& quality_, const std::string & league_, int id_) : name{name_},
    quality{quality_}, league{league_}, id{id_} {

        std::cout << "constructor de initializare manager\n";
    }

    manager(const manager& other) : name{other.name}, quality{other.quality}, league{other.league}, id{other.id} {

        std::cout << "constructor de copiere manager\n";
    }

};

class pack{
    int price;
    int nrOfItems;
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;

public:
    int getPrice() const {return price; }
    int getnrOfItems() const {return price; }
    const std::vector<player>& getPlayers() const {return players; }
    const std::vector<badge>& getBadges() const {return badges; }
    const std::vector<manager>& getManager() const {return managers; }

    pack(int price_, int nrOfItems_, const std::vector<player>& players_, const std::vector<badge>& badges_,
         const std::vector<manager>& managers_) : price{price_}, nrOfItems{nrOfItems_}, players{players_},
         badges{badges_}, managers{managers_} {

        std::cout << "constructor de initializare pack\n";
    }

    pack(pack& other) : price{other.price}, nrOfItems{other.nrOfItems}, players{other.players},
                                                  badges{other.badges}, managers{other.managers} {

        std::cout << "constructor de copiere pack\n";
    }

};

class collection{
    std::vector<player> players;
    std::vector<badge> badges;
    std::vector<manager> managers;
};

class balance{
    int bal;
};

int main() {
    std::cout << "Inainte de apel constructor\n";
    player pl{"Alexandru Mateiu", "Universitatea Craiova", "CM", "Silver",32, 66,
              69, 80, 71, 66, 50, 80};
    badge bdg{"Universitatea Craiova", "Silver", 12};
    manager mngr{"Laurentiu Reghecampf", "Silver", "Liga 1", 19};
    std::cout << "Dupa apel constructor\n";
    std::cout << pl.getName() << " " << pl.getPos() << " " << pl.getPac() <<'\n';

    std::vector<player> jucatori;
    std::vector<manager> manageri;
    std::vector<badge> steme;
    jucatori.push_back(pl);
    manageri.push_back(mngr);
    steme.push_back(bdg);
    pack pck{1200, 10, jucatori, steme, manageri};

    std::cout << pck.getManager()[0].getName() <<'\n';

    return 0;
}
