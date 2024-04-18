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
            this->board[i][j] = n - '0';
        }
    }
}

void Game::printBoard(void) {
    for (auto i = 0; i < 9; i++) {
        for (auto j = 0; j < 9; j++) {
            std::cout << (int)this->board[i][j];
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

void Game::Solve(void) {
    this->stats.expansion_count = 0;
    this->stats.t = (time_t)0;

    auto starting_time = time(nullptr);

    switch (this->algo) {
    case BREADTH_FIRST_SEARCH:
        // call function
        break;

    case ITERATIVE_DEEPENING_SEARCH:
        // call function
        break;

    case UNIFORM_COST_SEARCH:
        // call function
        break;

    case A_STAR_SEARCH:
        // call function
        break;

    case GREEDY_BEST_FIRST_SEARCH:
        // call function
        break;

    default:
        break;
    }

    auto ending_time = time(nullptr);
    this->stats.t = ending_time - starting_time;

    return;
}

struct GameStats Game::getStats(void) { return this->stats; }
