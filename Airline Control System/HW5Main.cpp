/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

#include "flightCol.h"

PlaneCol planeClass;			// instance of the plane collection
CrewCol crewClass;				// instance of the crew collection
FlightCol flightClass;			// instance of the flight collection

int main() {
	
	int choice;						// used to hold the user's menu selection
	int returnPos;					// holds the value returned by search functions
	
	cout << "Welcome to the Mean Green Airlines Application!" << endl << endl;
	
	do {	// will loop until user inputs '0' as choice
		
		// PRINTING MENU TO USER
		cout << "******************** MENU *********************" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Add a Plane" << endl;
		cout << "2 - Add a Crew Member" << endl;
		cout << "3 - Add a Flight" << endl;
		cout << "4 - Edit a Plane's Information" << endl;
		cout << "5 - Edit a Crew Member's Information" << endl;
		cout << "6 - Edit a Flight's Information" << endl;
		cout << "7 - Delete a Plane's Information" << endl;
		cout << "8 - Delete a Crew Member's Information" << endl;
		cout << "9 - Delete a Flight's Information" << endl;
		cout << "10 - Find a Plane" << endl;
		cout << "11 - Find a Crew Member" << endl;
		cout << "12 - Find a Flight" << endl;
		cout << "13 - Print all Planes" << endl;
		cout << "14 - Print all Crew Members" << endl;
		cout << "15 - Print all Flights" << endl;
		cout << "16 - Print One Plane's Information" << endl;
		cout << "17 - Print One Crew Member's Information" << endl;
		cout << "18 - Print One Flight's Information" << endl;
		cout << "19 - Load Data" << endl;
		cout << "20 - Save Data" << endl;
		cout << "21 - Print Plane Schedule" << endl;
		cout << "22 - Print Crew Member Schedule" << endl;
		cout << "23 - Update Status'" << endl;
		cout << "24 - Delete Flights By Status" << endl;
		cout << "25 - Print Flights By Status" << endl;
		cout << endl << "Enter menu option: ";
		cin >> choice;
		cout << endl;

		// ACCESSING USERS CHOICE
		switch (choice) {
		
			case 0:
				cout << "Thanks for using the Mean Green Airlines Application!" << endl;
				break;
			case 1:
				planeClass.AddPlane();
				break;
			case 2:
				crewClass.AddCrewMember();
				break;
			case 3:
				flightClass.AddFlight();
				break;
			case 4:
				planeClass.EditPlane();
				break;
			case 5:
				crewClass.EditCrewMember();
				break;
			case 6:
				flightClass.EditFlight();
				break;
			case 7:
				planeClass.DeletePlane();
				break;
			case 8:
				crewClass.DeleteCrewMember();	
				break;
			case 9:
				flightClass.DeleteFlight();
				break;
			case 10:
				cin.ignore();
				returnPos = planeClass.SearchPlane();
				if(returnPos != -1)
				{
					cout << "The PLANE is at position " << returnPos << endl;
				}
				else
				{
					cout << "The PLANE could not be found." << endl;
				}
				break;
			case 11:
				cin.ignore();
				returnPos = crewClass.SearchCrewMember();
				if(returnPos != -1)
				{
					cout << "The CREW MEMBER is at position " << returnPos << endl;
				}
				else
				{
					cout << "The CREW MEMBER could not be found." << endl;
				}
				break;
			case 12:
				returnPos = flightClass.SearchFlight();
				if(returnPos != -1)
				{
					cout << "The FLIGHT is at position " << returnPos << endl;
				}
				else
				{
					cout << "The FLIGHT could not be found." << endl;
				}
				break;
			case 13:
				planeClass.PrintAllPlanes();
				break;
			case 14:
				crewClass.PrintAllCrewMembers();
				break;
			case 15:
				flightClass.PrintAllFlights();
				break;
			case 16:	
				planeClass.PrintOnePlane();
				break;
			case 17:
				crewClass.PrintOneCrewMember();
				break;
			case 18:
				flightClass.PrintOneFlight();
				break;
			case 19:		
				planeClass.LoadAllData();
				crewClass.LoadAllData();
				flightClass.LoadAllData();
				break;
			case 20:		
				planeClass.SaveAllData();
				crewClass.SaveAllData();
				flightClass.SaveAllData();
				break;
			case 21:
				flightClass.PrintPlaneSchedule();
				break;
			case 22:
				flightClass.PrintCrewMemberSchedule();
				break;
			case 23:
				flightClass.UpdateStatus();
				break;
			case 24:
				flightClass.DeleteByStatus();
				break;
			case 25:
				flightClass.PrintByStatus();
				break;
			
			default:
				cout << "Invaild selection. Please Try Again." << endl;
				break;
		}
		
		// AUTOMATICALLY UPDATING THE FLIGHT STATUS
		flightClass.UpdateStatus();
		
		cout << endl;
	} while(choice != 0);
	
	return 0;
}