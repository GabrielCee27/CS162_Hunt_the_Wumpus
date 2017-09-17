#include "./gold.h"

/******************************************************************************
 * Funtion: message
 * Description: prints message to player
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: prints message to player
 ******************************************************************************/
void gold:: message(){
	std::cout<<"You see a glimmer nearby.\n";
};

/******************************************************************************
 * Funtion: constructor
 * Description: sets type to 'g'
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: type is char g
 ******************************************************************************/
gold::gold(){
	type = 'g';
};

/******************************************************************************
 * Funtion: action
 * Description: prints message and sets gold to false
 * Parameters: info &g
 * Pre-Conditions: gold needs to be in one of the rooms
 * Post-Conditions: gold is false and message printed to player
 ******************************************************************************/
void gold:: action(info &g){
	std::cout<<"You picked up the gold\n";
	g.gold = false;
};
