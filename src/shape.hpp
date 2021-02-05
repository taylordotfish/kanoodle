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
#include <array>
#include <cassert>
#include <cstddef>
#include <vector>

class Shape {
    public:
    template <std::size_t nrows, std::size_t ncols, typename T>
    Shape(std::array<std::array<T, ncols>, nrows> rows) :
    m_dimensions(nrows, ncols) {
        m_solid.reserve(nrows * ncols);
        for (auto&& row : rows) {
            for (auto&& tile : row) {
                m_solid.push_back(static_cast<bool>(tile));
            }
        }
    }

    Location dimensions() const {
        return m_dimensions;
    }

    bool is_solid(const Location& loc) const {
        const auto index = loc.row() * m_dimensions.col() + loc.col();
        assert(index < m_solid.size());
        return m_solid[index];
    }

    private:
    Location m_dimensions;
    std::vector<bool> m_solid;
};

