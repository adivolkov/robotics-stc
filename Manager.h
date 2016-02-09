/*
 * Manager.h
 *
 *  Created on: Dec 18, 2015
 *      Author: colman
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include "Types.h"
#include "Robot.h"
#include "Behaviors/Behavior.h"
#include <vector>

using namespace std;



class Manager {
private:
	Robot *_robot;
	Behavior *_currBehavior;
	Behavior *_behaviorsArray[BEHAVIORS_ARRAY_SIZE];
	vector<RealPosition> _waypoints;

public:

	Manager(Robot *robot, vector<RealPosition> waypoints);
	void run();
	virtual ~Manager();
};

#endif /* DRIVER_H_ */
