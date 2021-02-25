/*
Name:			Austin Reeves
Professor:		Keathly
Assignment:		Homework 5
Date:			April 22, 2019
*/ 

#include "flightCol.h"
extern PlaneCol planeClass;				// instance of the plane collection
extern CrewCol crewClass;				// instance of the crew collection
extern FlightCol flightClass;			// instance of the flight collection

FlightCol::FlightCol(){
	flightCount = 0;
	deleteCount = 0;
}
	
void FlightCol::SetCounter(int count){							
	flightCount = count;
}
	
int FlightCol::GetCounter(){							
	return flightCount;
}
	
void FlightCol::AddFlight(){
	int numFlightsAdded;						// the number of flights the user wants to add at a time
	Flight flightObject;						// instance of Flight class
	unsigned int size = flightVec.size();		// holds the size of the flight vector
	int check;									// holds either 1 or 0 depending on if the tail number is unique
	
	string sCodeInp, eCodeInp, tailNumInp;		// starting and ending airport code; the tail number of the flight
	string statusInp;							// status variable
	int numPassInp, id;							// number of passengers on the plane; holds the ids of the crew members while being checked
	int pCount, cpCount, ccCount;				// counters for pilots, co-pilots, and cabin crew members in that order
	int sHour, sMin, sYear, sMonth, sDay;		// start date and time information of flight
	int eHour, eMin, eYear, eMonth, eDay;		// end date and time information of flight
	struct tm startTimeInfo;					// stores the time info for the starting time
	struct tm endTimeInfo;						// stores the time info for the ending time
	time_t now;									// used for the current system time
	time_t startEndDiff;						// the difference in time between the start and the end
	
	// PROMPT FOR FLIGHT INFO
	cout << "How many flights would you like to add? ";
	cin >> numFlightsAdded;
	
	for (int i = 0; i < numFlightsAdded; i++)
	{
		pCount = 0; cpCount= 0; ccCount= 0;		// setting counts back to zero every for each flight added
		
		// PROMPTING FOR TIME INFO
		cout << "Enter the starting MONTH, DAY, AND YEAR (seperated by spaces) of the flight: ";
		cin >> sMonth >> sDay >> sYear;
		cout << "Enter the starting HOUR AND MINUTE (seperated by a space) of the flight: ";
		cin >> sHour >> sMin;
		
		cout << "Enter the ending MONTH, DAY, AND YEAR (seperated by spaces) of the flight: ";
		cin >> eMonth >> eDay >> eYear;
		cout << "Enter the ending HOUR AND MINUTE (seperated by a space) of the flight: ";
		cin >> eHour >> eMin;
		
		// SETS THE CURRENT TIME TO THE CURRENT GM TIME
		time(&now);
		startTimeInfo = *gmtime(&now);
		endTimeInfo = *gmtime(&now);
	
		// MODIFIES TIME TO BE USERS INPUT
		startTimeInfo.tm_year = sYear - 1900;
		startTimeInfo.tm_mon = sMonth - 1;
		startTimeInfo.tm_mday = sDay;
		startTimeInfo.tm_hour = sHour - 1;
		startTimeInfo.tm_min = sMin;
		startTimeInfo.tm_sec = 0;
		
		endTimeInfo.tm_year = eYear - 1900;
		endTimeInfo.tm_mon = eMonth - 1;
		endTimeInfo.tm_mday = eDay;
		endTimeInfo.tm_hour = eHour - 1;
		endTimeInfo.tm_min = eMin;
		endTimeInfo.tm_sec = 0;
		
		// ASSIGNING TIME INFO
		flightObject.SetStartTimeAndDate(mktime(&startTimeInfo));
		flightObject.SetEndTimeAndDate(mktime(&endTimeInfo));
		
		// CALCULATING THE DIFFERENCE BETWEEN THE TWO TIMES
		startEndDiff = difftime(mktime(&endTimeInfo), mktime(&startTimeInfo));
		
		// PROMPTING FOR PLANE INFO
		cout << "Enter the NUMBER OF PASSENGERS on the flight: ";
		cin >> numPassInp;
		cin.ignore();
		
		// LOOPS UNTIL A VALID PLANE IS CHOSEN
		do {
			check = 0;	// do-while can be broken
			
			// PROMPTS FOR PLANE ID AND ENSURES IT TO BE UNIQUE
			tailNumInp = planeClass.ReturnTailNumber();
			if(tailNumInp == "none")
			{
				// only entereed when plane does not exist
				check = 1;	// do-while cannot be broken
			}
			else
			{
				// SEARCHES THROUGH ALL FLIGHTS TO SEE IF THE PLANE IS FREE DURING THE TIMES
				for (unsigned int i = 0; i < size; i++)	// loops through the size of the flight vector
				{
					// CHECKS IF THE PLANE IS USED IN ANY OTHER FLIGHTS
					if(flightVec[i].GetTailNum() == tailNumInp)
					{
						// CHECKS IF PLANE IS AVAILABLE DURING THE NEW TIME
						if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
						{
							check = 1;	// do-while CANNOT be broken
							cout << "Plane not available during that time. Try again." << endl;
							break;		// ends for-loop
						}
						else 
						{	
							// CHECKS IF PLANE HAS ENOUGH SEATS
							if(planeClass.ReturnNumSeats(tailNumInp) >= numPassInp)
							{
								check = 0;	// do-while can be broken
								break;		// ends for-loop
							}
							else
							{
								cout << "Plane does not have enough seats." << endl;
								check == 1; // do-while CANNOT be broken
								break;		// exits for-loop
							}
						}
					}
					else 
					{
						// CHECKS IF PLANE HAS ENOUGH SEATS
						if(planeClass.ReturnNumSeats(tailNumInp) >= numPassInp)
						{
							check = 0;	// do-while can be broken
							break;		// ends for-loop
						}
						else
						{
							cout << "Plane does not have enough seats." << endl;
							check == 1; // do-while CANNOT be broken
							break;		// ends for-loop
						}
					}
				}
			}
		}while(check == 1);	// loops until 'check' remains 0
		
		// PROMPTING FOR THE AIRPORT CODES
		cout << "Enter the START AIRPORT CODE of the flight: ";
		cin.ignore();
		getline(cin, sCodeInp);
		cout << "Enter the END AIRPORT CODE of the flight: ";
		getline(cin, eCodeInp);
		
		// PROMPTING FOR CREW MEMBERS
		int minimumCrew = planeClass.ReturnMinNumOfCrew(tailNumInp);	// gets the minimum crew required for a specific plane
		
		if(startEndDiff >= 28800)		// checks if the flight is greater than or equal to 8 hours (28800 seconds)
		{
			cout << "Flight requires double the minimum of crew members." << endl;
			
			// PILOTS
			for(int i = 0; i < 2; i++) // loops twice to get two pilots
			{
				// LOOPS UNTIL A VALID CREW MEMBER IS CHOSEN 
				do {
					check = 0;
					cout << "Asking for Pilot " << i + 1 << "- " << endl;
					
					// gets name and returns type of the crew member with that name
					string crewName = crewClass.ReturnName();				
					
					string crewType = crewClass.ReturnType(crewName);	
					// checks that it is a pilot 
					if(crewType == "Pilot")		
					{
						if(size > 0)
						{
							for(unsigned int i = 0; i < size; i++)
							{
								// checking if available during the time of the new flight
								if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
								{
									check = 1;
									cout << "Crew Member not available during that time. Try again." << endl;
									break; 	// exits loop
								}
								else
								{
									if(crewClass.ReturnStatus(crewName) == "Available")
									{
										// adds pilot to vector
										check = 0;
										flightObject.SetPilotID(crewClass.ReturnID(crewName));
										pCount++;
										cout << "** CREW MEMBER ASSIGNED **" << endl;
										break;	// exits loop
									}
									else
									{
										check = 1;
										cout << "Crew member is not marked as available. Could not add." << endl;
										break;	// exits loop
									}
								}
							}
						}
						else
						{
							if(crewClass.ReturnStatus(crewName) == "Available")
							{
								// adds pilot to vector
								check = 0;
								flightObject.SetPilotID(crewClass.ReturnID(crewName));
								pCount++;
								cout << "** CREW MEMBER ASSIGNED **" << endl;
								break;	// exits loop
								}
								else
								{
									check = 1;
									cout << "Crew member is not marked as available. Could not add." << endl;
									break;	// exits loop
								}
							}
					}
					else
					{	
						check = 1;
						cout << "Crew Member is not a Pilot. Try again." << endl;
					}
				}while(check == 1);		// loops until 'check' remains 0
			}
			// CO-PILOTS
			for(int i = 0; i < 2; i++) // loops twice to get two crew members
			{
				// LOOPS UNTIL A VALID CREW MEMBER IS CHOSEN 
				do {
					check = 0;
					cout << "Asking for Co-Pilot " << i + 1 << "- " << endl;
					
					// gets name and returns type of the crew member with that name
					string crewName = crewClass.ReturnName();
					
					// checks that it is a pilot  
					if(crewClass.ReturnType(crewName) == "Co-Pilot")		
					{
						if(size > 0)
						{
							for(unsigned int i = 0; i < size; i++)
							{
								// checking if available during the flight
								if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
								{
									check = 1;
									cout << "Crew Member not available during that time. Try again." << endl;
									break;	// exits loop
								}
								else
								{
									if(crewClass.ReturnStatus(crewName) == "Available")
									{
										// adds co-pilot to vector
										check = 0;
										flightObject.SetCoPilotID(crewClass.ReturnID(crewName));
										cpCount++;
										cout << "** CREW MEMBER ASSIGNED **" << endl;
										break;	// exits loop
									}
									else
									{
										check = 1;
										cout << "Crew member is not marked as available. Could not add." << endl;
										break;	// exits loop
									}
								}
							}
						}
						else
						{
							// Checks that the crew member is marked as available
							if(crewClass.ReturnStatus(crewName) == "Available")
							{
								// adds o-pilot to vector
								check = 0;
								flightObject.SetCoPilotID(crewClass.ReturnID(crewName));
								cpCount++;
								cout << "** CREW MEMBER ASSIGNED **" << endl;
								break;	// exits loop
							}
							else
							{
								check = 1;
								cout << "Crew member is not marked as available. Could not add." << endl;
								break;	// exits loop
							}
						}
					}
					else
					{	
						check = 1;
						cout << "Crew Member is not a Co-Pilot. Try again." << endl;
					}
				}while(check == 1);		// loops until 'check' remains 0
			}
			// CABIN MEMBERS
			minimumCrew *= 2;	// doubling the minimum number of crew required
			minimumCrew -= 4;	// accounting for the 2 pilots and 2 co-pilots needed in the flight
			for(int i = 0; i < minimumCrew; i++) // loops twice to get two crew members
			{
				// LOOPS UNTIL A VALID CREW MEMBER IS CHOSEN 
				do {
					check = 0;
					cout << "Asking for Cabin Member " << i + 1 << "- " << endl;
					
					// gets name and returns type of the crew member with that name
					string crewName = crewClass.ReturnName();
					
					// checks that it is a pilot 
					if(crewClass.ReturnType(crewName) == "Cabin Member")		
					{
						if(size > 0)
						{
							for(unsigned int i = 0; i < size; i++)
							{
								// checking if available during the flight
								if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
								{
									check = 1;
									cout << "Crew Member not available during that time. Try again." << endl;
									break;	// exits loop
								}
								else
								{
									// Checks that the crew member is marked as available
									if(crewClass.ReturnStatus(crewName) == "Available")
									{
										// adds cabin member to vector
										check = 0;
										flightObject.SetCabinID(crewClass.ReturnID(crewName));
										ccCount++;
										cout << "** CREW MEMBER ASSIGNED **" << endl;
										break;	// exits loop
									}
									else
									{
										check = 1;
										cout << "Crew member is not marked as available. Could not add." << endl;
										break;	// exits loop
									}
								}
							}
						}
						else
						{
							// Checks that the crew member is marked as available
							if(crewClass.ReturnStatus(crewName) == "Available")
							{
								// adds cabin member to vector
								check = 0;
								flightObject.SetCabinID(crewClass.ReturnID(crewName));
								ccCount++;
								cout << "** CREW MEMBER ASSIGNED **" << endl;
								break;	// exits loop
							}
							else
							{
								check = 1;
								cout << "Crew member is not marked as available. Could not add." << endl;
								break;	// exits loop
							}
						}
					}
					else
					{	
						check = 1;
						cout << "Crew Member is not a Cabin Member. Try again." << endl;
					}
				}while(check == 1);		// loops until 'check' remains 0
			}
		}
		else							// goes throough as long as the time is less than 8 hours
		{
			// PILOTS
			// LOOPS UNTIL A VALID CREW MEMBER IS CHOSEN 
			do {
				check = 0;
				cout << "Asking for the Pilot- " << endl;

				// gets name and returns type of the crew member with that name
				string crewName = crewClass.ReturnName();
					
				// checks that it is a pilot  
				if(crewClass.ReturnType(crewName) == "Pilot")		
				{
					if(size > 0)
					{
						for(unsigned int i = 0; i < size; i++)	// not entering loop because size is zero
						{
							// checking if available during the flight
							if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
							{
								check = 1;
								cout << "Crew Member not available during that time. Try again." << endl;
								break;	// exits loop
							}
							else
							{
								// Checks that the crew member is marked as available
								if(crewClass.ReturnStatus(crewName) == "Available")
								{
									// adds pilot to vector
									check = 0;
									flightObject.SetPilotID(crewClass.ReturnID(crewName));
									pCount++;
									cout << "** CREW MEMBER ASSIGNED **" << endl;
									break;	// exits loop
								}
								else
								{
									check = 1;
									cout << "Crew member is not marked as available. Could not add." << endl;
									break;	// exits loop
								}
							}
						}
					}
					else
					{
						// Checks that the crew member is marked as available
						if(crewClass.ReturnStatus(crewName) == "Available")
						{
							// adds pilot to vector
							check = 0;
							flightObject.SetPilotID(crewClass.ReturnID(crewName));
							pCount++;
							cout << "** CREW MEMBER ASSIGNED **" << endl;
							break;	// exits loop
						}
						else
						{
							check = 1;
							cout << "Crew member is not marked as available. Could not add." << endl;
							break;	// exits loop
						}
					}
					
				}
				else
				{	
					check = 1;
					cout << "Crew Member is not a Pilot. Try again." << endl;
				}
			}while(check == 1);		// loops until 'check' remains 0
			
			// CO-PILOTS
			// LOOPS UNTIL A VALID CREW MEMBER IS CHOSEN 
			do {
				check = 0;
				cout << "Asking for the Co-Pilot- " << endl;
				
				// gets name and returns type of the crew member with that name
				string crewName = crewClass.ReturnName();
					
				// checks that it is a pilot  
				if(crewClass.ReturnType(crewName) == "Co-Pilot")		
				{
					if(size > 0)
					{
						for(unsigned int i = 0; i < size; i++)
						{
							// checking if available during the flight
							if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
							{
								check = 1;
								cout << "Crew Member not available during that time. Try again." << endl;
								break;	// exits loop
							}
							else
							{
								// Checks that the crew member is marked as available
								if(crewClass.ReturnStatus(crewName) == "Available")
								{
									// adds co-pilot to vector
									check = 0;
									flightObject.SetCoPilotID(crewClass.ReturnID(crewName));
									cpCount++;
									cout << "** CREW MEMBER ASSIGNED **" << endl;
									break;	// exits loop
								}
								else
								{
									check = 1;
									cout << "Crew member is not marked as available. Could not add." << endl;
									break;	// exits loop
								}
							}
						}
					}
					else
					{
						// Checks that the crew member is marked as available
						if(crewClass.ReturnStatus(crewName) == "Available")
						{
							// adds co-pilot to vector
							check = 0;
							flightObject.SetCoPilotID(crewClass.ReturnID(crewName));
							cpCount++;
							cout << "** CREW MEMBER ASSIGNED **" << endl;
							break;	// exits loop
						}
						else
						{
							check = 1;
							cout << "Crew member is not marked as available. Could not add." << endl;
							break;	// exits loop
						}
					}
				}
				else
				{	
					check = 1;
					cout << "Crew Member is not a Co-Pilot. Try again." << endl;
				}
			}while(check == 1);		// loops until 'check' remains 0
			
			// CABIN MEMBERS
			minimumCrew -= 2;	// accounting for the 1 pilot and 1 co-pilot needed in the flight
			for(int i = 0; i < minimumCrew; i++) // loops for the minimum number of crew members
			{
				// LOOPS UNTIL A VALID CREW MEMBER IS CHOSEN 
				do {
					check = 0;
					cout << "Asking for Cabin Member " << i + 1 << "- " << endl;
					
					// gets name and returns type of the crew member with that name
					string crewName = crewClass.ReturnName();
					
					// checks that it is a pilot 
					if(crewClass.ReturnType(crewName) == "Cabin Member")		
					{
						if(size > 0)
						{
							for(unsigned int i = 0; i < size; i++)
							{
								// checking if available during the flight
								if((flightVec[i].GetStartTimeAndDate() > mktime(&endTimeInfo)) || (flightVec[i].GetEndTimeAndDate() > mktime(&startTimeInfo)))
								{
									check = 1;
									cout << "Crew Member not available during that time. Try again." << endl;
									break;	// exits loop
								}
								else
								{
									// Checks that the crew member is marked as available
									if(crewClass.ReturnStatus(crewName) == "Available")
									{
										// adds cabin member to vector
										check = 0;
										flightObject.SetCabinID(crewClass.ReturnID(crewName));
										ccCount++;
										cout << "** CREW MEMBER ASSIGNED **" << endl;
										break;	// exits loop
									}
									else
									{
										check = 1;
										cout << "Crew member is not marked as available. Could not add." << endl;
										break;	// exits loop
									}
								}
							}
						}
						else
						{
							// Checks that the crew member is marked as available
							if(crewClass.ReturnStatus(crewName) == "Available")
							{
								// adds cabin member to vector
								check = 0;
								flightObject.SetCabinID(crewClass.ReturnID(crewName));
								ccCount++;
								cout << "** CREW MEMBER ASSIGNED **" << endl;
								break;	// exits loop
							}
							else
							{
								check = 1;
								cout << "Crew member is not marked as available. Could not add." << endl;
								break;	// exits loop
							}
						}
					}
					else
					{	
						check = 1;	
						cout << "Crew Member is not a Cabin Member. Try again." << endl;
					}
				}while(check == 1);		// loops until 'check' remains 0
			}
		}
		
		
		// ASSIGNING INFORMATION TO VECTOR
		statusInp = "Active";
		flightObject.SetNumPilots(pCount);
		flightObject.SetNumCoPilots(cpCount);
		flightObject.SetNumCrew(ccCount);
		flightObject.SetStatus(statusInp);
		flightObject.SetNumPassengers(numPassInp);
		flightObject.SetTailNum(tailNumInp);
		flightObject.SetStartCode(sCodeInp);
		flightObject.SetEndCode(eCodeInp);
		flightObject.SetID(flightCount);
		
		flightVec.push_back(flightObject);
		cout << "***** FLIGHT ADDED *****" << endl;
		cout << endl;
		
		//INCREASE COUNTER
		flightCount++;
	}	
}

