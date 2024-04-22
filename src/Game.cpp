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

    auto starting_time = time(nullptr);

    switch (this->algo) {
    case BREADTH_FIRST_SEARCH:
        // call function
        break;

    case ITERATIVE_DEEPENING_SEARCH:
        this->IterativeDeepeningSearch();
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

bool Game::IterativeDeepeningSearch(void) {
    for (int depth = 1; depth <= 81; depth++) {
        if (this->depthLimitedSearch(depth))
            return true;
    }

    return false;
}

bool Game::depthLimitedSearch(int depth) {
    if (depth == 0) {
        return this->board.isFilled();
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.at(i, j) == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (this->isValidMove(i, j, num)) {
                        this->stats.expansion_count++;
                        board.at(i, j) = num;
                        if (this->depthLimitedSearch(depth - 1)) {
                            return true;
                        }
                        board.at(i, j) = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}

bool Game::isValidMove(int row, int col, int num) {
    if (this->board.at(row, col) != 0) {
        return false;
    }

    for (int i = 0; i < 9; ++i) {
        if (this->board.at(row, i) == num || this->board.at(i, col) == num ||
            board.at(row - row % 3 + i / 3, col - col % 3 + i % 3) == num) {
            return false;
        }
    }

    return true;
}
