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

    ~MapCell();

    Posn* getPosition();

    IEntity* getEntity();

    void setEntity(IEntity* entity);

    bool isWalkable();

    void setWalkability(bool new_walkable);

    void setIsEmpty(bool empty);

    bool isRandomEncounterable();

    void setRandomEncounters(bool encounter);

    bool isEmpty();

    void draw();



private:
    Posn* position;
    IEntity* c_entity;
    bool walkable;
    bool empty;
    bool randomEncounterable;
};


#endif //CS3520_2017FA_PROJ_MAPCELL_H
