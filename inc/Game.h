#pragma once

#include <cassert>
#include <iostream>

enum Algorithm {
    BREADTH_FIRST_SEARCH = 'B',
    ITERATIVE_DEEPENING_SEARCH = 'I',
    UNIFORM_COST_SEARCH = 'U',
    A_STAR_SEARCH = 'A',
    GREEDY_BEST_FIRST_SEARCH = 'G'
};

struct GameStats {
    time_t t;
    u_int16_t expansion_count;
};

class Game {
  private:
    Algorithm algo;
    u_int8_t board[9][9];
    GameStats stats;

  public:
    Game(int argc, char *argv[]);
    void printBoard(void);
    void Solve(void);
    struct GameStats getStats(void);
};
