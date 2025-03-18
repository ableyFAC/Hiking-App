/*
    UCI Rejects

    Vu, Ethan (Team Leader)
    Marinescu, Max

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "HikeList.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void HikeList::addHike(const Hike& hike, double price)
{
    hikeList.insert({ hike, price });
}

void HikeList::addHike(const string& location,
    const string& hikeName, int duration,
        char difficulty, double price)
{
    hikeList.insert(
        { Hike(location, hikeName, duration, difficulty), price });
}

double HikeList::getPrice(const string& hikeName) const
{
    auto hikeIter = find_if(hikeList.begin(), hikeList.end(),
        [hikeName](const auto& aHike)
        { return aHike.first.getHikeName() == hikeName; });

    return hikeIter->second;
}

void HikeList::printAllLocation() const
{
    auto hikeIter = hikeList.begin();
    auto hikeEnd = hikeList.end();

    while (hikeIter != hikeEnd)
    {
        cout << "\t" << hikeIter->first.getLocation() << endl;
        hikeIter = hikeList.upper_bound(hikeIter->first);
    }
    cout << endl;
}

void HikeList::printByLocation(const string& location) const
{
    auto hikeIter = hikeList.begin();
    auto hikeEnd = hikeList.end();

    while (hikeIter != hikeEnd)
    {
        hikeIter = find_if(hikeIter, hikeList.end(),
            [&location](const auto& hike)
            {return hike.first.getLocation() == location;});

        if (hikeIter != hikeList.end())
        {
            cout << hikeIter->first << "\t  Price (per person): $ "
                << fixed << setprecision(2) << hikeIter->second
                << endl << endl;

            ++hikeIter;
        }
    }
}

void HikeList::printByDuration() const
{
    multimap <int, string> tempMap;

    for (const auto& aHike : hikeList)
    {
        tempMap.insert(make_pair(aHike.first.getDuration(),
            (aHike.first.getHikeName() +
                ", " + aHike.first.getLocation())));
    }

    for (const auto& theHikes : tempMap)
    {
        cout << "\t" << "(" << theHikes.first << ") "
            << theHikes.second << endl;
    }
    cout << endl;
}

void HikeList::printByDuration(int days) const
{
    for (const auto& aHike : hikeList)
    {
        if (aHike.first.getDuration() == days)
        {
            cout << aHike.first << endl;
        }
    }
}

void HikeList::printByDifficulty(const char& difficulty) const
{
    for (const auto& aHike : hikeList)
    {
        if (aHike.first.getDifficulty() == difficulty)
        {
            cout << "\t(" << aHike.first.getDifficulty() << ") "
                << aHike.first.getHikeName() << ", "
                << aHike.first.getLocation() << endl;
        }
    }
    cout << endl;
}

void HikeList::printByPrice() const
{
    multimap <double, pair<string, string>> tempMap;

    for (const auto& aHike : hikeList)
    {
        tempMap.emplace(aHike.second,
            make_pair(aHike.first.getLocation(),
                aHike.first.getHikeName()));
    }

    for (const auto& aHike : tempMap)
    {
        cout << "\t$ " << fixed << setprecision(2)
            << setw(7) << aHike.first << " - "
            << aHike.second.first << " ("
            << aHike.second.second << ")\n";
    }
    cout << endl;
}

void HikeList::printByHikeName(const string& hikeName) const
{
    auto hikeIter = find_if(hikeList.begin(), hikeList.end(),
        [hikeName](const auto& aHike)
        { return aHike.first.getHikeName() == hikeName; });

    cout << hikeIter->first << " \t  $"
        << fixed << setprecision(2) << hikeIter->second
        << endl << endl;
}

void HikeList::clearList()
{
    hikeList.clear();
}