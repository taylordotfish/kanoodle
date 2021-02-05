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
#include "flip.hpp"
#include "location.hpp"
#include "rotation.hpp"
#include "shape.hpp"
#include <cstddef>
#include <utility>

class TransformedShape {
    public:
    TransformedShape(
        const Shape& shape,
        Rotation rotation = Rotation::deg0,
        Flip flip = Flip::none
    ) :
    m_shape(&shape),
    m_rotation(rotation),
    m_flip(flip) {
    }

    Location dimensions() const {
        Location dim = m_shape->dimensions();
        if (dimensions_swapped()) {
            std::swap(dim.row(), dim.col());
        }
        return dim;
    }

    bool is_solid(Location loc) const {
        transform(loc);
        return m_shape->is_solid(loc);
    }

    Rotation rotation() const {
        return m_rotation;
    }

    Flip flip() const {
        return m_flip;
    }

    void set_rotation(Rotation rotation) {
        m_rotation = rotation;
    }

    void set_flip(Flip flip) {
        m_flip = flip;
    }

    bool operator<(const TransformedShape& other) const {
        const auto dim1 = dimensions();
        const auto dim2 = other.dimensions();
        if (dim1 < dim2) return true;
        if (dim2 < dim1) return false;

        for (std::size_t y = 0; y < dim1.row(); ++y) {
            for (std::size_t x = 0; x < dim1.col(); ++x) {
                const bool solid1 = is_solid({y, x});
                const bool solid2 = other.is_solid({y, x});
                if (solid1 < solid2) return true;
                if (solid2 < solid1) return false;
            }
        }
        return false;
    }

    private:
    const Shape* m_shape = nullptr;
    Rotation m_rotation = Rotation::deg0;
    Flip m_flip = Flip::none;

    bool dimensions_swapped() const {
        switch (m_rotation) {
            case Rotation::deg90:
            case Rotation::deg270: {
                return true;
            }
            default: break;
        }
        return false;
    }

    void transform(Location& loc) const {
        rotate(loc);
        flip(loc);
    }

    void rotate(Location& loc) const {
        const auto dim = m_shape->dimensions();
        const auto row = loc.row();
        const auto col = loc.col();

        switch (m_rotation) {
            case Rotation::deg90: {
                loc.row() = col;
                loc.col() = dim.col() - 1 - row;
                break;
            }
            case Rotation::deg180: {
                loc.row() = dim.row() - 1 - row;
                loc.col() = dim.col() - 1 - col;
                break;
            }
            case Rotation::deg270: {
                loc.row() = dim.row() - 1 - col;
                loc.col() = row;
                break;
            }
            default: break;
        }
    }

    void flip(Location& loc) const {
        const auto dim = m_shape->dimensions();
        const auto col = loc.col();

        switch (m_flip) {
            case Flip::horizontal: {
                loc.col() = dim.col() - 1 - col;
                break;
            }
            default: break;
        }
    }
};
