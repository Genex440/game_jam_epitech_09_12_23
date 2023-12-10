/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** Tetris.hpp
*/

#pragma once

#include "display.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SQUARE_SIZE             20

#define GRID_HORIZONTAL_SIZE    12
#define GRID_VERTICAL_SIZE      20

#define LATERAL_SPEED           10
#define TURNING_SPEED           12
#define FAST_FALL_AWAIT_COUNTER 30

#define FADING_TIME             33

typedef enum GridSquare { EMPTY, MOVING, FULL, BLOCK, FADING } GridSquare;

class Tetris {
    public:
        void init();
        void run();
        void UpdateGame();
        void DrawGame();
        bool Createpiece();
        void GetRandompiece();
        void ResolveFallingMovement(bool *detection, bool *pieceActive);
        bool ResolveLateralMovement();
        bool ResolveTurnMovement();
        void CheckDetection(bool *detection);
        void CheckCompletion(bool *lineToDelete);
        int DeleteCompleteLines();

    private:
        const int screenWidth = 800;
        const int screenHeight = 450;
        bool gameOver = false;
        bool pause = false;
        GridSquare grid [GRID_HORIZONTAL_SIZE][GRID_VERTICAL_SIZE];
        GridSquare piece [4][4];
        GridSquare incomingPiece [4][4];
        int piecePositionX = 0;
        int piecePositionY = 0;
        Color fadingColor;
        bool beginPlay = true;
        bool pieceActive = false;
        bool detection = false;
        bool lineToDelete = false;
        int level = 1;
        int lines = 0;
        int gravityMovementCounter = 0;
        int lateralMovementCounter = 0;
        int turnMovementCounter = 0;
        int fastFallMovementCounter = 0;
        int fadeLineCounter = 0;
        int gravitySpeed = 30;
        Color pieceColor;
        Color pieceColors[7] = { RED, GREEN, BLUE, YELLOW, PURPLE, ORANGE, PINK };
};