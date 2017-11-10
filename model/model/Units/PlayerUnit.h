#ifndef CS3520_2017FA_PROJ_PLAYERCHARACTER_H
#define CS3520_2017FA_PROJ_PLAYERCHARACTER_H

#include "IUnit.h"
#include "../Equipment/Equipment.h"
#include "../Spells/Spell.h"
#include <vector>

class PlayerUnit : public IUnit {
public:
    PlayerUnit();

    /**
     *
     * @param vit
     * @param intel
     * @param dex
     * @param str
     * @param equipment
     * @param spell
     * @param mod_vit
     * @param mod_int
     * @param mod_dex
     * @param mod_dex
     * @param is_melee
     * @param lvl
     * @param name
     */
    PlayerUnit(string name, Point position, bool visible,
               unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
               unsigned int lvl, bool is_melee,
               vector<Equipment> equipmentList, vector<Spell> spellList,
               double mod_vit, double mod_int, double mod_dex, double mod_str);


    /**
     * Equips the chosen equipment to the player character and applies stat changes as necessary. Returns the old
     * equipment, if there is one.
     * @param equipment
     */
    Equipment equip(Equipment equipment);

    /**
     * adds EXP from a battle to the exp of this unit. Then calculates if there is a level up by this unit. Returns
     * true if there is a level up.
     * @param exp
     */
    bool addEXP(int exp);


private:
    double mod_vit, mod_int, mod_dex, mod_str;
};


#endif //CS3520_2017FA_PROJ_PLAYERCHARACTER_H