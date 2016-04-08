//
//  CharacterFactory.hpp
//  Roguemon  2.0
//
//  Created by Francesco Pegoraro on 08/04/16.
//  Copyright © 2016 guidolippi. All rights reserved.
//

#ifndef CharacterFactory_hpp
#define CharacterFactory_hpp

#include <stdio.h>
#include "Character.hpp"
#include "Elf.hpp"
#include "Monster.hpp"


class CharacterFactory {
public:
    enum CharacterType {Elfo, Druid, Paladin, Poke};
    
    static Character* makeCharacter(CharacterFactory::CharacterType type);
};

#endif /* CharacterFactory_hpp */
