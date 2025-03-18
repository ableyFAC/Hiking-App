/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike)
{
    out << "\t" << aHike.hikeName << " (" << aHike.location << ")\n"
        << "\t  Difficulty: ";

    switch (aHike.difficulty)
    {
    case 'e':
        out << "easy";
        break;
    case 'm':
        out << "moderate";
        break;
    case 's':
        out << "strenuous";
        break;
    }

    out << "\n\t  Duration: " << aHike.duration << " day(s)\n";

    return out;
}

string Hike::getLocation() const
{
    return location;
}

int Hike::getDuration() const
{
    return duration;
}

char Hike::getDifficulty() const
{
    return difficulty;
}

string Hike::getHikeName() const
{
    return hikeName;
}

bool Hike::operator<(const Hike& anotherHike) const
{
    return location < anotherHike.location;
}
