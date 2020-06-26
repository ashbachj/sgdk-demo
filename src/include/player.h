#ifndef PLAYER_H_
#define PLAYER_H_

#include <genesis.h>
#include "position.h"

struct Player {
  struct Position position;
  struct Sprite* sprite;
};

// TODO: add hitbox/hurtbox logic

#endif
