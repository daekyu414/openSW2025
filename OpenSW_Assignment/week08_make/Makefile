PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin

CC=gcc
AR=ar

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean all basic

all: $(BIN_DIR)/myapp

basic: $(LIB_DIR)/libmybasic.a

$(BIN_DIR)/myapp: $(LIB_DIR)/libmybasic.a $(OBJ_DIR)/myapp.o
	$(CC) $(OBJ_DIR)/myapp.o -L$(LIB_DIR) -lmybasic -o $(BIN_DIR)/myapp

$(LIB_DIR)/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/div.o $(OBJ_DIR)/mul.o
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $^ -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myapp