/*
 * RobotPosition.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: colman
 */

#include "RobotPosition.h"

RobotPosition::RobotPosition(double x, double y, double yaw): x(x), y(y), yaw(yaw) {

}

double RobotPosition::getX() {
	return x;
}
double RobotPosition::getY() {
	return y;
}
double RobotPosition::getYaw() {
	return yaw;
}

RobotPosition::~RobotPosition() {
	// TODO Auto-generated destructor stub
}

