/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "plane.h"
#include <vector>
#include <algorithm>
#include <iomanip> 
#include <iostream>
#include <fstream>

class PlaneCol {
	private:
		vector<Plane> planeVec;
		int planeCount;
	
	public:
		PlaneCol();		
			// constructor
		
		vector<Plane> GetPlaneVector();
			// acessor for plane vector
		
		void SetCounter(int count);							
			// mutator for plane count
			
		int GetCounter();							
			// accessor for plane count
		
		void AddPlane();
			// Prompt for plane information
			// Assign info
			// Increase counter
			
		void EditPlane();
			// calls search function
			// prompts user to input new information
			// sets new information to that plane
			
		void DeletePlane();
			// calls search function
			// removes plane at the returned position from vector
			// uses erase() function

		int SearchPlane();
			// prompt user for the tail number
			// searches through vector for given tail number
			// returns position to where the tail number was found
			
		void PrintAllPlanes();
			// uses cout to print information in table
			// uses setw from iomanip library
			
		void PrintOnePlane();
			// calls search function
			// prints information for only one plane
			
		void LoadAllData();
			// uses fstreams to read data in from a file
			
		void SaveAllData();
			// uses fstreams to print data to a file
			
		string ReturnTailNumber();
			// calls search function
			// gets the tail number at the position in the vector
			// returns the tail number
			
		int ReturnNumSeats(string tailNum);
			// takes in a string parameter for the tail number
			// searches for the position in the vector of the plane with that tail number
			// gets the number of seats that plane can hold
			// returns the number of seats
			
		int ReturnMinNumOfCrew(string tailNum);
			// takes in a string parameter for the tail number
			// searches for the position in the vector of the plane with that tail number
			// gets the minimum number of crew required for that plane 
			// returns the minimum number of crew required
};