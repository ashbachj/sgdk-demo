#include <genesis.h>
void main() {
VDP_init();
VDP_drawText("Hello World!", 2, 2);
while(1) {
VDP_waitVSync();
}
return 0;
}