void FlightCol::DeleteFlight(){
	int returnPos = SearchFlight();						// holds value returned by search function

	if(returnPos != -1)
	{
		// DELETES FLIGHT AT THE POSITION RETURNED BY SEARCH FUNCTION
		flightVec.erase(flightVec.begin() + returnPos);
		deleteCount++;
		cout << "***** FLIGHT DELETED *****" << endl;
	}
	else
	{
		cout << "Could not delete the FLIGHT" << endl;
	}
}

void FlightCol::EditFlight(){
	int returnPos = SearchFlight();				// holds value returned by search function
	int choice;									// holds menu selection
	
	// plane info that CAN be edited
	int numPassInp;
	string statusInp;
	time_t now;
	time_t currentTime;
	time(&now);
	struct tm currTime;
	currTime = *gmtime(&now);
	currentTime = mktime(&currTime);
	
	if(returnPos != -1)
	{
		do{ 
			cout << "What would you like to edit for this plane?" << endl;
			cout << "0 - Quit" << endl;
			cout << "1 - Number of Passengers" << endl;
			cout << "2 - Flight Status" << endl;
			cout << "Enter choice: ";
			cin >> choice;
			switch(choice)
			{
				case 0:
					break;
				
				case 1:
					cout << "Enter the NEW Number of Passengers: ";
					cin >> numPassInp;
					if (planeClass.ReturnNumSeats(flightVec[returnPos].GetTailNum()) >= numPassInp)
					{
						flightVec[returnPos].SetNumPassengers(numPassInp);
						cout << "***** FLIGHT EDITED *****" << endl;
					}
					else
					{
						cout << "Could not edit the FLIGHT." << endl;
					}
					break;
					
				case 2:
					do {
						cout << "Enter the NEW Flight Status: ";
						cout << "0 - Quit" << endl;
						cout << "1 - Completed" << endl;
						cout << "2 - Cancelled" << endl;
						cin >> choice;
						
						switch(choice)
						{
							case 0:
								break;
							
							case 1:
								if(flightVec[returnPos].GetEndTimeAndDate() < currentTime)
								{
									statusInp = "Completed";
									flightVec[returnPos].SetStatus(statusInp);
									cout << "***** FLIGHT EDITED *****" << endl;
								}
								else
								{	
									cout << "Could not edit the FLIGHT." << endl;
								}
								break;
							case 2:
								if(flightVec[returnPos].GetStartTimeAndDate() > currentTime)
								{
									statusInp = "Cancelled";
									flightVec[returnPos].SetStatus(statusInp);
									cout << "***** FLIGHT EDITED *****" << endl;
								}
								else
								{	
									cout << "Could not edit the FLIGHT." << endl;
								}
								break;
							default:
								cout << "Invalid selection. Try again." << endl;
								break;
						}
					}while(choice != 0);
					break;
				default:
					cout << "Invalid selection. Try again." << endl;
					break;
			}
			cout << endl;
			
		}while(choice != 0);
	}
	else
	{
		cout << "Could not edit the FLIGHT." << endl;
	}
}

