#include "Team.hpp"
#include "Team2.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <typeinfo>

using namespace ariel;
using namespace std;


void Team::add(Character* member) {
    if (member->isInTeam()){throw runtime_error("can be in a single Team");}
    if (members.size() >= 10) { throw std::runtime_error("Cannot add more members, team is full.");}
    members.push_back(member);
    member->setTeam(true);
}

int Team::stillAlive() const {
    int count = 0;
    for(const auto& member : members) {
        if(member->isAlive()) { ++count; }
    }
    return count;
}

void Team::attack(Team* other) {

    if (other == nullptr){throw invalid_argument("invlaid pointer");}
    else if (other == this) { throw std::runtime_error("Cannot harm self");}
    else if (!other->stillAlive()){throw runtime_error("the team is already dead..");}

    if (!this->leader->isAlive()){ this->leader = findClosestMemberToLeader(this->leader); }

    int potentialAttacks = other->stillAlive(); // return number of alive members

    for (size_t i = 0; i < potentialAttacks; i++){
        Character* victim = other->findClosestMemberToLeader(this->leader); // closest enemy to leader
        // Loop over team members starting from memberIndex

        if (typeid(this) == typeid(Team2)){

            for(Character* member : members) {

                if (!victim->isAlive()) { break; }
                if (!member->isPlayed() && member->isAlive()){
                    preformAttack(member, victim);
                }
                
            }

        } else {
            // Meaning Team 

            for(Character* member : members) {
                if(typeid(*member) == typeid(Cowboy) && !member->isPlayed() && member->isAlive()) {
                    if (!victim->isAlive()) { break; }
                    preformAttack(member, victim);
                }
            }

            for(Character* member : members) {
                if(!(typeid(*member) == typeid(Cowboy)) && !member->isPlayed() && member->isAlive()) {
                    if (!victim->isAlive()) { break; }
                    preformAttack(member, victim);
                }
            }
        }
        

    }

    for(Character* member : members) {
        member->setPlay(false);
    }
    
    // other->removeDeadMembers();
}


Character* Team::findClosestMemberToLeader(Character* leader) const {
    
    double min_distance = std::numeric_limits<int>::max();// Initialize the minimum distance.
    Character* closest_member = nullptr;

    // Iterate over the team members.
    for (Character* member : members) {
        // Skip if the member is not alive.
        if (!member->isAlive()) { continue; }

        // Calculate the distance from the member to the leader.
        double distance = member->distance(leader);

        // If the distance is less than the current minimum distance, update the minimum distance and the closest member.
        if (distance < min_distance) {
            min_distance = distance;
            closest_member = member;
        }
    }
    // cout << closest_member->getHitPoints() << " " << endl;
    // closest_member->getLocation().print();
    return closest_member;
}

void Team::preformAttack(Character* attacker, Character* victim){

    // cout << "Team::preformAttack" << endl;
    if(typeid(*attacker) == typeid(Cowboy)) {

        Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);

        if(cowboy != nullptr) {
            // cout << "This is a Cowboy, bullets = " << cowboy->hasboolets() << endl;
            if (cowboy->hasboolets()){
                cowboy->shoot(victim);
            }else{
                cowboy->reload();
            }
        }
        
    } else if(typeid(*attacker) == typeid(OldNinja)) {

        OldNinja* ninja = dynamic_cast<OldNinja*>(attacker);

        if(ninja != nullptr) {
            // cout << "This is a OldNinja, ninja->distance(victim) = " << ninja->distance(victim) << endl;
            if(ninja->distance(victim) < 1){
                ninja->slash(victim);
            }else{
                ninja->move(victim);
            }
        }
    }  else if(typeid(*attacker) == typeid(TrainedNinja)) {

        TrainedNinja* ninja = dynamic_cast<TrainedNinja*>(attacker);

        if(ninja != nullptr) {
            // cout << "This is a TrainedNinja, ninja->distance(victim) = " << ninja->distance(victim) << endl;
            if(ninja->distance(victim) < 1){
                ninja->slash(victim);
            }else{
                ninja->move(victim);
            }
        }
    }  else if(typeid(*attacker) == typeid(YoungNinja)) {

        YoungNinja* ninja = dynamic_cast<YoungNinja*>(attacker);
        if(ninja != nullptr) {
            // cout << "This is a YoungNinja, ninja->distance(victim) = " << ninja->distance(victim) << endl;
            if(ninja->distance(victim) < 1){
                ninja->slash(victim);
            }else{
                ninja->move(victim);
            }
        }
    }

    attacker->setPlay(true);
    
}


