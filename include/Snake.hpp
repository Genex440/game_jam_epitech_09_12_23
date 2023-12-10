/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** Snake.hpp
*/

#pragma once

#include "display.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SNAKE_LENGTH   256
#define SQUARE_SIZE     31

typedef struct Snake1 {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake1;

typedef struct Food {
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

class Snake {
    public:
        Snake() = default;
        ~Snake() = default;
        void init();
        void run();

    private:
        const int screenWidth = 800;
        const int screenHeight = 450;

        int framesCounter = 0;
        bool gameOver = false;
        bool pause = false;

        Food fruit = { 0 };
        Snake1 snake[SNAKE_LENGTH] = { 0 };
        Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
        bool allowMove = false;
        Vector2 offset = { 0 };
        int counterTail = 0;
        Image jean_eudes;
        Texture2D jean_eudes_texture;
};