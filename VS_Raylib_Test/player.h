#pragma once
#include "gameObject.h"
#include <iostream>
#include "sprites.h"

enum PlayerState {
	IDEL,
	RUNNING,
	ATTACKING
};
enum PlayerDir {
	Right,
	Left,
	Up,
	Down
};

class Player : public GameObject {
private:
	float x = GetPosition().x, y = GetPosition().y;
	float moveSpeed = 500;
	float attackSpeed = .5;
	Texture& texture;
	int state = 0;
	bool isRight = true;
	bool isUp = true;
	int dir = 0;
	Rectangle sourceRec = { 0 };

public:
    Player ();
	~Player() { UnloadTexture(texture); std::cout << "GAME: Player Deleted\n"; }
	void Draw() const;
	void Update(const float&);

	void SetSourceRec(const int&,const int&);

	inline float GetMoveSpeed() { return moveSpeed; }
	inline float GetWidth() { return texture.width/6.0f; }
	inline float GetHeight() { return texture.height/8.0f; }

	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }
};
