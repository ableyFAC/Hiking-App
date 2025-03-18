/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "MemberList.h"
#include "Reservations.h"

#include <iostream>

using namespace std;

MemberList::MemberList(const MemberList& aMember)
{
    memberList = new set<Member>(*aMember.memberList);
}

MemberList& MemberList::operator=(const MemberList& aMember)
{
    if (this == &aMember)
    {
        cerr << "Attempted assignment to itself." << endl;
    }

    memberList = new set<Member>(*aMember.memberList);

    return *this;
}

Reservations::Reservations(const Reservations& aReservation)
{
    first = nullptr;
    last = nullptr;
    count = 0;

    if (aReservation.count != 0)
    {
        Node* current = aReservation.first;
        while (current != nullptr)
        {
            Reservations::addReservation(current->getMemberID(),
                current->getHikeName());

            current = current->getNext();
        }
    }
}

Reservations& Reservations::operator=
    (const Reservations& aReservation)
{
    if (this == &aReservation)
    {
        cerr << "Attempted assignment to itself." << endl;
    }
    else
    {
        if (aReservation.count == 0)
        {
            clearList();
        }
        else if (count == 0)
        {
            copyCallingObjIsEmpty(aReservation);
        }
        else if (aReservation.count == count)
        {
            copyObjectsSameLength(aReservation);
        }
        else if (aReservation.count < count)
        {
            copyCallingObjLonger(aReservation);
        }
        else if (aReservation.count > count)
        {
            copyCallingObjShorter(aReservation);
        }
    }
    return *this;
}

void Reservations::copyCallingObjIsEmpty
    (const Reservations& aReservation)
{
    Node* current = aReservation.first;

    while (current != nullptr)
    {
        Reservations::addReservation(current->getMemberID(),
            current->getHikeName());

        current = current->getNext();
    }
}

void Reservations::copyObjectsSameLength
    (const Reservations& aReservation)
{
    Node* callingCurrent = first;
    Node* current = aReservation.first;

    while (current != nullptr)
    {
        callingCurrent->setReservationNo(current->getReservation());
        callingCurrent->setMemberID(current->getMemberID());
        callingCurrent->setHikeName(current->getHikeName());

        current = current->getNext();
        callingCurrent = callingCurrent->getNext();
    }
}

void Reservations::copyCallingObjLonger
    (const Reservations& aReservation)
{
    Node* callingCurrent = first;
    Node* current = aReservation.first;

    while (current != nullptr)
    {
        callingCurrent->setReservationNo(current->getReservation());
        callingCurrent->setMemberID(current->getMemberID());
        callingCurrent->setHikeName(current->getHikeName());

        current = current->getNext();
        callingCurrent = callingCurrent->getNext();

    }

    while (callingCurrent != nullptr)
    {
        Node* toDelete = callingCurrent;
        callingCurrent = callingCurrent->getNext(); 

        if (toDelete->getPrev()) 
        {
            toDelete->getPrev()->setNext(callingCurrent);
        }
        if (callingCurrent)
        {
            callingCurrent->setPrev(toDelete->getPrev());
        }
        delete toDelete; 
    }
    count = aReservation.count;
}

void Reservations::copyCallingObjShorter
    (const Reservations& aReservation)
{
    Node* callingCurrent = first;
    Node* current = aReservation.first;

    while (callingCurrent != nullptr)
    {
        callingCurrent->setReservationNo(current->getReservation());
        callingCurrent->setMemberID(current->getMemberID());
        callingCurrent->setHikeName(current->getHikeName());

        current = current->getNext();
        callingCurrent = callingCurrent->getNext();
    }

    Node* prevNode = last;
    
    while (current != nullptr)
    {
        Node* newNode = new Node(current->getMemberID(), 
            current->getHikeName(), prevNode, nullptr);

        newNode->setReservationNo(current->getReservation());
        
        prevNode->setNext(newNode);
        prevNode = newNode;

        current = current->getNext();
    }

    last = prevNode;
    count = aReservation.count;
}