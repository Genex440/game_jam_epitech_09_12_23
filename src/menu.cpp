/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** menu.cpp
*/

#include "menu.hpp"

void Menu::run()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game Menu");

    Vector2 sokobanPos = { 100, 100 };
    Vector2 tetrisPos = { 100, 150 };
    Vector2 snakePos = { 100, 200 };
    Vector2 memoryPos = { 100, 250 };

    Color sokobanColor = BLACK;
    Color tetrisColor = BLACK;
    Color snakeColor = BLACK;
    Color memoryColor = BLACK;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 mousePos = GetMousePosition();

        sokobanColor = CheckCollisionPointRec(mousePos, { sokobanPos.x, sokobanPos.y, MeasureText("Sokoban", 20), 20 }) ? RED : BLACK;
        tetrisColor = CheckCollisionPointRec(mousePos, { tetrisPos.x, tetrisPos.y, MeasureText("Tetris", 20), 20 }) ? RED : BLACK;
        snakeColor = CheckCollisionPointRec(mousePos, { snakePos.x, snakePos.y, MeasureText("Snake", 20), 20 }) ? RED : BLACK;
        memoryColor = CheckCollisionPointRec(mousePos, { memoryPos.x, memoryPos.y, MeasureText("Memory", 20), 20 }) ? RED : BLACK;

        DrawText("Sokoban", sokobanPos.x, sokobanPos.y, 20, sokobanColor);
        DrawText("Tetris", tetrisPos.x, tetrisPos.y, 20, tetrisColor);
        DrawText("Snake", snakePos.x, snakePos.y, 20, snakeColor);
        DrawText("Memory", memoryPos.x, memoryPos.y, 20, memoryColor);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, { sokobanPos.x, sokobanPos.y, MeasureText("Sokoban", 20), 20 })) {
                Sokoban sokobanGame;
                sokobanGame.init();
                sokobanGame.run();
            } else if (CheckCollisionPointRec(mousePos, { tetrisPos.x, tetrisPos.y, MeasureText("Tetris", 20), 20 })) {
                Tetris tetrisGame;
                tetrisGame.init();
                tetrisGame.run();
            } else if (CheckCollisionPointRec(mousePos, { snakePos.x, snakePos.y, MeasureText("Snake", 20), 20 })) {
                Snake snakeGame;
                snakeGame.init();
                snakeGame.run();
            } else if (CheckCollisionPointRec(mousePos, { memoryPos.x, memoryPos.y, MeasureText("Memory", 20), 20 })) {
                Memory memoryGame;
                memoryGame.init();
                memoryGame.run();
            }
        }
        EndDrawing();
    }
    CloseWindow();
}   