#include "./room.h"

/******************************************************************************
 * Funtion: constructor
 * Description: sets up room
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: e = NULL, rope is false, and been is false
 ******************************************************************************/
room::room(){
	e = NULL;
	rope = false;
	been = false;
};

/******************************************************************************
 * Funtion: setRope
 * Description: sets rope to a bool
 * Parameters: bool r
 * Pre-Conditions: none
 * Post-Conditions: rope is given a bool
 ******************************************************************************/
void room:: setRope(bool r){
	rope = r;
};

/******************************************************************************
 * Funtion: getRope
 * Description: returns rope bool
 * Parameters: none
 * Pre-Conditions: rope is a bool
 * Post-Conditions: returns bool
 ******************************************************************************/
bool room:: getRope(){
	return rope;
};

/******************************************************************************
 * Funtion: getEType
 * Description: returns type
 * Parameters: none
 * Pre-Conditions: e has a type
 * Post-Conditions: returns type
 ******************************************************************************/
char room::getEType(){
	char test = e->getType();
	return test;
};

/******************************************************************************
 * Funtion: setE
 * Description: sets e to an event
 * Parameters: event *& something
 * Pre-Conditions: none
 * Post-Conditions: e is set to an event
 ******************************************************************************/
void room::setE(event* & something){
	e = *&something;
};

/******************************************************************************
 * Funtion: setBeen
 * Description: sets been to bool
 * Parameters: bool x
 * Pre-Conditions: none
 * Post-Conditions: been is set
 ******************************************************************************/
void room:: setBeen(bool x){
	been =x;
};

/******************************************************************************
 * Funtion: eMessage
 * Description: gets message from event
 * Parameters: info g
 * Pre-Conditions: rooms allicated with events
 * Post-Conditions: event message is printed
 ******************************************************************************/
void room::eMessage(info g){
	if(!(been==true && getEType()=='g')&&
			!(g.wumpus==false && getEType()=='w'))
		e->message();
};

/******************************************************************************
 * Funtion: eAction
 * Description: event's actions
 * Parameters: info &g
 * Pre-Conditions: rooms set with events
 * Post-Conditions: actions carried out
 ******************************************************************************/
void room:: eAction(info &g){
	if(!(g.gold==false && getEType()=='g')&&
			!(g.wumpus==false && getEType()=='w'))
		e->action(g);
};

/******************************************************************************
 * Funtion: setNULL
 * Description: sets e to NULL
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: e is null
 ******************************************************************************/
void room:: setNULL(){
	e = NULL;
};

/******************************************************************************
 * Funtion: ifNULL
 * Description: checks if null
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: returns bool
 ******************************************************************************/
bool room:: ifNULL(){
	if(e == NULL)
		return true;
	else
		return false;
};
