#include "Game.h"

bool Game::IterativeDeepeningSearch(void) {
    for (int depth = 0; depth <= 81; depth++) {
        if (this->depthLimitedSearch(depth))
            return true;
    }

    return false;
}

bool Game::depthLimitedSearch(int depth) {
    if (depth == 0) {
        return this->board.isFilled();
    }
    this->stats.expansion_count++;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.at(i, j) == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (this->board.isValidMove(i, j, num)) {
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
