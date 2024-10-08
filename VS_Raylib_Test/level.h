#pragma once
#include <vector>
#include "gameObject.h"

using std::vector;

class Level {
protected:
	vector<GameObject*> gameObjects;
	int height;
	int width;
public:
	Level() { height = 0; width = 0; }
	~Level() {}
	virtual void drawLevel(const float&) const = 0;
	virtual void updateLevel(const float&) = 0;
};

