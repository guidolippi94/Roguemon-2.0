

#ifndef CharacterFactory_hpp
#define CharacterFactory_hpp

#include <stdio.h>

#include "Character.hpp"
#include "Elf.hpp"
#include "Druid.hpp"
#include "Paladin.hpp"
#include "Monster.hpp"


class CharacterFactory {
public:
    enum CharacterType {Elfo, Druid, Paladin, Poke};
    
    static Character* makeCharacter(CharacterFactory::CharacterType type);
};

#endif /* CharacterFactory_hpp */
