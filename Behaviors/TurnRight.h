/*
 * TurnRight.h
 *
 *  Created on: Jan 20, 2016
 *      Author: colman
 */

#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "../Robot.h"
#include "Behavior.h"

using namespace std;

class TurnRight: public Behavior {
public:
	TurnRight(Robot* robot):Behavior(robot){};
	bool startCond(RealPosition targetWaypoint, double angle);
	bool stopCond(RealPosition targetWaypoint, double angle);
	void action(){_robot->setSpeed(0.0,-1 * TURN_SPEED * _multiplier);}
	void pause();
	string name(){cout << "Turn Right:" << endl; return "TurnRight";}
};

#endif /* TURNRIGHT_H_ */
