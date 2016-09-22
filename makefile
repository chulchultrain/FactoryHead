


FH_DIR = $(shell pwd)

TE_DIR = $(FH_DIR)/TokenEvaluator
MG_DIR = $(FH_DIR)/MapGenerator
MD_DIR = $(FH_DIR)/MoveData
ED_DIR = $(FH_DIR)/EntryData
EF_DIR = $(FH_DIR)/EntryFilter
PE_DIR = $(FH_DIR)/PokemonEntry
WS_DIR = $(FH_DIR)/WorkingStats
DR_DIR = $(FH_DIR)/DataResolution
BS_DIR = $(FH_DIR)/BattleSim
BE_DIR = $(FH_DIR)/BattleEvaluator

FLAGS = -I$(FH_DIR) -c -Wall

BattleSimulator: $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(PE_DIR)/PokemonEntry.o $(PE_DIR)/PokemonEntryTester.o $(WS_DIR)/WorkingStats.o $(EF_DIR)/EntryFilter.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o $(BS_DIR)/BattleSim.o $(BS_DIR)/BattleSimulator.o
	g++ -o BattleSimulator $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(PE_DIR)/PokemonEntry.o $(WS_DIR)/WorkingStats.o $(EF_DIR)/EntryFilter.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o $(BS_DIR)/BattleSim.o $(BS_DIR)/BattleSimulator.o

BattleEvaluatorTester: $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(PE_DIR)/PokemonEntry.o $(PE_DIR)/PokemonEntryTester.o $(WS_DIR)/WorkingStats.o $(EF_DIR)/EntryFilter.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o $(BE_DIR)/BattleEvaluator.o $(BE_DIR)/BattleEvalTester.o
	g++ -o BattleEvaluatorTester $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(PE_DIR)/PokemonEntry.o $(WS_DIR)/WorkingStats.o $(EF_DIR)/EntryFilter.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o $(BE_DIR)/BattleEvaluator.o $(BE_DIR)/BattleEvalTester.o

