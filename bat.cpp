#include "./bat.h"
/******************************************************************************
 * Funtion: message
 * Description: Sends message to user
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: message printed to user
 ******************************************************************************/
void bat:: message(){
	std::cout<<"You hear wings flapping.\n";
};

/******************************************************************************
 * Funtion: constructor
 * Description: sets type to b
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: type is equal to b
 ******************************************************************************/
bat::bat(){
	type = 'b';
};

/******************************************************************************
 * Funtion: action
 * Description: Sends message and gives the player new coordinates.
 * Parameters: info &g
 * Pre-Conditions: info g.num needs to be greater than 0
 * Post-Conditions: player gets random coordinates
 ******************************************************************************/
void bat:: action(info &g){
	srand(time(NULL));
	std::cout<<"Super bat picks you up and drops you off on random spot\n";
	g.posR = rand()% g.num;
	g.posC = rand() % g.num;
};

