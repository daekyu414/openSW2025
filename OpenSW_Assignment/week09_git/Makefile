PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin

CC=gcc
AR=ar

.PHONY: clean all

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(LIB_DIR)/libmyops.so.1.0
	$(CC) $(SRC_DIR)/myapp.c -I$(INC_DIR) -L$(LIB_DIR) -lmyops -lm -o $(BIN_DIR)/myapp

$(LIB_DIR)/libmyops.so.1.0: $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mypow.o
	$(CC) -fPIC -shared -Wl,-soname=libmyops.so.1 $^ -o $(LIB_DIR)/libmyops.so.1.0
	ln -s libmyops.so.1.0 $(LIB_DIR)/libmyops.so.1
	ln -s libmyops.so.1 $(LIB_DIR)/libmyops.so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -fPIC -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*