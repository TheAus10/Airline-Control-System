/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Flight {
	private:
		int numPilots;								// number of pilots on flight; 8+ hours require 2 pilots & 2 co-pilots
		int numCoPilots;							// number of co-pilots on flight
		int numCrew;								// number of cabin crew member on flight; 8+ hours require twice the minimum
		vector<int> pilotID;						// list of pilots on flight by ID
		vector<int> coPilotID;						// list of co-pilots on flight by ID
		vector<int> cabinID;						// list of cabin crew members on flight by ID
		int id;										// id number for the flight
		int numPassengers;							// number of passengers on the flight currently; a COUNT
		string planeTailNum;						// the tail number of the plane used for the flight
		time_t startTimeAndDate;					// time and date the flight starts
		time_t endTimeAndDate;						// time and date the flight ends
		string startAirportCode;					// starting airport code
		string endAirportCode;						// ending airport code
		string status;								// status of the flight
		
	public:
		Flight();									// constructor
		void SetNumPilots(int numPilotsInput);		// mutator for number of pilots
		int GetNumPilots();							// accessor for number of pilots
		
		void SetNumCoPilots(int numCoPilotsInput);	// mutator for number of co-pilots
		int GetNumCoPilots();						// accessor for number of co-pilots
		
		void SetNumCrew(int numCrewInput);			// mutator for number of crew members
		int GetNumCrew();							// accessor for number of crew members
		
		void SetPilotID(int pilotIDInput);			// mutator for list of pilots
		int GetPilotID(int position);				// accessor for list of pilots
		
		void SetCoPilotID(int coPilotIDInput);		// mutator for list of pilots
		int GetCoPilotID(int position);				// accessor for list of pilots
		
		void SetCabinID(int cabCrewInput);			// mutator for list of cabin crew members
		int GetCabinID(int position);				// accessor for list of cabin crew members
		
		void SetID(int idInput);					// mutator for flight id
		int GetID();								// accessor for flight id
		
		void SetNumPassengers(int passengersInput);	// mutator for number of passengers
		int GetNumPassengers();						// accessor for number of passengers
		
		void SetTailNum(string tailNumInput);		// mutator for plane tail number used for the flight
		string GetTailNum();						// accessor for plane tail number used for thr flight
		
		void SetStartTimeAndDate(time_t timeInfo);	// mutator for starting time and date of flight
		time_t GetStartTimeAndDate();				// accessor for starting time and date of flight; returns the EPOCH number
		
		void SetEndTimeAndDate(time_t timeInfo);	// mutator for ending time and date of flight
		time_t GetEndTimeAndDate();					// accessor for ending time and date of flight; returns the EPOCH number
		
		void SetStartCode(string startCodeInput);	// mutator for starting airport code of flight
		string GetStartCode();						// accessor for starting airport code of flight
		
		void SetEndCode(string endCodeInput);		// mutator for ending airport code of flight
		string GetEndCode();						// accessor for ending airport code of flight
		
		void SetStatus(string statusInput);			// mutator for status of the flight
		string GetStatus();							// acessor for status of flight
		
		int CheckPilotID(int idInput);				// loops through pilot vector and checks if the input id is in that vector
		int CheckCoPilotID(int idInput);			// loops through co-pilot vector and checks if the input id is in that vector
		int CheckCabinID(int idInput);				// loops through cabin crew vector and checks if the input id is in that vector
};