/*
 * Node.h
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include "Types.h"
using namespace std;



class Node {
private:
	int row, col;


public:
	bool visited;
	vector<Node *> neighborsInSpanningTree;

	Node(int row, int col);
	virtual ~Node();
	Position getPosition();
	bool isVisited();
};

#endif /* NODE_H_ */
