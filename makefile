CC := g++
CFLAGS := -Wall -Iinc -Wno-sign-compare

ALGOS := $(shell ls src/algorithms/*)
SRC := src/main.cpp src/Board.cpp src/Game.cpp $(ALGOS)
BUILD := bin/TP1

SUDOKU := 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400

$(shell mkdir -p src bin inc test)

$(BUILD): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD)

debug: $(SRC)
	$(CC) $(CFLAGS) -g $(SRC) -o $(BUILD)

test: $(BUILD)
	$(BUILD) B $(SUDOKU)
	$(BUILD) I $(SUDOKU)
	$(BUILD) U $(SUDOKU)

clean: $(BUILD)
	rm -rf bin/TP1
