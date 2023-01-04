//
// Created by diogotvf7 on 31-12-2022.
//

#ifndef AED2223_G29_CITY_H
#define AED2223_G29_CITY_H

#include <list>
#include <string>

#include "Airport.h"
#include "Airline.h"

class City {
    std::string name;
    std::list<Airport*> airports;

public:
    City(std::string name);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::list<Airport*> getAirports() const;

    void addAirport(Airport *airport);
};

struct CityHash {
    int operator() (const City *c) const {
        int hashValue = 0;
        for (auto ch : c->getName()) {
            hashValue = hashValue * 37 + ch;
        }
        return hashValue;
    }

    bool operator() (const City *c1, const City *c2) const {
        return c1->getName() == c2->getName();
    }
};


#endif //AED2223_G29_CITY_H
