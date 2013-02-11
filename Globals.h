/*
 * Globals.h
 *
 *  Created on: Jan 2, 2013
 *      Author: Brian
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

//PUT PEOPLE HERE
enum{
	Brian, Adam, Anthony, Brandon, Bryce, David
};
string names[David+1] = {
	"Brian", "Adam", "Anthony", "Brandon", "Bryce", "David"
};
//AND THEIR PREFS
int preferences[6][6] = {
		{5,6,3,2,1,4}, //Brian
		{6,5,3,2,1,4}, //Adam
		{4,3,5,6,2,1}, //Anthony
		{1,2,5,6,3,4},
		//{5,6,3,1,4,2}, //Brandon
		{4,3,6,5,2,1}, //Bryce
		{3,1,2,5,6,4}  //David
};

#endif /* GLOBALS_H_ */
