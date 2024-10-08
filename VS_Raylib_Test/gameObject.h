#pragma once
#include "raylib.h"
#include "raymath.h"

class GameObject {
protected:
    Vector2 position;
    float rotation;
    Vector2 scale;

public:
    GameObject(Vector2 position, float rotation, Vector2 scale)
        : position(position), rotation(rotation), scale(scale) {}
    virtual void draw(const float&) const = 0;
    virtual void update(const float&) = 0;
    ~GameObject() {}

};