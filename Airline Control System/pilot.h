/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "crew.h"

class Pilot : public Crew {						// pilot class derived from crew
	private:
		string rating;							// 5-char alphanumeric rating code for the pilot
		double pilotHours;						// cumulative number of hours of flight experience as a pilot
	
	public:
		Pilot();								// constructor
		void SetRating(string ratingInput);		// mutator for rating
		string GetRating();						// accessor for rating
		
		void SetPilotHours(double hoursInput);	// mutator for pilot hours
		double GetPilotHours();					// accessor for pilot hours
		
		void PrintInfo();						// overrides funct in base class and prints pilot info
		void SaveInfo();						// overrides funct in base class and prints info to file
};