PokemonEntryTester:$(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(PE_DIR)/PokemonEntry.o $(PE_DIR)/PokemonEntryTester.o $(WS_DIR)/WorkingStats.o $(EF_DIR)/EntryFilter.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o
	g++ -o PokemonEntryTester $(MG_DIR)/MapGenerator.o  $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(PE_DIR)/PokemonEntry.o $(PE_DIR)/PokemonEntryTester.o $(WS_DIR)/WorkingStats.o $(EF_DIR)/EntryFilter.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o

EntryFilterTester: $(EF_DIR)/EntryFilterTester.o $(EF_DIR)/EntryFilter.o $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o
	g++ -o EntryFilterTester $(EF_DIR)/EntryFilterTester.o $(EF_DIR)/EntryFilter.o $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o

MapGeneratorTester: $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o  $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o
	g++ -o MapGeneratorTester $(MG_DIR)/MapGenerator.o $(MG_DIR)/MapGeneratorTester.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o

TokenEvalTester: $(TE_DIR)/TokenEvalTester.o $(TE_DIR)/TypeTokenEvaluator.o $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o
	g++ -o TokenEvalTester $(TE_DIR)/TokenEvalTester.o $(TE_DIR)/TypeTokenEvaluator.o $(MG_DIR)/MapGenerator.o  $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o

DataResolutionTester:$(EF_DIR)/EntryFilter.o $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o $(DR_DIR)/DataResolution.o $(DR_DIR)/DataResolutionTester.o $(WS_DIR)/WorkingStats.o
	g++ -o DataResolutionTester $(EF_DIR)/EntryFilter.o $(MG_DIR)/MapGenerator.o $(MD_DIR)/MoveData.o $(ED_DIR)/EntryData.o $(TE_DIR)/TypeTokenEvaluator.o $(TE_DIR)/NameTokenEvaluator.o $(TE_DIR)/MoveTokenEvaluator.o $(DR_DIR)/DataResolution.o $(DR_DIR)/DataResolutionTester.o $(WS_DIR)/WorkingStats.o

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

$(MD_DIR)/MoveData.o: $(MD_DIR)/MoveData.h $(MD_DIR)/MoveData.cpp
	g++ $(FLAGS) $(MD_DIR)/MoveData.cpp -o $(MD_DIR)/MoveData.o

$(ED_DIR)/EntryData.o: $(ED_DIR)/EntryData.h $(ED_DIR)/EntryData.cpp
	g++ $(FLAGS) $(ED_DIR)/EntryData.cpp -o $(ED_DIR)/EntryData.o

$(EF_DIR)/EntryFilter.o: $(EF_DIR)/EntryFilter.h $(EF_DIR)/EntryFilter.cpp $(TE_DIR)/TypeTokenEvaluator.h $(TE_DIR)/MoveTokenEvaluator.h $(TE_DIR)/NameTokenEvaluator.h 
	g++ $(FLAGS) -o $(EF_DIR)/EntryFilter.o $(EF_DIR)/EntryFilter.cpp

$(EF_DIR)/EntryFilterTester.o: $(EF_DIR)/EntryFilter.h $(EF_DIR)/EntryFilterTester.cpp
	g++ $(FLAGS) -o $(EF_DIR)/EntryFilterTester.o $(EF_DIR)/EntryFilterTester.cpp

$(PE_DIR)/PokemonEntry.o: $(PE_DIR)/PokemonEntry.h $(PE_DIR)/PokemonEntry.cpp $(WS_DIR)/WorkingStats.h
	 g++ $(FLAGS) -o $(PE_DIR)/PokemonEntry.o $(PE_DIR)/PokemonEntry.cpp

$(PE_DIR)/PokemonEntryTester.o:$(PE_DIR)/PokemonEntry.h $(PE_DIR)/PokemonEntryTester.cpp
	g++ $(FLAGS) -o $(PE_DIR)/PokemonEntryTester.o $(PE_DIR)/PokemonEntryTester.cpp

$(WS_DIR)/WorkingStats.o:$(WS_DIR)/WorkingStats.h $(WS_DIR)/WorkingStats.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) -o $(WS_DIR)/WorkingStats.o $(WS_DIR)/WorkingStats.cpp

$(DR_DIR)/DataResolution.o:$(DR_DIR)/DataResolution.h $(DR_DIR)/DataResolution.cpp $(MG_DIR)/MapGenerator.h
	g++ $(FLAGS) -o $(DR_DIR)/DataResolution.o $(DR_DIR)/DataResolution.cpp

$(DR_DIR)/DataResolutionTester.o:$(DR_DIR)/DataResolution.h $(DR_DIR)/DataResolutionTester.cpp
	g++ $(FLAGS) -o  $(DR_DIR)/DataResolutionTester.o $(DR_DIR)/DataResolutionTester.cpp

$(BS_DIR)/BattleSim.o: $(BS_DIR)/BattleSim.h $(BS_DIR)/BattleSim.cpp
	g++ $(FLAGS) -o $(BS_DIR)/BattleSim.o $(BS_DIR)/BattleSim.cpp

$(BS_DIR)/BattleSimulator.o: $(BS_DIR)/BattleSim.h $(BS_DIR)/BattleSimulator.cpp
	g++ $(FLAGS) -o $(BS_DIR)/BattleSimulator.o $(BS_DIR)/BattleSimulator.cpp


$(BE_DIR)/BattleEvaluator.o: $(BE_DIR)/BattleEvaluator.h $(BE_DIR)/BattleEvaluator.cpp
	g++ $(FLAGS) -o $(BE_DIR)/BattleEvaluator.o $(BE_DIR)/BattleEvaluator.cpp

$(BE_DIR)/BattleEvalTester.o: $(BE_DIR)/BattleEvalTester.cpp $(BE_DIR)/BattleEvaluator.h
	g++ $(FLAGS) -o $(BE_DIR)/BattleEvalTester.o $(BE_DIR)/BattleEvalTester.cpp
