#include <genesis.h>
#include "include/util.h"
#include "include/background.h"
// resources.h is generated from resources.res
#include "resources.h"

void background_init()
{
  fgCameraPixelX = 0;
  fgCameraPixelY = 0;
  fgCameraLimitPixelX = 1024;
  fgCameraLimitPixelY = 480;
  VDP_loadTileSet(groundtile.tileset, 3, DMA);
  VDP_setPalette(PAL_BG, groundtile.palette->data);
  VDP_fillTileMapRectInc(PLAN_A,
                         TILE_ATTR_FULL(PAL_BG, 0, FALSE, FALSE, 3),
                         15,
                         15,
                         2,
                         3);
}

void background_update(int xVelocity, int yVelocity)
{
  fgCameraPixelX += xVelocity;
  fgCameraPixelY += yVelocity;
  updateCamera();
}

void background_updateVDP()
{
  // Foreground
  VDP_setHorizontalScroll(PLAN_A, -fgCameraPixelX);
  VDP_setVerticalScroll(PLAN_A, fgCameraPixelY);
  
  // Background, scrolls at half the rate.
  VDP_setHorizontalScroll(PLAN_B, -(fgCameraPixelX >> 1));
  VDP_setVerticalScroll(PLAN_B, (fgCameraPixelY >> 1));
}

void updateCamera()
{
    // TODO -- Calculate the camera's position based on the player's current position.

    // TODO -- Make sure the camera's position doesn't go below zero (for this demo we do this in JoypadHandler).

    if (fgCameraPixelX > fgCameraLimitPixelX)
    {
        fgCameraPixelX = fgCameraLimitPixelX;
    }

    if (fgCameraPixelY > fgCameraLimitPixelY)
    {
        fgCameraPixelY = fgCameraLimitPixelY;
    }

    fgCameraTileX = PIXEL_TO_TILE(fgCameraPixelX);
    fgCameraTileY = PIXEL_TO_TILE(fgCameraPixelY);

    bgCameraTileX = PIXEL_TO_TILE(fgCameraPixelX >> 1);
    bgCameraTileY = PIXEL_TO_TILE(fgCameraPixelY >> 1);
}
