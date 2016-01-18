/*
 * WayPointManager.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: colman
 */

#include "WayPointManager.h"
#include <iostream>

using namespace std;

WayPointManager::WayPointManager(vector<Position> &path) {
	this->path = path;
}

vector<Position> WayPointManager::findWaypoints(vector<Position> &path){
	int dx, dy, j = 0;
		string last_axis = "";
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
				if (last_axis == "second")
				{
					waypoints[j] = path[i];
					j += 1;
				}

				last_axis = "first";
			}
			else if (dy == 0)
			{
				// movement was detected in "first" axis.

				// check if axis was changed, and add waypoint to the path
				if (last_axis == "first")
				{
					waypoints[j] = path[i];
					j += 1;
				}

				last_axis = "second";
			}
		}

		waypoints.resize(j);
		this->waypoints = waypoints;
		// printWaypoints(); // uncomment to print the waypoints
		return waypoints;

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

WayPointManager::~WayPointManager() {
	// TODO Auto-generated destructor stub
}





