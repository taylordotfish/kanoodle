/*
 * Copyright (C) 2019 taylor.fish <contact@taylor.fish>
 *
 * This file is part of kanoodle-solver.
 *
 * kanoodle-solver is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * kanoodle-solver is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with kanoodle-solver. If not, see <https://www.gnu.org/licenses/>.
 */

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
