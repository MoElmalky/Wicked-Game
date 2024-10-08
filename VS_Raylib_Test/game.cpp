#include "game.h"

Game::Game()
{
    //window setup
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    std::cout << "GAME: Window Initialized.\n";

    //Player setup
    player = new Player({ 0,0 }, 0, { 25,0 });
    player->setPosition({ SCREEN_WIDTH / 2.0f - player->getWidth() / 2.0f,SCREEN_HEIGHT / 2.0f - player->getHeight() / 2.0f });
    std::cout << "GAME: Player Initialized.\n";

    //Camera setup
    cameraTarget = { player->getPosition().x + player->getWidth() / 2,
        player->getPosition().y + player->getHeight() / 2 };
    camera.target = cameraTarget;
    camera.offset = { SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT / 2.0f };
    camera.zoom = 1.0f;
    camera.rotation = 0;
    std::cout << "GAME: Camera Initialized.\n";

    currentLevel = new Level_1(20,20);

    RunGame();
}

Game::~Game()
{
    std::cout << "GAME: Closing game....\n";
    delete player;
    Sprites::unloadTextures();
}

void Game::RunGame()
{
    SetTargetFPS(targetFPS);
    while (!WindowShouldClose())
    {

        player->update(GetFrameTime());

        UpdateCamera();
        

        BeginDrawing();

            ClearBackground({ 71,171,169,255 });

            BeginMode2D(camera);

                /*DrawLineV(cameraTarget, player->getPosition(), GREEN);

                DrawRectangleLines(player->getPosition().x,player->getPosition().y ,
                    player->getWidth(), player->getHeight(), RED);

                DrawRectangleLines(3 * SCREEN_WIDTH / 10.0f, 3 * SCREEN_HEIGHT / 10.0f,
                    SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 2.5f, YELLOW);*/
                //DrawTextureRec(grass, { 64,64,64,64 }, { 300,300 }, WHITE);
                currentLevel->drawLevel(GetFrameTime());
                player->draw(GetFrameTime());
                //DrawRectangle(200, 200, 100, 100, RED);

            EndMode2D();

            DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
}

void Game::UpdateCamera() {
    if (cameraTarget.x - player->getPosition().x >= (SCREEN_WIDTH / 5.0f) + player->getWidth()/2)
        cameraTarget.x -= player->getMoveSpeed() * GetFrameTime();

    else if (cameraTarget.x - player->getPosition().x <= -(SCREEN_WIDTH / 5.0f) + player->getWidth() / 2)
        cameraTarget.x += player->getMoveSpeed() * GetFrameTime();

    if (cameraTarget.y - player->getPosition().y >= SCREEN_HEIGHT / 5.0f + player->getHeight() / 2)
        cameraTarget.y -= player->getMoveSpeed() * GetFrameTime();

    else if (cameraTarget.y - player->getPosition().y <= -SCREEN_HEIGHT/ 5.0f + player->getHeight() / 2)
        cameraTarget.y += player->getMoveSpeed() * GetFrameTime();

    camera.target = cameraTarget;
}