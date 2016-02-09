/*
 * Types.h
 *
 *  Created on: Jan 9, 2016
 *      Author: colman
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <vector>
#include <math.h>

using namespace std;

typedef vector<vector<bool> > Grid;
typedef pair<int, int> Coordinate;
typedef pair<int, int> Position;
typedef pair<double, double> RealPosition;

const double LINEAR_SPEED = 0.3;
const double TURN_SPEED = 0.4;
const double LINEAR_TOLERANCE = 0.03;
const double ANGLE_TOLERANCE = 0.4;

#define BEHAVIORS_ARRAY_SIZE 3

#endif /* TYPES_H_ */
