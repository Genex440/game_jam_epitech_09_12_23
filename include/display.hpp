/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** display.hpp
*/

#pragma once

#include "raylib.h"
#include <iostream>
#include <tuple>

class Display {
    public:
        Display();
        ~Display();

        std::tuple<int, int> getScreenSize() const;

    private:
        const int _screenWidth = 800;
        const int _screenHeight = 450;
};