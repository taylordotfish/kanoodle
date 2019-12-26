#include "board.hpp"
#include "category.hpp"
#include "game-config.hpp"
#include "piece.hpp"
#include "piece-transformations.hpp"
#include "solver.hpp"
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    Board board(default_dimensions);
    std::set<Category> categories;
    if (!parse_board(std::cin, board, categories)) {
        return EXIT_FAILURE;
    }

    std::vector<PieceTransformations> pieces;
    for (const auto& piece : default_pieces) {
        if (categories.count(piece.category()) == 0) {
            pieces.emplace_back(piece);
        }
    }
    Solver solver(board, pieces);

    bool first = true;
    for (auto&& solution : solver.solve()) {
        if (!first) std::cout << "\n";
        first = false;
        std::cout << solution;
    };
    return EXIT_SUCCESS;
}
