/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "pilot.h"

Pilot::Pilot(){									// constructor
	rating = "none";
	pilotHours = 0;
}

void Pilot::SetRating(string ratingInput){		// mutator for rating
	rating = ratingInput;
}

string Pilot::GetRating(){						// accessor for rating
	return rating;
}

void Pilot::SetPilotHours(double hoursInput){	// mutator for pilot hours
	pilotHours = hoursInput;
}

double Pilot::GetPilotHours(){					// accessor for pilot hours
	return pilotHours;
}

void Pilot::PrintInfo(){						// prints info for pilot
	// call gets buckaroo //
	cout << setw(10) << GetID() << setw(20) << GetName() << setw(14) << GetType() << setw(12) << GetStatus() << setw(8) << rating << setw(12) << pilotHours << setw(12) << "-" <<endl;
}

void Pilot::SaveInfo(){
	ofstream fout;
	
	fout.open("CrewOutput.txt", ios::app);
	
	fout << GetType() << endl;
	fout << GetID() << endl;
	fout << GetName() << endl;
	fout << GetStatus() << endl;
	fout << rating << endl;
	fout << pilotHours << endl;
	
	fout.close();
}