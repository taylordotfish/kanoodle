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
#include "piece.hpp"
#include "transformed-shape.hpp"
#include <set>

class PieceTransformations {
    public:
    PieceTransformations(const Piece& piece) : m_category(piece.category()) {
        auto rot = static_cast<int>(Rotation::begin);
        auto end = static_cast<int>(Rotation::end);

        for (; rot < end; ++rot) {
            auto flip = static_cast<int>(Flip::begin);
            auto end = static_cast<int>(Flip::end);

            for (; flip < end; ++flip) {
                m_shapes.emplace(
                    piece.shape(),
                    static_cast<Rotation>(rot),
                    static_cast<Flip>(flip)
                );
            }
        }
    }

    Category category() const {
        return m_category;
    }

    auto begin() const {
        return m_shapes.begin();
    }

    auto end() const {
        return m_shapes.end();
    }

    std::size_t size() const {
        return m_shapes.size();
    }

    private:
    Category m_category = Category::none;
    std::set<TransformedShape> m_shapes;
};
