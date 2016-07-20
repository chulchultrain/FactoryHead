


FH_DIR = $(shell pwd)

T_DIR = $(FH_DIR)/Token
TE_DIR = $(FH_DIR)/TokenEvaluator
MG_DIR = $(FH_DIR)/MapGenerator


FLAGS = -I$(FH_DIR) -c -Wall

TOKEN_OBJS = $(T_DIR)/TypeToken.o $(T_DIR)/NameToken.o $(T_DIR)/MoveToken.o

TokenTester: $(T_DIR)/TypeToken.o $(T_DIR)/TokenTester.o
	g++ -o TokenTester $(T_DIR)/TypeToken.o $(T_DIR)/TokenTester.o

$(T_DIR)/TypeToken.o: $(T_DIR)/Token.h $(T_DIR)/TypeToken.h $(T_DIR)/TypeToken.cpp
	g++ $(FLAGS) $(T_DIR)/TypeToken.cpp -o $(T_DIR)/TypeToken.o

$(T_DIR)/TokenTester.o: $(T_DIR)/TypeToken.h $(T_DIR)/TokenTester.cpp
	g++ $(FLAGS) $(T_DIR)/TokenTester.cpp -o $(T_DIR)/TokenTester.o



