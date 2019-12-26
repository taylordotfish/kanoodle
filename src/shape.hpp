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

