/*
 * Main.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#include "Map.h"
#include "STC.h"

int main() {
	float mapResolution = 0.025;
	float robotSize = 0.3;
	Map map(mapResolution, robotSize);

	const char *filePath = "roboticLabMap.png";
	map.loadMapFromFile(filePath);

	map.inflateMap();

	map.buildFineGrid();
	map.buildCoarseGrid();

	//const char *outputFile = "newRoboticLabMap.png";
	//map.saveMapToFile(outputFile);
	Position startPos;
	startPos.first = 6;
	startPos.second = 17;

	STC stc(map, startPos);

	return 0;
}


