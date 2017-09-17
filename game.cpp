#include "./game.h"

/******************************************************************************
 * Funtion: constructor
 * Description: sets up game to begin playing
 * Parameters: int x
 * Pre-Conditions: gets num from user
 * Post-Conditions: game is set up to start playing
 ******************************************************************************/
game::game(int x){
	setRooms(x);
	setInfo();
	for(int i=0; i<6; i++){ //sets up event array
		if(i<2)
			events[i] = new pit;
		else if(i>1 && i<4)
			events[i] = new bat;
		else if(i==4)
			events[i] = new gold;
		else if(i==5)
			events[i] = new wumpus;
	};
	setEvents(x);
	setRopeUp();
	setWumpusPos(g);
	rooms[g.posR][g.posC].setBeen(true);				
};

/******************************************************************************
 * Funtion: setWumpusPos
 * Description: sets wumpus position
 * Parameters: info & g
 * Pre-Conditions: wumpus needs to be in one of the rooms
 * Post-Conditions: wumpus coordinates are set
 ******************************************************************************/
void game::setWumpusPos(info &g){
	for(int i=0; i<g.num; i++)
		for(int k=0; k<g.num; k++)
			if(rooms[i][k].ifNULL()==false)
				if(rooms[i][k].getEType() == 'w'){
					g.wumpusR = i;
					g.wumpusC = k;
				}

};

/******************************************************************************
 * Funtion: playing
 * Description: returns bool to determine if the game should continue
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: bool returned
 ******************************************************************************/
bool game:: playing(){
	if(!g.wumpus && !g.gold && rooms[g.posR][g.posC].getRope()==true){
		std::cout<<"You won the game!\n";
		return false;
	}
	else if(g.arrows<1){
		std::cout<<"Out of arrows\n";
		return false;
	}
	else if(g.playing)
		return true;

	else if(!g.playing)
		return false;
};

/******************************************************************************
 * Funtion: prompt
 * Description: prompts user
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: users pick to move or shoot is executed
 ******************************************************************************/
void game:: prompt(){
	if(g.playing){
		int ans;
		bool error=true;
		std::cout<<"1) Move or 2) Shoot?";
		do{
			std::cout<<"\n:";
			std::cin>>ans;
			if(std::cin.fail()|| ans>2 || ans<1){
				std::cin.clear();
				std::cin.ignore();
				error=true;
			}
			else if(ans==2 && g.arrows<1)
				error= true;
			else
				error = false;
		}while(error);
		if(ans == 1)
			move(g);
		else
			shoot(g);
	}
};

/******************************************************************************
 * Funtion: setInfo
 * Description: sets g
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: info is set
 ******************************************************************************/
void game::setInfo(){
	g.arrows = 3;
	g.wumpus = true;
	g.gold = true;
	g.playing = true;

};

/******************************************************************************
 * Funtion: setRopeUp
 * Description: sets up rope in a room
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: rope is set in one random room
 ******************************************************************************/
void game::setRopeUp(){
	srand(time(NULL));
	bool go=true;
	int r, c;
	while(go){
		r = rand()%g.num;
		c = rand()%g.num;
		if(rooms[r][c].ifNULL() == true){
			rooms[r][c].setRope(true);
			go = false;
		}
	};
	g.posR = r;
	g.posC = c;
};

/******************************************************************************
 * Funtion: shoot
 * Description: shoots in one direction for 3 rooms
 * Parameters: info & g
 * Pre-Conditions: arrows > 0
 * Post-Conditions: --arrow 
 ******************************************************************************/
void game:: shoot(info & g){
	int ans;
	bool error=true;
	std::cout<<"\n        1)Up\n";
	std::cout<<"2) Left        3)Right\n";
	std::cout<<"        4)Down";
	do{
		std::cout<<"\n:";
		std::cin>>ans;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			error = true;
		}
		else if(ans<1 ||ans>4){
			error = true;
		}
		else if((ans==1 && g.posR ==0)||
				(ans==2 && g.posC ==0)||
				(ans==3 && g.posC == g.num-1)||
				(ans==4 && g.posR == g.num-1))
			error = true;
		else
			error = false;
	}while(error);
	--g.arrows;
	if((ans==1 && g.posR-g.wumpusR<=3 && g.posR-g.wumpusR>0 && g.posC==g.wumpusC)||
			(ans==3 && g.wumpusC-g.posC<=3 && g.wumpusC-g.posC>0 && g.posR==g.wumpusR)||
			(ans==2 && g.posC-g.wumpusC<=3 && g.posC-g.wumpusC>0 && g.posR==g.wumpusR)||
			(ans==4 && g.wumpusR-g.posR<=3 && g.wumpusR-g.posR>0 && g.posC==g.wumpusC)){
		g.wumpus = false;
		std::cout<<"You killed the wumpus!\n";

	}
	else{
		std::cout<<"You didn't hit the wumpus, he is now awake.\n";
		wake(g);
	}


};


/******************************************************************************
 * Funtion: print
 * Description: prints board to player
 * Parameters: none
 * Pre-Conditions: board needs to be set up
 * Post-Conditions: board is printed to user
 ******************************************************************************/
