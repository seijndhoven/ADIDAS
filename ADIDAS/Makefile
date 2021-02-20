CC 			= gcc

CFLAGS 			= -Wall -Werror -Wextra -pedantic -Wno-unused-parameter -ggdb -Og -std=c99 $(INC_DIRS)

INC_DIR 		= ./inc
LIB_DIR			= ./lib
SRC_DIR 		= ./src
INC_DIRS		= -I$(INC_DIR) -I$(SRC_DIR)

TESTFILE 		= Makefile

HEADER_FILES	        = $(INC_DIR)/*.h

SHARED_OBJ_FILES        = $(SRC_DIR)/channel.o \
			  $(SRC_DIR)/encode.o \
		      	  $(SRC_DIR)/decode.o \
			  $(SRC_DIR)/io.o \
		          $(SRC_DIR)/parity.o

TARGETS 		= encode channel decode

.PHONY:	all clean

all: $(TARGETS)

encode:	$(SRC_DIR)/encode_main.o $(SHARED_OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

channel: $(SRC_DIR)/channel_main.o $(SHARED_OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

decode:	$(SRC_DIR)/decode_main.o $(SHARED_OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

.c.o: $(HEADER_FILES)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(TARGETS) $(SRC_DIR)/*.o
