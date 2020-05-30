#ifndef BACKGROUND_H
#define BACKGROUND_H

#define PAL_FG PAL1
#define PAL_BG PAL0

#define PLANE_FG VDP_PLAN_A
#define PLANE_BG VDP_PLAN_B

u32 fgCameraPixelX;
u32 fgCameraPixelY;
u16 fgCameraTileX;
u16 fgCameraTileY;
u16 bgCameraTileX;
u16 bgCameraTileY;
u32 fgCameraLimitPixelX;
u32 fgCameraLimitPixelY;

void background_init(xPosition, yPosition);
void background_update(int xVelocity, int yVelocity);
void background_updateVDP();
void updateCamera();
int getCameraY();

#endif
