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
#include <cstddef>

class Location {
    public:
    constexpr Location(std::size_t row, std::size_t col) :
    m_row(row), m_col(col) {
    }

    std::size_t& row() {
        return m_row;
    }

    std::size_t row() const {
        return m_row;
    }

    std::size_t& col() {
        return m_col;
    }

    std::size_t col() const {
        return m_col;
    }

    Location& operator+=(const Location& other) {
        m_row += other.m_row;
        m_col += other.m_col;
        return *this;
    }

    Location operator+(const Location& other) const {
        auto result = *this;
        result += other;
        return result;
    }

    bool operator<(const Location& other) const {
        if (m_row < other.m_row) return true;
        if (m_row > other.m_row) return false;
        return m_col < other.m_col;
    }

    private:
    std::size_t m_row = 0;
    std::size_t m_col = 0;
};
