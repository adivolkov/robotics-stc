/*
 * WayPointManager.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: colman
 */

#include "WayPointManager.h"
#include <iostream>

using namespace std;

WayPointManager::WayPointManager(vector<Position> &path) : path(path) {}

void WayPointManager::findWaypoints(){

	int dx, dy, waypointsCounter = 0;
	bool isXAxis = true;
	vector<Position> waypoints;
	waypoints.resize(path.size());

	for (unsigned int i = 0; i < path.size()-1; ++i)
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
	// printWaypoints(); // uncomment to print the waypoints

}

void WayPointManager::printWaypoints(){
	for (unsigned int i = 0; i < this->waypoints.size()-1; ++i)
	{
		cout << i << ": " << "(" << waypoints[i].first << "," << waypoints[i].second << ")" << endl;
	}
}

vector<Position> WayPointManager::getWaypoints(){
	return this->waypoints;
}

WayPointManager::~WayPointManager() {}





