CC := g++
CFLAGS := -Wall -Iinc -Wno-sign-compare

ALGOS := $(shell ls src/algorithms/*)
SRC := src/main.cpp src/Board.cpp src/Game.cpp $(ALGOS)
BUILD := bin/TP1

$(shell mkdir -p src bin inc test)

build: $(TARGET)
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD) -O3

debug: $(TARGET)
	$(CC) $(CFLAGS) -g $(SRC) -o $(BUILD)

test: $(BUILD)
	$(BUILD) B 530070000 600195000 098000060 800060003 400803001 700020006 060000280 000419005 000080079
	$(BUILD) I 530070000 600195000 098000060 800060003 400803001 700020006 060000280 000419005 000080079

clean: $(BUILD)
	rm -rf bin/TP1
