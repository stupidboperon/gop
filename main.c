#include <genesis.h>
#include "../resources.h"

u16 ind=TILE_USER_INDEX;

int main(bool hardReset){
    SYS_disableInts();VDP_setScreenWidth320();
    
    int bgind = ind;
    VDP_loadTileSet(img_cloudybg.tileset,ind,DMA);
    ind+=img_cloudybg.tileset->numTile;
    TileMap *bgmap = unpackTileMap(img_cloudybg.tilemap,NULL);
    VDP_setTileMapEx(BG_A, bgmap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, bgind), 0, 0,  0, 0, 40, 28, CPU);
    PAL_setColors(0,(u16*)img_cloudybg.palette->data,16,CPU);
    
    //VDP_drawText("beebo", 0, 0);
    SYS_enableInts();

    while(1){
        // always call this method at the end of the frame
        SYS_doVBlankProcess();
    }

    return 0;
}
