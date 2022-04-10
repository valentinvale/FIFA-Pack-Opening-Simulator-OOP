//
// Created by valus on 10.04.2022.
//

#ifndef OOP_GOALKEEPER_H
#define OOP_GOALKEEPER_H


#include <ostream>
#include "player.h"

class goalkeeper : public player {
    int div;
    int han;
    int kic;
    int ref;
    int spe;
    int posi;

public:
    goalkeeper(int id, const std::string &name, const std::string &team, const std::string &pos,
               const std::string &quality, int ovr, int div, int han, int kic, int ref, int spe, int posi);

    void afis(std::ostream& os) const override;

    friend std::ostream &operator<<(std::ostream &os, const goalkeeper &goalkeeper);
};


#endif //OOP_GOALKEEPER_H
