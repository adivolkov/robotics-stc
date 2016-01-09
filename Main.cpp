/*
 * Main.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#include "Map.h"
#include "STC.h"
#include "ConfigurationManager.h"
#include <iostream>

using namespace std;

int main() {

	ConfigurationManager config("parameters.txt");
	RobotPosition initRobotPosition = config.getInitialRobotPosition();

	cout << "map path: " << config.getMapPath() << endl;
	cout << "initial robot position: (" << initRobotPosition.getX() << "," << initRobotPosition.getY() << "," << initRobotPosition.getYaw() << ")" << endl;
	cout << "robot size: " << config.getRobotSizeCM() << endl;
	cout << "map resolution: " << config.getMapResolutionCM() << endl;

	float mapResolution = config.getMapResolutionCM() / 100;
	float robotSize = config.getRobotSizeCM() / 100;
	Map map(mapResolution, robotSize);

	map.loadMapFromFile(config.getMapPath().c_str());

	map.inflateMap();

	map.buildFineGrid();
	map.buildCoarseGrid();

	// configure start position

	Coordinate pixelCoord(initRobotPosition.getX(), initRobotPosition.getY());
	// translate to coarse grid
	Position startPos = map.pixelToCoarseCoordinate(pixelCoord);
	cout << "start pos in coarse: (" << startPos.first << "," << startPos.second << ")" << endl;
	STC stc(map, startPos);
	stc.buildSpanningTree();
	stc.saveSpanningTreeToFile("roboticLabMap_spanningTree.png");

	return 0;
}


