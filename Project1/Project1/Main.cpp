/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures

    * This project was made for my C++ 2 class
    * I made it with the help of another classmates
  
*/

#include "Hike.h"
#include "HikeList.h" 
#include "HikeReader.h" 

#include "Member.h" 
#include "MemberList.h" 
#include "MemberReader.h" 

#include "Interface.h" 
#include "ReservationReader.h" 

#include <iostream>

using namespace std;

int main()
{
    MemberList aMember;
    getMemberData(aMember);

    HikeList aHike;
    getHikeData(aHike);

    Reservations aReservation;
    getReservationData(aReservation);

    displayMenu();

    processReservation(aHike, aMember, aReservation);

    system("Pause");

    return 0;
    
}
