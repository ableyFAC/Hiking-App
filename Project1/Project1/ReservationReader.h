/*
	UCI Rejects

	Vu, Ethan (Team Leader)
	Marinescu, Max

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Interface.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILES = "reservations_database.txt";

void createReservation(ifstream& infile, Reservations& aReservation)
{
	int memberID = 0;
	string hikeName;

	while (!infile.eof())
	{
		infile >> memberID >> hikeName;
		aReservation.addReservation(memberID, hikeName);
	}
}

void getReservationData(Reservations& aReservation)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILES);

	if (!infile)
	{
		cerr << RESERVATIONS_FILES << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservation(infile, aReservation);

	infile.close();
}
