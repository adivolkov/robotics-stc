/*
 * ConfigurationManager.h
 *
 *  Created on: Jan 9, 2016
 *      Author: colman
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <string>
#include "Models/RobotPosition.h"

class RobotPosition;

using namespace std;

class ConfigurationManager {
private:
	string mapPath;
	RobotPosition initialRobotPosition;
	float robotSizeCM;
	float mapResolutionCM;
public:
	ConfigurationManager(const char* filePath);
	string getMapPath();
	RobotPosition getInitialRobotPosition();
	float getRobotSizeCM();
	float getMapResolutionCM();
	virtual ~ConfigurationManager();
};

#endif /* CONFIGURATIONMANAGER_H_ */
