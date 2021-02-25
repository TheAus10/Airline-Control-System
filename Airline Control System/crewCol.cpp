/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstddef>

using namespace std;
#include "crewCol.h"

CrewCol::CrewCol() {								// constructor
	crewCount = 0;
	deleteCount = 0;
}

void CrewCol::SetCounter(){							// mutator for crew count
	crewCount++;
}

int CrewCol::GetCounter(){							// accessor for crew count
	return crewCount;
}

void CrewCol::AddCrewMember(){
	int    numCrewAdded, menuChoice;				// holds the number of crew they want to add; holds users menu choice
	string nameInp, typeInp, ratingInp, statusInp, posInp;	// name, type, rating, status, and position input variables
	double hrsInp;									// flight hours input variable
	int    statusInt, posInt;						// holds menu option for status and position
	Crew*  crewObject = new Crew;					// instance of crew object
	Pilot* pilotPtr;								// pointer to pilots					
	CoPilot* coPilotPtr;							// pointer to co-pilots
	Cabin* cabinPtr;								// pointer to cabin members	
	int    check;									// holds either 1 or 0 depending on if name number is unique
	unsigned int size = crewVec.size();			    // holds the size of the crew vector
	
	do {
		cout << "What type of Crew Member(s) would you like to add?" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Pilot" << endl;
		cout << "2 - Co-Pilot" << endl;
		cout << "3 - Cabin Member" << endl;
		cout << "Enter menu choice: ";
		cin >> menuChoice;
	
		switch(menuChoice)
		{
			case 0:
				break;
				
			case 1:
				// PROMPT FOR CREW INFO
				cout << "How many Pilots would you like to add? ";
				cin >> numCrewAdded;
				cin.ignore();

				for(int i = 0; i < numCrewAdded; i++)
				{
					// ALLOCATES SPACE FOR A NEW PILOT
					pilotPtr = new Pilot;
					
					if(i>0){cin.ignore();}	// ignores after first loop
					
					// CHECKING FOR UNIQUE NAME
					do {
						check = 0;
						cout << "Enter the NAME of Pilot " << i+1 << ": ";
						getline(cin, nameInp);
						
						// SEACRHES THROUGH PLANE VECTOR TO MAKE SURE NAMES ARE UNIQUE
						for (unsigned int j = 0; j < size; j++)
						{
							if(nameInp == crewVec[j]->GetName())
							{
								cout << "A crew member is already registered under that name. Try again" << endl;
								check = 1;
							}
						}
					}while(check == 1);	// loops until 'check' remains 0
					
					// GETS RATING
					cout << "Enter the 5 character rating: ";
					cin >> ratingInp;
					
					// GETS FLIGHT HOURS
					cout << "Enter the number of flight hours: ";
					cin >> hrsInp;
					
					// GETS STATUS AND CHECKS FOR CORRECT INPUT
					do {
						check = 0;
						cout << "Is the crew member (1)Available, (2)On Leave, or (3)Sick: ";
						cin >> statusInt;
						if (statusInt == 1) {statusInp = "Available";}
						else if (statusInt == 2) {statusInp = "On Leave";}
						else if (statusInt == 3) {statusInp = "Sick";}
						else { cout << "Invalid selection. Try Again." << endl; check = 1;}
					}while(check == 1);
					
					typeInp = "Pilot";

					// ASSIGNING CREW INFO
					pilotPtr->SetName(nameInp);
					pilotPtr->SetType(typeInp);
					pilotPtr->SetStatus(statusInp);
					pilotPtr->SetRating(ratingInp);
					pilotPtr->SetPilotHours(hrsInp);
					pilotPtr->SetID(crewCount);				// assigns the crew member's ID to the count of crew members
	
					crewVec.push_back(pilotPtr);
		
					//INCREMENT COUNTER
					crewCount++;
					cout << endl;
				}
				cout << "***** CREW MEMBER(S) ADDED *****" << endl;
				break;
				
			case 2:
				// PROMPT FOR CREW INFO
				cout << "How many Co-Pilots would you like to add? ";
				cin >> numCrewAdded;
				cin.ignore();

				for(int i = 0; i < numCrewAdded; i++)
				{
					// ALLOCATING SPACE FOR A NEW CO-PILOT
					coPilotPtr = new CoPilot;
					
					if(i>0){cin.ignore();}	// ignores after first loop
					
					// CHECKING FOR UNIQUE NAME
					do {
						check = 0;
						cout << "Enter the NAME of Co-Pilot " << i+1 << ": ";
						getline(cin, nameInp);
						
						// SEACRHES THROUGH PLANE VECTOR TO MAKE SURE NAMES ARE UNIQUE
						for (unsigned int j = 0; j < size; j++)
						{
							if(nameInp == crewVec[j]->GetName())
							{
								cout << "A crew member is already registered under that name. Try again" << endl;
								check = 1;
							}
						}
					}while(check == 1);	// loops until 'check' remains 0
					
					// GETS RATING
					cout << "Enter the 4 character rating: ";
					cin >> ratingInp;
					
					// GETS FLIGHT HOURS
					cout << "Enter the number of flight hours: ";
					cin >> hrsInp;
					
					// GETS STATUS AND CHECKS FOR CORRECT INPUT
					do {
						check = 0;
						cout << "Is the crew member (1)Available, (2)On Leave, or (3)Sick: ";
						cin >> statusInt;
						if (statusInt == 1) {statusInp = "Available";}
						else if (statusInt == 2) {statusInp = "On Leave";}
						else if (statusInt == 3) {statusInp = "Sick";}
						else { cout << "Invalid selection. Try Again." << endl; check = 1;}
					}while(check == 1);
					
					typeInp = "Co-Pilot";

					// ASSIGNING CREW INFO
					coPilotPtr->SetName(nameInp);
					coPilotPtr->SetType(typeInp);
					coPilotPtr->SetStatus(statusInp);
					coPilotPtr->SetRating(ratingInp);
					coPilotPtr->SetCoPilotHours(hrsInp);
					coPilotPtr->SetID(crewCount);				// assigns the crew member's ID to the count of crew members
	
					crewVec.push_back(coPilotPtr);
		
					//INCREMENT COUNTER
					crewCount++;
					cout << endl;
				}
				cout << "***** CREW MEMBER(S) ADDED *****" << endl;
				break;
				
			case 3:
				// PROMPT FOR CREW INFO
				cout << "How many Cabin Members would you like to add? ";
				cin >> numCrewAdded;
				cin.ignore();

				for(int i = 0; i < numCrewAdded; i++)
				{
					// ALLOCATING SPACE FOR A NEW CABIN MEMBER
					cabinPtr = new Cabin;
					
					if(i>0){cin.ignore();}	// ignores after first loop
					
					// CHECKING FOR UNIQUE NAME
					do {
						check = 0;
						cout << "Enter the NAME of Cabin Member " << i+1 << ": ";
						getline(cin, nameInp);
						
						// SEACRHES THROUGH PLANE VECTOR TO MAKE SURE NAMES ARE UNIQUE
						for (unsigned int j = 0; j < size; j++)
						{
							if(nameInp == crewVec[j]->GetName())
							{
								cout << "A crew member is already registered under that name. Try again" << endl;
								check = 1;
							}
						}
					}while(check == 1);	// loops until 'check' remains 0
					
					// GETS RATING AND CHECKS FOR CORRECT INPUT
					do {
						check = 0;
						cout << "Is the crew member (1)First Class, (2)Business Class, (3)Economy Front, or (4)Economy Rear: ";
						cin >> posInt;
						if (posInt == 1) {posInp = "First";}
						else if (posInt == 2) {posInp = "Business";}
						else if (posInt == 3) {posInp = "Econ Front";}
						else if (posInt == 4) {posInp = "Econ Rear";}
						else { cout << "Invalid selection. Try Again." << endl; check = 1;}
					}while(check == 1);
					
					// GETS STATUS AND CHECKS FOR CORRECT INPUT
					do {
						check = 0;
						cout << "Is the crew member (1)Available, (2)On Leave, or (3)Sick: ";
						cin >> statusInt;
						if (statusInt == 1) {statusInp = "Available";}
						else if (statusInt == 2) {statusInp = "On Leave";}
						else if (statusInt == 3) {statusInp = "Sick";}
						else { cout << "Invalid selection. Try Again." << endl; check = 1;}
					}while(check == 1);
					
					typeInp = "Cabin Member";

					// ASSIGNING CREW INFO
					cabinPtr->SetName(nameInp);
					cabinPtr->SetType(typeInp);
					cabinPtr->SetStatus(statusInp);
					cabinPtr->SetPosition(posInp);
					cabinPtr->SetID(crewCount);				// assigns the crew member's ID to the count of crew members
	
					crewVec.push_back(cabinPtr);
		
					//INCREMENT COUNTER
					crewCount++;
					cout << endl;
				}
				cout << "***** CREW MEMBER(S) ADDED *****" << endl;
				break;
			
			default:
				cout << "Invalid selection. Try Again." << endl;
				break;
		}
	}while(menuChoice != 0);
}

