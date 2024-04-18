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
        this->BreadthFirstSearch();
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

bool Game::BreadthFirstSearch(void) {
    auto q = std::queue<Board>();

    q.push(this->board);

    while (!q.empty()) {
        Board current = q.front();
        q.pop();

        // current.show();
        // std::cout << std::endl;

        if (current.validateSolution()) {
            this->board = current;
            return true;
        }

        for (u_int8_t i = 0; i < 9; i++) {
            for (u_int8_t j = 0; j < 9; j++) {
                if (this->board.at(i, j) != 0)
                    continue;
                for (u_int8_t n = 1; n <= 9; n++) {
                    if (this->board.isValidMove(n, i, j)) {
                        Board nb = current;
                        nb.at(i, j) = n;
                        q.push(nb);
                    }
                }
            }
        }
    }

    return false;
}
