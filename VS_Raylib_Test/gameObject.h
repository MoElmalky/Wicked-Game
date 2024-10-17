#pragma once
#include "raylib.h"
#include "raymath.h"

class GameObject {
private:
    int ID;

    Vector2 position;
    float rotation;
    Vector2 scale;

    inline void SetID() { static int next_valid_ID = 0; ID = next_valid_ID++; }

public:
    GameObject() { SetID(); }

    GameObject(Vector2 position, float rotation, Vector2 scale)
        : position(position), rotation(rotation), scale(scale) {
        SetID();
    }

    virtual ~GameObject() {}

    virtual void Draw() const = 0;
    virtual void Update(const float&) = 0;

    constexpr int GetID() { return ID; }

    constexpr Vector2 GetPosition() { return position; }
    constexpr float GetRotation() { return rotation; }
    constexpr Vector2 GetScale() { return scale; }

    inline void SetPosition(Vector2 pos) { position = pos; }
    inline void SetRotation(float rot) { rotation = rot; }
    inline void SetScale(Vector2 scl) { scale = scl; }
};

