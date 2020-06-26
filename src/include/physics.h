#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <genesis.h>
#include "position.h"

struct Position getPlayerPosition();

void updatePhysics(int xDirection,
                   int yDirection,
                   Sprite *player);

#endif
