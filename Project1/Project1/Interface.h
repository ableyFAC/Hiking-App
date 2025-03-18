/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();
void processReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

void chooseByLocation(const HikeList& aHike, MemberList& aMember, 
    Reservations& aReservation);

void chooseByDuration(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

void chooseByDifficulty(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

void chooseByPrice(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

int askIfMember(MemberList& aMember);
int addNewMember(MemberList& aMember);

void makeReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

void viewReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

void cancelReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

void askToReserve(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation);

#endif 