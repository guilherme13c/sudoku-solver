#include "Game.h"

bool Game::GreedyBestFirstSearch(void) {
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

        int best_i = 0, best_j = 0, min_possibilities = 9;
        std::vector<bool> ns(9, false);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (currentBoard.at(i, j) == 0) {
                    int count = 0;
                    std::vector<bool> ns_tmp(9, false);
                    for (int k = 1; k <= 9; k++) {
                        ns_tmp[k - 1] = currentBoard.isValidMove(i, j, k);
                        if (ns_tmp[k - 1])
                            count++;
                    }
                    if (min_possibilities > count) {
                        best_i = i;
                        best_j = j;
                        min_possibilities = count;
                        ns = ns_tmp;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            if (ns[i]) {
                auto copy = currentBoard;
                copy.at(best_i, best_j) = (i+1);
                pq.push({-min_possibilities, copy});
            }
        }
    }

    return false;
}