int FlightCol::SearchFlight(){
	int idInp;									// user input for id
	int position = -1;							// the position of the matching name; if no match, returns -1
	unsigned int size = flightVec.size();			// size of the vector
	
	// PROMPTS FOR THE ID 
	cout << "Enter the ID of the flight: ";
	cin >> idInp;
	
	// LOOPS THROUGH THE VECTOR
	for(unsigned int i = 0; i < size; i++)
	{
		// CHECKS IF EACH ITERATION OF THE VECTOR HAS A MATCHING NAME
		if(flightVec[i].GetID() == idInp)
		{
			position = i;
		}
	}
	
	// CHECKS IF THE POSITION HAS CHANGED
	if(position == -1)
	{
		cout << "Could not find a flight with that ID." << endl;
	}
	
	return position;
}
	
void FlightCol::PrintAllFlights(){			// prints all crew members information in a table
	unsigned int size = flightVec.size();	// holds size of flight vector
	time_t startTime, endTime;				// holds start and time as epopchs
	string startTimeStr, endTimeStr;		// holds start and time as strings
	
	cout << "***** ALL FLIGHTS LISTED BELOW *****" << endl;
	
	cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
	cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
	
	for (unsigned int i = 0; i < size; i++)
	{
		// PRINTS ALL FLIGHT INFORMATION
		startTime = flightVec[i].GetStartTimeAndDate();		// stores the starting epoch time
		endTime = flightVec[i].GetEndTimeAndDate();			// stores the ending epoch time
		startTimeStr = ctime(&startTime);					// stroes the end time string returned by the ctime() funct
		endTimeStr = ctime(&endTime);						// stroes the end time string returned by the ctime() funct
		
		startTimeStr.erase(startTimeStr.end() - 1);			// removes 'newline' character from start time string
		endTimeStr.erase(endTimeStr.end() - 1);				// removes 'newline' character from end time string
		
		cout << setw(5) << flightVec[i].GetID();
		cout << setw(30) << startTimeStr;
		cout << setw(30) << endTimeStr;
		cout << setw(15) << flightVec[i].GetNumPassengers();
		cout << setw(12) << flightVec[i].GetTailNum();
		cout << setw(15) << flightVec[i].GetNumPilots();
		cout << setw(18) << flightVec[i].GetNumCoPilots();
		cout << setw(18) << flightVec[i].GetNumCrew();
		cout << setw(15) << flightVec[i].GetStartCode();
		cout << setw(13) << flightVec[i].GetEndCode();
		cout << setw(12) << flightVec[i].GetStatus();
		cout << endl;
	}
}
	
