/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

void Snake::init()
{
    framesCounter = 0;
    gameOver = false;
    pause = false;

    counterTail = 1;
    allowMove = false;

    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

        if (i == 0) snake[i].color = DARKBLUE;
        else snake[i].color = PINK;
    }

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }

    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = SKYBLUE;
    fruit.active = false;
    jean_eudes = LoadImage("assets/jean_eudes.png");
    ImageResize(&jean_eudes, SQUARE_SIZE, SQUARE_SIZE);
    jean_eudes_texture = LoadTextureFromImage(jean_eudes);
}

void Snake::run()
{
    while (!WindowShouldClose()) {
        if (!gameOver)
        {
            if (IsKeyPressed('P')) pause = !pause;

            if (!pause)
            {
                if (IsKeyPressed(KEY_RIGHT) && (snake[0].speed.x == 0) && allowMove)
                {
                    snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
                    allowMove = false;
                }
                if (IsKeyPressed(KEY_LEFT) && (snake[0].speed.x == 0) && allowMove)
                {
                    snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
                    allowMove = false;
                }
                if (IsKeyPressed(KEY_UP) && (snake[0].speed.y == 0) && allowMove)
                {
                    snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
                    allowMove = false;
                }
                if (IsKeyPressed(KEY_DOWN) && (snake[0].speed.y == 0) && allowMove)
                {
                    snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
                    allowMove = false;
                }
                for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;

                if ((framesCounter%5) == 0)
                {
                    for (int i = 0; i < counterTail; i++)
                    {
                        if (i == 0)
                        {
                            snake[0].position.x += snake[0].speed.x;
                            snake[0].position.y += snake[0].speed.y;
                            allowMove = true;
                        }
                        else snake[i].position = snakePosition[i-1];
                    }
                }
                if (((snake[0].position.x) > (screenWidth - offset.x)) ||
                    ((snake[0].position.y) > (screenHeight - offset.y)) ||
                    (snake[0].position.x < 0) || (snake[0].position.y < 0))
                {
                    gameOver = true;
                }
                for (int i = 1; i < counterTail; i++)
                {
                    if ((snake[0].position.x == snake[i].position.x) && (snake[0].position.y == snake[i].position.y)) gameOver = true;
                }
                if (!fruit.active)
                {
                    fruit.active = true;
                    fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };

                    for (int i = 0; i < counterTail; i++)
                    {
                        while ((fruit.position.x == snake[i].position.x) && (fruit.position.y == snake[i].position.y))
                        {
                            fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
                            i = 0;
                        }
                    }
                }
                if ((snake[0].position.x < (fruit.position.x + fruit.size.x) && (snake[0].position.x + snake[0].size.x) > fruit.position.x) &&
                    (snake[0].position.y < (fruit.position.y + fruit.size.y) && (snake[0].position.y + snake[0].size.y) > fruit.position.y))
                {
                    snake[counterTail].position = snakePosition[counterTail - 1];
                    counterTail += 1;
                    fruit.active = false;
                }

                framesCounter++;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                init();
                gameOver = false;
            }
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if (!gameOver)
            {
                for (int i = 0; i < counterTail; i++) DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);
                DrawTexture(jean_eudes_texture, fruit.position.x, fruit.position.y, WHITE);
                if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
            }
            else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);
        EndDrawing();
    }
}