#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include <SDL_ttf.h>
#include "GameWindow.h"
#include "../model/Battle/Battle.h"

GameWindow::GameWindow(string title, unsigned int width, unsigned int height, unsigned int multiplier) {
    this->title = move(title);
    this->width = width;
    this->height = height;
    this->multiplier = multiplier;
    this->game = new World();
    // this calls init and sets the state of closed based on if the window opens properly
    closed = !init();
}

bool GameWindow::init() {
    // attempt to initialize everything
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "Failed to initialize SDL2" << endl;
    }
    /**
    if (TTF_Init() == -1) {
        cerr << "Failed to initialize TTF" << endl;
    }
    **/

    // create a window with the following settings
    window = SDL_CreateWindow(
            title.c_str(),                    // window title
            SDL_WINDOWPOS_CENTERED,           // initial x position
            SDL_WINDOWPOS_CENTERED,           // initial y position
            width * multiplier,               // width, in pixels
            height * multiplier,              // height, in pixels
            SDL_WINDOW_MAXIMIZED
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    // create a renderer and throw an error if it fails to initialize
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    // Check that the renderer was successfully created
    if (renderer == NULL) {
        // In the case that the window could not be made...
        printf("Could not create renderer: %s\n", SDL_GetError());
        return false;
    }

    // return true if everything works
    return true;
}

GameWindow::~GameWindow() {
    // Close and destroy the window and renderer
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    // Clean up
    TTF_Quit();
    SDL_Quit();
}

