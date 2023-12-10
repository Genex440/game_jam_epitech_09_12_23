/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** Memory.hpp
*/

#pragma once

#include "display.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

struct Card {
    char symbol;
    bool flipped;
    bool matched;
};


class Memory {
    public:
        Memory();
        ~Memory();
        
        void init();
        void run();
    private:
        const int screenWidth = 800;
        const int screenHeight = 450;
        std::vector<Card> cards;
        std::vector<int> flippedIndices;
        const int rows = 4;
        const int cols = 4;
        const int gridSize = 100;
        const int gridSpacing = 10;
};