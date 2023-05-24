#pragma once

#include "Character.hpp"

using namespace std;


namespace ariel {

    class Ninja : public Character {

        protected:
            int speed;
            Ninja(std::string name, Point location, int hitPoints, int speed) : Character(location, hitPoints, name), speed(speed) {}
        public:
            void move(Character* target);
            void slash(Character* target);
            string print() const override;

    };


}
