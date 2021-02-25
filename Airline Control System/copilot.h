/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "pilot.h"

class CoPilot : public Crew {					// co-pilot class derived from crew
	private:
		string rating;							// 4-char alphanumeric rating code for the pilot
		double coPilotHours;					// cumulative number of hours of flight experience as a co-pilot
	
	public:
		CoPilot();								// constructor
		void SetRating(string ratingInput);		// mutator for rating
		string GetRating();						// accessor for rating
		
		void SetCoPilotHours(double hoursInput);// mutator for pilot hours
		double GetCoPilotHours();				// accessor for pilot hours
		
		void PrintInfo();						// overrides funct in base class and prints co-pilot info
		void SaveInfo();						// overrides funct in base class and prints info to file
};