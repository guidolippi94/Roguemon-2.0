

#include "CharacterFactory.hpp"

Character* CharacterFactory::makeCharacter(CharacterFactory::CharacterType type, int x, int y, int id, std::string addr) {
    Character *ch;
    switch (type) {
        case CharacterFactory::Elfo:
            
            ch = new Elf(x, y , id, addr);
            break;
        case CharacterFactory::Druido:
            ch = new Druid(x, y , id, addr);
            break;
        case CharacterFactory::Paladino:
            ch = new Paladin(x, y , id, addr);
            break;
        case CharacterFactory::Poke:
            ch = new Monster::Monster(x, y , id, addr);
            break;
        default:
            ch = new Monster::Monster(x, y , id, addr);
            break;
    }
    return ch;
}
