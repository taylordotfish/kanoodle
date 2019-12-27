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
