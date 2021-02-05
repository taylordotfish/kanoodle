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
#include "category.hpp"
#include "shape.hpp"
#include <utility>

class Piece {
    public:
    Piece(Category category, Shape shape) :
    m_category(category),
    m_shape(std::move(shape)) {
    }

    Category category() const {
        return m_category;
    }

    const Shape& shape() const {
        return m_shape;
    }

    private:
    Category m_category = Category::A;
    Shape m_shape;
};
