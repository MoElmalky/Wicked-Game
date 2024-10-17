#pragma once
#include "gameObject.h"
#include "sprites.h"
#include <iostream>

class Goblin : public GameObject
{
private:
	float x = GetPosition().x, y = GetPosition().y;
	Rectangle srcRec = { 0 };
	Texture& texture;
	float counter = 0.0f;
	int currentFrame = 0;
public:
	Goblin(Vector2 pos);
	~Goblin() { }
	void Draw() const ;
	void Update(const float& dt);
	void UpdateSourceRec(const float& dt);
};

