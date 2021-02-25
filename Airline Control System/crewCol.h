/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

//#include "crew.h"
//#include "pilot.h"
//#include "copilot.h"
#include "cabin.h"

class CrewCol {
	private:
		vector<Crew*> crewVec;
		int crewCount;					// keeps track of the TOTAL number of crew members
		int deleteCount;				// keeps track of the total number of deleted crew members
	
	public:
		CrewCol();
			// constructor
			
		void SetCounter();							
			// mutator for crew count
			
		int GetCounter();							
			// accessor for crew count
	
		void AddCrewMember();
			// Prompt for crew information
			// Assign id
			// Sort out by type of crew
			// Increment counter
			
		void EditCrewMember();
			// calls search function
			// allows them to change the TYPE of the crew member
			// assigns new type to the returned position

		void DeleteCrewMember();
			// calls search function
			// uses erase() to delete that crew member from the vector
			
		int SearchCrewMember();
			// prompt user for crew member name
			// loops through to find a person with that name
			// returns an integer to the position 
		
		void PrintAllCrewMembers();
			// prints all crew members information in a table
			// uses setw function in iomanip library
			
		void PrintOneCrewMember();
			// calls search function
			// prints information for that user
			
		void LoadAllData();
			// uses fstreams to read data in from a file
			
		void SaveAllData();
			// uses fstreams to print data to a file
			
		string ReturnName();
			// calls search function
			// gets the name of the person at the returned position
			// returns name
			
		string ReturnType(string name);
			// takes in name parameter
			// searches for crew member with that name
			// gets the type of the crew member at the position
			// returns type
			
		int ReturnID(string name);
			// takes in name parameter
			// searches for crew member with that name
			// gets the id of the crew member at the position
			// returns id
			
		string ReturnStatus(string name);
			// takes in name as parameter
			// searches for crew member with that name
			// stores the status of that crew member
			// returns status
};