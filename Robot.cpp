/*
 * Robot.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: colman
 */

#include "Robot.h"

Robot::Robot(string ip, int port, double x, double y, double yaw) {
	pc = new PlayerClient(ip, port);
	pp = new Position2dProxy(pc);
	lp = new LaserProxy(pc);
	pp->SetOdometry(x,y,yaw);
	for (int i = 0; i<20; i++){
		read();
	}
}

void Robot::setSpeed(double linearSpeed, double angularSpeed){
	pp -> SetSpeed(linearSpeed, angularSpeed);
}

double Robot::getXPos(){
	return pp -> GetXPos();
}

double Robot::getYPos(){
	return pp -> GetYPos();
}

double Robot::getYaw(){
	return pp -> GetYaw();
}

void Robot::read(){
	pc -> Read();
}

Robot::~Robot() {
	delete lp;
	delete pp;
	delete pc;
}

