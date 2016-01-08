/*
 * STC.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: colman
 */

#include "STC.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "lodepng.h"

using namespace std;

STC::STC(Map &map, Position startPos) :
		map(map) {
	buildGraph();
	printGraph();
	DFS(graph[startPos.first][startPos.second]);
	printDFS();
	saveGraphToFile();
}

void STC::buildGraph() {
	Grid coarseGrid = map.getCoarseGrid();
	int gridRows = coarseGrid.size();
	int gridCols = coarseGrid[0].size();

	graph.resize(gridRows);
	for (int i = 0; i < gridRows; i++)
		graph[i].resize(gridCols);

	for (int i = 0; i < gridRows; i++) {
		for (int j = 0; j < gridCols; j++) {
			if (!coarseGrid[i][j]) {
				Node* node = new Node(i, j);
				graph[i][j] = node;
			}
		}
	}
}

void STC::printGraph() {
	int gridRows = graph.size();
	int gridCols = graph[0].size();

	for (int i = 0; i < gridRows; i++) {
		for (int j = 0; j < gridCols; j++) {
			if (graph[i][j]) {
				cout << setw(2) << i << ":" << setw(2) << j << " ";
			} else {
				cout << "  :   ";
			}
		}
		cout << endl;
	}
}

void STC::drawLineOnImage(vector<unsigned char> &image, Position positionA, Position positionB, int mapWidth) {
	Position pixelPositionA = map.getCoarseGridPixelCoordinate(positionA);
	Position pixelPositionB = map.getCoarseGridPixelCoordinate(positionB);
	int cellWidth = map.getCoarseGridPixelWidth();

	if (positionA.first == positionB.first) {
		// horizontal line
		int start = (pixelPositionA.second < pixelPositionB.second) ? pixelPositionA.second : pixelPositionB.second;
		start += cellWidth / 2; // we want to draw from the middle
		int length = abs(pixelPositionA.second - pixelPositionB.second);
		for (int i = start; i <= start+length; i++) {
			int c = ((pixelPositionA.first + cellWidth / 2) * mapWidth + i) * 4;
				image[c] = 255;
				image[c + 1] = 0;
				image[c + 2] = 0;
				image[c + 3] = 255;
		}
	} else {
		// vertical line
		int start = (pixelPositionA.first < pixelPositionB.first) ? pixelPositionA.first : pixelPositionB.first;
		start += cellWidth / 2; // we want to draw from the middle
		int length = abs(pixelPositionA.first - pixelPositionB.first);
		for (int i = start; i <= start+length; i++) {
			int c = (i * mapWidth + pixelPositionA.second + cellWidth / 2) * 4;
				image[c] = 255;
				image[c + 1] = 0;
				image[c + 2] = 0;
				image[c + 3] = 255;
		}
	}
}

void STC::drawGraphOnImage(vector<unsigned char> &image, int mapWidth) {
	int gridRows = graph.size();
	int gridCols = graph[0].size();

	for (int i = 0; i < gridRows; i++) {
		for (int j = 0; j < gridCols; j++) {
			if (graph[i][j] != NULL) {
				for (int k = 0; k < 4; k++) {
					if (graph[i][j]->neighborsInSpanningTree[k] != NULL) {
						Position positionA = graph[i][j]->getPosition();
						Position positionB = graph[i][j]->neighborsInSpanningTree[k]->getPosition();
						drawLineOnImage(image, positionA, positionB, mapWidth);
					}
				}

			}
		}
	}
}

void STC::saveGraphToFile() {
	Grid mapGrid = map.getMapGrid();
	vector<unsigned char> image;

	int mapHeight = mapGrid.size();
	int mapWidth = mapGrid[0].size();

	image.resize(mapHeight * mapWidth * 4);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			int c = (i * mapWidth + j) * 4;
			if (mapGrid[i][j]) {
				image[c] = 0;
				image[c + 1] = 0;
				image[c + 2] = 0;
				image[c + 3] = 255;
			} else {
				image[c] = 255;
				image[c + 1] = 255;
				image[c + 2] = 255;
				image[c + 3] = 255;
			}

		}
	}

	drawGraphOnImage(image, mapWidth);
	lodepng::encode("map_with_graph.png", image, mapWidth, mapHeight);
}

void STC::printDFS() {
	int gridRows = graph.size();
	int gridCols = graph[0].size();

	for (int i = 0; i < gridRows; i++) {
		for (int j = 0; j < gridCols; j++) {
			if (graph[i][j] != NULL) {
				for (int k = 0; k < 4; k++) {
					if (graph[i][j]->neighborsInSpanningTree[k] != NULL) {
						cout << "(" << graph[i][j]->getPosition().first << ","
								<< graph[i][j]->getPosition().second << ")";
						cout << " -> ";
						cout << "("
								<< graph[i][j]->neighborsInSpanningTree[k]->getPosition().first
								<< ","
								<< graph[i][j]->neighborsInSpanningTree[k]->getPosition().second
								<< ")" << endl;
					}
				}

			}
		}
	}
}

void STC::DFS(Node* n) {
	n->visited = true;
	int x = n->getPosition().first;
	int y = n->getPosition().second;

	// right
	int row = x + 1;
	int col = y;
	if (row >= 0 && row < graph.size() && col >= 0 && col < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[0] = graph[row][col];
			DFS(graph[row][col]);
		}
	}

	// up
	row = x;
	col = y - 1;
	if (row >= 0 && row < graph.size() && col >= 0 && col < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[1] = graph[row][col];
			DFS(graph[row][col]);
		}
	}

	// left
	row = x - 1;
	col = y;
	if (row >= 0 && row < graph.size() && col >= 0 && col < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[2] = graph[row][col];
			DFS(graph[row][col]);
		}
	}

	// down
	row = x;
	col = y + 1;
	if (row >= 0 && row < graph.size() && col >= 0 && col < graph[0].size()) {
		if (graph[row][col] != NULL && !graph[row][col]->visited) {
			n->neighborsInSpanningTree[3] = graph[row][col];
			DFS(graph[row][col]);
		}
	}
}

STC::~STC() {
	// TODO Auto-generated destructor stub
}

