/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include <string>
using namespace std;

class Plane {
	private:
		string make;							// the make of the plane
		string model;							// model of the plane
		string tailNum;							// unique tail number for the plane; used as alphanumeric ID
		int numSeats;							// number of seats on the plane
		int minNumOfCrew;						// minimum number of crew members needed
		double range;							// the fuel range for this plane;
		
	public:
		Plane();								// constructor
		void SetMake(string makeInput);			// mutator function for make
		string GetMake();						// accessor function for make
		
		void SetModel(string modelInput);		// mutator function for model
		string GetModel();						// accessor function for model
		
		void SetTailNum(string tailNumInput);	// mutator function for tail number
		string GetTailNum();					// accessor function for tail number
		
		void SetNumSeats(int numSeatsInput);	// mutator function for number of seats
		int GetNumSeats();						// accessor function for number of seats
		
		void SetMinCrew(int numCrewInput);		// mutator function for miin number of crew
		int GetMinCrew();						// accessor function for min number of crew
		
		void SetRange(double rangeInput);		// mutator function for fuel range
		double GetRange();						// accessor function for fuel range
};