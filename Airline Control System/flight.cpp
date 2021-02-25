/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "flight.h"
//#include "crewCol.h"
#include <iostream>

using namespace std;

Flight::Flight(){									// constructor
	numPilots = 0;									// number of pilots used
	numCoPilots = 0;								// number of co-pilots used
	numCrew = 0;									// number of cabin crew members used
	id = 0;											// id number for the flight
	numPassengers = 0;								// number of passengers on the flight currently; a COUNT
	planeTailNum = "none";							// the tail number of the plane used for the flight
	startAirportCode = "none";						// starting airport code
	endAirportCode = "none";						// ending airport code
	status = "none";								// status of the flight
}

void Flight::SetNumPilots(int numPilotsInput){		// mutator for number of pilots
	numPilots = numPilotsInput;
}

int Flight::GetNumPilots(){							// accessor for number of pilots
	return numPilots;
}

void Flight::SetNumCoPilots(int numCoPilotsInput){	// mutator for number of pilots
	numCoPilots = numCoPilotsInput;
}

int Flight::GetNumCoPilots(){						// accessor for number of pilots
	return numCoPilots;
}

void Flight::SetNumCrew(int numCrewInput){			// mutator for number of crew members
	numCrew = numCrewInput;
}

int Flight::GetNumCrew(){							// accessor for number of crew members
	return numCrew;
}

void Flight::SetPilotID(int pilotIDInput){			// mutator for list of pilots 					
	pilotID.push_back(pilotIDInput);
}

int Flight::GetPilotID(int position){				// accessor for list of pilots					
	int id;
	id = pilotID.at(position);
	return id;
}

void Flight::SetCoPilotID(int coPilotIDInput){		// mutator for list of co-pilots 				
	coPilotID.push_back(coPilotIDInput);
}

int Flight::GetCoPilotID(int position){				// accessor for list of co-pilots				 
	int id;
	id = coPilotID.at(position);
	return id;
}

void Flight::SetCabinID(int cabCrewInput){			// mutator for list of cabin crew members		
	cabinID.push_back(cabCrewInput);
}

int Flight::GetCabinID(int position){				// accessor for list of cabin crew members		
	int id;
	id = cabinID.at(position);
	return id;
}

void Flight::SetID(int idInput){					// mutator for flight id
	id = idInput;
}

int Flight::GetID(){								// accessor for flight id
	return id;
}

void Flight::SetNumPassengers(int passengersInput){	// mutator for number of passengers
	numPassengers = passengersInput;
}

int Flight::GetNumPassengers(){						// accessor for number of passengers
	return numPassengers;
}

void Flight::SetTailNum(string tailNumInput){		// mutator for plane tail number used for the flight
	planeTailNum = tailNumInput;
}

string Flight::GetTailNum(){						// accessor for plane tail number used for thr flight
	return planeTailNum;
}

void Flight::SetStartTimeAndDate(time_t timeInfo){	// mutator for starting time of flight
	startTimeAndDate = timeInfo;
}

time_t Flight::GetStartTimeAndDate(){				// accessor for starting time of flight
	return startTimeAndDate;
}

void Flight::SetEndTimeAndDate(time_t timeInfo){	// mutator for ending time of flight
	endTimeAndDate = timeInfo;
}

time_t Flight::GetEndTimeAndDate(){					// accessor for ending time of flight
	return endTimeAndDate;
}

void Flight::SetStartCode(string startCodeInput){	// mutator for starting airport code of flight
	startAirportCode = startCodeInput;
}

string Flight::GetStartCode(){						// accessor for starting airport code of flight
	return startAirportCode;
}

void Flight::SetEndCode(string endCodeInput){		// mutator for ending airport code of flight
	endAirportCode = endCodeInput;
}

string Flight::GetEndCode(){						// accessor for ending airport code of flight
	return endAirportCode;
}

void Flight::SetStatus(string statusInput){			// mutator for status of the flight
	status = statusInput;
}

string Flight::GetStatus(){							// acessor for status of flight
	return status;
}

int Flight::CheckPilotID(int idInput){				// loops through pilot vector and checks if the input id is in that vector
	int check = 0;
	unsigned int size = pilotID.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if(idInput == GetPilotID(i))
		{
			check = 1;
		}
	}
	return check;
}

int Flight::CheckCoPilotID(int idInput){			// loops through co-pilot vector and checks if the input id is in that vector
	int check = 0;
	unsigned int size = coPilotID.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if(idInput == GetCoPilotID(i))
		{
			check = 1;
		}
	}
	return check;
}

int Flight::CheckCabinID(int idInput){				// loops through cabin crew vector and checks if the input id is in that vector
	int check = 0;
	unsigned int size = cabinID.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if(idInput == GetCabinID(i))
		{
			check = 1;
		}
	}
	return check;
}
