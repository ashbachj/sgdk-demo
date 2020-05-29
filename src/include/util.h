#ifndef UTIL_H
#define UTIL_H

#define LEFT_EDGE 0
#define TOP_EDGE 0

#define SCREEN_PIXEL_WIDTH 320
#define SCREEN_PIXEL_HEIGHT 224

#define SCREEN_TILE_WIDTH 40
#define SCREEN_TILE_HEIGHT 28

#define SCREEN_TILE_WIDTH_PLUS_ONE 41
#define SCREEN_TILE_HEIGHT_PLUS_ONE 29

#define CHARACTER_WIDTH 16

#define TILE_TO_PIXEL(x) ((x) << 3)
#define PIXEL_TO_TILE(x) ((x) >> 3)

#endif
