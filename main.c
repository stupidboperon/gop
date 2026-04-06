#include <genesis.h>


int main(bool hardReset){
    VDP_drawText("beebo", 12, 12);

    while(1){
        // always call this method at the end of the frame
        SYS_doVBlankProcess();
    }

    return 0;
}