void CrewCol::EditCrewMember(){	
	cin.ignore();
	int returnPos = SearchCrewMember();		// holds value returned by search function
	string typeInp, statusInp;				// type, status input variables
	int choice;								// holds menu selection

	if(returnPos != -1)	// checks that seacfh function returned a usable ID
	{
		cout << "What would you like to edit?" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Status" << endl;
		cout << "2 - Type" << endl;
		cout << "Enter selection: ";
		cin >> choice;
		switch(choice)
		{
			case 0:
				break;
			
			case 1:	
				cout << endl;
				cout << crewVec[returnPos]->GetName() << " is currently " << crewVec[returnPos]->GetStatus() << endl;
				cout << "What would you like to change the STATUS to?" << endl;
				cout << "0 - Quit" << endl;
				cout << "1 - Available" << endl;
				cout << "2 - On Leave" << endl;
				cout << "3 - Sick" << endl;
				cout << "Enter selection: ";
				cin >> choice;
				switch(choice)
				{
					case 0:
						break;
		
					case 1:
						statusInp = "Available";
						crewVec[returnPos]->SetStatus(statusInp);
						cout << "***** CREW MEMBER EDITED *****" << endl;
						break;
			
					case 2:
						statusInp = "On Leave";
						crewVec[returnPos]->SetStatus(statusInp);
						cout << "***** CREW MEMBER EDITED *****" << endl;
						break;
			
					case 3:
						statusInp = "Sick";
						crewVec[returnPos]->SetStatus(statusInp);
						cout << "***** CREW MEMBER EDITED *****" << endl;
						break;
			
					default:
						cout << "Invalid selection. Try again." << endl;
				}
				break;
			case 2:
				cout << endl;
				cout << crewVec[returnPos]->GetName() << " is currently a " << crewVec[returnPos]->GetType() << endl;
				cout << "What would you like to change the TYPE to?" << endl;
				cout << "0 - Quit" << endl;
				cout << "1 - Pilot" << endl;
				cout << "2 - Co-Pilot" << endl;
				cout << "3 - Cabin Member" << endl;
				cout << "Enter selection: ";
				cin >> choice;
				switch(choice)
				{
					case 0:
						break;
	
					case 1:
						typeInp = "Pilot";
						crewVec[returnPos]->SetType(typeInp);
						cout << "***** CREW MEMBER EDITED *****" << endl;
						break;
			
					case 2:
						typeInp = "Co-Pilot";
						crewVec[returnPos]->SetType(typeInp);
						cout << "***** CREW MEMBER EDITED *****" << endl;
						break;
			
					case 3:
						typeInp = "Cabin Member";
						crewVec[returnPos]->SetType(typeInp);
						cout << "***** CREW MEMBER EDITED *****" << endl;
						break;
			
					default:
						cout << "Invalid selection. Try again." << endl;
				}
				break;
			default:
				cout << "Invalid selection. Try again." << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Could not edit Crew Member" << endl;
	}
}

void CrewCol::DeleteCrewMember(){
	cin.ignore();
	int returnPos = SearchCrewMember();	// holds value returned by search function
	
	if(returnPos != -1)
	{
		crewVec.erase(crewVec.begin() + returnPos);
		deleteCount++;
		cout << "***** CREW MEMBER DELETED *****" << endl;
	}
	else
	{
		cout << "Could not delete the CREW MEMBER" << endl;
	}
}
	
int CrewCol::SearchCrewMember(){
	string nameInp;								// user input for name
	int position = -1;							// the position of the matching name; if no match, returns -1
	unsigned int size = crewVec.size();			// size of the vector
	
	// PROMPTS FOR THE NAME 
	cout << "Enter the NAME of the crew member: ";
	//cin.ignore();
	getline(cin, nameInp);
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING NAME
		if(crewVec[i]->GetName() == nameInp)
		{
			position = i;
		}
	}
	
	// CHECKS IF THE POSITION HAS CHANGED
	if(position == -1)
	{
		cout << "Could not find a crew member with that name." << endl;
	}
	
	return position;
}
	
