CC := g++
CFLAGS := -Wall -Iinc -Wno-sign-compare

SRC := $(shell ls src/*)
BUILD := bin/TP1

$(shell mkdir -p src bin inc test)

build: $(TARGET)
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD) -O3

debug: $(TARGET)
	$(CC) $(CFLAGS) -g $(SRC) -o $(BUILD)

test: $(BUILD)
	$(BUILD) I 530070000 600195000 098000060 800060003 400803001 700020006 060000280 000419005 000080079

clean: $(BUILD)
	rm -rf bin/TP1
