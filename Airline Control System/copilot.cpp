/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "copilot.h"

CoPilot::CoPilot(){								// constructor
	rating = "none";
	coPilotHours = 0;
}

void CoPilot::SetRating(string ratingInput){	// mutator for rating
	rating = ratingInput;
}

string CoPilot::GetRating(){					// accessor for rating
	return rating;
}

void CoPilot::SetCoPilotHours(double hoursInput){	// mutator for pilot hours
	coPilotHours = hoursInput;
}

double CoPilot::GetCoPilotHours(){				// accessor for pilot hours
	return coPilotHours;
}

void CoPilot::PrintInfo(){						// prints info for co-pilot
	cout << setw(10) << GetID() << setw(20) << GetName() << setw(14) << GetType() << setw(12) << GetStatus() << setw(8) << rating << setw(12) << coPilotHours << setw(12) << "-" <<endl;
}
void CoPilot::SaveInfo(){
	ofstream fout;
	
	fout.open("CrewOutput.txt", ios::app);
	
	fout << GetType() << endl;
	fout << GetID() << endl;
	fout << GetName() << endl;
	fout << GetStatus() << endl;
	fout << rating << endl;
	fout << coPilotHours << endl;
	
	fout.close();
}