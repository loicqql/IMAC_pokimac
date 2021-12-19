CC=g++
CFLAGS=-Wall -ansi

pokimac: build/game.o build/main.o  build/map.o build/player.o build/pokimac.o build/cell.o
	$(CC) -o $@ $^

build/main.o: src/main.cpp
	$(CC) -o $@ -c $<

build/game.o: src/class/Game/Game.cpp src/class/Game/Game.h
	$(CC) -o $@ -c $<

build/map.o: src/class/Map/Map.cpp src/class/Map/Map.h
	$(CC) -o $@ -c $<

build/player.o: src/class/Player/Player.cpp src/class/Player/Player.h
	$(CC) -o $@ -c $<

build/pokimac.o: src/class/Pokimac/Pokimac.cpp src/class/Pokimac/Pokimac.h 
	$(CC) -o $@ -c $<

build/cell.o: src/class/Map/Cell/Cell.cpp src/class/Map/Cell/Cell.h
	$(CC) -o $@ -c $<

clean: 
	rm -rf build/*.o
	rm -rf pokimac

