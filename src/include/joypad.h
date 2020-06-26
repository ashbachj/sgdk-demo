#ifndef JOYPAD_H_
#define JOYPAD_H_

#include <genesis.h>

extern int playEffect;
extern int xDirection;
extern int yDirection;

void joyHandler( u16 joy, u16 changed, u16 state);

#endif
