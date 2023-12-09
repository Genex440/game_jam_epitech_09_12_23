/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** dispay.cpp
*/

#include "display.hpp"

Display::Display()
{
    InitWindow(_screenWidth, _screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
}

Display::~Display()
{
    CloseWindow();
}

std::tuple<int, int> Display::getScreenSize() const
{
    return std::make_tuple(_screenWidth, _screenHeight);
}