#pragma once

#include <string>

class Level;
class Mob;
class TileSource;
class Vec3;
class Vec2;

// Size : 88
class MobFactory {
public:
	MobFactory(Level &);
	std::string getMobNameID(int);
//	void postProcessSpawnMobs(TileSource&, int, int, Random*);
	void addMob(std::unique_ptr<Mob, std::default_delete<Mob> >, bool);
	void tick(Player&);
	Entity* CreateMob(int, TileSource &, const Vec3 &, Vec2 *);
	void _categoryID(int);
	//void popCapAllows(Player&, MobSpawnerData const&, bool) const;
};
