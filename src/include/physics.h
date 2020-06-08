#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <genesis.h>

struct Position {
  int x;
  int y;
};

struct Position getPlayerPosition();

void updatePhysics(int xDirection,
                   int yDirection,
                   Sprite *player);

#endif
