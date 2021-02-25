/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "crew.h"

Crew::Crew(){									// constructor
	name = "none";
	type = "none";
	id = 0;
}

void Crew::SetName(string nameInput){			// mutator for name
	name = nameInput;
}

string Crew::GetName(){							// accessor for name
	return name;
}
void Crew::SetType(string typeInput){			// mutator for type
	type = typeInput;
}

string Crew::GetType(){							// accessor for type
	return type;
}

void Crew::SetStatus(string statusInput){		// mutator for status
	status = statusInput;
}

string Crew::GetStatus(){						// accessor for status
	return status;
}

void Crew::SetID(int idInput){					// mutator for id number
	id = idInput;
}

int Crew::GetID(){								// accessor for id number
	return id;
};

void Crew::PrintInfo(){							// prints info for crew member
	cout << setw(10) << id << setw(20) << name << setw(14) << type << setw(12) << status << endl;
}

void Crew::SaveInfo(){
	ofstream fout;
	
	fout.open("CrewOutput.txt", ios::app);
	
	fout << type << endl;
	fout << id << endl;
	fout << name << endl;
	fout << status << endl;
	
	fout.close();
}