/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** game.hpp
*/

#pragma once

#include "display.hpp"
#include <iostream>
#include <tuple>
#include <random>

namespace Game {
    class Snake {
        public:
            Snake(std::tuple<int, int> mapSize);
            ~Snake();

            int run();
        private:
            std::tuple<int, int> _position;
            std::tuple<int, int> _mapSize;
            std::tuple<int, int> _fruitPosition;
    };
}