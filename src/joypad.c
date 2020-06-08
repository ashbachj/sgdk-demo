#include <genesis.h>
#include "include/joypad.h"

xDirection = 0;
yDirection = 0;

void joyHandler( u16 joy, u16 changed, u16 state)
{
  if (joy == JOY_1)
  {
    // Change state of player based on input
    if (state & BUTTON_RIGHT)
    {
      xDirection= 1;
    }
    else if (state & BUTTON_LEFT)
    {
      xDirection = -1;
    }
    else { // button released
      if ( (changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) )
      {
        xDirection = 0;
      }
    }

    if (state & BUTTON_A)
    {
      yDirection = -1;
    } else {
      yDirection = 0;
    } 
  }
}
