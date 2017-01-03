C_COMPILER=gcc
CFLAGS = -Wall -g

SRC_FILES=\
  $(wildcard ./*.c)
OUTPUT_FILE=main
LIBS = -lm

.PHONY: clean
.PHONY: test

test:
	$(C_COMPILER) $(CFLAGS) $(SRC_FILES) $(LIBS) -o $(OUTPUT_FILE)
	./$(OUTPUT_FILE) -v

clean:
	rm -rf $(OUTPUT_FILE)
