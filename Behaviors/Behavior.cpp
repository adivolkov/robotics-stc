/*
 * Behavior.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: colman
 */

#include "Behavior.h"

Behavior::Behavior(Robot *robot):_robot(robot), _multiplier(1) {}

Behavior::~Behavior() {}

Behavior* Behavior::addNext(Behavior *next){
	_nextBehaviors.push_back(next);
	return this;
}

Behavior *Behavior::selectNext(RealPosition targetWaypoint, double angle){
	for (unsigned int i = 0; i < _nextBehaviors.size(); ++i) {
		if (_nextBehaviors[i]->startCond(targetWaypoint, angle))
		{
			return _nextBehaviors[i];
		}

	}
	return NULL;
}





