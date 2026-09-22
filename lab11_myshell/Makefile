PROJ_DIR = $(shell pwd)
SRC_DIR = $(PROJ_DIR)/src
OBJ_DIR = $(PROJ_DIR)/obj
INC_DIR = $(PROJ_DIR)/include
BIN_DIR = $(PROJ_DIR)/bin

OBJS = $(OBJ_DIR)/myshell.o $(OBJ_DIR)/do_exec.o

all: $(BIN_DIR)/myshell

$(BIN_DIR)/myshell: $(OBJS)
	gcc $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $^ -o $@ -I$(INC_DIR)

clean: 
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*