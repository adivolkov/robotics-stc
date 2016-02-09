/*
 * Behavior.h
 *
 *  Created on: Jan 19, 2016
 *      Author: colman
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include "../Robot.h"
#include "../Types.h"
#include <iostream>

using namespace std;

class Behavior {
private:
	vector<Behavior *> _nextBehaviors;

protected:
	Robot *_robot;
	double _multiplier;

public:
	virtual bool startCond(RealPosition targetWaypoint, double angle) = 0;
	virtual bool stopCond(RealPosition targetWaypoint, double angle) = 0;

	virtual void action() = 0;

	Behavior *addNext(Behavior *next);
	Behavior *selectNext(RealPosition targetWaypoint, double angle);
	virtual string name() = 0;
	Behavior(Robot *robot);
	virtual ~Behavior();
};

#endif /* BEHAVIOR_H_ */
