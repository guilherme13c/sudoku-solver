#include "Game.h"

Game::Game(int argc, char *argv[]) {
    assert(argc == 11);

    assert(argv[1][0] == BREADTH_FIRST_SEARCH ||
           argv[1][0] == ITERATIVE_DEEPENING_SEARCH ||
           argv[1][0] == UNIFORM_COST_SEARCH || argv[1][0] == A_STAR_SEARCH ||
           argv[1][0] == GREEDY_BEST_FIRST_SEARCH);

    this->algo = (Algorithm)argv[1][0];
    this->stats.expansion_count = 0;
    this->stats.t = (time_t)0;

    for (auto i = 0; i < 9; i++) {
        for (auto j = 0; j < 9; j++) {
            u_int8_t n = argv[2 + i][j];
            this->board.at(i, j) = n - '0';
        }
    }
}

void Game::printBoard(char sepNum, char sepLine) {
    this->board.show(sepNum, sepLine);
}

void Game::Solve(void) {
    this->stats.expansion_count = 0;
    this->stats.t = (time_t)0;

    auto starting_time = std::chrono::high_resolution_clock::now();

    switch (this->algo) {
    case BREADTH_FIRST_SEARCH:
        this->BreadthFirstSearch();
        break;

    case ITERATIVE_DEEPENING_SEARCH:
        this->IterativeDeepeningSearch();
        break;

    case UNIFORM_COST_SEARCH:
        this->UniformCostSearch();
        break;

    case A_STAR_SEARCH:
        this->AStarSearch();
        break;

    case GREEDY_BEST_FIRST_SEARCH:
        this->GreedyBestFirstSearch();
        break;

    default:
        break;
    }

    auto ending_time = std::chrono::high_resolution_clock::now();
    this->stats.t = std::chrono::duration_cast<std::chrono::milliseconds>(
                        ending_time - starting_time)
                        .count();

    return;
}

struct GameStats Game::getStats(void) { return this->stats; }
