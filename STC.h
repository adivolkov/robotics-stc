/*
 * STC.h
 *
 *  Created on: Dec 9, 2015
 *      Author: colman
 */

#ifndef STC_H_
#define STC_H_

#include "Map.h"
#include "Node.h"

using namespace std;


class STC {
private:
	Map &map;
	vector<vector<Node *> > graph;
	Position startPos;

	void DFS(Node* n);
	void drawLineOnImage(vector<unsigned char> &image, Position positionA, Position positionB, int mapWidth);
	void drawSpanningTree(vector<unsigned char> &image, int mapWidth);
public:
	STC(Map &map, Position startPos);
	void printGraph();
	void printDFS();
	void buildSpanningTree();
	void saveSpanningTreeToFile(const char* filePath);
	virtual ~STC();
};

#endif /* STC_H_ */
