CC = g++
EXE = Poker
GFLAG = -Wall

all:$(EXE)

$(EXE): main.cpp sources/cartes.cpp headers/paquet.hpp sources/table.cpp  sources/table.cpp sources/joueurs.cpp sources/utile.cpp
	$(CC) -o $(EXE) main.cpp sources/cartes.cpp headers/paquet.hpp sources/table.cpp sources/joueurs.cpp sources/utile.cpp $(GFLAG)

clean:
	rm -f $(EXE)
