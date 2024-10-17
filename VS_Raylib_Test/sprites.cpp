#include "sprites.h"

Sprites::Sprites() {

}

Sprites::~Sprites() {
	
}

void Sprites::unloadTextures() {
	UnloadTexture(terrain);
	UnloadTexture(foam);
	UnloadTexture(water);
	UnloadTexture(goblin);
}

void Sprites::DrawSprite(const Sprite& sprite, const float& x, const float& y) {
	DrawTextureRec(getTexture(sprite.texture), sprite.rec, { x,y }, WHITE);
}

Texture& Sprites::getTexture(int texture) {
	switch (texture)
	{
	case Textures::Terrain:
		if (!terrain.height) { terrain = LoadTexture("assets/terrain.png"); std::cout << "GAME: Loading Texture.\n"; }
		return terrain;
	case Textures::Water:
		if (!water.height) water = LoadTexture("assets/water.png");
		return water;
	case Textures::Foam:
		if (!foam.height) foam = LoadTexture("assets/foam.png");
		return foam;
	case Textures::goblin:
		if (!goblin.height) goblin = LoadTexture("assets/goblin.png");
		return goblin;
	case Textures::player:
		if (!player.height) player = LoadTexture("assets/player.png");
		return player;
	}
}

void Sprites::DrawFoam(const float& x, const float& y) {
	static auto previousTime = std::chrono::system_clock::now();
	static auto currentTime = std::chrono::system_clock::now();
	static int currentFrame = 0;
	static Rectangle rec = { 0.0f,0.0f,192.0f,192.0f };
	static float elapsedTime;
	currentTime = std::chrono::system_clock::now();
	elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime).count();
	if (elapsedTime >= 1000.0f / 8.0f) {
		++currentFrame %= 8; 
		previousTime = std::chrono::system_clock::now();
		rec = { 192.0f * currentFrame,0.0f,192.0f,192.0f };
	}
	DrawTextureRec(getTexture(Textures::Foam), rec, { x,y }, WHITE);
}