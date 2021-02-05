/*
 * Copyright (C) 2019 taylor.fish <contact@taylor.fish>
 *
 * This file is part of kanoodle-solver.
 *
 * kanoodle-solver is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * kanoodle-solver is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with kanoodle-solver. If not, see <https://www.gnu.org/licenses/>.
 */

#include "board.hpp"
#include "category.hpp"
#include "game-config.hpp"
#include "piece.hpp"
#include "piece-transformations.hpp"
#include "solver.hpp"
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    Board board(default_dimensions);
    std::set<Category> categories;
    if (!parse_board(std::cin, board, categories)) {
        return EXIT_FAILURE;
    }

    std::vector<PieceTransformations> pieces;
    for (const auto& piece : default_pieces) {
        if (categories.count(piece.category()) == 0) {
            pieces.emplace_back(piece);
        }
    }
    Solver solver(board, pieces);

    bool first = true;
    for (auto&& solution : solver.solve()) {
        if (!first) std::cout << "\n";
        first = false;
        std::cout << solution;
    };
    return EXIT_SUCCESS;
}
