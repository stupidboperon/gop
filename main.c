#include <genesis.h>
#include <gfx.h>

u16 ind=TILE_USER_INDEX;

int main(bool hardReset){
    SYS_disableInts();VDP_setScreenWidth320();
    
    int beebind = ind;
    VDP_loadTileSet(img_beebo.tileset,ind,DMA);
    ind+=img_beebo.tileset->numTile;
    TileMap *beebmap = unpackTileMap(img_beebo.tilemap,NULL);
    VDP_setTileMapEx(BG_A, beebmap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, beebind), 0, 0,  0, 0, 10, 19, CPU);
    PAL_setColors(0,(u16*)img_beebo.palette->data,16,CPU);
    
    VDP_drawText("beebo", 0, 0);
    SYS_enableInts();

    while(1){
        // always call this method at the end of the frame
        SYS_doVBlankProcess();
    }

    return 0;
}
