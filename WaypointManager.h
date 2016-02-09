/*
 * WaypointManager.h
 *
 *  Created on: Jan 18, 2016
 *      Author: colman
 */

#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <vector>
#include "Types.h"
using namespace std;

class WaypointManager {
public:
	vector<RealPosition> path;
	vector<RealPosition> waypoints;
	WaypointManager(vector<RealPosition> &path);

	vector<RealPosition> getWaypoints();

	void printWaypoints();

	virtual ~WaypointManager();
};

#endif /* WAYPOINTMANAGER_H_ */
