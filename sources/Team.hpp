#pragma once

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include "Point.hpp"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace ariel {

    class Team {

        protected:
            Character* leader;
            vector<Character*> members;
            void preformAttack(Character* attacker, Character* victim);

        public:

            Team(Character* leader) { 
                if (leader->isInTeam()){throw runtime_error("can be in a single Team");}
                
                this->leader = leader;
                leader->setTeam(true);
                members.push_back(leader);
                
            }

            virtual ~Team() = default;
            virtual void add(Character* member);
            virtual void attack(Team* other);
            virtual int stillAlive() const;
            virtual void print() const { cout << "SIZE MEMBERS " << members.size() << endl;}

            void removeDeadMembers() { members.erase(remove_if(members.begin(), members.end(),[](Character* member){ return !member->isAlive(); }),members.end()); }
            Character* findClosestMemberToLeader(Character* leader) const; 
    };



}