void FlightCol::PrintOneFlight(){
	
	// CALLS SEARCH FUNCTION
	int returnPos = SearchFlight();						// holds value returned by search function
	
	unsigned int size = flightVec.size();				// holds the size of the flight vector		
	time_t startTime, endTime;							// holds epoch for start and end time
	string startTimeStr, endTimeStr;					// holds string for the start and end times
	
	if(returnPos != -1)
	{
		// PRINTS FLIGHT INFORMATION AT THE RETURNED VECTOR POSITION FROM THE SEARCH FUNCTION
		cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
		cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
	
		startTime = flightVec[returnPos].GetStartTimeAndDate();		// stores the starting epoch time
		endTime = flightVec[returnPos].GetEndTimeAndDate();			// stores the ending epoch time
		startTimeStr = ctime(&startTime);							// stroes the end time string returned by the ctime() funct
		endTimeStr = ctime(&endTime);								// stroes the end time string returned by the ctime() funct
		
		startTimeStr.erase(startTimeStr.end() - 1);					// removes 'newline' character from start time string
		endTimeStr.erase(endTimeStr.end() - 1);						// removes 'newline' character from end time string
		
		cout << setw(5) << flightVec[returnPos].GetID();
		cout << setw(30) << startTimeStr;
		cout << setw(30) << endTimeStr;
		cout << setw(15) << flightVec[returnPos].GetNumPassengers();
		cout << setw(12) << flightVec[returnPos].GetTailNum();
		cout << setw(15) << flightVec[returnPos].GetNumPilots();
		cout << setw(18) << flightVec[returnPos].GetNumCoPilots();
		cout << setw(18) << flightVec[returnPos].GetNumCrew();
		cout << setw(15) << flightVec[returnPos].GetStartCode();
		cout << setw(13) << flightVec[returnPos].GetEndCode();
		cout << setw(12) << flightVec[returnPos].GetStatus();
		cout << endl;
	}
	else
	{
		cout << "Could not print flight information." << endl;
	}
}
	
