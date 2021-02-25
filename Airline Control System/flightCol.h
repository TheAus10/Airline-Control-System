/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 
#include "flight.h"
#include "planeCol.h"
#include "crewCol.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class FlightCol {
	private:
		vector<Flight> flightVec;
		int flightCount;				// keeps track of the TOTAL number of flights that have been added
		int deleteCount;				// keeps track of the TOTAL number of flights that have been deleted
	
	public:
		FlightCol();
			// constructor
			
		void SetCounter(int count);							
			// mutator for crew count
		
		int GetCounter();							
			// accessor for crew count
	
		void AddFlight();
			// Prompt for flight information
			// Check if plane is available
			// Check if crew are available
			// Assign info
			// Increment counter
			// takes in objects of the plane and crew collections

		void DeleteFlight();
			// check that flight is not active
			// removes a specified flight from the crew member vector
			// requires a search
			
		void EditFlight();
			// calls search function
			// allows them to change numPassengers, status
			// assigns new type to the returned position
			
		int SearchFlight();
			// prompt user for flight id
			// loops through flight vector to find matching id
			// returns postion of the flight with that id
		
		void PrintAllFlights();
			// prints all flights information in a table
			// uses setw function in iomanip library
			
		void PrintOneFlight();
			// prompt for a flight id
			// prints information for that user
			// requires search
			
		void LoadAllData();
			// uses fstreams to read data in from a file
			
		void SaveAllData();
			// uses fstreams to print data to a file
			
		void PrintPlaneSchedule();
			// prompt for plane tail num
			// print all flights for that plane
			
		void PrintCrewMemberSchedule();
			// prompt for name of crew member
			// print all flights for that crew member
		
		void PrintByStatus();
			// use menu to select which status to search for
			// down each menu branch, print all flights with that status
			
		void DeleteByStatus();
			// use menu to select which status to search for; CANNOT be active
			// down each menu branch, delete all flights with that status
			
		void UpdateStatus();
			// checks time to see if flights have been completed yet
			// updates status of all flights
			// deletes flights that are 
			// called periodically throughout the program
};