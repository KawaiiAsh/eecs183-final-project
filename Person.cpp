/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Person.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * XinLerou Liu, Xinyu Yang, Yushen Dong, Yujie Yang
 * xinlerou,yxinyu,bildong,jkjkyang
 *
 * Final Project - Elevators
 */

#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string inputString) : Person() {
    stringstream ss(inputString);
    char junk;
    ss >> turn;
    ss >> junk; // Discard character
    ss >> currentFloor;
    ss >> junk; // Discard character
    ss >> targetFloor;
    ss >> junk; // Discard character
    ss >> angerLevel;
}


bool Person::tick(int currentTime) {
    
    // Every TICKS_PER_ANGER_INCREASE, this function increases the
    // person's anger level by 1.
    if (currentTime % TICKS_PER_ANGER_INCREASE == 0) {
        angerLevel++;
    }
    
    // If, after increasing, the person has an anger level of MAX_ANGER,
    // the function will return true.
    if (angerLevel >= MAX_ANGER) {
        return true;
    }
    
    // If the person has an anger level less than MAX_ANGER,
    // the function will return false.
    else {
        return false;
    }
}

// Prints the infoString of the person NOT including the turn
void Person::print(ostream &outs) {
    outs << "f" << currentFloor << "t" << targetFloor << "a" << angerLevel << endl;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person() {
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const {
    return turn;
}

int Person::getCurrentFloor() const {
    return currentFloor;
}

int Person::getTargetFloor() const {
    return targetFloor;
}

int Person::getAngerLevel() const {
    return angerLevel;
}

ostream &operator<<(ostream &outs, Person p) {
    p.print(outs);
    return outs;
}
