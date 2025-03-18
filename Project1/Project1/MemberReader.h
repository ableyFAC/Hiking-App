/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/
#include "MemberList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MEMBER_FILE = "members_database.txt";

void createMemberList(ifstream& infile, MemberList& aMemberList)
{
    string firstName;
    string lastName;
    int points = 0;

    while (!infile.eof())
    {
        infile >> firstName >> lastName >> points;
        aMemberList.addMember(firstName, lastName, points);
    }
}

void getMemberData(MemberList& aMemberList)
{
    ifstream infile;

    infile.open(MEMBER_FILE);

    if (!infile)
    {
        cerr << MEMBER_FILE << " does not exist." << endl;
        exit(1);
    }

    createMemberList(infile, aMemberList);

    infile.close();
}