void FlightCol::LoadAllData(){				// uses fstreams to read data in from a file
	ifstream fin;									// input stream variable
	Flight flightObject;							// instance of flight class
	
	// twmp flight info variables
	int fID, count = 0, numPassInp, cID;
	int pCount = 0, cpCount = 0, ccCount = 0;
	string tailNumInp, sCodeInp, eCodeInp, statusInp;
	time_t startTime, endTime;
	
	
	// OPENS THE FILE
	fin.open("FlightOutput.txt");
	
	// CHECKS THAT THE FILE OPENED CORRECTLY
	if (fin.is_open())
	{
		// READS FROM THE FILE
		fin >> count;
		fin >> deleteCount;
		flightCount = count + deleteCount;
		for (int i = 0; i < count; i++)
		{
			fin >> fID;
			fin >> startTime;
			fin >> endTime;
			fin >> numPassInp;
			fin >> tailNumInp;
			fin >> pCount;
			for (int i = 0; i < pCount; i ++)
			{
				fin >> cID;
				flightObject.SetPilotID(cID);
			}
			fin >> cpCount;
			for (int i = 0; i < cpCount; i ++)
			{
				fin >> cID;
				flightObject.SetCoPilotID(cID);
			}
			fin >> ccCount;
			for (int i = 0; i < ccCount; i ++)
			{
				fin >> cID;
				flightObject.SetCabinID(cID);
			}
			fin >> sCodeInp;
			fin >> eCodeInp;
			fin >> statusInp;
			
			flightObject.SetID(fID);
			flightObject.SetStartTimeAndDate(startTime);
			flightObject.SetEndTimeAndDate(endTime);
			flightObject.SetNumPassengers(numPassInp);
			flightObject.SetTailNum(tailNumInp);
			flightObject.SetNumPilots(pCount);
			flightObject.SetNumCoPilots(cpCount);
			flightObject.SetNumCrew(ccCount);
			flightObject.SetStartCode(sCodeInp);
			flightObject.SetEndCode(eCodeInp);
			flightObject.SetStatus(statusInp);
		
			flightVec.push_back(flightObject);
		}
		
		cout << "***** FLIGHT INFORMATION LOADED *****" << endl;
	}
	else
	{
		cout << "Could not load flight information." << endl;
	}
	
	// CLOSES THE FILE
	fin.close();
}
	
