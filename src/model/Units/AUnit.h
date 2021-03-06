//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H


#ifndef CS3520_2017FA_PROJ_SPELLS_H
#include "../Spells/Spell.h"
#endif //CS3520_2017FA_PROJ_SPELL_H

#include "../Item/Equipment/Equipment.h"
#include "../Item/Item.h"
#include "IEntity.h"
#include "../World/DirectionType.h"
#include <string>
#include <vector>


class Spell;

class AUnit : public IEntity {
public:
    AUnit();

    AUnit(const AUnit &unit);

    ~AUnit() override;

    /**
     * Calculates the damage a unit takes based on a damage stat passed in by the class. Returns the amount of damage
     * taken by the unit
     * @param damage
     */
    virtual int takeDamage(Spell * s, AUnit* attacker);

    /**
     *
     * @return the damage statistic dealt by this unit.
     */
    virtual int calcBasicAttack();

    unsigned int get_health() const;

    unsigned int get_max_health() const;

    unsigned int get_mana() const;

    unsigned int get_max_mana() const;

    unsigned int get_p_def() const;

    unsigned int get_m_def() const;

    unsigned int get_vit() const;

    unsigned int get_int() const;

    unsigned int get_dex() const;

    unsigned int get_str() const;

    unsigned int get_lvl() const;

    void addSpell(Spell * spell);

    Spell ** getSpells() const;

    Spell * getSpell(unsigned int i) const;

    bool is_melee() const;

    void reset();


    int curSpellSize = 0;


protected:
    unsigned int health, max_health, mana, max_mana, p_defense, m_defense;
    unsigned int st_vit, st_int, st_dex, st_str;
    unsigned int lvl, exp;
    bool melee;
    vector<Equipment>* equipmentList; // each element in the array pertains to a specific stats
    Spell ** spellList; // will be displayed in a list when the player selects this option

    /**
    * updates the statistics of the unit.
    */
    virtual void updateStats();
};

#endif //CS3520_2017FA_PROJ_UNIT_H