CC=g++
CFLAGS=-Wall -ansi

pokimac: build/main.o build/map.o build/player.o build/pokimac.o
	$(CC) -o $@ $^

build/main.o: src/main.cpp
	$(CC) -o $@ -c $<

build/map.o: src/class/Map/Map.cpp
	$(CC) -o $@ -c $<

build/player.o: src/class/Player/Player.cpp
	$(CC) -o $@ -c $<

build/pokimac.o: src/class/Pokimac/Pokimac.cpp
	$(CC) -o $@ -c $<

clean: 
	rm -rf build/*.o
	rm -rf pokimac

