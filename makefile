


FH_DIR = $(shell pwd)

T_DIR = $(FH_DIR)/Token
TE_DIR = $(FH_DIR)/TokenEvaluator
MG_DIR = $(FH_DIR)/MapGenerator


FLAGS = -I$(FH_DIR) -c -Wall

TOKEN_OBJS = $(T_DIR)/Token.o

MapGeneratorTester: $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o
	g++ -o MapGeneratorTester $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o

TokenTester: $(T_DIR)/Token.o $(T_DIR)/TokenTester.o
	g++ -o TokenTester $(T_DIR)/Token.o $(T_DIR)/TokenTester.o

$(T_DIR)/Token.o: $(T_DIR)/Token.h  $(T_DIR)/Token.cpp
	g++ $(FLAGS) $(T_DIR)/Token.cpp -o $(T_DIR)/Token.o

$(T_DIR)/TokenTester.o: $(T_DIR)/Token.h $(T_DIR)/TokenTester.cpp
	g++ $(FLAGS) $(T_DIR)/TokenTester.cpp -o $(T_DIR)/TokenTester.o


$(MG_DIR)/MapGenerator.o: $(MG_DIR)/MapGenerator.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(MG_DIR)/MapGenerator.cpp -o $(MG_DIR)/MapGenerator.o

$(MG_DIR)/MapGeneratorTester.o: $(MG_DIR)/MapGeneratorTester.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(MG_DIR)/MapGeneratorTester.cpp -o $(MG_DIR)/MapGeneratorTester.o
