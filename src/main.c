#include <genesis.h>
#include "include/tiles.h"
#include "include/util.h"
#include "include/background.h"
#include "include/joypad.h"
#include "include/physics.h"

// resources.h is generated from resources.res
#include "resources.h"

Sprite* player;

int main()
{ 
  VDP_init();
  char debug[20];

  VDP_setScreenWidth320();
  VDP_setScreenHeight224();

  VDP_setTextPlan(PLAN_WINDOW);
  VDP_setWindowAddress(0xD000);
  VDP_setAPlanAddress(0xC000);
  VDP_setBPlanAddress(0xE000);
  VDP_setHScrollTableAddress(0xF000);
  VDP_setSpriteListAddress(0xFC00);
  VDP_setWindowHPos(0, 1);
  VDP_setWindowVPos(0, 27);
  

  JOY_init();
  JOY_setEventHandler( &joyHandler );
  
  SPR_init(0,0,0);

  VDP_setHilightShadow(0);
  VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);

  background_init(getPlayerPosition().x, getPlayerPosition().y);
  
  VDP_setPalette(PAL2, sheela.palette->data);
  player = SPR_addSprite(&sheela,
                         getPlayerPosition().x,
                         getPlayerPosition().y,
                         TILE_ATTR(PAL2, TRUE, FALSE, FALSE));

  while(1) {
    updatePhysics(xDirection, yDirection, player);
    sprintf(debug,"xv: %d, yv: %d", getPlayerPosition().x, getPlayerPosition().y);
    VDP_clearText(0,0,20);
    VDP_drawText(debug, 0, 0);
//    VDP_clearTextBG(PLAN_WINDOW, 0, 0, 20);
//    VDP_drawTextBG(PLAN_WINDOW, debug, 0, 0);
    SPR_update();
    background_update(getPlayerPosition().x, getPlayerPosition().y);
    background_updateVDP();
    VDP_waitVSync();
  }
  
  return 0;
}
