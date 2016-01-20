/*
 * WaypointManager.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: colman
 */

#include "WaypointManager.h"
#include <iostream>

using namespace std;

WaypointManager::WaypointManager(vector<RealPosition> &path) : path(path) {
	this->waypoints = path;
	printWaypoints();
}

vector<RealPosition> WaypointManager::getWaypoints(){

	double dx, dy;
	int waypointsCounter = 0;
	bool isXAxis;
	vector<RealPosition> waypoints;
	waypoints.resize(path.size());

	// handle first node is a waypoint exception
	if (path.size() >= 2)
	{
		dx = path[0].first - path[1].first;
		dy = path[0].second - path[1].second;
		isXAxis = (dx == 0) ? false : true;
		waypoints[0] = path[0];
		waypointsCounter += 1;
	}

	for (unsigned int i = 1; i < path.size()-1; ++i)
	{
		// check movement
		dx = path[i].first - path[i+1].first;
		dy = path[i].second - path[i+1].second;

		if (dx == 0)
		{

			// movement was detected in "second" axis.

			// check if axis was changed, and add waypoint to the path
			if (isXAxis)
			{
				waypoints[waypointsCounter] = path[i];
				waypointsCounter += 1;
			}

			isXAxis = false;
		}
		else if (dy == 0)
		{
			// movement was detected in "first" axis.

			// check if axis was changed, and add waypoint to the path
			if (!isXAxis)
			{
				waypoints[waypointsCounter] = path[i];
				waypointsCounter += 1;
			}

			isXAxis = true;
		}
	}

	waypoints.resize(waypointsCounter);
	this->waypoints = waypoints;
	//printWaypoints(); // uncomment to print the waypoints
	return waypoints;
}

void WaypointManager::printWaypoints(){
	cout << endl << endl << endl;
	for (unsigned int i = 0; i < this->waypoints.size()-1; ++i)
	{
		cout << i << ": " << "(" << waypoints[i].first << "," << waypoints[i].second << ")" << endl;
		//cout << "puck( pose [" << waypoints[i].second << " " << waypoints[i].first << " 0 ] color \"red\" )" << endl;
	}
}

WaypointManager::~WaypointManager() {}





