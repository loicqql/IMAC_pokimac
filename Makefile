CC=g++
CFLAGS=-Wall -ansi
CFLAGSDEBUG=-DDEBUG -g

pokimac: build/game.o build/event.o build/main.o build/map.o build/player.o build/pokimac.o build/cell.o build/inventory.o
	$(CC) -o $@ $^

build/main.o: src/main.cpp
	$(CC) -o $@ -c $< -DDEBUG -g

build/game.o: src/class/Game/Game.cpp src/class/Game/Game.h
	$(CC) -o $@ -c $< -DDEBUG -g

build/map.o: src/class/Map/Map.cpp src/class/Map/Map.h
	$(CC) -o $@ -c $< -DDEBUG -g

build/player.o: src/class/Player/Player.cpp src/class/Player/Player.h
	$(CC) -o $@ -c $< -DDEBUG -g

build/pokimac.o: src/class/Pokimac/Pokimac.cpp src/class/Pokimac/Pokimac.h 
	$(CC) -o $@ -c $< -DDEBUG -g

build/cell.o: src/class/Map/Cell/Cell.cpp src/class/Map/Cell/Cell.h
	$(CC) -o $@ -c $< -DDEBUG -g

build/event.o: src/class/Game/Event/Event.cpp src/class/Game/Event/Event.h
	$(CC) -o $@ -c $< -DDEBUG -g

build/inventory.o: src/class/Player/Inventory/Inventory.cpp src/class/Player/Inventory/Inventory.h
	$(CC) -o $@ -c $< -DDEBUG -g

clean: 
	rm -rf build/*.o
	rm -rf pokimac

