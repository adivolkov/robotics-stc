/*
 * MoveForward.h
 *
 *  Created on: Jan 20, 2016
 *      Author: colman
 */

#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_

#include "../Robot.h"
#include "Behavior.h"

using namespace std;

class MoveForward: public Behavior {

public:
	MoveForward(Robot* robot): Behavior(robot){};
	bool startCond(RealPosition targetWaypoint, double angle){return true;}
	bool stopCond(RealPosition targetWaypoint, double angle);
	void action(){_robot->setSpeed(LINEAR_SPEED * _multiplier,0.0);}
	string name(){cout << "Move Forward:" << endl; return "Move Forward";}
};


#endif /* MOVEFORWARD_H_ */
