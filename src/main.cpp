#include "Game.h"

int main(int argc, char **argv) {
    auto g = Game(argc, argv);

    g.Solve();

    auto stats = g.getStats();

    std::cout << stats.expansion_count << " " << stats.t << std::endl;

    g.printBoard('\v', ' ');

    return 0;
}
