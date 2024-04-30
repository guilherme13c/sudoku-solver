#include "Game.h"

bool Game::AStarSearch(void) {
    std::priority_queue<std::pair<int, Board>> pq;

    pq.push({0, board});

    while (!pq.empty()) {
        auto [heuristicValue, currentBoard] = pq.top();
        pq.pop();
        this->stats.expansion_count++;

        if (currentBoard.isFilled()) {
            this->board = currentBoard;
            return true;
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (currentBoard.at(i, j) == 0) {
                    for (int k = 1; k <= 9; k++) {
                        if (currentBoard.isValidMove(i, j, k)) {
                            auto copy = currentBoard;
                            copy.at(i, j) = k;
                            pq.push({heuristicValue + 1, copy});
                        }
                    }
                    goto next_iteration;
                }
            }
        }
    next_iteration: {};
    }

    return false;
}
