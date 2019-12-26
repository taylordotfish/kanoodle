#pragma once
#include <ostream>

enum class Flip {
    none,
    horizontal,
    end,
    begin = none,
};

std::ostream& operator<<(std::ostream& stream, Flip self) {
    switch (self) {
        case Flip::none: {
            stream << "[no flip]";
            break;
        }
        case Flip::horizontal: {
            stream << "[horizontal flip]";
            break;
        }
        default: {
            stream << "[unknown flip]";
            break;
        }
    }
    return stream;
}