void CrewCol::PrintAllCrewMembers(){				// prints all crew members information in a table
	unsigned int size = crewVec.size();
	
	cout << "***** ALL CREW MEMBERS LISTED BELOW *****" << endl;
	cout << setw(10) << "ID" << setw(20) << "NAME" << setw(14) << "TYPE" << setw(12) << "STATUS" << setw(8) << "RATING" << setw(12) << "FLIGHT HRS" << setw(12) << "POSITION" <<endl;
	
	for (unsigned int i = 0; i < size; i++)
	{
		crewVec[i]->PrintInfo();
	}
}

void CrewCol::PrintOneCrewMember(){
	cin.ignore();
	int returnPos = SearchCrewMember();	// holds value returned by search function
	
	if(returnPos != -1)
	{
		cout << setw(10) << "ID" << setw(20) << "NAME" << setw(14) << "TYPE" << setw(12) << "STATUS" << setw(8) << "RATING" << setw(12) << "FLIGHT HRS" << setw(12) << "POSITION" <<endl;
		crewVec[returnPos]->PrintInfo();
	}
	else
	{
		cout << "Could not print information the CREW MEMBER" << endl;
	}
}

void CrewCol::LoadAllData(){						// uses fstreams to read data in from a file
	ifstream fin;									// input stream variable
	Crew* crewObject = new Crew;					// instance of crew class
	Pilot* pilotPtr;								// pointer to pilots							
	CoPilot* coPilotPtr;							// pointer to co-pilots
	Cabin* cabinPtr;								// pointer to cabin members	
	
	// crew info variables
	int idInp, count;
	string nameInp, typeInp, statusInp, ratingInp, posInp;
	double hrsInp;
	
	// OPENS THE FILE
	fin.open("CrewOutput.txt");
	
	// CHECKS THAT THE FILE OPENED CORRECTLY
	if (fin.is_open())
	{
		// READS FROM THE FILE
		fin >> count;
		fin >> deleteCount;
		crewCount = count + deleteCount;
		for (int i = 0; i < count; i++)
		{
			fin.ignore();
			getline(fin, typeInp);
			if(typeInp == "Pilot")
			{
				pilotPtr = new Pilot;
				fin >> idInp;
				fin.ignore();
				getline(fin, nameInp);
				getline(fin, statusInp);
				getline(fin, ratingInp);
				fin >> hrsInp;
				
				pilotPtr->SetName(nameInp);
				pilotPtr->SetType(typeInp);
				pilotPtr->SetStatus(statusInp);
				pilotPtr->SetRating(ratingInp);
				pilotPtr->SetPilotHours(hrsInp);
				pilotPtr->SetID(idInp);
	
				crewVec.push_back(pilotPtr);
			}
			else if(typeInp == "Co-Pilot")
			{
				coPilotPtr = new CoPilot;
				fin >> idInp;
				fin.ignore();
				getline(fin, nameInp);
				getline(fin, statusInp);
				getline(fin, ratingInp);
				fin >> hrsInp;
				
				coPilotPtr->SetName(nameInp);
				coPilotPtr->SetType(typeInp);
				coPilotPtr->SetStatus(statusInp);
				coPilotPtr->SetRating(ratingInp);
				coPilotPtr->SetCoPilotHours(hrsInp);
				coPilotPtr->SetID(idInp);
	
				crewVec.push_back(coPilotPtr);
			}
			else if(typeInp == "Cabin Member")
			{
				cabinPtr = new Cabin;
				getline(fin, nameInp);
				getline(fin, statusInp);
				getline(fin, posInp);
				fin >> idInp;
				
				cabinPtr->SetName(nameInp);
				cabinPtr->SetType(typeInp);
				cabinPtr->SetStatus(statusInp);
				cabinPtr->SetPosition(posInp);
				cabinPtr->SetID(idInp);
	
				crewVec.push_back(cabinPtr);
			}
		}
		
		cout << "***** CREW MEMBER INFORMATION LOADED *****" << endl;
	}
	else
	{
		cout << "Could not load crew member information." << endl;
	}
	
	// CLOSES THE FILE
	fin.close();
}

