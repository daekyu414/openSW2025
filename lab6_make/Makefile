PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib

CC=gcc
AR=ar

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean all

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(LIB_DIR)/libfuncs.a $(OBJ_DIR)/main.o
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_DIR) -lfuncs -o $(BIN_DIR)/myapp

$(LIB_DIR)/libfuncs.a: $(OBJ_DIR)/func1.o $(OBJ_DIR)/func2.o
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*

mytest:
	echo $(OBJS)