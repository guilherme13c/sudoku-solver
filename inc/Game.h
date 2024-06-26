#pragma once

#include "Board.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <queue>

enum Algorithm {
    BREADTH_FIRST_SEARCH = 'B',
    ITERATIVE_DEEPENING_SEARCH = 'I',
    UNIFORM_COST_SEARCH = 'U',
    A_STAR_SEARCH = 'A',
    GREEDY_BEST_FIRST_SEARCH = 'G'
};

struct GameStats {
    int64_t t;
    u_int64_t expansion_count;
};

class Game {
  private:
    Algorithm algo;
    Board board;
    GameStats stats;

    bool BreadthFirstSearch(void);

    bool IterativeDeepeningSearch(void);
    bool depthLimitedSearch(int depth);

    bool UniformCostSearch(void);

    bool GreedyBestFirstSearch(void);

    bool AStarSearch(void);

  public:
    Game(int argc, char *argv[]);
    void printBoard(char sepNum = ' ', char sepLine = '\n');
    void Solve(void);
    struct GameStats getStats(void);
};
