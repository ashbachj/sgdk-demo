#include <genesis.h>
#include "include/tiles.h"
#include "include/util.h"
#include "include/background.h"

// resources.h is generated from resources.res
#include "resources.h"

int xPosition = 40;
int yPosition = 136;
int xVelocity = 0;
int yVelocity = 0;
int xDirection = 0;
int isOnGround = 1;
const int xAcceleration = 2;
const int xFriction = -1;
const int gravity = 1;
const int xMaxVelocity = 12;
const int yMaxVelocity = -8;
const int yMinPosition = 136;

Sprite* player;

void joyHandler( u16 joy, u16 changed, u16 state)
{
  if (joy == JOY_1)
  {
    // Change state of player based on input
    if (state & BUTTON_RIGHT)
    {
      // move right
      xDirection= 1;
    }
    else if (state & BUTTON_LEFT)
    {
      // move left
      xDirection = -1;
    }
    else { // button released
      if ( (changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) )
      {
        // stop x motion
        xDirection = 0;
      }
    }
    
    if ((state & changed & BUTTON_UP) && isOnGround)
    {
      // move up
      yVelocity = yMaxVelocity;
      isOnGround = 0;
    }
  }
}

void updatePhysics()
{
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
  
  xPosition += xVelocity;
  yPosition += yVelocity;

  if (xPosition < LEFT_EDGE) {
    xPosition = LEFT_EDGE;
  } else if (xPosition > SCREEN_PIXEL_WIDTH-CHARACTER_WIDTH) {
    xPosition = SCREEN_PIXEL_WIDTH-CHARACTER_WIDTH;
  }
  if (yPosition > yMinPosition) {
    yPosition = yMinPosition;
    isOnGround = 1;
  }

  SPR_setPosition(player, xPosition, yPosition);
}

int main()
{ 
  VDP_init();
  char debug[20];

  VDP_setScreenWidth320();
  VDP_setScreenHeight224();

  VDP_setTextPlan(PLAN_B);
  VDP_setWindowAddress(0xD000);
  VDP_setWindowHPos(0, 0);
  VDP_setWindowVPos(1, 27);
  
  JOY_init();
  JOY_setEventHandler( &joyHandler );
  
  SPR_init(0,0,0);

  VDP_setHilightShadow(0);
  VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);
  
  //VDP_drawImageEx(PLAN_A, &moon, TILE_ATTR_FULL(PAL1, 0, 0, 0, 1), 20, 20, 0, CPU);
/*  VDP_setPalette(PAL0, PAL_TEST_BG);
  VDP_setPalette(PAL1, PAL_TEST_FG);
  PAL_setColor((PAL1 * 16), 0x0e00);
*/
  background_init();
  
  VDP_setPalette(PAL2, sheela.palette->data);
  player = SPR_addSprite(&sheela,
                xPosition,
                yPosition,
                TILE_ATTR(PAL2, TRUE, FALSE, FALSE));

  while(1) {
    updatePhysics();
    sprintf(debug,"xv: %d, yv: %d", xVelocity, yVelocity);
    VDP_clearText(2,2,20);
    VDP_drawText(debug, 2, 2);
//    VDP_clearTextBG(PLAN_WINDOW, 0, 0, 20);
//    VDP_drawTextBG(PLAN_WINDOW, debug, 0, 0);
    SPR_update();
    background_update(xVelocity, yVelocity);
    VDP_waitVSync();
    background_updateVDP();
  }
  
  return 0;
}
