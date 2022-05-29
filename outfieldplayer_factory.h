//
// Created by valus on 28.05.2022.
//

#ifndef OOP_OUTFIELDPLAYER_FACTORY_H
#define OOP_OUTFIELDPLAYER_FACTORY_H


#include "outfieldplayer.h"

class outfieldplayer_factory {
public:
    static outfieldplayer ofp_liga1();
    static outfieldplayer ofp_liga2();
    static outfieldplayer ofp_liga3();
};


#endif //OOP_OUTFIELDPLAYER_FACTORY_H
