#include "levels.h"
#include <iostream>

Level_1::Level_1(int width, int height) {
	this->width = width;
	this->height = height;
	std::cout << "GAME: Level 1 Inisialized.\n";
	gameObjects.push_back(new Goblin({200,200}));
	gameObjects.push_back(new Goblin({40,40}));
}

Level_1::~Level_1() {

	std::cout << "GAME: Deleting Level 1 Game Objects.\n";
	for (auto &gameObject : gameObjects) {
		std::cout << "GAME: Game Object " << gameObject->GetID() << "Deleted\n";
		delete gameObject;
	}
}

void Level_1::DrawLevel() const {
	static bool print = true;
	for (int x = 0; x < width; x++) {
		Sprites::DrawFoam((x - 1) * 64, - 64);
		Sprites::DrawFoam((x - 1) * 64, (height - 2) * 64);
	}
	for (int y = 1; y < height-1; y++) {
		Sprites::DrawFoam(-64, (y - 1) * 64);
		Sprites::DrawFoam((width - 2) * 64, (y - 1) * 64);
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (y == 0) {
				if (x == 0) {
					Sprites::DrawSprite(Sprites::grass_topLeft, x * 64, y * 64);
				}
				else if (x == width - 1) {
					Sprites::DrawSprite(Sprites::grass_topRight, x * 64, y * 64);
				}
				else {
					Sprites::DrawSprite(Sprites::grass_top, x * 64, y * 64);
				}
			}
			else if (y == width - 1) {
				if (x == 0) {
					Sprites::DrawSprite(Sprites::grass_bottomLeft, x * 64, y * 64);
				}
				else if (x == width - 1) { 
					Sprites::DrawSprite(Sprites::grass_bottomRight, x * 64, y * 64);
				}
				else {
					Sprites::DrawSprite(Sprites::grass_bottom, x * 64, y * 64);
				}
			}
			else {
				if (x == 0) { 
					Sprites::DrawSprite(Sprites::grass_left, x * 64, y * 64);
				}
				else if (x == width - 1) {
					Sprites::DrawSprite(Sprites::grass_right, x * 64, y * 64);
				}
				else Sprites::DrawSprite(Sprites::grass_mid, x * 64, y * 64);
			}
		}
	}

	for (auto &gameObject : gameObjects) {
		gameObject->Draw();
	}

	if (print) {
		std::cout << "GAME: Drawing Terrain.\n";
		print = false;
	}
}

void Level_1::UpdateLevel(const float& dt) {

	for (auto &gameObject : gameObjects) {
		gameObject->Update(dt);
	}
}