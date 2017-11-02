//
// Created by Andrew Alcala on 11/9/2017.
//

#ifndef CS3520_2017FA_PROJ_MAPCELL_H
#define CS3520_2017FA_PROJ_MAPCELL_H


#include "../Units/IEntity.h"

class MapCell {
public:
    MapCell(Posn* position, bool walkable);

    MapCell(Posn* position, IEntity* c_entity, bool walkable);

    Posn getPosition();

    IEntity getEntity();

    void setEntity(const IEntity& entity);

    bool isWalkable();

    void setWalkability(bool new_walkable);

    bool isRandomEncounterable();

    void setRandomEncounters(bool encounter);

    void draw();


private:
    Posn* position;
    IEntity* c_entity;
    bool walkable;
    bool randomEncounterable;
};


#endif //CS3520_2017FA_PROJ_MAPCELL_H
