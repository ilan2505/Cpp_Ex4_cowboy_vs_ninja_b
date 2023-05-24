#pragma once

#include "Ninja.hpp"

using namespace std;


namespace ariel {

    class TrainedNinja : public Ninja {
        public:
            TrainedNinja(std::string name, Point location) : Ninja(name, location, 120, 12) {} // 120 HP and 12 speed
            
    };



}
