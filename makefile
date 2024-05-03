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

test: $(BUILD) test/generate_report.py
	test/easy/test.sh
	test/medium/test.sh
	test/hard/test.sh

	python3 test/generate_report.py

clean:
	rm -rf bin/TP1 test/*/*.txt test/data.csv test/*.png
