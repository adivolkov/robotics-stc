/*
 * Node.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: colman
 */

#include "Node.h"

Node::Node(int row, int col) : row(row), col(col), visited(false) {
	neighborsInSpanningTree.resize(4);
	edges.resize(4);
	for (int i=0;i<4;i++) {
		edges[i] = false;
	}
}

Position Node::getPosition() {
	Position position;
	position.first = row;
	position.second = col;
	return position;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

