#pragma once
#include "level.h"
#include "sprites.h"
#include "goblin.h"

class Level_1 : public Level {
private:

public:
	Level_1(int h,int w);
	~Level_1();
	void DrawLevel() const;
	void UpdateLevel(const float&);
};
