PROJ_DIR=$(abspath ..)
SRC_DIR=$(PROJ_DIR)/advanced_ops/src
OBJ_DIR=$(PROJ_DIR)/advanced_ops/obj
LIB_DIR=$(PROJ_DIR)/lib
INC_DIR=$(PROJ_DIR)/include

CC=gcc
AR=ar

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean all 

all: $(LIB_DIR)/libmyadvanced.a

$(LIB_DIR)/libmyadvanced.a: $(OBJ_DIR)/mypow.o $(OBJ_DIR)/mymod.o
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $^ -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/libmyadvanced.a