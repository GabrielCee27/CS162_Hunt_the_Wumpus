#include "./event.h"

/******************************************************************************
 * Funtion: getType
 * Description: returns type
 * Parameters: none
 * Pre-Conditions: type needs to be allicated
 * Post-Conditions: returns type
 ******************************************************************************/
char event::getType(){
	return type;
};	

/******************************************************************************
 * Funtion: setType
 * Description: sets type
 * Parameters: char t
 * Pre-Conditions: none
 * Post-Conditions: type is set with a char
 ******************************************************************************/
void event:: setType(char t){
	type = t;
};

