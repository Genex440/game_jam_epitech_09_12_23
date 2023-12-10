/*
** EPITECH PROJECT, 2023
** game_jam_epitech_09_12_23
** File description:
** Memory.cpp
*/

#include "Memory.hpp"

Memory::Memory()
{
}

Memory::~Memory()
{
}

void Memory::init()
{
    cards.clear();
    flippedIndices.clear();

    std::vector<char> symbols = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    std::random_shuffle(symbols.begin(), symbols.end());

    for (int i = 0; i < rows * cols; ++i) {
        Card card = {symbols[i / 2], false, false};
        cards.push_back(card);
    }

    std::random_shuffle(cards.begin(), cards.end());
}

void Memory::run()
{
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (mousePos.x < gridSpacing || mousePos.y < gridSpacing ||
                mousePos.x > screenWidth - gridSpacing || mousePos.y > screenHeight - gridSpacing)
                continue;
            int col = static_cast<int>((mousePos.x - gridSpacing) / (gridSize + gridSpacing));
            int row = static_cast<int>((mousePos.y - gridSpacing) / (gridSize + gridSpacing));
            int index = row * cols + col;

            if (!cards[index].flipped && flippedIndices.size() < 3) {
                cards[index].flipped = true;
                flippedIndices.push_back(index);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < rows * cols; ++i) {
            int col = i % cols;
            int row = i / cols;
            float x = col * (gridSize + gridSpacing) + gridSpacing;
            float y = row * (gridSize + gridSpacing) + gridSpacing;

            DrawRectangle(x, y, gridSize, gridSize, cards[i].flipped ? cards[i].matched ? YELLOW : ORANGE : DARKBLUE);

            if (cards[i].flipped) {
                char symbolText[2];
                symbolText[0] = cards[i].symbol;
                symbolText[1] = '\0';

                DrawText(symbolText,
                         static_cast<int>(x + gridSize / 2 - MeasureText(symbolText, 30) / 2),
                         static_cast<int>(y + gridSize / 2 - 15), 30, WHITE);
            }
        }

        if (flippedIndices.size() == 2 || flippedIndices.size() == 3) {
            int index1 = flippedIndices[0];
            int index2 = flippedIndices[1];

            if (cards[index1].symbol == cards[index2].symbol) {
                cards[index1].matched = true;
                cards[index2].matched = true;
            }

            if (flippedIndices.size() == 3) {
                if (!cards[index1].matched) {
                    cards[index1].flipped = false;
                    cards[index2].flipped = false;
                }
                flippedIndices.erase(flippedIndices.begin());
                flippedIndices.erase(flippedIndices.begin());
            }
        }

        if (std::all_of(cards.begin(), cards.end(), [](const Card &card) { return card.matched; })) {
            DrawText("Congratulations! You Win!", screenWidth / 2 - MeasureText("Congratulations! You Win!", 30) / 2,
                     screenHeight / 2 - 15, 30, BLACK);
        }
        EndDrawing();
    }
}