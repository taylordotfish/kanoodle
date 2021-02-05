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
