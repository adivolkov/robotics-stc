/*
 * MoveForward.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: colman
 */

#include "MoveForward.h"
#include "../Helper.h"

using namespace std;

bool MoveForward::stopCond(RealPosition targetWaypoint, double angle){
	int m2 = (angle < 180) ? 1 : -1;
	RealPosition currentWaypoint;
	currentWaypoint.first = _robot->getYPos();
	currentWaypoint.second = _robot->getXPos();

	// rank: 0 - made it. 1 - slow down. 2 - not in sight.
	int rank = Helper::isCloseEnough(targetWaypoint,currentWaypoint);
	if (rank == 0){
		return true;
	}
	else if (rank == 1){
		_multiplier = 0.3;
		return false;
	}
	_multiplier = 1;
	return false;
}