void GameWindow::pollEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            // quit out of the game
            case SDL_QUIT:
                this->closed = true;
                break;

                // check for specific key press, output based on current game state
            case SDL_KEYDOWN:
                // OVERWORLD
                if (game->getCurrentGameState() == OVERWORLD) {
                    bool moved = false;
                    direction_t direction;
                    switch (event.key.keysym.sym) {
                        // left
                        case SDLK_LEFT: {
                            direction = LEFT;
                            moved = true;
                            break;
                        }
                            // right
                        case SDLK_RIGHT: {
                            direction = RIGHT;
                            moved = true;
                            break;
                        }
                            // up
                        case SDLK_UP: {
                            direction = UP;
                            moved = true;
                            break;
                        }
                            // down
                        case SDLK_DOWN: {
                            direction = DOWN;
                            moved = true;
                            break;
                        }
                            // "P" key: pauses
                        case SDLK_p: {
                            game->setCurrentGameState(MENU);
                            break;
                        }
                        case SDLK_x: {
                            int x = game->getPlayer()->getPosition()->getX();
                            int y = game->getPlayer()->getPosition()->getY();
                            switch (game->getPlayer()->getDirection()) {
                                case UP: {
                                    if (y != 0 && !game->getWorldMap().getWorldMap()[x][y - 1]->isEmpty()) {
                                        cout << game->getWorldMap().getWorldMap()[x][y - 1]->getEntity()->getName()
                                             << endl;
                                        if (game->getWorldMap().getWorldMap()[x][y - 1]->getEntity()->is_item()) {
                                            game->getWorldMap().getWorldMap()[x][y - 1]->setWalkability(true);
                                            game->getWorldMap().getWorldMap()[x][y-1]->setIsEmpty(true);
                                        }
                                    }
                                    break;
                                }
                                case DOWN: {
                                    if (y != game->getWorldMap().WORLDMAP_HEIGHT &&
                                        !game->getWorldMap().getWorldMap()[x][y + 1]->isEmpty()) {
                                        if (game->getWorldMap().getWorldMap()[x][y + 1]->getEntity()->is_item()) {
                                            game->getWorldMap().getWorldMap()[x][y + 1]->setWalkability(true);
                                            game->getWorldMap().getWorldMap()[x][y + 1]->setIsEmpty(true);
                                        }
                                        cout << game->getWorldMap().getWorldMap()[x][y + 1]->getEntity()->getName()
                                             << endl;
                                    }
                                    break;
                                }
                                case LEFT: {
                                    if (x != 0 && !game->getWorldMap().getWorldMap()[x - 1][y]->isEmpty()) {
                                        if (game->getWorldMap().getWorldMap()[x-1][y]->getEntity()->is_item()) {
                                            game->getWorldMap().getWorldMap()[x-1][y]->setWalkability(true);
                                            game->getWorldMap().getWorldMap()[x-1][y]->setIsEmpty(true);
                                        }
                                        cout << game->getWorldMap().getWorldMap()[x - 1][y]->getEntity()->getName()
                                             << endl;
                                    }
                                    break;
                                }
                                case RIGHT: {
                                    if (x != game->getWorldMap().WORLDMAP_WIDTH &&
                                        !game->getWorldMap().getWorldMap()[x + 1][y]->isEmpty()) {
                                        if (game->getWorldMap().getWorldMap()[x+1][y]->getEntity()->is_item()) {
                                            game->getWorldMap().getWorldMap()[x+1][y]->setWalkability(true);
                                            game->getWorldMap().getWorldMap()[x+1][y]->setIsEmpty(true);
                                        }
                                        cout << game->getWorldMap().getWorldMap()[x + 1][y]->getEntity()->getName()
                                             << endl;
                                    }
                                    break;
                                }
                                default:
                                    break;
                            }
                            break;
                        }
                            // default/unused key
                        default: {
                            break;
                        }
                    }

                    // checks if it was movement
                    if (moved) {
                        game->movePlayer(direction);
                    }
                }


                // MENU
                if (game->getCurrentGameState() == MENU) {
                    switch (event.key.keysym.sym) {
                        // TODO: left: move menu
                        case SDLK_LEFT: {
                            break;
                        }
                            // TODO: right: move menu
                        case SDLK_RIGHT: {
                            break;
                        }
                            // "P" key: unpauses
                        case SDL_SCANCODE_P: {
                            game->setCurrentGameState(OVERWORLD);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }


                // BATTLE
                if (game->getCurrentGameState() == BATTLE) {

                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT: {
                            if (game->curMenuOption > 0) {
                                game->curMenuOption--;
                                cout << game->curMenuOption + 1 << ": " << game->menuStrings[game->curMenuOption] << endl;
                            }
                            break;
                        }

                        case SDLK_UP: {
                            if (game->curMenuOption > 1) {
                                game->curMenuOption-= 2;
                                cout << game->curMenuOption + 1 << ": " << game->menuStrings[game->curMenuOption] << endl;
                            }
                            break;
                        }

                        case SDLK_RIGHT: {
                            if (game->curMenuOption < 3) {
                                game->curMenuOption++;
                                cout << game->curMenuOption + 1 << ": " << game->menuStrings[game->curMenuOption] << endl;
                            }
                            break;
                        }

                        case SDLK_DOWN: {
                            if (game->curMenuOption < 2) {
                                game->curMenuOption+= 2;
                                cout << game->curMenuOption + 1 << ": " << game->menuStrings[game->curMenuOption] << endl;
                            }
                            break;
                        }

                        case SDLK_x: {
                            Battle b;
                            PlayerUnit *p = game->getPlayer();
                            EnemyUnit *e = game->getEnemyUnit();

                            if (game->curMenuOption == 0) {
                                b.doBattle(p, e, 0);
                            }
                            if (game->curMenuOption == 1) {
                                b.doBattle(p, e, 1);
                            }
                            if (game->curMenuOption == 2) {
                                cout << "YOU HAVE " << game->curNumPotion << " POTIONS!" << endl;
                                if (game->curNumPotion != 0) {
                                    p->reset();
                                    game->curNumPotion--;
                                    cout << "You Healed" << endl;
                                }
                                b.doBattle(p, e, 4);
                            }
                            if (game->curMenuOption == 3) {
                                game->setCurrentGameState(OVERWORLD);
                                game->getEnemyUnit()->reset();
                                cout << "YOU FLED THE BATTLE. weakling..." << endl;
                            }


                            break;
                        }

                        default: {
                            break;
                        }

                        }
                    if (game->getPlayer()->get_health() == 0) {
                        game->setCurrentGameState(DEAD);
                    } else if (game->getEnemyUnit()->get_health() == 0) {
                        game->setCurrentGameState(OVERWORLD);
                        game->getEnemyUnit()->reset();
                    }
                }

            default:
                break;
        }
    }
}


