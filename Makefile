
hunt: event.o pit.o bat.o gold.o wumpus.o room.o game.o driver.o 
	g++ event.o pit.o bat.o gold.o wumpus.o room.o game.o driver.o -o hunt
event.o: event.cpp event.h
	g++ event.cpp event.h -c
pit.o: pit.cpp pit.h event.cpp
	g++ pit.cpp pit.h event.cpp -c
bat.o: bat.cpp bat.h event.cpp
	g++ bat.cpp bat.h event.cpp -c
gold.o: gold.cpp gold.h  event.cpp
	g++ gold.cpp gold.h event.cpp -c
wumpus.o: wumpus.cpp wumpus.h event.cpp
	g++ wumpus.cpp wumpus.h event.cpp -c
room.o: room.cpp room.h event.cpp
	g++ room.cpp room.h  event.cpp -c
game.o: pit.cpp bat.cpp gold.cpp wumpus.cpp room.cpp game.cpp game.h
	g++ game.cpp game.h pit.cpp bat.cpp gold.cpp wumpus.cpp room.cpp -c
driver.o: event.cpp pit.cpp bat.cpp gold.cpp wumpus.cpp room.cpp game.cpp driver.cpp        
	g++ event.cpp game.cpp driver.cpp pit.cpp bat.cpp gold.cpp wumpus.cpp room.cpp -c
clean:
	rm -f hunt *.o *.h.gch
