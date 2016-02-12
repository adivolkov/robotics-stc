/*
 * Manager.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: colman
 */

#include "Types.h"
#include "Helper.h"
#include "Manager.h"
#include "Behaviors/MoveForward.h"
#include "Behaviors/TurnLeft.h"
#include "Behaviors/TurnRight.h"

#include <math.h>

Manager::Manager(Robot *robot, vector<RealPosition> waypoints) : _robot(robot), _waypoints(waypoints) {
	_currBehavior = NULL;
	_behaviorsArray[0] = new TurnLeft(robot);
	_behaviorsArray[1] = new MoveForward(robot);
	_behaviorsArray[2] = new TurnRight(robot);
	_behaviorsArray[0]->addNext(_behaviorsArray[1]);
	_behaviorsArray[2]->addNext(_behaviorsArray[1]);
	_behaviorsArray[1]->addNext(_behaviorsArray[0]);
	_behaviorsArray[1]->addNext(_behaviorsArray[2]);

}

void Manager::run()
{

	double yaw;
	_robot->read();

	int nextWaypointCounter = 0;
	RealPosition currentWaypoint;
	RealPosition nextWaypoint;
	
	currentWaypoint.first = _robot->getYPos();
	currentWaypoint.second = _robot->getXPos();
	yaw = _robot->getYaw();
	nextWaypoint = this->_waypoints[nextWaypointCounter];
	//cout << "var p1 = { x:" << currentWaypoint.second << ", y:" << currentWaypoint.first << "}" << endl;
	//cout << "var p2 = { x:" << nextWaypoint.second << ", y:" << nextWaypoint.first << "}" << endl;
	double angle = Helper::radiansToDegrees(atan2( (nextWaypoint.first - currentWaypoint.first),nextWaypoint.second - currentWaypoint.second));

	if (Helper::isRight(_robot->getYaw(), angle)) {
		_currBehavior = _behaviorsArray[2];
	} else {
		_currBehavior = _behaviorsArray[0];
	}


	if (!(_currBehavior->startCond(nextWaypoint, angle))){
		return;
	}

	while (_currBehavior && nextWaypointCounter < _waypoints.size()) {
		_robot->read();
		while (!_currBehavior->stopCond(nextWaypoint, angle)) {
			_currBehavior->action();
			_robot->read();
		}

		currentWaypoint.first = _robot->getYPos();
		currentWaypoint.second = _robot->getXPos();
		if (_currBehavior->name() == "Move Forward") {
			nextWaypointCounter++;
			nextWaypoint = this->_waypoints[nextWaypointCounter];
			angle = Helper::radiansToDegrees(atan2((nextWaypoint.first - currentWaypoint.first),nextWaypoint.second - currentWaypoint.second));
		}
		cout << "From (" << nextWaypointCounter << "): ";
		Helper:: printRealPosition(currentWaypoint);
		cout << "To   (" << nextWaypointCounter + 1 << "): ";
		Helper:: printRealPosition(nextWaypoint);

		_currBehavior = _currBehavior->selectNext(nextWaypoint, angle);


}
cout << "Manager stopped." << endl;
}

Manager::~Manager() {for (int i = 0; i < BEHAVIORS_ARRAY_SIZE; i++) delete _behaviorsArray[i];}

