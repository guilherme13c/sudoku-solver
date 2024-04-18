#include "Board.h"

u_int8_t &Board::at(const u_int8_t x, const u_int8_t y) {
    return this->values[x * 9 + y];
}

Board::Board(void) {
    this->values = new u_int8_t[9 * 9];
    assert(this->values != nullptr);
}

bool Board::validateSolution() {
    for (int i = 0; i < 9; ++i) {
        bool rowFlags[9] = {false};
        bool colFlags[9] = {false};
        for (int j = 0; j < 9; ++j) {
            if (this->at(i, j) != 0 && rowFlags[this->at(i, j) - 1]) {
                return false;
            }
            rowFlags[this->at(i, j) - 1] = true;

            if (this->at(i, j) != 0 && colFlags[this->at(i, j) - 1]) {
                return false;
            }
            colFlags[this->at(i, j) - 1] = true;
        }
    }

    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            bool subgridFlags[9] = {false};
            for (int i = row; i < row + 3; ++i) {
                for (int j = col; j < col + 3; ++j) {
                    if (this->at(i, j) != 0 &&
                        subgridFlags[this->at(i, j) - 1]) {
                        return false;
                    }
                    subgridFlags[this->at(i, j) - 1] = true;
                }
            }
        }
    }

    return true;
}

bool Board::isValidMove(const u_int8_t val, const u_int8_t x,
                        const u_int8_t y) {
    if (this->at(x, y) != 0)
        return false;

    for (int i = 0; i < 9; ++i) {
        if (this->at(x, i) == val || this->at(i, y) == val) {
            return false;
        }
    }

    int subgridStartX = (x / 3) * 3;
    int subgridStartY = (y / 3) * 3;
    for (int i = subgridStartX; i < subgridStartX + 3; ++i) {
        for (int j = subgridStartY; j < subgridStartY + 3; ++j) {
            if (this->at(i, j) == val) {
                return false;
            }
        }
    }

    return true;
}

Board::Board(const Board &other) {
    values = new u_int8_t[9 * 9];

    memcpy(values, other.values, 9 * 9 * sizeof(u_int8_t));
}

Board::~Board() { delete[] values; }

Board &Board::operator=(const Board &other) {
    if (this != &other) {
        delete[] values;

        values = new u_int8_t[9 * 9];

        memcpy(values, other.values, 9 * 9 * sizeof(u_int8_t));
    }
    return *this;
}

void Board::show(char sepNum, char sepLine) {
    for (auto i = 0; i < 9; i++) {
        for (auto j = 0; j < 9; j++) {
            std::cout << (int)this->at(i, j) << sepNum;
        }
        std::cout << sepLine;
    }
}
