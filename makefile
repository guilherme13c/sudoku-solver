CC := g++
CFLAGS := -Wall -O3 -Iinc

SRC := $(shell ls src/*)
BUILD := bin/TP1

$(shell mkdir -p src bin inc test)

build: $(TARGET)
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD)

debug: $(TARGET)
	$(CC) $(CFLAGS) -g $(SRC) -o $(BUILD)

test: $(BUILD)
	$(BUILD) B 107006450 025340008 060001070 053000029 610009800 000602007 001093200 008000000 040078591

clean: $(BUILD)
	rm -rf bin/TP1