void FlightCol::SaveAllData(){				// uses fstreams to print data to a file
	ofstream fout;									// output stream variable
	unsigned int size = flightVec.size();			// saves the size of the vector
	
	// OPENS THE FILE
	fout.open("FlightOutput.txt", ios::out | ios::trunc);
	
	// PRINTS TO THE FILE
	fout << flightVec.size() << endl;
	fout << deleteCount << endl;
	for (unsigned int i = 0; i < size; i++)
	{
		fout << flightVec[i].GetID() << endl;
		fout << flightVec[i].GetStartTimeAndDate() << endl;
		fout << flightVec[i].GetEndTimeAndDate() << endl;
		fout << flightVec[i].GetNumPassengers() << endl;
		fout << flightVec[i].GetTailNum() << endl;
		fout << flightVec[i].GetNumPilots() << endl;
		for(unsigned int j = 0; j < flightVec[i].GetNumPilots(); j++)
		{
			fout << flightVec[i].GetPilotID(j) << endl;
		}
		fout << flightVec[i].GetNumCoPilots() << endl;
		for(unsigned int j = 0; j < flightVec[i].GetNumCoPilots(); j++)
		{
			fout << flightVec[i].GetCoPilotID(j) << endl;
		}
		fout << flightVec[i].GetNumCrew() << endl;
		for(unsigned int j = 0; j < flightVec[i].GetNumCrew(); j++)
		{
			fout << flightVec[i].GetCabinID(j) << endl;
		}
		fout << flightVec[i].GetStartCode() << endl;
		fout << flightVec[i].GetEndCode() << endl;
		fout << flightVec[i].GetStatus() << endl;
	}
	
	cout << "***** FLIGHT INFORMATION SAVED *****" << endl;
	
	// CLOSES THE FILE
	fout.close();
}
	
void FlightCol::PrintPlaneSchedule(){
	string tailNumInp = planeClass.ReturnTailNumber();
	unsigned int size = flightVec.size();			// saves the size of the vector
	time_t startTime;
	time_t endTime;
	string startTimeStr;
	string endTimeStr;
	
	cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
	cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
	
	// LOOPING THROUGH VECTOR
	for (unsigned int i = 0; i < size; i++)
	{
		// ONLY PRINTS IF IT IS THE SAME TAIL NUMBER
		if(flightVec[i].GetTailNum() == tailNumInp)
		{
			startTime = flightVec[i].GetStartTimeAndDate();		// stores the starting epoch time
			endTime = flightVec[i].GetEndTimeAndDate();			// stores the ending epoch time
			startTimeStr = ctime(&startTime);					// stroes the end time string returned by the ctime() funct
			endTimeStr = ctime(&endTime);						// stroes the end time string returned by the ctime() funct
		
			startTimeStr.erase(startTimeStr.end() - 1);			// removes 'newline' character from start time string
			endTimeStr.erase(endTimeStr.end() - 1);				// removes 'newline' character from end time string
		
			cout << setw(5) << flightVec[i].GetID();
			cout << setw(30) << startTimeStr;
			cout << setw(30) << endTimeStr;
			cout << setw(15) << flightVec[i].GetNumPassengers();
			cout << setw(12) << flightVec[i].GetTailNum();
			cout << setw(15) << flightVec[i].GetNumPilots();
			cout << setw(18) << flightVec[i].GetNumCoPilots();
			cout << setw(18) << flightVec[i].GetNumCrew();
			cout << setw(15) << flightVec[i].GetStartCode();
			cout << setw(13) << flightVec[i].GetEndCode();
			cout << setw(12) << flightVec[i].GetStatus();
			cout << endl;
		}
	}
	
}
	
