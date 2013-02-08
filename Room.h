#ifndef ROOM_H_
#define ROOM_H_
#include"Globals.h"
#include<iostream>
using namespace std;
//bad style, I know.
class Room{
public:
	int owner;
	bool taken;

	Room(){
		owner = -1;
		taken = false;
	}
	void clr(){
		owner = -1;
		taken = false;
	}
	void print(){
		if(taken)
			cout << names[owner] << " lives here";
		else{
			cout << "This room is available.\n";
		}
	}
};

#endif //ROOM_H_
