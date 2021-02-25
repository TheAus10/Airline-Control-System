/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "planeCol.h"

PlaneCol::PlaneCol(){
	planeCount = 0;
}

vector<Plane> PlaneCol::GetPlaneVector(){
	return planeVec;
}

void PlaneCol::SetCounter(int count){
	planeCount = count;
}

int PlaneCol::GetCounter(){
	return planeCount;
}

void PlaneCol::AddPlane(){
	
	int numPlanesAdded;							// the number of planes the user wants to add at a time
	Plane planeObject;							// instance of Plane class
	unsigned int size = planeVec.size();		// holds the size of the plane vector
	int check;									// holds either 1 or 0 depending on if the tail number is unique
	
	string makeInp, modelInp, tailNumInp;		// make, model, and tail number of plane	
	int numSeatsInp, minNumOfCrewInp;			// number of seats on the plane and number of crew on plane
	double rangeInp;							// fuel range of the plane
	
	// PROMPT FOR PLANE INFO
	cout << "How many planes would you like to add? ";
	cin >> numPlanesAdded;
	cin.ignore();
	
	for (int i = 0; i < numPlanesAdded; i++)
	{
		do {
			check = 0;
			cout << "Enter the TAIL NUMBER of the plane: ";
			cin.ignore();
			getline(cin, tailNumInp);
			if (size > 0)		// checks that this isnt the first plane being added
			{
				// SEACRHES THROUGH PLANE VECTOR TO MAKE SURE TAIL NUMBERS ARE UNIQUE
				for (unsigned int i = 0; i < size; i++)
				{
					if(tailNumInp == planeVec[i].GetTailNum())
					{
						cout << "A plane is already registered under that tail number. Try again" << endl;
						check = 1;
					}
				}
			}
		}while(check == 1);	// loops until 'check' remains 0
		cout << "Enter the MAKE of the plane: ";
		getline(cin, makeInp);
		cout << "Enter the MODEL of the plane: ";
		getline(cin, modelInp);
		cout << "Enter the NUMBER OF SEATS on the plane: ";
		cin >> numSeatsInp;
		cout << "Enter the MINIMUM NUMBER OF CREW REQUIRED on the plane (inluding Pilots and Co-Pilots): ";
		cin >> minNumOfCrewInp;
		cout << "Enter the FUEL RANGE on the plane: ";
		cin >> rangeInp;
		
		// ASSIGNING INFORMATION TO VECTOR
		planeObject.SetMake(makeInp);
		planeObject.SetModel(modelInp);
		planeObject.SetTailNum(tailNumInp);
		planeObject.SetNumSeats(numSeatsInp);
		planeObject.SetMinCrew(minNumOfCrewInp);
		planeObject.SetRange(rangeInp);			
		
		planeVec.push_back(planeObject);
		cout << "***** PLANE ADDED *****" << endl;
		cout << endl;
		
		//INCREASE COUNTER
		planeCount++;
	}
}

void PlaneCol::EditPlane(){
	int returnPos = PlaneCol::SearchPlane();	// holds value returned by search function
	int choice;									// holds menu selection
	
	// plane info that CAN be edited
	int minNumOfCrewInp, numSeatsInp;
	double rangeInp;
	
	if(returnPos != -1)
	{
		do{ 
			cout << "What would you like to edit for this plane?" << endl;
			cout << "0 - Quit" << endl;
			cout << "1 - Number of Seats" << endl;
			cout << "2 - Minimun Number of Crew Required" << endl;
			cout << "3 - Fuel Range" << endl;
			cin >> choice;
			switch(choice)
			{
				case 0:
					break;
				
				case 1:
					cout << "Enter the NEW Number of Seats: ";
					cin >> numSeatsInp;
					planeVec[returnPos].SetNumSeats(numSeatsInp);
					cout << "***** PLANE EDITED *****" << endl;
					break;
					
				case 2:
					cout << "Enter the NEW Minimum Number of Crew Requried: ";
					cin >> minNumOfCrewInp;
					planeVec[returnPos].SetMinCrew(minNumOfCrewInp);
					cout << "***** PLANE EDITED *****" << endl;
					break;
					
				case 3:
					cout << "Enter the NEW Fuel Range: ";
					cin >> rangeInp;
					planeVec[returnPos].SetRange(rangeInp);
					cout << "***** PLANE EDITED *****" << endl;
					break;
				
				default:
					cout << "Invalid selection. Try again." << endl;
			}
			cout << endl;
			
		}while(choice != 0);
	}
	else
	{
		cout << "Could not edit the PLANE" << endl;
	}
}

void PlaneCol::DeletePlane(){
	int returnPos = PlaneCol::SearchPlane();	// holds value returned by search function
	
	if(returnPos != -1)
	{
		planeVec.erase(planeVec.begin() + returnPos);
		cout << "***** PLANE DELETED *****" << endl;
	}
	else
	{
		cout << "Could not delete the PLANE" << endl;
	}
}

int PlaneCol::SearchPlane(){
	string tailNumInp;							// user input for tail number
	int position = -1;							// the position of the matching tail num; if no match, returns -1
	unsigned int size = planeVec.size();		// size of the vector
	
	// PROMPTS FOR THE TAIL NUMBER
	cout << "Enter the TAIL NUMBER of the plane: ";
	cin >> tailNumInp;
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING TAIL NUMBER
		if(planeVec[i].GetTailNum() == tailNumInp)
		{
			position = i;
		}
	}
	
	// CHECKS IF THE POSITION HAS CHANGED
	if(position == -1)
	{
		cout << "Could not find a Plane with that TAIL NUMBER." << endl;
	}
	
	return position;
}

