/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "MemberList.h"

#include <algorithm>

using namespace std;

void MemberList::addMember(const string& firstName,
    const string& lastName)
{
    Member tempMember = Member(firstName, lastName);

    tempMember.setID(DEFAULT_ID +
        static_cast<int>(memberList->size()));

    memberList->insert(tempMember);
}

void MemberList::addMember(const string& firstName,
    const string& lastName, int points)
{
    Member tempMember = Member(firstName, lastName);

    tempMember.setID(DEFAULT_ID +
        static_cast<int>(memberList->size()));

    tempMember.addPoints(points);
    memberList->insert(tempMember);
}

int MemberList::getLastID() const
{
    return (memberList->rbegin())->getID();
}

int MemberList::getPoints(int memberID) const
{
    return (find_if(memberList->begin(), memberList->end(),
        [memberID](const auto& element)
        { return element.getID() == memberID; }))->getPoints();
}

void MemberList::printMember(int memberID,
    const string& lastName) const
{
    auto tempMember = find_if(memberList->begin(), memberList->end(),
        [memberID](const auto& element)
            { return element.getID() == memberID; });
    if (tempMember->getLastName() == lastName)
    {
        tempMember->printMember();
    }
}

void MemberList::clearList()
{
    memberList->clear();
}

MemberList::~MemberList()
{
    delete memberList;
    memberList = nullptr;
}
