#pragma once

#include "Ninja.hpp"

using namespace std;


namespace ariel {


    class OldNinja : public Ninja {
        public:
            OldNinja(std::string name, Point location) : Ninja(name, location, 150, 8) {} // 150 HP and 8 speed
    };


}
