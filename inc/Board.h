#pragma once

#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>

class Board {
  private:
    u_int8_t *values;

  public:
    Board(void);
    Board(const Board &other);
    ~Board();
    Board &operator=(const Board &other);
    bool operator<(const Board &other) const;

    u_int8_t &at(const u_int8_t x, const u_int8_t y);
    u_int8_t &at(const u_int8_t x, const u_int8_t y) const;

    bool isFilled(void);
    bool isValidMove(int row, int col, int num);
    int countPossibleMoves(int row, int col) const;
    int countTotalPossibleMoves(void) const;

    void show(char sepNum = ' ', char sepLine = '\n');
};
