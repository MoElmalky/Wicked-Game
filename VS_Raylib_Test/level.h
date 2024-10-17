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
	virtual ~Level() {}
	virtual void DrawLevel() const = 0;
	virtual void UpdateLevel(const float&) = 0;
};

