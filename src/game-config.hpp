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
