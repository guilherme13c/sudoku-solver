#include "Board.h"

u_int8_t &Board::at(const u_int8_t x, const u_int8_t y) {
    return this->values[x * 9 + y];
}

Board::Board(void) {
    this->values = new u_int8_t[9 * 9];
    assert(this->values != nullptr);
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

bool Board::isFilled(void) {
    for (auto i = 0; i < 81; i++) {
        if (this->values[i] == 0)
            return false;
    }
    return true;
}
