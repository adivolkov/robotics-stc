/*
 * Map.h
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_


#include <vector>
#include "Types.h"
using namespace std;


class Map {
private:
	vector<unsigned char> image;
	Grid map;
	unsigned int mapWidth;
	unsigned int mapHeight;

	float mapResolution;
	float robotSize;
	int robotSizeInCells;
	int inflationRadius;

	Grid fineGrid; // each cell in the size of the robot
	Grid coarseGrid; // each cell in the size of 2x2 of the robot

	bool checkIfCellIsOccupied(int i, int j);
	void printGrid(const Grid &grid) const;
	void reduceGrid(const Grid &originalGrid, Grid &reducedGrid, int reduceConstant);
	bool checkIfReducedCellIsOccupied(int i, int j, const Grid &originalGrid, int reduceConstant) const;
	void inflateCell(int i, int j);


public:
	Map(float mapResolution, float robotSize);
	void loadMapFromFile(const char* filePath);
	void saveMapToFile(const char* filePath);
	void inflateMap();
	Grid getMapGrid();

	void buildFineGrid();
	void buildCoarseGrid();
	Grid getCoarseGrid();

	Coordinate coarseToPixelCoordinate(Coordinate coarsGridCoord);
	Coordinate pixelToCoarseCoordinate(Coordinate pixelCoord);
	Coordinate fineToPixelCoordinate(Coordinate fineGridCoord);
	int getCoarseGridPixelWidth();
	int getFineGridPixelWidth();

	virtual ~Map();
};

#endif /* MAP_H_ */
