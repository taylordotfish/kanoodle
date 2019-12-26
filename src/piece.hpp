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
