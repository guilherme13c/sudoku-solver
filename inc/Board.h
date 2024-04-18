#pragma once

#include <cassert>
#include <cstring>
#include <iostream>

class Board {
  private:
    u_int8_t *values;

  public:
    Board(void);
    Board(const Board &other);
    ~Board();
    Board &operator=(const Board &other);

    u_int8_t &at(const u_int8_t x, const u_int8_t y);

    bool validateSolution(void);
    bool isValidMove(const u_int8_t val, const u_int8_t x, const u_int8_t y);

    void show(char sepNum = ' ', char sepLine = '\n');
};
