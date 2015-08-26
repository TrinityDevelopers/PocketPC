#pragma once

#include "TileTickingQueue.h"
#include "mcpe/util/FullTile.h"
#include "mcpe/util/TilePos.h"
#include "mcpe/util/DataID.h"
class Tile;

class TileSource {
public:
	FullTile getTile(int, int, int);
	Tile* getTilePtr(int, int, int);
	DataID getData(int, int, int);
	bool setTileAndData(int, int, int, FullTile, int);
	TileTickingQueue* getTickQueue(TilePos const&);
	void updateNeighborsAt(const TilePos &, TileID);
};
