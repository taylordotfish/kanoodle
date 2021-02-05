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
#include "board.hpp"
#include "location.hpp"
#include "output-config.hpp"
#include "piece-transformations.hpp"
#include "transformed-shape.hpp"
#include <cstddef>
#include <vector>
#include <utility>

class Solver {
    using Pieces = std::vector<PieceTransformations>;

    public:
    Solver(Board board, const Pieces& pieces) :
    m_board(std::move(board)),
    m_pieces(&pieces) {
    }

    std::vector<Board> solve() {
        place_next();
        using std::swap;
        std::vector<Board> result;
        swap(result, m_solved);
        return result;
    }

    std::vector<Board>& solutions() {
        return m_solved;
    }

    const std::vector<Board>& solutions() const {
        return m_solved;
    }

    private:
    Board m_board;
    std::vector<Board> m_solved;
    const Pieces* m_pieces = nullptr;
    Pieces::const_iterator m_it = m_pieces->begin();

    std::size_t m_depth = 0;
    std::size_t m_shape_index = 0;

    const PieceTransformations& piece() const {
        return *m_it;
    }

    void place_next() {
        if (m_it == m_pieces->end()) {
            m_solved.push_back(m_board);
            if constexpr (config_show_progress) {
                std::cerr << "Solutions: " << m_solved.size() << "\n";
            }
            return;
        }
        for (auto&& shape : piece()) {
            place(shape);
            if (m_depth == 0) {
                ++m_shape_index;
            }
        }
    }

    void place(const TransformedShape& shape) {
        auto&& dim = shape.dimensions();
        auto&& board_dim = m_board.dimensions();

        const auto max_row = board_dim.row() - dim.row() + 1;
        const auto max_col = board_dim.col() - dim.col() + 1;

        for (std::size_t y = 0; y < max_row; ++y) {
            for (std::size_t x = 0; x < max_col; ++x) {
                place(shape, {y, x});
                if constexpr (config_show_progress) {
                    if (m_depth == 0) {
                        std::cerr << "[" << m_shape_index + 1 << "/";
                        std::cerr << piece().size() << "] ";
                        std::cerr << "(" << y + 1 << ", " << x + 1 << ") ";
                        std::cerr << "[" << y * max_col + x + 1 << "/";
                        std::cerr << max_row * max_col << "]\n";
                    }
                }
            }
        }
    }

    void place(const TransformedShape& shape, const Location& loc) {
        bool success = m_board.try_place(piece().category(), shape, loc);
        if (!success) {
            return;
        }

        ++m_it;
        ++m_depth;
        place_next();
        --m_depth;
        --m_it;
        m_board.place(Category::none, shape, loc);
    }
};
