C_COMPILER=gcc
CFLAGS = -Wall -g

# Directories
ROOT = ../../

SRC_FILES=\
  $(wildcard ./*.c) \
  $(ROOT)utility/utility.c \
  $(ROOT)hashTable/dictionary/dict.c

INC_DIRS=\
  -I$(ROOT)utility/ \
  -I$(ROOT)hashTable/dictionary

LIBS=\
  -lm

OUTPUT_FILE=main

.PHONY: clean
.PHONY: test

test:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(LIBS) $(SRC_FILES) -o $(OUTPUT_FILE)
	./$(OUTPUT_FILE) -v
	dot -T png -O bh.dot

clean:
	rm -rf $(OUTPUT_FILE)
