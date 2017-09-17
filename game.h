#include "./room.h"
#include "./pit.h"
#include "./bat.h"
#include "./gold.h"
#include "./wumpus.h"
#include "./info.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>

class game{
	private:
		room ** rooms;
		info g;
		event *events[6];
	public:
		void setPlayer();
		game(int);//constructor
		void setInfo();
		void setRooms(const int);
		void setEvents(const int);
		int getArrows();
		void removeArrow();
		int getPosition();
		void setPosition();
		void print();
		void setRopeUp();
		void check();
		~game(); //destructor
		void prompt(); // ask to move or shoot
		bool playing();
		void setWumpusPos(info &);
		void shoot(info &);
		void move(info &g); 
		void shoot(int ans);
		void wake(info &g);
};
