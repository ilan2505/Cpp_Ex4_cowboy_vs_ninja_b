#pragma once

#include "Point.hpp"
#include <string>

using namespace std;

namespace ariel {

    class Character {
    
    protected:
        Point location;
        int hitPoints;
        string name;
        bool inTeam = false;
        bool played = false;

    public:
        Character(Point location, int hitPoints, std::string name) : location(location), hitPoints(hitPoints), name(name) {}
        virtual ~Character() = default;

        virtual string print() const = 0;
        virtual void setTeam(bool add){ inTeam = add;}
        virtual bool isInTeam() { return inTeam;}
        virtual void setPlay(bool flag){played = flag;}
        virtual bool isPlayed() { return played;}
        virtual double distance(const Character& other) const;
        virtual double distance(const Character* other) const;

        int getHitPoints() { return hitPoints;}
        void hit(int damage);
        std::string getName() const { return name; }
        Point getLocation() const { return location; }
        bool isAlive() const;



    };
}