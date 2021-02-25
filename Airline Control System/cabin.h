/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "copilot.h"

class Cabin : public Crew {						// cabin class derived from crew
	private:
		string position;						// position of cabin member on plane (Position: First Class, Business Class, Economy Front, Economy Rear, Lead)
		
	public:
		Cabin();								// constructor
		void SetPosition(string posInput);		// mutator for position
		string GetPosition();					// accessor for position
		
		void PrintInfo();						// overrides funct in base class and prints cabin info
		void SaveInfo();						// overrides funct in base class and prints info to file
};