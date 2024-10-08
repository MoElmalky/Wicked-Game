#pragma once
#include "gameObject.h"
#include <iostream>
#include <chrono>

struct Sprite
{
	int texture;
	Rectangle rec;
};

enum Textures {
	Terrain,
	water,
	foam
};

class Sprites {
private:
	
	
public:
	Sprites();
	~Sprites();
	static void unloadTextures();
	static void DrawSprite(const Sprite&, const float& x, const float& y);
	static void DrawFoam(const float& x, const float& y);
	static Texture& getTexture(int texture);
	inline static Texture terrain = { 0 };
	inline static Texture water = { 0 };
	inline static Texture foam = { 0 };
	inline static Sprite grass_topLeft = { Terrain,{0,0,64,64 } };
	inline static Sprite grass_top = { Terrain,{64,0,64,64 } };
	inline static Sprite grass_topRight = { Terrain,{128,0,64,64 } };
	inline static Sprite grass_left = { Terrain,{0,64,64,64 } };
	inline static Sprite grass_mid = { Terrain,{64,64,64,64 } };
	inline static Sprite grass_right = { Terrain,{128,64,64,64 } };
	inline static Sprite grass_bottomLeft = { Terrain,{0,128,64,64 } };
	inline static Sprite grass_bottom = { Terrain,{64,128,64,64 } };
	inline static Sprite grass_bottomRight = { Terrain,{128,128,64,64 } };
};
