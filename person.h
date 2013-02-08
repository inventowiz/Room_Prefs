/*
 * person.h
 *
 *  Created on: Jan 2, 2013
 *      Author: Brian
 */

#ifndef PERSON_H_
#define PERSON_H_

#include"Globals.h"
#include<iostream>
using namespace std;
//again, bad style
class Person {
public:
	int prefs[6];
	int name;
	bool living;
	void print(){
		cout << names[name] << " - ";
		for (int i=0;i<5;i++){
			cout << prefs[i] << ", " ;
		}
		cout << prefs[5];
	}
	void clr(){
		name = -1;
		living = false;
		for(int i=0;i<6;i++){
			prefs[i] = 0;
		}
	}
	Person(int n, int p[6], bool l){
		name = n;
		living = l;
		for(int i=0;i<6;i++){
			prefs[i] = p[i];
		}
	}
	Person(){
		name = -1;
		living = false;
		for(int i=0;i<6;i++){
			prefs[i] = 0;
		}
	}

};

#endif /* PERSON_H_ */
