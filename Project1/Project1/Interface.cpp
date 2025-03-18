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
#include <iomanip>

using namespace std;

void displayMenu()
{
    string stars(51, '*');
    cout << stars << "\n"
        << "\t        HIKING IN THE US \n"
        << stars << endl << endl;

    cout << "\t1. Browse by location\n"
        << "\t2. Browse by duration\n"
        << "\t3. Browse by difficulty\n"
        << "\t4. Browse by price\n"
        << "\t5. Make a reservation\n"
        << "\t6. View reservation\n"
        << "\t7. Cancel reservation\n"
        << "\t8. Exit\n" << endl;
}

void processReservation(const HikeList& aHike, MemberList& aMember, 
    Reservations& aReservation)
{
    int selection = 0;

    while (selection != 8)
    {
        cout << "Please make a selection: ";
        cin >> selection;

        if (selection == 1)
        {
            chooseByLocation(aHike, aMember, aReservation);
        }
        else if (selection == 2)
        {
            chooseByDuration(aHike, aMember, aReservation); 
        }
        else if (selection == 3)
        {
            chooseByDifficulty(aHike, aMember, aReservation);
        }
        else if (selection == 4)
        {
            chooseByPrice(aHike, aMember, aReservation); 
        }
        else if (selection == 5)
        {
            makeReservation(aHike, aMember, aReservation); 
        }
        else if (selection == 6)
        {
            viewReservation(aHike, aMember, aReservation); 
        }
        else if (selection == 7)
        {
            cancelReservation(aHike, aMember, aReservation); 
        }
        else if (selection == 8)
        {
            cout << "\nThank you for visiting!\n" << endl;
        }

        if (selection != 8)
        {
            system("Pause");
            cout << endl;
            displayMenu();
        }
    }
}

void chooseByLocation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << endl;
    aHike.printAllLocation();

    cout << "Choose a location: ";
    string location;
    cin >> location;

    cout << endl;
    aHike.printByLocation(location);
    askToReserve(aHike, aMember, aReservation);
}

void chooseByDuration(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << "\n\t(days)\n";
    aHike.printByDuration();

    cout << "How many days are you considering?: ";
    int days = 0;
    cin >> days;

    cout << endl;
    aHike.printByDuration(days);
    askToReserve(aHike, aMember, aReservation);
}

void chooseByDifficulty(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << "\nChoose a difficulty level: \n"
        << endl << "\t e. easy\n"
        << "\t m. moderate\n"
        << "\t s. strenuous\n" << endl;

    cout << "Your choice: ";
    char difficulty = 'e';
    cin >> difficulty;

    cout << "\n\t(difficulty level)\n";

    aHike.printByDifficulty(difficulty);
    askToReserve(aHike, aMember, aReservation);
}

void chooseByPrice(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << endl;
    aHike.printByPrice();
    askToReserve(aHike, aMember, aReservation);
}

int askIfMember(MemberList& aMember)
{
    int id = 0;

    cout << "\nAre you a member? (y/n) ";
    char memberStatus = 'y';
    cin >> memberStatus;

    if (memberStatus == 'y')
    {
        cout << "\nWhat is your member ID number? ";
        cin >> id;

        cout << "\nWhat is your last name? ";
        string lastName;
        cin >> lastName;
        cout << endl;

        aMember.printMember(id, lastName);
        cout << "\tMembership # " << id << endl << endl;

    }

    else if (memberStatus == 'n')
    {
        id = addNewMember(aMember);
    }

    return id;
}

int addNewMember(MemberList& aMember)
{
    cout << "\n\t Let's add you to the member list!\n"
        << "\t         What is your first name? ";
    string firstName;
    cin >> firstName;

    cout << "\t         What is your last name? ";
    string lastName;
    cin >> lastName;
    cout << endl;
    
    aMember.addMember(firstName, lastName);

    cout << "\t Welcome to the club! \n"
        << "\t         Your member ID number is: " << aMember.getLastID()
        << endl << endl;

    return aMember.getLastID();
}

void makeReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    int id = askIfMember(aMember);

    cout << "Which hike would you like to reserve (hike name)? ";
    string hikeName;
    cin >> hikeName;
    
    cout << endl;
    aHike.printByHikeName(hikeName); 
    double price = aHike.getPrice(hikeName);
    int points = aMember.getPoints(id);

    if (points > 0)
    {
        cout << "\tDiscounted price using points: $"
            << fixed << setprecision(2) << price - (points / 100)
            << endl << endl;
    }

    int reservationNum = aReservation.addReservation(id, hikeName);

    cout << "\tBefore proceeding, please make a note "
        << "of your reservation number.\n"
        << " \t  Reservation #: " << reservationNum << endl << endl;

    cout << "( *** Will continue to scheduling and payment. *** )\n";
}

void viewReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << "\nEnter reservation #: ";
    int reservationNum = 0;
    cin >> reservationNum;

    cout << endl;
    aReservation.printReservation(reservationNum, aHike, aMember);

}

void cancelReservation(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << "\nEnter reservation #: ";
    int reservationNum = 0;
    cin >> reservationNum;

    cout << endl;
    aReservation.printReservation(reservationNum, aHike, aMember);

    cout << "Are you sure you want to cancel this reservation? (y/n) ";
    char cancel = 'y';
    cin >> cancel;
    cout << endl;

    if (cancel == 'y')
    {
        aReservation.cancelReservation(reservationNum);
        cout << "Reservation #" << reservationNum <<
            " has been canceled. \n" << endl;
    }
}

void askToReserve(const HikeList& aHike, MemberList& aMember,
    Reservations& aReservation)
{
    cout << "Would you like to make a reservation? (y/n) ";
    char reservation = 'y';
    cin >> reservation;

    if (reservation == 'y')
    {
        makeReservation(aHike, aMember, aReservation); 
    }
    cout << endl;
}