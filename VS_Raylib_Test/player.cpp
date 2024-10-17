#include "player.h"

Player::Player()
    : GameObject({}, {}, {}) ,texture(Sprites::getTexture(Textures::player)) {
    sourceRec = { 0,0,texture.width / 6.0f,texture.height / 8.0f };
}

void Player::Draw() const{
    DrawRectangleLines(x, y, texture.width/6.0f, texture.height / 8.0f, GREEN);
    DrawTextureRec(texture, sourceRec, { x,y }, WHITE);
    DrawCircle(x + texture.width / 12.0f, y + texture.height / 16.0f, 5, GREEN);
}

void Player::Update(const float& dt){
    static float counter = 0.0f;
    static int currentFrame = 0;
    static int toggleAttackAnimation = 0;
    counter += dt;
    
    float xInput = 0.0f, yInput = 0.0f;
    if (state != ATTACKING) {
        if (counter >= 1 / 12.0f) { ++currentFrame %= 6; counter = 0; state = IDEL;}

        if (IsKeyDown(KEY_A)) {
            xInput = -1;
            state = RUNNING;
            isRight = false;
            dir = Left;
        }
        if (IsKeyDown(KEY_D)) {
            xInput = 1;
            state = RUNNING;
            isRight = true;
            dir = Right;
        }
        if (IsKeyDown(KEY_W)) {
            yInput = -1;
            state = RUNNING;
            isUp = true;
            dir = Up;
        }
        if (IsKeyDown(KEY_S)) {
            yInput = 1;
            state = RUNNING;
            isUp = false;
            dir = Down;
        }
        Vector2 normVec = Vector2Normalize({ xInput, yInput });
        Vector2 rVec = Vector2Multiply({ moveSpeed * dt ,moveSpeed * dt },normVec);
        SetPosition(Vector2Add(GetPosition(), rVec));

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            state = ATTACKING;
            currentFrame = 0;
            counter = 0;
        }
    }
    else {
        if (counter >= attackSpeed/6.0f) {
            currentFrame++;
            counter = 0;
            if(currentFrame >=6)
            {
                currentFrame = 0;
                toggleAttackAnimation = ~toggleAttackAnimation;
                state = IDEL;
            }
        }
    }
    x = GetPosition().x;
    y = GetPosition().y;
    SetSourceRec(currentFrame,toggleAttackAnimation);
}


void Player::SetSourceRec(const int &cf,const int &t) {
    if (state == IDEL) {
        if (isRight) {
            sourceRec = { cf * (texture.width / 6.0f),0,texture.width / 6.0f,texture.height / 8.0f };
        }
        else {
            sourceRec = { cf * (texture.width / 6.0f),0,- texture.width / 6.0f,texture.height / 8.0f };
        }
    }
    else if (state == RUNNING) {
        if (isRight) {
            sourceRec = { cf * (texture.width / 6.0f),texture.height / 8.0f,texture.width / 6.0f,texture.height / 8.0f };
        }
        else {
            sourceRec = { cf * (texture.width / 6.0f),texture.height / 8.0f,-texture.width / 6.0f,texture.height / 8.0f };
        }
    } 
    else if (state == ATTACKING) {
        if (dir == Right)
            sourceRec = { cf * (texture.width / 6.0f),(2 - t) * texture.height / 8.0f,texture.width / 6.0f,texture.height / 8.0f };
        else if (dir == Left)
            sourceRec = { cf * (texture.width / 6.0f),(2 - t) * texture.height / 8.0f,-texture.width / 6.0f,texture.height / 8.0f };
        else if (dir == Up)
            sourceRec = { cf * (texture.width / 6.0f),(6 - t) * texture.height / 8.0f,texture.width / 6.0f,texture.height / 8.0f };
        else
            sourceRec = { cf * (texture.width / 6.0f),(4 - t) * texture.height / 8.0f,texture.width / 6.0f,texture.height / 8.0f };
    }
}