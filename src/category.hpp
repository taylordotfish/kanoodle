#pragma once
#include "output-config.hpp"
#include <ostream>
#include <optional>
#include <string_view>

enum class Category {
    none,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    end,
    begin = none,
};

inline std::string get_category_color(Category category) {
    switch (category) {
        case Category::A: {
            return "\x1b[1;48;5;202m";
        }
        case Category::B: {
            return "\x1b[1;37;48;5;160m";
        }
        case Category::C: {
            return "\x1b[1;37;48;5;19m";
        }
        case Category::D: {
            return "\x1b[22;30;48;5;217m";
        }
        case Category::E: {
            return "\x1b[1;37;48;5;28m";
        }
        case Category::F: {
            return "\x1b[22;30;48;5;255m";
        }
        case Category::G: {
            return "\x1b[22;30;48;5;117m";
        }
        case Category::H: {
            return "\x1b[1;37;48;5;201m";
        }
        case Category::I: {
            return "\x1b[22;30;48;5;220m";
        }
        case Category::J: {
            return "\x1b[1;37;48;5;90m";
        }
        case Category::K: {
            return "\x1b[22;30;48;5;112m";
        }
        case Category::L: {
            return "\x1b[22;30;48;5;250m";
        }
        case Category::none: {
            return "\x1b[22;39;49m";
        }
        default: {
            return "";
        }
    }
}

inline std::ostream& operator<<(std::ostream& stream, Category self) {
    if (self == Category::none) {
        if constexpr (use_unicode) {
            stream << "·";
        } else {
            stream << ".";
        }
        return stream;
    }

    auto value = static_cast<int>(self);
    auto end = static_cast<int>(Category::end);

    if (value >= end) {
        stream << "?";
        return stream;
    }
    stream.put('A' + value - static_cast<int>(Category::A));
    return stream;
}

inline std::optional<Category> parse_category(std::string_view str) {
    if (str.size() != 1) {
        return std::nullopt;
    }
    if (str == " " || str == ".") {
        return Category::none;
    }
    if (str[0] < 'A') {
        return std::nullopt;
    }
    int value = static_cast<int>(Category::A) + str[0] - 'A';
    if (value >= static_cast<int>(Category::end)) {
        return std::nullopt;
    }
    return static_cast<Category>(value);
}
