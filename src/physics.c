#include <genesis.h>
#include "include/physics.h"
#include "include/util.h"

struct Position playerPosition;
int xVelocity;
int yVelocity;
int isOnGround;
int canJump;
const int xAcceleration = 2;
const int xFriction = -1;
const int gravity = 1;
const int xMaxVelocity = 12;
const int yMaxVelocity = -8;
const int yMinPosition = 136;

void initializePhysics()
{
  playerPosition.x = 40;
  playerPosition.y = 136;
  xVelocity = 0;
  yVelocity = 0;
  isOnGround = 1;
  int canJump = 1;
}

struct Position getPlayerPosition()
{
  return playerPosition;
}

void updatePhysics(int xDirection,
                   int yDirection,
                   Sprite *player)
{
  if (yDirection && isOnGround && canJump) {
    yVelocity = yMaxVelocity;
    isOnGround = 0;
    canJump = 0;
  }
    
  xVelocity = xDirection*xAcceleration;
  if (xVelocity > 0) {
    xVelocity -= xFriction;
  } else if (xVelocity < 0) {
    xVelocity += xFriction;
  }
  if (xVelocity < -xMaxVelocity) {
    xVelocity = -xMaxVelocity;
  } else if (xVelocity > xMaxVelocity) {
    xVelocity = xMaxVelocity;
  }

  yVelocity += gravity;
  if (isOnGround) {
    yVelocity = 0;
  }
  else if (yVelocity > -yMaxVelocity) {
    yVelocity = -yMaxVelocity;
  }
  
  playerPosition.x += xVelocity;
  playerPosition.y += yVelocity;

  if (playerPosition.x < LEFT_EDGE) {
    playerPosition.x = LEFT_EDGE;
  } else if (playerPosition.x > SCREEN_PIXEL_WIDTH-CHARACTER_WIDTH) {
    playerPosition.x = SCREEN_PIXEL_WIDTH-CHARACTER_WIDTH;
  }
  if (playerPosition.y > yMinPosition - 8) {
    if (!yDirection) {
      canJump = 1;
    }
    if (playerPosition.y > yMinPosition) {
      playerPosition.y = yMinPosition;
      isOnGround = 1;
    }
  }

  SPR_setPosition(player, playerPosition.x, playerPosition.y);
}
