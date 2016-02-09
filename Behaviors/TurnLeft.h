/*
 * TurnLeft.h
 *
 *  Created on: Jan 20, 2016
 *      Author: colman
 */

#ifndef TURNLEFT_H_
#define TURNLEFT_H_

#include "../Robot.h"
#include "Behavior.h"

using namespace std;

class TurnLeft: public Behavior {
public:
	TurnLeft(Robot* robot): Behavior(robot){};
	bool startCond(RealPosition targetWaypoint, double angle);
	bool stopCond(RealPosition targetWaypoint, double angle);
	void action(){_robot->setSpeed(0.0,TURN_SPEED * _multiplier);}
	void pause();
	string name(){cout << "Turn Left:" << endl; return "TurnLeft";}
};

#endif /* TURNLEFT_H_ */
