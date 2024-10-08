#pragma once
#include "gameObject.h"
#include <iostream>
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
	float& x = position.x, & y = position.y;
	float moveSpeed = 500;
	float attackSpeed = .5;
	Texture texture;
	int state = 0;
	bool isRight = true;
	bool isUp = true;
	int dir = 0;
	Rectangle sourceRec = { 0 };

public:
    Player (Vector2 position, float rotation, Vector2 scale);
	~Player() { UnloadTexture(texture); std::cout << "GAME: Player Deleted\n"; }
	void draw(const float&) const;
	void update(const float&);

	void setSourceRec(const int&,const int&);

	inline Vector2 getPosition() { return position; }
	inline float getRotaion() { return rotation; }
	inline float getMoveSpeed() { return moveSpeed; }
	inline float getWidth() { return texture.width/6.0f; }
	inline float getHeight() { return texture.height/8.0f; }

	inline void setPosition(float x, float y) { this->x = x; this->y = y; }
	inline void setPosition(Vector2 pos) { this->position = pos; }

	inline void setRotaion(float rotation) { this->rotation = rotation; }
	inline void setMoveSpeed(float speed) { this->moveSpeed = speed; }
};