void FlightCol::PrintCrewMemberSchedule(){
	unsigned int size = flightVec.size();			// saves the size of the vector
	time_t startTime, endTime;						// holds epoch for start and end
	string startTimeStr, endTimeStr;				// holds the start and end times as strings
	
	int unscheduled = 0;							// holds 0 if crew mem is unscheduled; if scheduled gets set to 1
	
	// prompt for name of crew member
	cin.ignore();
	string crewName = crewClass.ReturnName();		// gets the crew members name and stores it
	int idNum = crewClass.ReturnID(crewName);		// gets the id of the crew member with that name and stores it
	
	// print all flights for that crew member
	cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
	cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
	
	for(unsigned int i = 0; i < size; i++)
	{
		// SEARCHES THROUGH THE PILOT VECTOR FOR EACH FLIGHT
		int checkPilot = flightVec[i].CheckPilotID(idNum);
		if(checkPilot == 1)
		{
			startTime = flightVec[i].GetStartTimeAndDate();			// stores the starting epoch time
			endTime = flightVec[i].GetEndTimeAndDate();				// stores the ending epoch time
			startTimeStr = ctime(&startTime);						// stroes the end time string returned by the ctime() funct
			endTimeStr = ctime(&endTime);							// stroes the end time string returned by the ctime() funct
		
			startTimeStr.erase(startTimeStr.end() - 1);				// removes 'newline' character from start time string
			endTimeStr.erase(endTimeStr.end() - 1);					// removes 'newline' character from end time string
		
			cout << setw(5) << flightVec[i].GetID();
			cout << setw(30) << startTimeStr;
			cout << setw(30) << endTimeStr;
			cout << setw(15) << flightVec[i].GetNumPassengers();
			cout << setw(12) << flightVec[i].GetTailNum();
			cout << setw(15) << flightVec[i].GetNumPilots();
			cout << setw(18) << flightVec[i].GetNumCoPilots();
			cout << setw(18) << flightVec[i].GetNumCrew();
			cout << setw(15) << flightVec[i].GetStartCode();
			cout << setw(13) << flightVec[i].GetEndCode();
			cout << setw(12) << flightVec[i].GetStatus();
			cout << endl;
			
			unscheduled = 1;
		}
		else 
		{
			// SEACRHES THROUGH CO-PILOT VECTOR FOR EACH FLIGHT
			int checkCoPilot = flightVec[i].CheckCoPilotID(idNum);
			if(checkCoPilot == 1)
			{
				startTime = flightVec[i].GetStartTimeAndDate();			// stores the starting epoch time
				endTime = flightVec[i].GetEndTimeAndDate();				// stores the ending epoch time
				startTimeStr = ctime(&startTime);						// stroes the end time string returned by the ctime() funct
				endTimeStr = ctime(&endTime);							// stroes the end time string returned by the ctime() funct
		
				startTimeStr.erase(startTimeStr.end() - 1);				// removes 'newline' character from start time string
				endTimeStr.erase(endTimeStr.end() - 1);					// removes 'newline' character from end time string
		
				cout << setw(5) << flightVec[i].GetID();
				cout << setw(30) << startTimeStr;
				cout << setw(30) << endTimeStr;
				cout << setw(15) << flightVec[i].GetNumPassengers();
				cout << setw(12) << flightVec[i].GetTailNum();
				cout << setw(15) << flightVec[i].GetNumPilots();
				cout << setw(18) << flightVec[i].GetNumCoPilots();
				cout << setw(18) << flightVec[i].GetNumCrew();
				cout << setw(15) << flightVec[i].GetStartCode();
				cout << setw(13) << flightVec[i].GetEndCode();
				cout << setw(12) << flightVec[i].GetStatus();
				cout << endl;
				
				unscheduled = 1;
			}
			else 
			{
				// SEARCHES THROUGH CABIN CREW VECTOR FOR EACH FLIGHT
				int checkCabin = flightVec[i].CheckCabinID(idNum);
				if(checkCabin == 1)
				{
					startTime = flightVec[i].GetStartTimeAndDate();			// stores the starting epoch time
					endTime = flightVec[i].GetEndTimeAndDate();				// stores the ending epoch time
					startTimeStr = ctime(&startTime);						// stroes the end time string returned by the ctime() funct
					endTimeStr = ctime(&endTime);							// stroes the end time string returned by the ctime() funct
		
					startTimeStr.erase(startTimeStr.end() - 1);				// removes 'newline' character from start time string
					endTimeStr.erase(endTimeStr.end() - 1);					// removes 'newline' character from end time string
		
					cout << setw(5) << flightVec[i].GetID();
					cout << setw(30) << startTimeStr;
					cout << setw(30) << endTimeStr;
					cout << setw(15) << flightVec[i].GetNumPassengers();
					cout << setw(12) << flightVec[i].GetTailNum();
					cout << setw(15) << flightVec[i].GetNumPilots();
					cout << setw(18) << flightVec[i].GetNumCoPilots();
					cout << setw(18) << flightVec[i].GetNumCrew();
					cout << setw(15) << flightVec[i].GetStartCode();
					cout << setw(13) << flightVec[i].GetEndCode();
					cout << setw(12) << flightVec[i].GetStatus();
					cout << endl;
					
					unscheduled = 1;
				}
			}
		}
	}
	// IF THE ID IS UNUSED, PRINTS THIS TO USER
	if(unscheduled == 0)
	{
		cout << "Crew Member has not been scheduled yet." << endl;
	}
}

