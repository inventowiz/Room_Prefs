/*
 * rooms.cpp
 *
 *  Created on: Jan 2, 2013
 *      Author: Brian
 */
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"person.h"
#include"Room.h"
#include"Globals.h"

//const int MAX_RUNS = 500;

void reset(Person* list, Room* house);
void populate(Person* list);
void printList(Person* list);
void printRooms(Room* list);
int rollDie();
bool everyoneHappy(Room brothel[6]);
void assign(Room* rooms, Person* mates, int rm, int per);
int printFinal(Room* rooms, Person* bros);
int pickRooms(Room *house,Person* people);

int main(){
	int MAX_RUNS;
	cout << "Enter a number of times to run the function: ";
	cin >> MAX_RUNS;
	srand(time(NULL)); //seed the rand()
	Room house[6],finalH[6];
	Person people[6],finalP[6];
	int curavg = 100,flipcount = 0;
	//will be replaced after first run, practically infinity
	reset(people, house);
	populate(finalP);
	printList(people);
	for(int i=0;i<MAX_RUNS;i++){
		reset(people,house);
		int newavg = pickRooms(house,people);
		if(newavg < curavg){ //update final H and P
			for(int j=0;j<6;j++){
				finalH[j]=house[j];
				finalP[j]=people[j];
			}
			curavg = newavg;
			flipcount++;
			cout << "---FINAL OUTPUT UPDATED---\n";
		}
	}
	cout << "\n<-----RESULT----->";
	printFinal(finalH,finalP);
	cout << "Flipped output " << flipcount << " times.\n";
	return 0;
}

int pickRooms(Room *house,Person* people){
	int counter = 1;
	while(!everyoneHappy(house)){ //for debugging. change to !everyoneHappy(house)
		cout << "Beginning iteration " << counter <<":\n";

		//determine random person
		int chosenone = rollDie();
		cout << names[chosenone] << " was chosen.\n";
		if(people[chosenone].living){
			//person already has a room
			cout << names[chosenone] << " already has a room.\n";
			counter++;
			continue;
		}
		//give chosenone a room
		int i=0;
		while(i<6){
			int pref = people[chosenone].prefs[i];
			if(house[pref].taken){
				cout << "Choice " << i << ": taken\n";
				i++;
				continue;
			}
			cout << "Choice " << i << ": available\n";
			//assign chosenone his i choice
			assign(house,people,pref,chosenone);
			cout << names[chosenone] << " gets room " << pref <<
					", his choice " << i << endl;
			i++;
			break;
		}
		counter++;
		cout << endl << endl;
	}
	int avg = printFinal(house,people);
	return avg;
}

void reset(Person* list, Room* house){
	for(int i=0;i<6;i++){
		list[i].clr();
		house[i].clr();
	}
	populate(list);
}

void populate(Person* list){
	for(int i=0;i<6;i++){
		list[i].name = i;
		for(int k=0;k<6;k++){
			list[i].prefs[k] = ((preferences[i][k]) - 1);
		}
	}
}

void printList(Person* list){
	for(int j=0;j<6;j++){
		list[j].print();
		cout << endl;
	}
}

void printRooms(Room* list){
	for(int j=0;j<6;j++){
		cout << j << endl;
		list[j].print();
		cout << endl;
	}
}

int rollDie(){
	return rand() % 6;
}


bool everyoneHappy(Room brothel[6]){
	for(int i=0;i<6;i++){
		if(!brothel[i].taken)
			return false;
	}
	return true;
}

void assign(Room* rooms, Person* mates, int rm, int per){
	rooms[rm].owner = per;
	rooms[rm].taken = true;
	mates[per].living = true;
}

int printFinal(Room* rooms, Person* bros){
	int totalchoice = 0;
	cout << endl << "FINAL RESULTS:\n";
	for(int i=0;i<6;i++){
		cout << "Room " << i << ": " << names[rooms[i].owner] <<
				", his choice ";
		for(int j=0;j<6;j++){
			if(bros[rooms[i].owner].prefs[j] == i){
				cout << j << endl;
				totalchoice = totalchoice + j;
				break; //for speed
			}
		}
	}
	double result = totalchoice/6.0;
	cout << "Average preference received: " << result << endl;
	return result;
}
