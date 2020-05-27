#pragma once

#include <string>

#include "random.h"

class Utility
{
public:
	int getCurrentHours();
	int getCurrentMinutes();
	int getCurrentSeconds();

	std::string getTimeString(int min, int hour);
	std::string getAM_PM(int hour);

	int getCorrectMinuteRotation();
	int getCorrectHourRotation();

	int getRandomMinute();
	int getRandomHour();

	int minuteToRotation(int mins);
	int hourToRotation(int mins, int hour);

	int UpdateHour(int hour, int min, bool update);
	int UpdateMinute(int min, bool update);

private:
	random mRandom;
};