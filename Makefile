APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
LIB = ./lib
LIBS = -lm -led -L $(LIB)
SRC = ./src

FLAGS = -Wall
CC = gcc

all: libed clean_myapp myapps
	

libed: $(OBJ)/float_vector.o $(OBJ)/hello.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

myapps: \
	$(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	$(CC) $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/app


clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*

clean_myapp:
	rm -rf $(BIN)/*

