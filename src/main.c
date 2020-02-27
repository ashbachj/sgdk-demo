#include <genesis.h>
#include "include/tiles.h"

void joyHandler( u16 joy, u16 changed, u16 state)
{
  if (joy == JOY_1)
  {
    // Change state of player based on input
    if (state & BUTTON_RIGHT)
    {
      // move right
    }
    else if (state & BUTTON_LEFT)
    {
      // move left
    }
    else if (state & BUTTON_UP)
    {
      // move up
    }
    else if (state & BUTTON_DOWN)
    {
      // move down
    }
    else { // button released
      if ( (changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) )
      {
        // stop x motion
      }
      else if ( (changed & BUTTON_UP) | (changed & BUTTON_DOWN) )
      {
        // stop y motion
      }
    }
  }
}

int main()
{
  VDP_init();
  VDP_drawText("Hello World!", 2, 2);
  JOY_init();
  JOY_setEventHandler( &joyHandler );

  VDP_loadTileData( (const u32 *)tile, 1, 1, 0);
  VDP_setTileMapXY(PLAN_A, 1, 5, 5);

  VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL2, 0, 1, 0, TILE1), 6, 5);
  
  VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL1, 1, 0, 0, TILE1), 7, 7);
  VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL2, 0, 0, 0, TILE1), 7, 7);
  VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE1), 8, 7);
  VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL2, 1, 0, 0, TILE1), 8, 7);
  
  VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL1, 1, 0, 0, 1), 7, 7);
  VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL2, 0, 0, 0, 1), 7, 7);
  VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL1, 0, 0, 0, 1), 8, 7);
  VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL2, 1, 0, 0, 1), 8, 7);
 
  VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL3, 0, 0, 0, TILE1 ), 12, 12, 8, 8); 
  
  while(1) {
    VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL0, 0, 0, 0, TILE1), 12, 1, 4, 4);
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL1, 0, 1, 0, TILE1), 12, 1, 4, 4);
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL2, 0, 0, 0, TILE1), 12, 1, 4, 4);
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL3, 0, 1, 0, TILE1), 12, 1, 4, 4);
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
    VDP_waitVSync();
  }
  
  return 0;
}