void game:: print(){
	if(g.wumpus || g.gold){
		std::cout<<"\nObjectives:\n";
		if(g.wumpus)
			std::cout<<"Kill the wumpus\n";
		if(g.gold)
			std::cout<<"Collect the gold\n";
		std::cout<<std::endl;
	}
	std::cout<<"Arrow(s): "<<g.arrows;
	std::cout<<"\nPlayer position: "<<g.posR<<","<<g.posC<<std::endl;
	for(int i=0; i<g.num; i++){
		std::cout<<std::endl;
		for(int k=0; k<g.num; k++){
			if(i == g.posR && k==g.posC)
				std::cout<<"|x|";
			else
				std::cout<<"| |";
		};
	};

	std::cout<<std::endl;
	std::cout<<std::endl;
};

/******************************************************************************
 * Funtion: setRooms
 * Description: sets up rooms with given dimensions
 * Parameters: const int x
 * Pre-Conditions: none
 * Post-Conditions: rooms are set
 ******************************************************************************/
void game::setRooms(const int x){
	g.num=x;
	rooms = new room*[g.num]; //setting up rows
	for(int i=0; i<g.num; i++)
		rooms[i] = new room[g.num]; //2d array made
};

/******************************************************************************
 * Funtion: deconstructor
 * Description: deletes memory on heap
 * Parameters: none
 * Pre-Conditions: memory on heap
 * Post-Conditions: memory deallicated
 ******************************************************************************/
game::~game(){
	for(int i=0; i<g.num; i++)	
		delete [] rooms[i];
	delete [] rooms;
	for(int i=0; i<6; i++)
		delete events[i];
};

/******************************************************************************
 * Funtion: check
 * Description: checks rooms around players to give hints
 * Parameters: none
 * Pre-Conditions: rooms need to be set with events
 * Post-Conditions: hints printed if event nearby
 ******************************************************************************/
void game:: check(){
	std::cout<<std::endl;
	if(rooms[g.posR][g.posC].getRope() == true && g.wumpus == false && g.gold==false)
		g.playing = false;
	if(g.playing){
		if(rooms[g.posR][g.posC].ifNULL() == false)
			rooms[g.posR][g.posC].eAction(g);
		if(g.playing){
			for(int i=0; i<g.num; i++)//checks for hints
				for(int k=0; k<g.num; k++){
					if((abs(i-g.posR)==1 && abs(k-g.posC)==1)||
							(i==g.posR && abs(k-g.posC)==1)||
							(k==g.posC && abs(i-g.posR)==1))
						if(rooms[i][k].ifNULL() ==false){
							rooms[i][k].eMessage(g);
						}
				};
		}
	}
};

/******************************************************************************
 * Funtion: wake
 * Description: wakes up wumpus
 * Parameters: info &g
 * Pre-Conditions: rooms and player needs to be set
 * Post-Conditions: wumpus either moves or stays in same location
 ******************************************************************************/
void game:: wake(info &g){
	int r,c,n;
	bool error =true;
	srand(time(NULL));
	n=rand()%100+1;
	if(n<=75){
		while(error){
			r= rand()%g.num;
			c= rand()% g.num;
			if((r==g.posR && c ==g.posC)|| rooms[r][c].ifNULL()==false)
				error = true;
			else{
				rooms[r][c].setE(events[5]);
				rooms[g.wumpusR][g.wumpusC].setNULL();
				g.wumpusR = r;
				g.wumpusC = c;
				error = false;
			}
		};
	}

};

/******************************************************************************
 * Funtion: move
 * Description: moves player in one direction
 * Parameters: info &g
 * Pre-Conditions: player postion needs to be set
 * Post-Conditions: player moves one space in one direction
 ******************************************************************************/
void game::move(info &g){
	int ans;
	bool error=true;
	std::cout<<"\n        1)Up\n";
	std::cout<<"2) Left        3)Right\n";
	std::cout<<"        4)Down";
	do{
		std::cout<<"\n:";
		std::cin>>ans;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			error = true;
		}
		else if(ans<1 ||ans>4){
			error = true;
		}
		else if((ans==1 && g.posR ==0)||
				(ans==2 && g.posC ==0)||
				(ans==3 && g.posC == g.num-1)||
				(ans==4 && g.posR == g.num-1))
			error = true;
		else
			error = false;
	}while(error);

	if(ans==1){
		--g.posR;
	}
	else if(ans==2){
		--g.posC;
	}
	else if(ans==3){
		++g.posC;
	}
	else if(ans==4){
		++g.posR;
	}
	rooms[g.posR][g.posC].setBeen(true);
};


/******************************************************************************
 * Funtion: setEvents
 * Description: sets rooms with events 
 * Parameters: const int x
 * Pre-Conditions: rooms need to be set
 * Post-Conditions: rooms set with events
 ******************************************************************************/
void game::setEvents(const int x){
	srand(time(NULL));
	for(int i=0; i<6;){
		int rand1 = rand()%g.num;
		int rand2 = rand()%g.num;
		if(rooms[rand1][rand2].ifNULL() == true){
			rooms[rand1][rand2].setE(events[i]);
			++i;			
		}
	};
};
