#include "mcpe/client/renderer/TileTessellator.h"

bool TileTessellator::tessellateBeaconInWorld(Tile* tile, TilePos const& pos){
	useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	
	forcedUV = tile->getTextureUVCoordinateSet("glass", 0);
	setRenderBounds(0, 0, 0, 1, 1, 1); 
    tessellateBlockInWorld(tile, pos);
	forcedUV = tile->getTextureUVCoordinateSet("diamond_block", 0);//beacon
	setRenderBounds(0.125, 0, 0.125, 0.875, 0.1875, 0.875); 
	tessellateBlockInWorld(tile, pos);
	forcedUV = tile->getTextureUVCoordinateSet("Obsidian", 0);//beacon
    setRenderBounds(0.1875, 0.1875, 0.1875, 0.8125, 0.8125, 0.8125);
	tessellateBlockInWorld(tile, pos);
	if(tileSource->getTilePtr(x,y-1,z)->id==43 && tileSource->getTilePtr(x,y-1,z-1)->id==43 && tileSource->getTilePtr(x,y-1,z+1)->id==43 && tileSource->getTilePtr(x-1,y-1,z)->id==43 && tileSource->getTilePtr(x+1,y-1,z)->id==43 && tileSource->getTilePtr(x-1,y-1,z-1)->id==43 && tileSource->getTilePtr(x+1,y-1,z-1)->id==43 && tileSource->getTilePtr(x-1,y-1,z-1)->id==43 && tileSource->getTilePtr(x-1,y-1,z+1)->id==43 && tileSource->getTilePtr(x+1,y-1,z-1)->id==43 && tileSource->getTilePtr(x+1,y-1,z+1)->id==43){
		forcedUV = tile->getTextureUVCoordinateSet("glass", 0);
		setRenderBounds(0.375, 0.8125, 0.375, 0.625, 256, 0.625); 
		tessellateBlockInWorld(tile, pos);
		forcedUV = tile->getTextureUVCoordinateSet("redstone_block", 0);
        setRenderBounds(0.3125, 0.8125, 0.3125, 0.6875, 256, 0.6875); 
		tessellateBlockInWorld(tile, pos);
	}
	useForcedUV = false;
	return true;
}
