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
	vector<Position> path;
	vector<Position> waypoints;
	WaypointManager(vector<Position> &path);

	vector<Position> getWaypoints();

	void printWaypoints();

	virtual ~WaypointManager();
};

#endif /* WAYPOINTMANAGER_H_ */
