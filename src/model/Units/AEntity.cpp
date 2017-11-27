#include "AEntity.h"

AEntity::AEntity() {

}

AEntity::~AEntity() {

}

const string &AEntity::getName() const {
    return name;
}

Point AEntity::getPosition() {
    return position;
}

bool AEntity::isVisible() {
    return visible;
}

void AEntity::enableVisibility() {
    visible = true;
}

void AEntity::disableVisibility() {
    visible = false;
}