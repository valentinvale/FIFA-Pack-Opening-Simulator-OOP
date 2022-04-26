//
// Created by valus on 10.04.2022.
//

#ifndef OOP_OUTFIELDPLAYER_H
#define OOP_OUTFIELDPLAYER_H


#include <ostream>
#include "player.h"

class outfieldplayer : public player{
    int pac;
    int sho;
    int pas;
    int dri;
    int def;
    int phy;

public:
    outfieldplayer(int id, const std::string &name, const std::string &team, const std::string &pos,
                   const std::string &quality, int ovr, int pac, int sho, int pas, int dri, int def, int phy);

    outfieldplayer(const outfieldplayer& other);

    ~outfieldplayer() override;

    void afis(std::ostream &os) const override;
    void chemistryStyle() override;

    friend std::ostream &operator<<(std::ostream &os, const outfieldplayer &outfieldplayer);

    outfieldplayer& operator=(const outfieldplayer& other);

    [[nodiscard]] std::shared_ptr<player> clone() const override;

};


#endif //OOP_OUTFIELDPLAYER_H
