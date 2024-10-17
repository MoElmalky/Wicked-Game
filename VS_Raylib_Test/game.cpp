#include "game.h"

Game::Game()
{
    //window setup
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    std::cout << "GAME: Window Initialized.\n";

    //Player setup
    player = new Player();
    player->SetPosition({ SCREEN_WIDTH / 2.0f - player->GetWidth() / 2.0f,SCREEN_HEIGHT / 2.0f - player->GetHeight() / 2.0f});
    std::cout << "GAME: Player Initialized.\n";

    //Camera setup
    cameraTarget = { player->GetPosition().x + player->GetWidth() / 2,
        player->GetPosition().y + player->GetHeight() / 2 };
    camera.target = cameraTarget;
    camera.offset = { SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT / 2.0f };
    camera.zoom = 1.0f;
    camera.rotation = 0;
    std::cout << "GAME: Camera Initialized.\n";

    currentLevel = new Level_1(15,15);

    RunGame();
}

Game::~Game()
{
    std::cout << "GAME: Closing game....\n";
    delete player;
    delete currentLevel;
    Sprites::unloadTextures();
}

void Game::RunGame()
{
    SetTargetFPS(targetFPS);
    while (!WindowShouldClose())
    {

        player->Update(GetFrameTime());

        UpdateCamera();

        currentLevel->UpdateLevel(GetFrameTime());


        BeginDrawing();

            ClearBackground({ 71,171,169,255 });
           
            BeginMode2D(camera);

                currentLevel->DrawLevel();
                player->Draw();

            EndMode2D();

            DrawRectangleLines(SCREEN_WIDTH / 3.33f,SCREEN_HEIGHT / 3.33f,
                SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 2.5f, RED);
            DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
}

void Game::UpdateCamera() {

    if (cameraTarget.x - player->GetPosition().x >= (SCREEN_WIDTH / 5.0f) + player->GetWidth()/2)
        cameraTarget.x -= player->GetMoveSpeed() * GetFrameTime();

    else if (cameraTarget.x - player->GetPosition().x <= -(SCREEN_WIDTH / 5.0f) + player->GetWidth() / 2)
        cameraTarget.x += player->GetMoveSpeed() * GetFrameTime();

    if (cameraTarget.y - player->GetPosition().y >= SCREEN_HEIGHT / 5.0f + player->GetHeight() / 2)
        cameraTarget.y -=  player->GetMoveSpeed() * GetFrameTime();

    else if (cameraTarget.y - player->GetPosition().y <= -SCREEN_HEIGHT/ 5.0f + player->GetHeight() / 2)
        cameraTarget.y += player->GetMoveSpeed() * GetFrameTime();

    camera.target = cameraTarget;
}