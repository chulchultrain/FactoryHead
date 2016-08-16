


FH_DIR = $(shell pwd)

TE_DIR = $(FH_DIR)/TokenEvaluator
MG_DIR = $(FH_DIR)/MapGenerator
BS_DIR = $(FH_DIR)/BaseStats
MD_DIR = $(FH_DIR)/MoveData
ED_DIR = $(FH_DIR)/EntryData
EF_DIR = $(FH_DIR)/EntryFilter


FLAGS = -I$(FH_DIR) -c -Wall

EntryFilterTester: $(EF_DIR)/EntryFilterTester.o $(EF_DIR)/EntryFilter.o $(MG_DIR)/MapGenerator.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o
	g++ -o EntryFilterTester $(EF_DIR)/EntryFilterTester.o $(EF_DIR)/EntryFilter.o $(MG_DIR)/MapGenerator.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o

MapGeneratorTester: $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o
	g++ -o MapGeneratorTester $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o

TokenEvalTester: $(TE_DIR)/TokenEvalTester.o $(TE_DIR)/TypeTokenEvaluator.o $(MG_DIR)/MapGenerator.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o
	g++ -o TokenEvalTester $(TE_DIR)/TokenEvalTester.o $(TE_DIR)/TypeTokenEvaluator.o $(MG_DIR)/MapGenerator.o $(BS_DIR)/BaseStats.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o


$(MG_DIR)/MapGenerator.o: $(MG_DIR)/MapGenerator.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(MG_DIR)/MapGenerator.cpp -o $(MG_DIR)/MapGenerator.o

$(MG_DIR)/MapGeneratorTester.o: $(MG_DIR)/MapGeneratorTester.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(MG_DIR)/MapGeneratorTester.cpp -o $(MG_DIR)/MapGeneratorTester.o

$(TE_DIR)/TypeTokenEvaluator.o: $(TE_DIR)/TypeTokenEvaluator.cpp $(TE_DIR)/TypeTokenEvaluator.h $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(TE_DIR)/TypeTokenEvaluator.cpp -o $(TE_DIR)/TypeTokenEvaluator.o

$(TE_DIR)/NameTokenEvaluator.o: $(TE_DIR)/NameTokenEvaluator.cpp $(TE_DIR)/NameTokenEvaluator.h $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(TE_DIR)/NameTokenEvaluator.cpp -o $(TE_DIR)/NameTokenEvaluator.o

$(TE_DIR)/TokenEvalTester.o: $(TE_DIR)/NameTokenEvaluator.h $(TE_DIR)/TypeTokenEvaluator.h $(TE_DIR)/MoveTokenEvaluator.h $(TE_DIR)/TokenEvalTester.cpp
	g++ $(FLAGS) $(TE_DIR)/TokenEvalTester.cpp -o $(TE_DIR)/TokenEvalTester.o

$(TE_DIR)/MoveTokenEvaluator.o: $(TE_DIR)/MoveTokenEvaluator.cpp $(TE_DIR)/MoveTokenEvaluator.h $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) $(TE_DIR)/MoveTokenEvaluator.cpp -o $(TE_DIR)/MoveTokenEvaluator.o

$(BS_DIR)/BaseStats.o: $(BS_DIR)/BaseStats.h $(BS_DIR)/BaseStats.cpp
	g++ $(FLAGS) $(BS_DIR)/BaseStats.cpp -o $(BS_DIR)/BaseStats.o

$(MD_DIR)/MoveData.o: $(MD_DIR)/MoveData.h $(MD_DIR)/MoveData.cpp
	g++ $(FLAGS) $(MD_DIR)/MoveData.cpp -o $(MD_DIR)/MoveData.o

$(ED_DIR)/EntryData.o: $(ED_DIR)/EntryData.h $(ED_DIR)/EntryData.cpp
	g++ $(FLAGS) $(ED_DIR)/EntryData.cpp -o $(ED_DIR)/EntryData.o

$(EF_DIR)/EntryFilter.o: $(EF_DIR)/EntryFilter.h $(EF_DIR)/EntryFilter.cpp $(TE_DIR)/TypeTokenEvaluator.h $(TE_DIR)/MoveTokenEvaluator.h $(TE_DIR)/NameTokenEvaluator.h 
	g++ $(FLAGS) -o $(EF_DIR)/EntryFilter.o $(EF_DIR)/EntryFilter.cpp

$(EF_DIR)/EntryFilterTester.o: $(EF_DIR)/EntryFilter.h $(EF_DIR)/EntryFilterTester.cpp
	g++ $(FLAGS) -o $(EF_DIR)/EntryFilterTester.o $(EF_DIR)/EntryFilterTester.cpp
