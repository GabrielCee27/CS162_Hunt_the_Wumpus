/******************************************************************************
 * Program Filename: Hunt the Wumpus
 * Author: Gabriel Cisneros
 * Date: May 22, 2016
 * Description: Hunt the Wumpus game
 * Input: Player movement/shooting directions
 * Output: Players Progression through the game
 ******************************************************************************/
#include "./game.h"
#include <iostream>


int main(int argc, char ** argv){
	int arg;
	bool playing=true;
	if(argc != 2){
		std::cout<<"Invalid number of arguements\n";
		return 0;
	}
	arg = argv[1][0]; //gets ascii value
	if(arg>52 && arg <58)
		arg = arg - '0';
	else{
		std::cout<<"Invalid input\n";
		return 0;
	};

	game g(arg);
	do{
		g.check();
		g.print();
		if(g.playing())
			g.prompt();
		else
			playing = false;
	}while(playing);
	return 0;
};