void PlaneCol::PrintAllPlanes(){
	unsigned int size = planeVec.size();		// saves the size of the vector
	
	cout << "***** ALL PLANES LISTED BELOW *****" << endl;
	cout << setw(20) << "TAIL NUMBER" << setw(20) << "MAKE" << setw(20) << "MODEL" << setw(20) << "NUM. SEATS" << setw(20) << "MIN. CREW" << setw(20) << "FUEL RANGE" << endl;
	
	for (unsigned int i = 0; i < size; i++)
	{
		cout << setw(20) << planeVec[i].GetTailNum();
		cout << setw(20) << planeVec[i].GetMake();
		cout << setw(20) << planeVec[i].GetModel();
		cout << setw(20) << planeVec[i].GetNumSeats();
		cout << setw(20) << planeVec[i].GetMinCrew();
		cout << setw(20) << planeVec[i].GetRange();
		cout << endl;
	}		
}

void PlaneCol::PrintOnePlane(){
	int returnPos = PlaneCol::SearchPlane();	// holds value returned by search function
	if(returnPos != -1)
	{
		cout << setw(20) << "TAIL NUMBER" << setw(20) << "MAKE" << setw(20) << "MODEL" << setw(20) << "NUM. SEATS" << setw(20) << "MIN. CREW" << setw(20) << "FUEL RANGE" << endl;
		cout << setw(20) << planeVec[returnPos].GetTailNum();
		cout << setw(20) << planeVec[returnPos].GetMake();
		cout << setw(20) << planeVec[returnPos].GetModel();
		cout << setw(20) << planeVec[returnPos].GetNumSeats();
		cout << setw(20) << planeVec[returnPos].GetMinCrew();
		cout << setw(20) << planeVec[returnPos].GetRange();
		cout << endl;
	}
	else
	{
		cout << "Could not print information for that PLANE." << endl;
	}
}

void PlaneCol::LoadAllData(){					// uses fstreams to read data in from a file
	ifstream fin;								// input stream variable
	Plane planeObject;							// instance of Plane class
	
	// plane information variables
	string tailNumInp, makeInp, modelInp;
	int numSeatsInp, minNumOfCrewInp, count;
	double rangeInp;
	
	// OPENS THE FILE
	fin.open("PlaneOutput.txt");
	
	// CHECKS THAT THE FILE OPENED CORRECTLY
	if (fin.is_open())
	{
		// READS FROM THE FILE
		fin >> count;
		planeCount = count;
		for (int i = 0; i < planeCount; i++)
		{
			fin.ignore();
			getline(fin, tailNumInp);
			getline(fin, makeInp);
			getline(fin, modelInp);
			fin >> numSeatsInp;
			fin >> minNumOfCrewInp;
			fin >> rangeInp;
			
			planeObject.SetMake(makeInp);
			planeObject.SetModel(modelInp);
			planeObject.SetTailNum(tailNumInp);
			planeObject.SetNumSeats(numSeatsInp);
			planeObject.SetMinCrew(minNumOfCrewInp);
			planeObject.SetRange(rangeInp);			
		
			planeVec.push_back(planeObject);
		}
		
		cout << "***** PLANE INFORMATION LOADED *****" << endl;
	}
	else
	{
		cout << "Could not load plane information." << endl;
	}
	
	// CLOSES THE FILE
	fin.close();
}

void PlaneCol::SaveAllData(){					// uses fstreams to print data to a file
	ofstream fout;								// output stream variable
	unsigned int size = planeVec.size();		// saves the size of the vector
	
	// OPENS THE FILE
	fout.open("PlaneOutput.txt", ios::out | ios::trunc);	// overwrites file each time
	
	// PRINTS TO THE FILE
	
	fout << planeVec.size() << endl;
	for (unsigned int i = 0; i < size; i++)
	{
		fout << planeVec[i].GetTailNum() << endl;
		fout << planeVec[i].GetMake() << endl;
		fout << planeVec[i].GetModel() << endl;
		fout << planeVec[i].GetNumSeats() << endl;
		fout << planeVec[i].GetMinCrew() << endl;
		fout << planeVec[i].GetRange() << endl;
	}
	
	cout << "***** PLANE INFORMATION SAVED *****" << endl;
	
	// CLOSES THE FILE
	fout.close();
}

string PlaneCol::ReturnTailNumber(){
	int returnPos = PlaneCol::SearchPlane();	// holds value returned by search function
	string tempTailNum;							// temporary variablr for the tail number
	
	if(returnPos != -1)
	{
		tempTailNum = planeVec[returnPos].GetTailNum();
	}
	else
	{
		tempTailNum = "none";
		cout << "Could not retrieve TAIL NUMBER" << endl;
	}
	
	return tempTailNum;
}

int PlaneCol::ReturnNumSeats(string tailNum){
	unsigned int size = planeVec.size();		// size of the vector
	int numberOfSeats = -1;
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING TAIL NUMBER
		if(planeVec[i].GetTailNum() == tailNum)
		{
			numberOfSeats = planeVec[i].GetNumSeats();
		}
	}
	
	return numberOfSeats;
}

int PlaneCol::ReturnMinNumOfCrew(string tailNum){
	unsigned int size = planeVec.size();		// size of the vector
	int minimumCrew = -1;
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING TAIL NUMBER
		if(planeVec[i].GetTailNum() == tailNum)
		{
			minimumCrew = planeVec[i].GetMinCrew();
		}
	}
	
	return minimumCrew;
}