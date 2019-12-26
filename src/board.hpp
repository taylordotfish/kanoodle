#pragma once
#include "category.hpp"
#include "location.hpp"
#include "output-config.hpp"
#include "transformed-shape.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <istream>
#include <string>
#include <ostream>
#include <set>
#include <utility>
#include <vector>

static constexpr const char* ansi_reset = "\x1b[0m";

class Board {
    public:
    Board(Location dimensions) :
    m_dimensions(std::move(dimensions)),
    m_tiles(dimensions.row() * dimensions.col(), Category::none) {
    }

    const Location& dimensions() const {
        return m_dimensions;
    }

    Category get(const Location& loc) const {
        return const_cast<Board&>(*this).ref(loc);
    }

    std::optional<Category> try_get(const Location& loc) const {
        if (loc.row() >= dimensions().row()) {
            return std::nullopt;
        }
        if (loc.col() >= dimensions().col()) {
            return std::nullopt;
        }
        return get(loc);
    }

    void place(Category cat, const Location& loc) {
        ref(loc) = cat;
    }

    void place(
        Category cat,
        const TransformedShape& shape,
        const Location& loc
    ) {
        const auto dim = shape.dimensions();
        for (std::size_t y = 0; y < dim.row(); ++y) {
            for (std::size_t x = 0; x < dim.col(); ++x) {
                if (shape.is_solid({y, x})) {
                    place(cat, loc + Location(y, x));
                }
            }
        }
    }

    bool try_place(Category cat, const Location& loc) {
        if (get(loc) == Category::none) {
            return false;
        }
        place(cat, loc);
        return true;
    }

    bool try_place(
        Category cat,
        const TransformedShape& shape,
        const Location& loc
    ) {
        const auto dim = shape.dimensions();
        for (std::size_t y = 0; y < dim.row(); ++y) {
            for (std::size_t x = 0; x < dim.col(); ++x) {
                if (!shape.is_solid({y, x})) {
                    continue;
                }
                auto&& cur = try_get(loc + Location(y, x));
                if (cur != Category::none) {
                    return false;
                }
            }
        }
        place(cat, shape, loc);
        return true;
    }

    private:
    Location m_dimensions;
    std::vector<Category> m_tiles;

    Category& ref(const Location& loc) {
        const auto index = loc.row() * m_dimensions.col() + loc.col();
        assert(index < m_tiles.size());
        return m_tiles[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const Board& self) {
        auto&& dim = self.dimensions();
        for (std::size_t y = 0; y < dim.row(); ++y) {
            for (std::size_t x = 0; x < dim.col(); ++x) {
                auto&& category = self.get({y, x});
                if constexpr (use_color) {
                    stream << get_category_color(category);
                }
                stream << get_category_color(category) << category;
            }
            if constexpr (use_color) {
                stream << ansi_reset << "\n";
            }
        }
        return stream;
    }
};

inline bool parse_board(
    std::istream& stream,
    Board& board,
    std::set<Category>& categories
) {
    std::string line;
    for (std::size_t y = 0; y < board.dimensions().row(); ++y) {
        std::getline(stream, line);
        auto end = std::min(board.dimensions().col(), line.size());
        for (std::size_t x = 0; x < end; ++x) {
            std::string str(1, line[x]);
            auto cat = parse_category(str);
            if (!cat) {
                std::cerr << "Invalid piece: " << str << "\n";
                return false;
            }
            categories.emplace(*cat);
            board.place(*cat, {y, x});
        }
    }
    return true;
}
