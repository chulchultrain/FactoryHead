


FH_DIR = $(shell pwd)

TE_DIR = $(FH_DIR)/TokenEvaluator
MG_DIR = $(FH_DIR)/MapGenerator
BS_DIR = $(FH_DIR)/BaseStats
MD_DIR = $(FH_DIR)/MoveData
ED_DIR = $(FH_DIR)/EntryData

FLAGS = -I$(FH_DIR) -c -Wall


MapGeneratorTester: $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o
	g++ -o MapGeneratorTester $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o

TypeTokenEvalTester: $(TE_DIR)/TypeTokenEvalTester.o $(TE_DIR)/TypeTokenEvaluator.o $(MG_DIR)/MapGenerator.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o
	g++ -o TypeTokenEvalTester $(TE_DIR)/TypeTokenEvalTester.o $(TE_DIR)/TypeTokenEvaluator.o $(MG_DIR)/MapGenerator.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o


$(MG_DIR)/MapGenerator.o: $(MG_DIR)/MapGenerator.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(MG_DIR)/MapGenerator.cpp -o $(MG_DIR)/MapGenerator.o

$(MG_DIR)/MapGeneratorTester.o: $(MG_DIR)/MapGeneratorTester.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(MG_DIR)/MapGeneratorTester.cpp -o $(MG_DIR)/MapGeneratorTester.o

$(TE_DIR)/TypeTokenEvaluator.o: $(TE_DIR)/TypeTokenEvaluator.cpp $(TE_DIR)/TypeTokenEvaluator.h
	g++ $(FLAGS) $(TE_DIR)/TypeTokenEvaluator.cpp -o $(TE_DIR)/TypeTokenEvaluator.o

$(TE_DIR)/TypeTokenEvalTester.o: $(TE_DIR)/TypeTokenEvaluator.h $(TE_DIR)/TypeTokenEvalTester.cpp
	g++ $(FLAGS) $(TE_DIR)/TypeTokenEvalTester.cpp -o $(TE_DIR)/TypeTokenEvalTester.o

$(BS_DIR)/BaseStats.o: $(BS_DIR)/BaseStats.h $(BS_DIR)/BaseStats.cpp
	g++ $(FLAGS) $(BS_DIR)/BaseStats.cpp -o $(BS_DIR)/BaseStats.o

$(MD_DIR)/MoveData.o: $(MD_DIR)/MoveData.h $(MD_DIR)/MoveData.cpp
	g++ $(FLAGS) $(MD_DIR)/MoveData.cpp -o $(MD_DIR)/MoveData.o

$(ED_DIR)/EntryData.o: $(ED_DIR)/EntryData.h $(ED_DIR)/EntryData.cpp
	g++ $(FLAGS) $(ED_DIR)/EntryData.cpp -o $(ED_DIR)/EntryData.o
