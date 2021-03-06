#include "PlayerUnit.h"



using namespace std;

PlayerUnit::PlayerUnit() = default;

PlayerUnit::PlayerUnit(string name, Posn* position, unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                       unsigned int lvl, bool is_melee,
                       vector<Equipment>* equipmentList, Spell** spellList,
                       double mod_vit, double mod_int, double mod_dex, double mod_str) {
    this->name = std::move(name);
    this->position = position;
    this->direction = DOWN;
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = dex;
    this->st_str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_dex = mod_dex;
    this->melee = melee;
    this->lvl = lvl;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->visible = true;

    updateStats();

    this->equipmentList = equipmentList;
    this->spellList = spellList;
}

PlayerUnit::~PlayerUnit() {
    this->equipmentList->clear();
    delete [] this->spellList;
    delete position;
}

void PlayerUnit::equip(Equipment const equipment, Item ** inventory, int curInventorySize) {
    Equipment curEquip = (*this->equipmentList)[equipment.getType()];
    this->st_str -= curEquip.getStr();
    this->st_vit -= curEquip.getVit();
    this->st_int -= curEquip.getIntel();
    this->st_dex -= curEquip.getSpeed();

    inventory[curInventorySize] = &curEquip;

    this->st_str += equipment.getStr();
    this->st_vit += equipment.getVit();
    this->st_int += equipment.getIntel();
    this->st_dex += equipment.getSpeed();
    (*this->equipmentList)[equipment.getType()] = equipment;
    updateStats();
}

bool PlayerUnit::addEXP(int const exp) {
    int new_exp = this->exp + exp;
    if (new_exp >= 100) {
        this->exp %= 100;
        lvl += 1;
        this->st_vit += mod_vit;
        this->st_int += mod_int;
        this->st_dex += mod_dex;
        this->st_str += mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}

direction_t PlayerUnit::getDirection() {
    return this->direction;
}

void PlayerUnit::setDirection(direction_t direction) {
    this->direction = direction;
}




