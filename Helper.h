/*
 * Helper.h
 *
 *  Created on: Jan 23, 2016
 *      Author: colman
 */

#ifndef HELPER_H_
#define HELPER_H_

#include <math.h>
#include "Types.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

class Helper {
public:
	Helper();
	static double radiansToDegrees(double radians){
		return radians * 180 / M_PI;
	}

	static double degressToRadians(double degrees){
		return degrees * M_PI / 180;
	}
	virtual ~Helper();

	static int isCloseEnough(RealPosition a, RealPosition b){
		double x_a = a.second;
		double y_a = a.first;
		double x_b = b.second;
		double y_b = b.first;

		if ((abs(x_a - x_b) <  LINEAR_TOLERANCE) &&
				(abs(y_a - y_b) < LINEAR_TOLERANCE)){
			return 0; // VERY CLOSE
		}
		else if ((abs(x_a - x_b) <  10 * LINEAR_TOLERANCE) &&
				(abs(y_a - y_b) < 10 * LINEAR_TOLERANCE)){
			return 1; // CLOSE! CAREFUL!
		}
		return 2; // FAR AWAY.
	}

	static void printRealPosition(RealPosition a){
		cout << "{ x:" << a.second << ", y:" << a.first << "}" << endl;
	}

	static int isAngleCloseEnough(RealPosition a, double yaw, RealPosition b){
		double angle = radiansToDegrees(atan2( (b.first - a.first),b.second - a.second));
		if (abs(yaw - angle) < ANGLE_TOLERANCE){
			return 0; // VERY CLOSE;
		}
		else if (abs(yaw - angle) < ANGLE_TOLERANCE * 40){
			return 1; // CLOSE! CAREFUL!
		}
		return 2; // FAR AWAY;
	}

	static int isRight(double current, double target){
		double difference = current - target;

		while (difference < -180)
			difference += 360;

		while (difference > 180)
			difference -= 360;

		if (difference > 0){
			return true;
		}
		return false;
	}
};

#endif /* HELPER_H_ */
