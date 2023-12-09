/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** Sokoban.hpp
*/

#pragma once

#include "display.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PLAYER_MAX_LIFE         5
#define LINES_OF_BRICKS         5
#define BRICKS_PER_LINE        20

typedef struct Player {
    Vector2 position;
    Vector2 size;
    int life;
} Player;

typedef struct Ball {
    Vector2 position;
    Vector2 speed;
    int radius;
    bool active;
} Ball;

typedef struct Brick {
    Vector2 position;
    bool active;
} Brick;

class Arkanoid {
    public:
        Arkanoid() = default;
        ~Arkanoid() = default;
        void init();
        void run();

    private:
        Player player;
        Ball ball;
        Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE];
        bool gameOver;
        bool pause;
        Vector2 brickSize = { 0 };
        const int screenWidth = 800;
        const int screenHeight = 450;
};
