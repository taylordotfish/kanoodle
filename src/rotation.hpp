#pragma once
#include <ostream>

enum class Rotation {
    deg0,
    deg90,
    deg180,
    deg270,
    end,
    begin = deg0,
};

std::ostream& operator<<(std::ostream& stream, Rotation self) {
    switch (self) {
        case Rotation::deg0: {
            stream << "0°";
            break;
        }
        case Rotation::deg90: {
            stream << "90°";
            break;
        }
        case Rotation::deg180: {
            stream << "180°";
            break;
        }
        case Rotation::deg270: {
            stream << "270°";
            break;
        }
        default: {
            stream << "?°";
            break;
        }
    }
    return stream;
}
