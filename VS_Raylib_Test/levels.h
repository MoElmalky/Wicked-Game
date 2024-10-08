#pragma once
#include "level.h"
#include "sprites.h"

class Level_1 : public Level {
private:

public:
	Level_1(int h,int w);
	~Level_1();
	void drawLevel(const float&) const;
	void updateLevel(const float&);
};
