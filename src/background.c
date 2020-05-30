#include <genesis.h>
#include "include/util.h"
#include "include/background.h"
// resources.h is generated from resources.res
#include "resources.h"

void background_init(int xPosition, int yPosition)
{
  fgCameraPixelX = xPosition;
  fgCameraPixelY = 28;
  fgCameraLimitPixelX = 1024;
  fgCameraLimitPixelY = 480;
  VDP_loadTileSet(groundtile.tileset, 3, DMA);
  VDP_setPalette(PAL_BG, groundtile.palette->data);
  for (int i = 0; i < 64; i += 2) {
    VDP_fillTileMapRectInc(PLAN_B,
                           TILE_ATTR_FULL(PAL_BG, 0, FALSE, FALSE, 3),
                           i,
                           PIXEL_TO_TILE(fgCameraPixelY)+2,
                           2,
                           2);
  }
  VDP_fillTileMapRect(PLAN_B,
                      TILE_ATTR_FULL(PAL_BG, 0, FALSE, FALSE, 5),
                      0,
                      PIXEL_TO_TILE(fgCameraPixelY)+3,
                      64,
                      7);
}

void background_update(int xPosition, int yPosition)
{
  fgCameraPixelX = xPosition;
  fgCameraPixelY = yPosition;
  updateCamera();
}

void background_updateVDP()
{
  // Foreground
  VDP_setHorizontalScroll(PLAN_A, -fgCameraPixelX);
  VDP_setVerticalScroll(PLAN_A, fgCameraPixelY);
  
  // Background, scrolls at half the rate.
  VDP_setHorizontalScroll(PLAN_B, -(fgCameraPixelX >> 1));
  VDP_setVerticalScroll(PLAN_B, fgCameraPixelY);
}

void updateCamera()
{
    // TODO -- Calculate the camera's position based on the player's current position.

    // TODO -- Make sure the camera's position doesn't go below zero (for this demo we do this in JoypadHandler).

    if (fgCameraPixelX > fgCameraLimitPixelX)
    {
      fgCameraPixelX = 0;
    } else if (fgCameraPixelX < 0) {
      fgCameraPixelX = 0;
    }

    if (fgCameraPixelY > fgCameraLimitPixelY)
    {
      fgCameraPixelY = 0;
    } else if (fgCameraPixelY < 0) {
      fgCameraPixelY = 0;
    }

    fgCameraTileX = PIXEL_TO_TILE(fgCameraPixelX);
    fgCameraTileY = PIXEL_TO_TILE(fgCameraPixelY);

    bgCameraTileX = PIXEL_TO_TILE(fgCameraPixelX >> 1);
    bgCameraTileY = PIXEL_TO_TILE(fgCameraPixelY >> 1);
}

int getCameraY() {
  return fgCameraPixelY;
}
