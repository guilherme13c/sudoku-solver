#include "Game.h"

bool Game::BreadthFirstSearch(void) {
    std::queue<Board> q;
    q.push(this->board);

    while (!q.empty()) {
        Board current = q.front();
        q.pop();
        this->stats.expansion_count++;

        if (current.isFilled()) {
            this->board = current;
            return true;
        }

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (current.at(row, col) == 0) {
                    for (int i = 1; i <= 9; i++) {
                        if (current.isValidMove(row, col, i)) {
                            Board copy = Board(current);
                            copy.at(row, col) = i;
                            q.push(copy);
                        }
                    }
                    goto next_iteration;
                }
            }
        }
    next_iteration: {} // jump to next iteration
    }

    return true;
}
