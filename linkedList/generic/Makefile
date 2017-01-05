C_COMPILER=gcc
CFLAGS = -Wall -g

# Directories
ROOT = ../../

SRC_FILES=\
  $(wildcard ./*.c) \
  $(ROOT)utility/utility.c

INC_DIRS=\
  -I$(ROOT)utility/

LIBS=\
  -lm

OUTPUT_FILE=main

.PHONY: clean
.PHONY: test

test:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(LIBS) $(SRC_FILES) -o $(OUTPUT_FILE)
	./$(OUTPUT_FILE) -v

clean:
	rm -rf $(OUTPUT_FILE)