void GameWindow::drawWorld() const {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    switch (game->getCurrentGameState()) {
        case OVERWORLD: {
            // determine the size of a cell
            SDL_Rect cell = SDL_Rect();
            cell.w = multiplier;
            cell.h = multiplier;

            // draws map
            for (int i = 0; i < game->getWorldMap().WORLDMAP_WIDTH; i++) {
                for (int j = 0; j < game->getWorldMap().WORLDMAP_HEIGHT; j++) {
                    MapCell *curCell = game->getWorldMap().getWorldMap()[i][j];
                    cell.x = i * multiplier;
                    cell.y = j * multiplier;

                    // tall grass
                    if (curCell->isWalkable() && curCell->isRandomEncounterable()) {
                        SDL_SetRenderDrawColor(renderer, 10, 86, 27, 255);

                    // regular walkable terrain
                    } else if(curCell->isWalkable()){
                        SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);
                    }
                    // unwalkable terrain (wall)
                    else{
                        SDL_SetRenderDrawColor(renderer, 217, 83, 79, 255);
                    }
                    // colors in the rectangle after the cell type is determined
                    SDL_RenderFillRect(renderer, &cell);

                    // if there is something in the cell
                    if (!curCell->isEmpty()) {
                        cell.w = multiplier;
                        cell.h = multiplier;

                        // get the position of the cell
                        cell.x = curCell->getPosition()->getX() * multiplier;
                        cell.y = curCell->getPosition()->getY() * multiplier;

                        // color as an item
                        if (curCell->getEntity()->is_item()) {
                            SDL_SetRenderDrawColor(renderer, 238, 216, 150, 255);

                        // color as an npc
                        } else {
                            SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
                        }

                        // draw the unit on top of the cell
                        SDL_RenderFillRect(renderer, &cell);
                    }
                }
            }

            // render the player
            SDL_Rect player = SDL_Rect();
            player.w = multiplier;
            player.h = multiplier;
            // get the position
            player.x = game->getPlayer()->getPosition()->getX() * multiplier;
            player.y = game->getPlayer()->getPosition()->getY() * multiplier;
            // choose the color
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &player);

            // draw the box showing which direction the player is facing
            player.w = multiplier / 3;
            player.h = multiplier / 3;
            switch (game->getPlayer()->getDirection()) {
                case UP: {
                    player.x += player.w;
                    break;
                }
                case DOWN: {
                    player.x += player.w;
                    player.y += multiplier;
                    player.y -= player.h;
                    break;
                }
                case LEFT: {
                    player.y += player.h;
                    break;
                }
                case RIGHT: {
                    player.x += multiplier;
                    player.x -= player.w;
                    player.y += player.h;
                    break;
                }
                default:
                    break;
            }
            SDL_SetRenderDrawColor(renderer, 2, 2, 2, 2);

            SDL_RenderFillRect(renderer, &player);
            break;
        }
        case (BATTLE): {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Rect background = SDL_Rect();
            SDL_Rect cell = SDL_Rect();
            SDL_Rect icon = SDL_Rect();
            // draw Background
            background.w = (game->getWorldMap().WORLDMAP_WIDTH * multiplier);
            background.h = (game->getWorldMap().WORLDMAP_HEIGHT * multiplier);
            background.x = 0;
            background.y = 0;

            SDL_RenderFillRect(renderer, &background);  // draw the background

            // draw the enemy
            SDL_Surface * surface;
            SDL_Texture * texture;

            surface = SDL_LoadBMP("/Users/roger/CLionProjects/CS3520-2017FA-PROJ/src/view/icons/enemyicon/GeorginaTheGoblin.bmp");
            if (!surface) {
                printf("Could not create surface: %s\n", SDL_GetError());
            }

            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if (!texture) {
                printf("Could not create texture: %s\n", SDL_GetError());
            }

            icon.w = background.w / 3;
            icon.h = icon.w;

            icon.x = (background.w / 2) - (icon.w / 2);
            icon.y = ((game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier) - (icon.h / 2);

            // put icon on top of the background
            SDL_RenderCopy(renderer, texture, NULL, &icon);


            // draw Menu Options
            // top left box
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH * multiplier)/2;        // width of an option box
            cell.h = ((game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier)/2; // height of an option box

            // create each box
            for (int i = 0; i < 4; i++) {
                // determine the icon for the ability
                switch (i) {
                    case 0: {
                        surface = SDL_LoadBMP("/Users/roger/CLionProjects/CS3520-2017FA-PROJ/src/view/icons/battleicons/sword.bmp");
                        break;
                    }
                    case 1: {
                        surface = SDL_LoadBMP("/Users/roger/CLionProjects/CS3520-2017FA-PROJ/src/view/icons/battleicons/spell.bmp");
                        break;
                    }
                    case 2: {
                        surface = SDL_LoadBMP("/Users/roger/CLionProjects/CS3520-2017FA-PROJ/src/view/icons/battleicons/potion.bmp");
                        break;
                    }
                    case 3: {
                        surface = SDL_LoadBMP("/Users/roger/CLionProjects/CS3520-2017FA-PROJ/src/view/icons/battleicons/running_man.bmp");
                        break;
                    }
                    default:
                        if (!surface) {
                            printf("Could not create surface: %s\n", SDL_GetError());
                        }
                        break;
                }

                texture = SDL_CreateTextureFromSurface(renderer, surface);
                if (!texture) {
                    printf("Could not create texture: %s\n", SDL_GetError());
                }

                // left boxes
                if (i == 0 || i == 2) {
                    cell.x = 0;
                }

                // right boxes
                if (i == 1 || i == 3) {
                    cell.x = cell.w;
                }

                // top boxes
                cell.y = (game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier * 2;

                // bottom boxes
                if (i == 2 || i == 3) {
                    cell.y += cell.h;
                }

                // create icon
                icon.w = cell.h;                                             // the icon is a square
                icon.h = cell.h;                                             // the icon is a square
                icon.x = cell.x + (cell.w / 2) - (icon.w / 2);               // place in the center
                icon.y = cell.y;                                             // place in the center

                // determine if the current option box is the one being hovered
                if (game->curMenuOption == i) {
                    SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
                } else {
                    SDL_SetRenderDrawColor(renderer, 227, 178, 178, 255);
                }

                // color the box
                SDL_RenderFillRect(renderer, &cell);
                SDL_SetRenderDrawColor(renderer, 249, 249, 249, 255);

                // put icon on top
                SDL_RenderCopy(renderer, texture, NULL, &icon);
            }


            // player health bar outline
            cell.x = 0;
            cell.y = 0;
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier;
            cell.h = multiplier;
            // enemy health bar outline
            SDL_SetRenderDrawColor(renderer, 17, 126, 52, 255);
            SDL_RenderFillRect(renderer, &cell);
            cell.x = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier;
            cell.y = 0;
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier;
            cell.h = multiplier;
            SDL_SetRenderDrawColor(renderer, 197, 40, 0, 255);
            SDL_RenderFillRect(renderer, &cell);
            // player health bar
            cell.x = 0;
            cell.y = 0;
            cell.w = ((game->getWorldMap().WORLDMAP_WIDTH / 2)  *
                     (double) game->getPlayer()->get_health() / (double) game->getPlayer()->get_max_health()) * multiplier - 5;
            cell.h = multiplier - 5;
            SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);
            SDL_RenderFillRect(renderer, &cell);
            //enemy health bar
            cell.x = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier + 5;
            cell.y = 0;
            cell.w = ((game->getWorldMap().WORLDMAP_WIDTH / 2) * (double) game->getEnemyUnit()->get_health()
                     / (double) game->getEnemyUnit()->get_max_health()) * multiplier - 5;
            cell.h = multiplier - 5;
            SDL_SetRenderDrawColor(renderer, 217, 83, 79, 255);
            SDL_RenderFillRect(renderer, &cell);

            break;
        }
        case(DEAD): {
            SDL_Rect screen = SDL_Rect();

            // create the screen
            screen.w = (game->getWorldMap().WORLDMAP_WIDTH * multiplier);
            screen.h = (game->getWorldMap().WORLDMAP_HEIGHT * multiplier);
            screen.x = 0;
            screen.y = 0;

            // draw the screen
            SDL_Surface * surface;
            SDL_Texture * texture;

            surface = SDL_LoadBMP("/Users/roger/CLionProjects/CS3520-2017FA-PROJ/src/view/icons/gameover.bmp");
            if (!surface) {
                printf("Could not create surface: %s\n", SDL_GetError());
            }

            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if (!texture) {
                printf("Could not create texture: %s\n", SDL_GetError());
            }

            // put icon on top of the background
            SDL_RenderCopy(renderer, texture, NULL, &screen);
        }

        default: {
            break;
        }
    }


    SDL_RenderPresent(renderer);
}


