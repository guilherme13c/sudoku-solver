# Sudoku Solver

This project is a sudoku solver made for the Artificial Inteligence course of [UFMG](https://ufmg.br/).

# How to use

## Build the program

To build the program on a Unix environment, you can use the command:

``` bash
make
```

**Obs: This program depends on `g++` and `gnu make`. Make sure you have both programs installed before running the build command.**

## Solve a sudoku problem

The program implements 5 different algorithms to solve a given instance of the game. The algorithms are the following:

| Code | Algorithm                  |
|------|----------------------------|
| B    | Breadth-first search       |
| I    | Iterative deepening search |
| U    | Uniform-cost search        |
| A    | A* search                  |
| G    | Greedy best-first search   |

In order to run execute the program, one can run the command:

``` bash
bin/TP1 [algorithm-code] [game-instance-lines]
```

For example:

``` bash
bin/TP1 A 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400
```

Where each of the 9 following parameters represent a line of the game (0 represents an empty cell on the grid). The lines must be given in order.
