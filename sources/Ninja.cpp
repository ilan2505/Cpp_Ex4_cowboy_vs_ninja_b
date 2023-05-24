#include "Ninja.hpp"
#include <iostream>


using namespace std;
using namespace ariel;


void Ninja::move(Character* target) {
    // Calculate the new location - Speed is based on the Ninja type
    Point newLocation = Point::moveTowards(getLocation(), target->getLocation(), speed);
    // Update this ninja's location
    location = newLocation;
}

void Ninja::slash(Character* target) {
    if (target == this) { throw std::runtime_error("Cannot harm self");}
    if (!isAlive()) { throw std::runtime_error("Dead cannot attack"); }
    if (!target->isAlive()) { throw std::runtime_error("Cannot attack a dead enemy");}
    
    if (isAlive() && distance(target) < 1) {
        target->hit(40);
    }
}

string Ninja::print() const {
    // Character::print();
    cout << " and has " << speed << " speed";
    return "N";
}