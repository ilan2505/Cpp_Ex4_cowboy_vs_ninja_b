
#include "Cowboy.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

void Cowboy::shoot(Character* target) {
    
    if (target == this) { throw std::runtime_error("Cannot harm self");}
    if (!isAlive()) { throw std::runtime_error("Dead cannot attack"); }
    if (!target->isAlive()) { throw std::runtime_error("Cannot attack a dead enemy");}

    if (hasboolets()) {
        target->hit(10);
        bullets--;
    }
}

string Cowboy::print() const {
    cout << " and has " << bullets << " bullets";
    return "C";
}

void Cowboy::reload() {
    if (!isAlive()){ throw runtime_error(" Dead cowboy can not reload");}
    bullets = 6; 
}
