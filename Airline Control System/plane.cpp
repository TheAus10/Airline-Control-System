/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "plane.h"

Plane::Plane(){									// constructor
	make = "none";							
	model = "none";							
	tailNum = "none";						
	numSeats = 0;							
	minNumOfCrew = 0;						
	range = 0;							
}

void Plane::SetMake(string makeInput){			// mutator function for make
	make = makeInput;
}

string Plane::GetMake(){						// accessor function for make
	return make;
}

void Plane::SetModel(string modelInput){		// mutator function for model
	model = modelInput;
}

string Plane::GetModel(){						// accessor function for model
	return model;
}

void Plane::SetTailNum(string tailNumInput){	// mutator function for tail number
	tailNum = tailNumInput;
}

string Plane::GetTailNum(){						// accessor function for tail number
	return tailNum;
}

void Plane::SetNumSeats(int numSeatsInput){		// mutator function for number of seats
	numSeats = numSeatsInput;
}

int Plane::GetNumSeats(){						// accessor function for number of seats
	return numSeats;
}

void Plane::SetMinCrew(int numCrewInput){		// mutator function for miin number of crew
	minNumOfCrew = numCrewInput;
}

int Plane::GetMinCrew(){						// accessor function for min number of crew
	return minNumOfCrew;
}

void Plane::SetRange(double rangeInput){		// mutator function for fuel range
	range = rangeInput;
}

double Plane::GetRange(){						// accessor function for fuel range
	return range;
}

