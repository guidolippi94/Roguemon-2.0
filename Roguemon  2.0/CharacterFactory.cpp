

#include "CharacterFactory.hpp"

Character* CharacterFactory::makeCharacter(CharacterFactory::CharacterType type) {
    Character *ch;
    switch (type) {
        case CharacterFactory::Elfo:
            ch = new Elf::Elf();
            break;
        case CharacterFactory::Druid:
            ch = new Druid::Druid();
            break;
        case CharacterFactory::Paladin:
            ch = new Paladin::Paladin();
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
