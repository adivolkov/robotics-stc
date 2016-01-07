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

	void buildGraph();
	void DFS(Node* n);

	void printGraph();
	void printDFS();
	void drawLineOnImage(vector<unsigned char> &image, Position positionA, Position positionB, int mapWidth);
	void drawGraphOnImage(vector<unsigned char> &image, int mapWidth);
	void saveGraphToFile();
public:
	STC(Map &map, Position startPos);
	void buildSpanningTree();
	virtual ~STC();
};

#endif /* STC_H_ */