void CrewCol::SaveAllData(){						// uses fstreams to print data to a file
	ofstream fout;									// output stream variable
	unsigned int size = crewVec.size();				// saves the size of the vector
	
	// OPENS THE FILE
	fout.open("CrewOutput.txt", ios::out | ios::trunc);
	
	// PRINTS TO THE FILE
	fout << crewVec.size() << endl;
	fout << deleteCount << endl;
	
	// CLOSES THE FILE
	fout.close();
	
	// CALLS VIRTUAL SAVE FUNCTIONS
	for (unsigned int i = 0; i < size; i++)
	{
		crewVec[i]->SaveInfo();
	}
	
	cout << "***** CREW MEMBER INFORMATION SAVED *****" << endl;
}

string CrewCol::ReturnType(string name){
	unsigned int size = crewVec.size();		// size of the vector
	string tempType;							// temporary variablr for the tail number
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING TAIL NUMBER
		if(crewVec[i]->GetName() == name)
		{
			tempType = crewVec[i]->GetType();
		}
	}
	
	return tempType;
}

string CrewCol::ReturnName(){
	int returnPos = SearchCrewMember();			// holds value returned by search function
	string tempName;							// temporary variablr for the tail number
	
	if(returnPos != -1)
	{
		tempName = crewVec[returnPos]->GetName();
	}
	else
	{
		tempName = "none";
		cout << "Could not retrieve NAME." << endl;
	}
	
	return tempName;
}

int CrewCol::ReturnID(string name){
	unsigned int size = crewVec.size();		// size of the vector
	int id = -1;
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING TAIL NUMBER
		if(crewVec[i]->GetName() == name)
		{
			id = crewVec[i]->GetID();
		}
	}
	
	return id;
}

string CrewCol::ReturnStatus(string name){
	unsigned int size = crewVec.size();		// size of the vector
	string tempStatus;
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING TAIL NUMBER
		if(crewVec[i]->GetName() == name)
		{
			tempStatus = crewVec[i]->GetStatus();
		}
	}
	
	return tempStatus;
}