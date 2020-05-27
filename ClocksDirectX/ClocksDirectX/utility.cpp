#include <ctime>

#include "utility.h"

using namespace std;

int Utility::getCurrentHours() {
	time_t now = time(0);
	struct tm& t = *localtime(&now);
	/*Alternatively to remove reporting these as errors or warnings
	open Project Properties > Configuration Properties > C/C++ > Preprocessor (as above)
	and paste in ;_CRT_SECURE_NO_WARNINGS into the Preprocessor Definitions box
	*/
	//struct tm t;
	//localtime_s(&t, &now);
	return t.tm_hour;
}
int Utility::getCurrentMinutes() {
	time_t now = time(0);
	struct tm t;
	localtime_s(&t, &now);
	return t.tm_min;
}
int Utility::getCurrentSeconds() {
	time_t now = time(0);
	struct tm t;
	localtime_s(&t, &now);
	return t.tm_sec;
}

string Utility::getTimeString(int min, int hour) {
	string currentTime = "";

	if (to_string(hour).length() <= 1) {
		currentTime += "0" + to_string(hour) + " : ";
	}
	else {
		if (hour > 12) {
			if (to_string(hour - 12).length() <= 1) {
				currentTime += "0" + to_string(hour - 12) + " : ";
			}
			else {
				currentTime += to_string(hour - 12) + " : ";
			}
		}
		else {
			currentTime += to_string(hour) + " : ";
		}
	}

	if (to_string(min).length() <= 1) {
		currentTime += "0" + to_string(min) + " : ";
	}
	else {
		currentTime += to_string(min) + " : ";
	}

	if (to_string(getCurrentSeconds()).length() <= 1) {
		currentTime += "0" + to_string(getCurrentSeconds());
	}
	else {
		currentTime += to_string(getCurrentSeconds());
	}

	return currentTime;
}

string Utility::getAM_PM(int hour) {
	string AMPM;
	if (hour < 12) {
		AMPM += " AM";
	}
	else {
		AMPM += " PM";
	}

	return AMPM;
}

// Get rotation for minite clock hand for current time
int Utility::getCorrectMinuteRotation() {
	int rotation;
	int minute = getCurrentMinutes();

	rotation = (360 / 60) * minute;

	return rotation;
}
// Get rotation for hour clock hand for current time
int Utility::getCorrectHourRotation() {
	int rotation;
	int hour = getCurrentHours();

	if (hour > 12) {
		hour -= 12;
	}

	rotation = (360 / 12) * hour;

	rotation += getCorrectMinuteRotation() / 12.f;

	return rotation;
}

int Utility::getRandomMinute() {
	int minute;

	minute = mRandom.getRandomNum(1, 60);

	return minute;
}

int Utility::getRandomHour() {
	int hour;

	hour = mRandom.getRandomNum(1, 12);

	return hour;
}

int Utility::minuteToRotation(int mins) {
	int rotation;

	rotation = (360 / 60) * mins;

	return rotation;
}

int Utility::hourToRotation(int mins, int hour) {
	int minuteRotation;
	int rotation;

	minuteRotation = (360 / 60) * mins;

	rotation = (360 / 12) * hour;

	rotation += minuteRotation / 12.f;

	return rotation;
}

int Utility::UpdateHour(int hour, int min, bool update) {
	int hours = hour;

	if (min == 0 && update) {
		hours += 1;

		if (hours > 24) {
			hours = 1;
		}
	}

	return hours;
}

int Utility::UpdateMinute(int min, bool update) {
	int mins = min;
	if (getCurrentSeconds() == 0 && update) {
		mins += 1;

		if (mins > 60) {
			mins = 1;
		}
	}

	return mins;
}