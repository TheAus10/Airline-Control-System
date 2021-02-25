/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "cabin.h"

Cabin::Cabin(){									// constructor
	position = "none";
}

void Cabin::SetPosition(string posInput){		// mutator for position
	position = posInput;
}

string Cabin::GetPosition(){					// accessor for position
	return position;
}

void Cabin::PrintInfo(){						// prints info for cabin member
	cout << setw(10) << GetID() << setw(20) << GetName() << setw(14) << GetType() << setw(12) << GetStatus() << setw(8) << "-" << setw(12) << "-" << setw(12) << position <<endl;
}
void Cabin::SaveInfo(){
	ofstream fout;
	
	fout.open("CrewOutput.txt", ios::app);
	
	fout << GetType() << endl;
	fout << GetName() << endl;
	fout << GetStatus() << endl;
	fout << position << endl;
	fout << GetID() << endl;
	
	fout.close();
}