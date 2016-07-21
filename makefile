


FH_DIR = $(shell pwd)

T_DIR = $(FH_DIR)/Token
TE_DIR = $(FH_DIR)/TokenEvaluator
MG_DIR = $(FH_DIR)/MapGenerator


FLAGS = -I$(FH_DIR) -c -Wall

TOKEN_OBJS = $(T_DIR)/Token.o

TokenTester: $(T_DIR)/Token.o $(T_DIR)/TokenTester.o
	g++ -o TokenTester $(T_DIR)/Token.o $(T_DIR)/TokenTester.o

$(T_DIR)/Token.o: $(T_DIR)/Token.h  $(T_DIR)/Token.cpp
	g++ $(FLAGS) $(T_DIR)/Token.cpp -o $(T_DIR)/Token.o

$(T_DIR)/TokenTester.o: $(T_DIR)/Token.h $(T_DIR)/TokenTester.cpp
	g++ $(FLAGS) $(T_DIR)/TokenTester.cpp -o $(T_DIR)/TokenTester.o



