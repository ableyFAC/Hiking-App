/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
    Member(const std::string& aFirstName, const std::string& aLastName) :
        firstName(aFirstName), lastName(aLastName), id(0), points(0) {}

    void addPoints(int morePoints);
    void setID(int newID);

    int getID() const;
    std::string getLastName() const;
    int getPoints() const;

    void printMember() const;

    bool operator<(const Member& aMember) const;

private:
    int id;
    std::string firstName;
    std::string lastName;
    int points;
};
#endif



