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

#pragma once
#include "location.hpp"
#include "piece.hpp"
#include <vector>

static constexpr Location default_dimensions = {5, 11};
static const std::vector<Piece> default_pieces = {
    {
        Category::A,
        std::array{
            std::array{1, 0, 0},
            std::array{1, 1, 1},
        }
    },
    {
        Category::B,
        std::array{
            std::array{1, 1, 0},
            std::array{1, 1, 1},
        }
    },
    {
        Category::C,
        std::array{
            std::array{0, 1},
            std::array{0, 1},
            std::array{0, 1},
            std::array{1, 1},
        }
    },
    {
        Category::D,
        std::array{
            std::array{1, 1, 1, 1},
            std::array{0, 0, 1, 0},
        }
    },
    {
        Category::E,
        std::array{
            std::array{1, 1, 0, 0},
            std::array{0, 1, 1, 1},
        }
    },
    {
        Category::F,
        std::array{
            std::array{1, 0},
            std::array{1, 1},
        }
    },
    {
        Category::G,
        std::array{
            std::array{1, 1, 1},
            std::array{0, 0, 1},
            std::array{0, 0, 1},
        }
    },
    {
        Category::H,
        std::array{
            std::array{1, 1, 0},
            std::array{0, 1, 1},
            std::array{0, 0, 1},
        }
    },
    {
        Category::I,
        std::array{
            std::array{1, 1},
            std::array{0, 1},
            std::array{1, 1},
        }
    },
    {
        Category::J,
        std::array{
            std::array{1},
            std::array{1},
            std::array{1},
            std::array{1},
        }
    },
    {
        Category::K,
        std::array{
            std::array{1, 1},
            std::array{1, 1},
        }
    },
    {
        Category::L,
        std::array{
            std::array{0, 1, 0},
            std::array{1, 1, 1},
            std::array{0, 1, 0},
        }
    },
};
