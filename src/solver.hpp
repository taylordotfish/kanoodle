#pragma once
#include "board.hpp"
#include "location.hpp"
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

    const PieceTransformations& piece() const {
        return *m_it;
    }

    void place_next() {
        if (m_it == m_pieces->end()) {
            m_solved.push_back(m_board);
            return;
        }
        for (auto&& shape : piece()) {
            place(shape);
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
            }
        }
    }

    void place(const TransformedShape& shape, const Location& loc) {
        bool success = m_board.try_place(piece().category(), shape, loc);
        if (!success) {
            return;
        }

        ++m_it;
        place_next();
        --m_it;
        m_board.place(Category::none, shape, loc);
    }
};
