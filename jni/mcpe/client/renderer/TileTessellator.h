#pragma once
#include <string>
#include <functional>

class Tessellator;
#include "../../util/TilePos.h"
#include "../../tile/Tile.h"
#include "../../level/TileSource.h"
#include "../../util/Vec3.h"
#include "texture/TextureUVCoordinateSet.h"
#include "../../util/AABB.h"
#include "../../util/DataID.h"

class TileTessellator {
public:

    bool forceOpaque; // 0
    bool mirror; // 1
    TileSource* tileSource; // 4
    TextureUVCoordinateSet forcedUV; // 8
    bool useForcedUV; // 40
    char filler[88]; // 44
    int rotBottom; // 132
    int rotTop; // 136
    int rotEast; // 140
    int rotWest; // 144
    int rotNorth; // 148
    int rotSouth; // 152
    char filler1[512]; // 156
    Tessellator* tess; // 668
    AABB bounds; // 672
	
	bool tessellateInWorld(Tile*, const TilePos&, unsigned char, bool);
	bool tessellateBlockInWorld(Tile*, const TilePos&);
	bool tessellateRowTexture(Tile*, unsigned char, float, float, float);
	bool tessellateRowInWorld(Tile*, const TilePos&, unsigned char);
	bool tessellateCrossPolyInWorld(Tile*, TilePos const&, unsigned char, bool);
	bool tessellateCrossPolyTexture(TextureUVCoordinateSet const&, Vec3 const&, bool, Tile*);
	bool isSolidRender(Tile const*);
	bool tessellateCrossInWorld(Tile*, const TilePos&, unsigned char, bool);
	bool tessellateCrossTexture(Tile*, unsigned char, float, float, float, bool);
	bool tessellateCrossTexture(TextureUVCoordinateSet const&, float, float, float, bool, Tile*, float);
	void renderFaceUp(Tile*, const Vec3&, const TextureUVCoordinateSet&);
    void tessellateTorch(Tile*, float, float, float, float, float);
    void tex1(unsigned int);
    DataID getData(const TilePos&) const;
    unsigned int getLightColor(const TilePos&);

	void setRenderBounds(float x1, float y1, float z1, float x2, float y2, float z2) {
		bounds = AABB(x1, y1, z1, x2, y2, z2);
	}
	
	/*render functions*/
	bool tessellateBeaconInWorld(Tile*, TilePos const&);
};