void FlightCol::PrintByStatus(){
	unsigned int size = flightVec.size();	// holds size of the vector
	int choice;								// holds users menu selection
	time_t startTime, endTime;				// holds epoch fro start and end time
	string startTimeStr, endTimeStr;		// holds strings for the start and end time
	
	do {
		// PRINTS MENU TO USER
		cout << "Which flights would you like to print?" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Completed" << endl;
		cout << "2 - Cancelled" << endl;
		cout << "3 - Active" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		
		switch(choice)
		{
			// QUIT
			case 0:
				break;
				
			// COMPLETED
			case 1:
				cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
				cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
			
				for(unsigned int i = 0; i < size; i++)
				{
					if(flightVec[i].GetStatus() == "Completed")
					{
						startTime = flightVec[i].GetStartTimeAndDate();		// stores the starting epoch time
						endTime = flightVec[i].GetEndTimeAndDate();			// stores the ending epoch time
						startTimeStr = ctime(&startTime);					// stroes the end time string returned by the ctime() funct
						endTimeStr = ctime(&endTime);						// stroes the end time string returned by the ctime() funct
		
						startTimeStr.erase(startTimeStr.end() - 1);			// removes 'newline' character from start time string
						endTimeStr.erase(endTimeStr.end() - 1);				// removes 'newline' character from end time string
		
						cout << setw(5) << flightVec[i].GetID();
						cout << setw(30) << startTimeStr;
						cout << setw(30) << endTimeStr;
						cout << setw(15) << flightVec[i].GetNumPassengers();
						cout << setw(12) << flightVec[i].GetTailNum();
						cout << setw(15) << flightVec[i].GetNumPilots();
						cout << setw(18) << flightVec[i].GetNumCoPilots();
						cout << setw(18) << flightVec[i].GetNumCrew();
						cout << setw(15) << flightVec[i].GetStartCode();
						cout << setw(13) << flightVec[i].GetEndCode();
						cout << setw(12) << flightVec[i].GetStatus();
						cout << endl;
					}
				}
				break;
				
			// CANCELLED
			case 2:
				cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
				cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
				
				for(unsigned int i = 0; i < size; i++)
				{
					if(flightVec[i].GetStatus() == "Cancelled")
					{
						startTime = flightVec[i].GetStartTimeAndDate();		// stores the starting epoch time
						endTime = flightVec[i].GetEndTimeAndDate();			// stores the ending epoch time
						startTimeStr = ctime(&startTime);					// stroes the end time string returned by the ctime() funct
						endTimeStr = ctime(&endTime);						// stroes the end time string returned by the ctime() funct
		
						startTimeStr.erase(startTimeStr.end() - 1);			// removes 'newline' character from start time string
						endTimeStr.erase(endTimeStr.end() - 1);				// removes 'newline' character from end time string
		
						cout << setw(5) << flightVec[i].GetID();
						cout << setw(30) << startTimeStr;
						cout << setw(30) << endTimeStr;
						cout << setw(15) << flightVec[i].GetNumPassengers();
						cout << setw(12) << flightVec[i].GetTailNum();
						cout << setw(15) << flightVec[i].GetNumPilots();
						cout << setw(18) << flightVec[i].GetNumCoPilots();
						cout << setw(18) << flightVec[i].GetNumCrew();
						cout << setw(15) << flightVec[i].GetStartCode();
						cout << setw(13) << flightVec[i].GetEndCode();
						cout << setw(12) << flightVec[i].GetStatus();
						cout << endl;
					}
				}
				break;
				
			// ACTIVE
			case 3:
				cout << setw(5) << "ID" << setw(30) << "START TIME" << setw(30) << "END TIME" << setw(15) << "NUM. PASS." << setw(12) << "TAIL NUM."; 
				cout << setw(15) << "NUM. PILOTS" << setw(18) << "NUM. CO-PILOTS" << setw(18) << "NUM. CABIN MEM." << setw(15) << "START AIRPORT" << setw(13) << "END AIRPORT"  << setw(12) << "STATUS" << endl;
			
				for(unsigned int i = 0; i < size; i++)
				{
					if(flightVec[i].GetStatus() == "Active")
					{
						startTime = flightVec[i].GetStartTimeAndDate();		// stores the starting epoch time
						endTime = flightVec[i].GetEndTimeAndDate();			// stores the ending epoch time
						startTimeStr = ctime(&startTime);					// stroes the end time string returned by the ctime() funct
						endTimeStr = ctime(&endTime);						// stroes the end time string returned by the ctime() funct
		
						startTimeStr.erase(startTimeStr.end() - 1);			// removes 'newline' character from start time string
						endTimeStr.erase(endTimeStr.end() - 1);				// removes 'newline' character from end time string
		
						cout << setw(5) << flightVec[i].GetID();
						cout << setw(30) << startTimeStr;
						cout << setw(30) << endTimeStr;
						cout << setw(15) << flightVec[i].GetNumPassengers();
						cout << setw(12) << flightVec[i].GetTailNum();
						cout << setw(15) << flightVec[i].GetNumPilots();
						cout << setw(18) << flightVec[i].GetNumCoPilots();
						cout << setw(18) << flightVec[i].GetNumCrew();
						cout << setw(15) << flightVec[i].GetStartCode();
						cout << setw(13) << flightVec[i].GetEndCode();
						cout << setw(12) << flightVec[i].GetStatus();
						cout << endl;
					}
				}
				break;
				
			// DEFAULT
			default:
				cout << "Invalid selection. Try again.";
				break;
		}
		cout << endl;
	}while(choice != 0);
}
	
void FlightCol::DeleteByStatus(){
	unsigned int size = flightVec.size();		// holds the size of the flight vector
	int choice;									// holds users menu choice
	
	do {
		// PRINTS MENU TO USER
		cout << "Which flights would you like to delete?" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Completed" << endl;
		cout << "2 - Cancelled" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		
		switch(choice)
		{
			// QUIT
			case 0:
				break;
				
			// COMPLETED
			case 1:
				// LOOPS THROUGH FLIGHT VECTOR TO SEE IF ANY ARE COMPLETED
				for(unsigned int i = 0; i < size; i++)
				{
					if(flightVec[i].GetStatus() == "Completed")
					{
						// DELETES ALL COMPLETED FLIGHTS
						flightVec.erase(flightVec.begin() + i);
					}
				}
				cout << "Completed Flights deleted" << endl;
				break;
				
			// CANCELLED
			case 2:
				// LOOPS THROUGH FLIGHT VECTOR TO SEE IF ANY ARE CANCELLED
				for(unsigned int i = 0; i < size; i++)
				{
					if(flightVec[i].GetStatus() == "Cancelled")
					{
						// DELETES ALL CANCELLED FLIGHTS
						flightVec.erase(flightVec.begin() + i);
					}
				}
				cout << "Cancelled Flights deleted" << endl;
				break;
				
			// DEFAULT
			default:
				cout << "Invalid selection. Try again.";
				break;
		}
	}while(choice != 0);
}
	
void FlightCol::UpdateStatus(){
	unsigned int size = flightVec.size();
	time_t now, currentTime;			// epoch numbers for the current time
	time(&now);							// sets the current time
	struct tm currTime;					// will hold the current time
	currTime = *gmtime(&now);			// sets the current time to GM Time
	currentTime = mktime(&currTime);	// stores the epoch of the current time
	string statusInp;					// temp variable for the status
	
	for(unsigned int i = 0; i < size; i++)
	{
		if(flightVec[i].GetEndTimeAndDate() < currentTime)
		{
			statusInp = "Completed";
			flightVec[i].SetStatus(statusInp);
		}
	}
	cout << "** Status' Updated **" << endl;
}