//
//  CharacterFactory.cpp
//  Roguemon  2.0
//
//  Created by Francesco Pegoraro on 08/04/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#include "CharacterFactory.hpp"

Character* CharacterFactory::makeCharacter(CharacterFactory::CharacterType type) {
    Character *ch;
    switch (type) {
        case CharacterFactory::Elfo:
            ch = new Elf::Elf();
            break;
        case CharacterFactory::Poke:
            ch = new Monster::Monster();
            break;
        default:
            ch = new Monster::Monster();
            break;
    }
    return ch;
}
