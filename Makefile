# Eric Chun - jc2ppp - 10/10/20 - Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG = -g
OBJECTS = wordPuzzle.o hashTable.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

getWordInGrid.o: getWordInGrid.cpp
hashTable.o: hashTable.cpp hashTable.h
primenumber.o: primenumber.cpp
wordPuzzle.o: wordPuzzle.cpp hashTable.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
