#include "./pit.h"

/*******************************************************************************
 * Function: constructor
 * Description: sets type to p
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sets type to p
 ******************************************************************************/
pit::pit(){
	type = 'p';
};

/*******************************************************************************
 * Function: message
 * Description: prints message to player
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: prints message to player
 ******************************************************************************/
void pit:: message(){
	std::cout<<"You feel a breeze.\n";
};

/*******************************************************************************
 * Function: action
 * Description: prints message and sets playing to false
 * Parameters: info &g
 * Pre-Conditions: none
 * Post-Conditions: playing is false
 ******************************************************************************/
void pit:: action(info &g){
	std::cout<<"You fell down a pit, game over.\n";
	g.playing = false;
};

