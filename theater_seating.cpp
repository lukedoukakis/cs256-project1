/*
 * theater_seating.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: Luke
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void displayTheatre(string _theatre[15][30]){

	string chart = "";

	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 30; j++){
			chart.append(_theatre[i][j]);

		}
		chart.append("\n");

	}
	cout<<chart<<"\n";
}

void sellSeat(string _theatre[15][30], int _prices[15], int _sales){

	int user1, user2;


	do {
		cout<<"Enter a valid row: ";
		cin>>user1;
		if(user1 > 15){
			cout<<"Not a valid row. ";
		}
	} while (user1 > 15);

	do {
		cout<<"Enter a valid column: ";
		cin>>user2;
		if(user2 > 30){
			cout<<"Not a valid column. ";
		}
	} while (user2 > 30);


	_theatre[user1-1][user2-1] = "*";
	_sales = _sales + _prices[user1-1];
}

void displaySeatStats(string _theatre[15][30]){

	int count=0;

	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 30; j++){
			if(_theatre[i][j] == "*"){
				count++;
			}
		}
	}
	printf("%d seats have been sold. There for %d more seats open.\n", count, 450-count);
}

int main(){

	//initialize theatre
	string theatre[15][30];
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 30; j++){
			theatre[i][j] = "#";
		}
	}

	int prices[15]; //stores prices for each row
	int user; //where user's input is stored
	int sales = 0; //total ticket sales

	for(int i = 0; i < 15; i++){
		printf("Enter price for row %d: ", i+1);
		cin>>user;
		prices[i]=user;
	}

	cout<<"Seating chart:\n";
	displayTheatre(theatre);

	do {
		cout<<"PRESS 1: Enter seat sold\n";
		cout<<"PRESS 2: View amount of seats sold/open\n";
		cout<<"PRESS 3: View total ticket sales\n";
		cout<<"PRESS 4: Exit program\n";
		cin>>user;

		switch(user){
		case 1:
			sellSeat(theatre, prices, sales);
			cout<<"Seat has been sold. Current seating chart: \n";
			displayTheatre(theatre);
			cout<<"\n";
			break;
		case 2:
			displaySeatStats(theatre);
			break;
		case 3:
			printf("Ticket sales: %d\n", sales);
			break;
		case 4:
			return 0;
		}

	} while (1 > 0);
}



