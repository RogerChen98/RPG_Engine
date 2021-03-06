//
// Created by Andrew Alcala on 11/8/2017.
//

#include "World.h"
#include "../Units/NPCUnit.h"
#include <random>

/**
 * World Creation method.
 */
World::World() {
    worldMap = new WorldMap(1);
    this->curInventorySize = 0;
    NPCUnit *npcUnit = new NPCUnit(DIALOGUE, new Posn(0, 0), "GET THE LEGENDARY COW", "HI");
    Item *item = new Item("The Legendary Cow", "Description");
    EnemyUnit *enemyUnit = new EnemyUnit(1, 2, 3, 4, false, "Georgina", nullptr);
    Spell *spell = new Spell("Punch", 10, 2, 100, 100, DAMAGE, PHYSICAL);
    Spell *spell2 = new Spell("MegaPunch", 10, 2, 100, 100, DAMAGE, MAGICAL);
    enemyUnit->addSpell(spell);

    worldMap->setEnemy(enemyUnit);
    int cow_x = (rand() % 14) + 15;
    int cow_y = (rand() % 14) + 15;


    worldMap->getWorldMap()[10][5]->setEntity(npcUnit);
    worldMap->getWorldMap()[cow_x][cow_y]->setEntity(item);
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j < 30; j++) {
            int random_number = rand() % 100;
            if (random_number > 90) {
                worldMap->getWorldMap()[i][j]->setWalkability(false);
            }
        }
    }
    worldMap->getWorldMap()[10][10]->setWalkability(false);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            int random_number = rand() % 100;
            if (random_number > 70) {
                worldMap->getWorldMap()[i][j]->setRandomEncounters(true);
            }
        }
    }
    Posn *starting_point = new Posn(0, 0);
    vector<Equipment> *equipmentList;
    Spell **spellList = new Spell*[4];
    this->inventory = new Item *[INVENTORY_SLOTS];
    //TODO: probably need new here.
    this->player = new PlayerUnit("Twen", starting_point, STARTING_VIT, STARTING_INT, STARTING_DEX,
                                  STARTING_STR, STARTING_LVL, true, equipmentList, spellList, STARTING_MOD_VIT,
                                  STARTING_MOD_INT, STARTING_MOD_DEX, STARTING_MOD_STR);
    player->addSpell(spell);
    player->addSpell(spell2);
    this->gameState = OVERWORLD;
    this->curMenuOption = 0;

}

PlayerUnit *World::getPlayer() const {
    return player;
}

WorldMap World::getWorldMap() const {
    return *worldMap;
}

game_state_t World::getCurrentGameState() const {
    return gameState;
}

bool World::isGameOver() {
    return gameOver;
}

void World::onTick(int currTick) {

}


bool World::addToInventory(Item *item) {
    if (curInventorySize == INVENTORY_SLOTS) {
        return false;
    } else {
        inventory[curInventorySize] = std::move(item);
        curInventorySize++;
        return true;
    }
}

void World::trash(int i) {
    Item *trash = inventory[i];
    inventory[i] = inventory[curInventorySize];
    inventory[curInventorySize] = trash;
    curInventorySize--;
    delete trash;
}

void World::movePlayer(direction_t direction) {
    this->player->setDirection(direction);
    switch (direction) {
        case UP:
            if (this->player->getPosition()->getY() != 0 &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX()]
                [this->player->getPosition()->getY() - 1]->isWalkable()) {
                this->player->getPosition()->setY(this->player->getPosition()->getY() - 1);
            }
            break;
        case DOWN:
            if (this->player->getPosition()->getY() != worldMap->WORLDMAP_HEIGHT &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX()]
                [this->player->getPosition()->getY() + 1]->isWalkable()) {
                this->player->getPosition()->setY((this->player->getPosition()->getY() + 1));
            }
            break;
        case LEFT:
            if (this->player->getPosition()->getX() != 0 &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX() - 1]
                [this->player->getPosition()->getY()]->isWalkable()) {
                this->player->getPosition()->setX((this->player->getPosition()->getX() - 1));
            }
            break;
        case RIGHT:
            if (this->player->getPosition()->getX() != worldMap->WORLDMAP_WIDTH &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX() + 1]
                [this->player->getPosition()->getY()]->isWalkable()) {
                this->player->getPosition()->setX((this->player->getPosition()->getX() + 1));
            }
            break;
        default:
            break;
    }

    // Check for Random Encounter?
    MapCell ***map = worldMap->getWorldMap();
    auto x = player->getPosition()->getX();
    auto y = player->getPosition()->getY();
    if (map[x][y]->isRandomEncounterable()) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0.0, 10.0);
        int random_number = dist(mt); // Between 0 and 9
        if (random_number == 1) {

            cout << "*:*:*:ENTERING BATTLE:*:*:*" << endl;
            // initiate a battle sequence
//            std::random_device rd;
//            std::mt19937 mt(rd());
//            cout << "eat my shorts" << endl;
//            std::uniform_real_distribution<int> dist(0, this->getWorldMap().getCurSize());
//            cout << "eat my shorts" << endl;
//            int random_enemy = dist(mt);
//            cout << "eat my shorts" << endl;
            this->curEnemy = this->getWorldMap().getEnemies()[0];
            cout << "A WILD " << this->curEnemy->getName() << " HAS APPEARED!" << endl;
            cout << this->curEnemy->getName() << " HP: " <<  this->curEnemy->get_health() << endl;

            this->setCurrentGameState(BATTLE);
            cout << "WHAT WILL YOU DO?" << endl;
            this->curMenuOption = 0;
            cout << this->curMenuOption + 1 << ": " << this->menuStrings[this->curMenuOption] << endl;

        }
    }
}

EnemyUnit *World::getEnemyUnit() {
    return this->curEnemy;
}

Item **World::getInventory() {
    return this->inventory;
}

void World::setCurrentGameState(game_state_t newGameState) {
    this->gameState = newGameState;
}

World::~World() {
    delete this->player;
    delete this->worldMap;
}
