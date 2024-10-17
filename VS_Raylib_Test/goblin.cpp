#include "goblin.h"

Goblin::Goblin(Vector2 pos) : GameObject(pos, 0, {1,1}),
    texture(Sprites::getTexture(Textures::goblin)) {
    srcRec = { 0,0,texture.width / 7.0f,texture.height / 5.0f };
    std::cout << "GAME: New Goblin " << GetID();
    if (texture.width > 0)
        std::cout << "\t Texture Loaded successfully\n";
    else std::cout << std::endl;
}


void Goblin::Draw() const {
    DrawTextureRec(texture, srcRec, { x,y }, WHITE);
}

void Goblin::Update(const float &dt) {
	UpdateSourceRec(dt);
}

void Goblin::UpdateSourceRec(const float& dt) {
    counter += dt;

    if (counter >= 1 / 12.0f){
        ++currentFrame %= 6;
        counter = 0;
        srcRec = { currentFrame * texture.width / 7.0f ,0,texture.width / 7.0f,texture.height / 5.0f };
    }
}
