/*
 * WayPointManager.h
 *
 *  Created on: Jan 18, 2016
 *      Author: colman
 */

#ifndef WAYPOINTMANAGER_H_
#define WAYPOINTMANAGER_H_

#include <vector>
#include "Types.h"
using namespace std;

class WayPointManager {
public:
	vector<Position> path;
	vector<Position> waypoints;
	WayPointManager(vector<Position> &path);

	vector<Position> findWaypoints(vector<Position> &path);

	void printWaypoints();
	vector<Position> getWaypoints();

	virtual ~WayPointManager();
};

#endif /* WAYPOINTMANAGER_H_ */
