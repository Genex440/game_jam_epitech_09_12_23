/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** snake.cpp
*/

#include "game.hpp"

Game::Snake::Snake(std::tuple<int, int> mapSize)
{
    _position = std::make_tuple(std::get<0>(mapSize) / 2, std::get<1>(mapSize) / 2);
    _mapSize = mapSize;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, std::get<0>(mapSize));
    std::uniform_int_distribution<> disY(0, std::get<1>(mapSize));
    _fruitPosition = std::make_tuple(disX(gen), disY(gen));
}

Game::Snake::~Snake()
{
}

int Game::Snake::run()
{
    Display display;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(std::get<0>(_position), std::get<1>(_position), 10, 10, GREEN);
        DrawRectangle(std::get<0>(_fruitPosition), std::get<1>(_fruitPosition), 10, 10, RED);
        EndDrawing();
    }    
    return 0;
}
