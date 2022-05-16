#include <string>
#include <memory>
#include <utility>
#include "error.h"

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class player {

protected:
    int id = 0;
    std::string name;
    std::string team;
    std::string pos;
    std::string quality;
    int ovr;

    virtual void afis(std::ostream &os) const = 0;

public:
    virtual void chemistryStyle() = 0;
//    const std::string& getName() const;
//    const std::string& getTeam() const;
    //[[maybe_unused]] const std::string& getPos() const;
    const std::string& getQuality() const;
//    int getId() const;
    int getOvr() const;
//    int getPac() const;
//    int getSho() const;
//    int getPas() const;
//    int getDri() const;
//    int getDef() const;
//    int getPhy() const;

    player(int id_, const std::string& name_, const std::string& team_, const std::string& pos_, const std::string& quality_,
           int ovr_);

    //player();

    virtual ~player();

    player(const player& other);

    player& operator=(const player& other);

    friend std::ostream &operator<<(std::ostream& os, const player& pl);

    virtual std::shared_ptr<player> clone() const = 0;

};


#endif //OOP_PLAYER_H
