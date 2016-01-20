/*
 * Main.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#include "Map.h"
#include "STC.h"
#include "WaypointManager.h"
#include "ConfigurationManager.h"
#include "Robot.h"
#include "Behaviors/Behavior.h"
#include "Manager.h"
#include "Helper.h"
#include <iostream>


using namespace std;

void printCoordinate(Coordinate coord) {
	cout << "(" << coord.first << "," << coord.second << ")" << endl;
}

int main() {


	ConfigurationManager config("parameters.txt");
	RobotPosition initRobotPosition = config.getInitialRobotPosition();

	/*
	cout << "map path: " << config.getMapPath() << endl;
	cout << "initial robot position: (" << initRobotPosition.getX() << "," << initRobotPosition.getY() << "," << initRobotPosition.getYaw() << ")" << endl;
	cout << "robot size: " << config.getRobotSizeCM() << endl;
	cout << "map resolution: " << config.getMapResolutionCM() << endl;
	 */

	float mapResolution = config.getMapResolutionCM() / 100;
	float robotSize = config.getRobotSizeCM() / 100;
	Map map(mapResolution, robotSize);

	map.loadMapFromFile(config.getMapPath().c_str());

	map.inflateMap();

	map.buildFineGrid();
	map.buildCoarseGrid();

	// configure start position

	Coordinate pixelCoord(initRobotPosition.getX(), initRobotPosition.getY());
	printCoordinate(pixelCoord);
	RealPosition robotPosition = map.pixelToRobotPosition(pixelCoord);
	cout << "Real position: " << robotPosition.first << "," << robotPosition.second << endl;
	// translate to coarse grid
	Position startPos = map.pixelToCoarseCoordinate(pixelCoord);
	printCoordinate(startPos);
	printCoordinate(map.coarseToPixelCoordinate(startPos));
	STC stc(map, startPos);
	stc.buildSpanningTree();
	stc.printGraph();
	stc.saveSpanningTreeToFile("roboticLabMap_spanningTree.png");
	vector<RealPosition> path = stc.realPath();
	WaypointManager wpm(path);
	vector<RealPosition> waypoints = wpm.getWaypoints();
	stc.saveRealPathToFile(waypoints, "roboticLabMap_path.png");
	cout << "Initial Yaw: " << initRobotPosition.getYaw() << endl;
	Robot robot("localhost", 6665, robotPosition.second, robotPosition.first, Helper::degressToRadians(initRobotPosition.getYaw()));
	Manager manager(&robot, waypoints);
	manager.run();


	return 0;
}



