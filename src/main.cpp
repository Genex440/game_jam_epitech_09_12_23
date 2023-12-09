/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** main.cpp
*/

#include "game.hpp"

int main(int ac, char **av) {
    Game::Snake snake(std::make_tuple(800, 450));

    snake.run();
    return 0;
}