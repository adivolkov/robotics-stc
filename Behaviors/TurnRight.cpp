/*
 * TurnRight.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: colman
 */

#include "TurnRight.h"
#include "../Helper.h"

using namespace std;

bool TurnRight::startCond(RealPosition targetWaypoint, double angle){
	return (Helper::isRight(Helper::radiansToDegrees(_robot->getYaw()), angle));
}

bool TurnRight::stopCond(RealPosition targetWaypoint, double angle){
	RealPosition currentWaypoint;
	currentWaypoint.first = _robot->getYPos();
	currentWaypoint.second = _robot->getXPos();
	double yaw = Helper::radiansToDegrees(_robot->getYaw());

	int rank = Helper::isAngleCloseEnough(currentWaypoint, yaw, targetWaypoint);

	if (rank == 0){
		return true;
	}
	else if (rank == 1){
		_multiplier = 0.2;
		return false;
	}
	_multiplier = 1;
	return false;
}
