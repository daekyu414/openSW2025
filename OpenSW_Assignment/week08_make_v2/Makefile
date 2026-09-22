PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin
MY_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

CC=gcc
AR=ar

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean all basic_ops advanced_ops

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(MY_LIBS) 
	$(CC) $< -I$(INC_DIR) -L$(LIB_DIR) -lmybasic -lmyadvanced -lm -o $@

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops: 
	$(MAKE) -C advanced_ops

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean