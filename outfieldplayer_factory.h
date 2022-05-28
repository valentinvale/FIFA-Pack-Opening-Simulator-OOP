//
// Created by valus on 28.05.2022.
//

#ifndef OOP_OUTFIELDPLAYER_FACTORY_H
#define OOP_OUTFIELDPLAYER_FACTORY_H


#include "outfieldplayer.h"

class outfieldplayer_factory {
public:
    static outfieldplayer ofp_liga1() {return outfieldplayer(0, "Andrei Ivan", "Universitatea Craiova", "LW", "Silver", 70, 70, 70, 70, 70, 70, 70);}
    static outfieldplayer ofp_liga2() {return outfieldplayer(0, "Ricardo Grigore", "FC Dinamo Bucuresti", "CB", "Bronze", 60, 60, 60, 60, 60, 60, 60);}
    static outfieldplayer ofp_liga3() {return outfieldplayer(0, "Gelu Velici", "AS Viitorul Simian", "ST", "Bronze", 50, 50, 50, 50, 50, 50, 50);}
};


#endif //OOP_OUTFIELDPLAYER_FACTORY_H
