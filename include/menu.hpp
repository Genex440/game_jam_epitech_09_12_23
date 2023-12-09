/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** menu.hpp
*/

#pragma once

#include "Arkanoid.hpp"
#include "Tetris.hpp"
#include "Snake.hpp"
#include "Memory.hpp"

class Menu {
    public:
        Menu() = default;
        ~Menu() = default;
        void run();
};