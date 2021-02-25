/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Crew {
	private:
		string name;							// name of crew member
		string status;							// status of crew member
		string type;
		int id;									// unique number given to each crew member; CANT be modified
	
	public: 
		Crew();									// constructor
		void SetType(string typeInput);			// mutator for type
		string GetType();						// accessor for type
		
		void SetName(string nameInput);			// mutator for name
		string GetName();						// accessor for name
		
		void SetStatus(string statusInput);		// mutator for status
		string GetStatus();						// accessor for status
		
		void SetID(int idInput);				// mutator for id number
		int GetID();							// accessor for id number
		
		virtual void PrintInfo();				// prints all info for a crew member, starting with the basic info, then the more specific info
		virtual void SaveInfo();				// same as print, but uses file streams to save to a file
};