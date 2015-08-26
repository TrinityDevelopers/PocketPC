#pragma once

#include "TileID.h"

class FullTile
{
public:
	static FullTile AIR;

public:
	TileID id;
	unsigned char damage;

public:
	FullTile() : id(0), damage(0) {};
	FullTile(TileID id, unsigned char damage) : id(id), damage(damage) {}
};
