# Airline-Control-System

This is a C++ project for an airline control system that handles all planes, crew members, and flights going through the airline. The system uses STL, inheritance, runtime polymorphism, virtual functions, file I/O, and classes. 

### Design
There are 3 classes that give the specifications for planes, crew members, and flights. 
Each of these classes have a corresponding collection class that handles the entire collection of planes, crew members, or flights.
The crew member class has three child classes for the different types of crew members (pilots, co-pilots, and cabin members) that use inheritance and runtime polymorphism.

### To Run
The program has an included makefile. Use the `make` command to compile the project. 
The makefile will generate an executable `run` that can run the program. 

### To use
Upon opening the system, a menu will be show with every option. 
Output files are included that can be used to load in data (menu option 19) for the planes, crew, and flights.
From there you can add an entity, edit an existing entity, delete an entity, etc.
Print options are included to allow the user to see the data currently in the system. 
Once all changes have been made, there is a save option that will write the data into the output files. 
