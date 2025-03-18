/*
	UCI Rejects

	Vu, Ethan (Team Leader)
	Marinescu, Max

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Reservations.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int memberID,
	const std::string& hikeName)
{
	if (first == nullptr)
	{
		first = new Node(memberID, hikeName, nullptr, nullptr);
		last = first;
		last->setReservationNo(RESERVATION_NUM);
	}
	else
	{
		last = new Node(memberID, hikeName, last, nullptr);
		last->getPrev()->setNext(last);
		last->setReservationNo(last->getPrev()->getReservation() + 1);
	}

	++count;
	return last->getReservation();
	
}

void Reservations::cancelReservation(int reservation)
{
	if (count == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		Node* toDelete = findReservation(reservation);


		if (toDelete == first)
		{
			first = first->getNext();
			first->setPrev(nullptr);
		}
		else if (toDelete == last)
		{
			last = last->getPrev();
			last->setNext(nullptr);
		}
		else
		{
			toDelete->getPrev()->setNext(toDelete->getNext());
			toDelete->getNext()->setPrev(toDelete->getPrev());
		}

		delete toDelete;
		toDelete = nullptr;
		--count;
	}
}

void Reservations::printReservation(int reservation,
	const HikeList& hikeList, const MemberList& memberList) const
{
	Node* aReservation = findReservation(reservation);
	string hikeName = aReservation->getHikeName();

	hikeList.printByHikeName(hikeName);

	int points = memberList.getPoints(aReservation->getMemberID());
	double price = hikeList.getPrice(hikeName);

	if (points > 0)
	{
		cout << "\tDiscounted price using points: $"
			<< fixed << setprecision(2) << price - (points / 100)
			<< endl << endl;
	}
}

void Reservations::clearList()
{
	Node* temp = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	if (first != nullptr)
		clearList();
}

Node* Reservations::findReservation(int reservation) const
{
	Node* current = first;

	while (current->getReservation() != reservation)
	{
		current = current->getNext();
	}

	return current;
}
