/*
 * RobotPosition.h
 *
 *  Created on: Jan 9, 2016
 *      Author: colman
 */

#ifndef ROBOTPOSITION_H_
#define ROBOTPOSITION_H_

#include "../Types.h"
using namespace std;

class RobotPosition {
private:
	double x, y, yaw;
public:
	RobotPosition(double x, double y, double yaw);
	double getX();
	double getY();
	double getYaw();
	virtual ~RobotPosition();
};

#endif /* ROBOTPOSITION_H_ */
