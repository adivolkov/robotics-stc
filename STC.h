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
	void drawGraph();
public:
	STC(Map &map, Position startPos);
	void buildSpanningTree();
	virtual ~STC();
};

#endif /* STC_H_ */
