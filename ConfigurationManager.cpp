/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: colman
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "ConfigurationManager.h"
#include "Types.h"

using namespace std;

ConfigurationManager::ConfigurationManager(const char* filePath): initialRobotPosition(0, 0, 0) {
	ifstream confFile(filePath);
	string line;
	string parameterName;

	// map path
	string mapPath;
	getline(confFile, line);
	istringstream mapPathStream(line);
	mapPathStream >> parameterName >> mapPath;
	this->mapPath = mapPath;

	// initial robot position
	string initXStr, initYStr, initYawStr;
	getline(confFile, line);
	istringstream initPositionStream(line);
	initPositionStream >> parameterName >> initXStr >> initYStr >> initYawStr;
	int initX = atoi(initXStr.c_str());
	int initY = atoi(initYStr.c_str());
	int initYaw = atoi(initYawStr.c_str());
	initialRobotPosition = RobotPosition(initX, initY, initYaw);

	// robot size (assume to be squared)
	string robotSizeCMStr;
	getline(confFile, line);
	istringstream robotSizeStream(line);
	robotSizeStream >> parameterName >> robotSizeCMStr;
	robotSizeCM = atof(robotSizeCMStr.c_str());

	// map resolution
	string mapResolutionCMStr;
	getline(confFile, line);
	istringstream mapResolutionStream(line);
	mapResolutionStream >> parameterName >> mapResolutionCMStr;
	mapResolutionCM = atof(mapResolutionCMStr.c_str());
}

string ConfigurationManager::getMapPath() {
	return mapPath;
}

RobotPosition ConfigurationManager::getInitialRobotPosition() {
	return initialRobotPosition;
}

float ConfigurationManager::getRobotSizeCM() {
	return robotSizeCM;
}

float ConfigurationManager::getMapResolutionCM() {
	return mapResolutionCM;
}

ConfigurationManager::~ConfigurationManager() {
	// TODO Auto-generated destructor stub
}

