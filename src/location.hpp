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
