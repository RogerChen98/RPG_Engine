#include "IEntity.h"

IEntity::IEntity() = default;

IEntity::~IEntity() = default;

const string &IEntity::getName() const {
    return name;
}

Posn* IEntity::getPosition() {
    return position;
}

bool IEntity::isVisible() {
    return visible;
}

void IEntity::enableVisibility() {
    visible = true;
}

void IEntity::disableVisibility() {
    visible = false;
}

void IEntity::setPosition(unsigned int a, unsigned int b) {
    position = new Posn(a, b);
}

bool IEntity::is_item() {
    return item;
}