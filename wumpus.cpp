#include "./wumpus.h"

/******************************************************************************
 * Funtion: constructor 
 * Description: sets up type
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: type is w
 ******************************************************************************/
wumpus::wumpus(){
	type= 'w';
};

/******************************************************************************
 * Funtion: message
 * Description: prints message
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: prints message to user
 ******************************************************************************/
void wumpus::message(){
	std::cout<<"You smell a terrible stench.\n";
};

/******************************************************************************
 * Funtion: action
 * Description: prints message, playing is false
 * Parameters: info &g
 * Pre-Conditions: none
 * Post-Conditions: message printed to player and playing is false
 ******************************************************************************/
void wumpus:: action(info &g){
	std:: cout<<"Wumpus wakes up and eats you\n";
	g.playing = false;
};

