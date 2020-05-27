#include <iostream>
#include <sstream>
#include <iomanip>
#include <assert.h>

#include "Time.h"

Time::Time() {	//default constructor
	time_t now = time(0);
	struct tm t;
	localtime_s(&t, &now);
	setTime(t.tm_hour, t.tm_min, t.tm_sec);
}


//using memberwise initialisation
Time::Time(const Time& t)
	: inSeconds_(t.inSeconds_)
{}
//Q1
//create Time from 3 integers representing its hours, minutes and seconds
Time::Time(int h, int m, int s)
	: inSeconds_((h * 3600) + (m * 60) + s)
{}
//create Time from a long long number of seconds
Time::Time(long timeInSecs)
	: inSeconds_(timeInSecs)
{}
//create Time from a formatted string ("HH:MM:SS")
Time::Time(const string& str) { 	//requires sstream library
	istringstream is(str);
	char ch;				//(any) colon field delimiter
	int h, m, s;
	is >> h >> ch >> m >> ch >> s;
	inSeconds_ = (h * 3600) + (m * 60) + s;
}
//

Time::~Time() {
}
int Time::getHours() const { 	//return a data member value, hrs_
	return inSeconds_ / 3600;
}
int Time::getMinutes() const {	//return a data member value, mins_
	return (inSeconds_ % 3600) / 60;
}
int Time::getSeconds() const {	//return a data member value, secs_
	return inSeconds_ % 60;
}
void Time::setTime(int h, int m, int s) {	//set the time
	inSeconds_ = (h * 3600) + (m * 60) + s;
}
void Time::readInTime() {  	//read in time form user
	int h, m, s;
	cout << "Enter the hours: ";
	cin >> h;
	cout << "Enter the minutes: ";
	cin >> m;
	cout << "Enter the seconds: ";
	cin >> s;
	inSeconds_ = (h * 3600) + (m * 60) + s;
}
void Time::displayTime() const {	 //display time (00:00:00)
	cout << toString();
}

bool Time::isSameAs(const Time& t) const {
	assert(t.isValid());
	return inSeconds_ == t.inSeconds_;
}

bool Time::isEarlierThan(const Time& t) const {
	assert(t.isValid());
	return inSeconds_ < t.inSeconds_;
}

void Time::increment(long s) {	//add seconds to time
	inSeconds_ += s;
}


Time Time::plus(long s) const {	//create a time from handle + s
	return Time(inSeconds_ + s);
}

Time Time::plus(const Time& t) const {	//create a time from handle + t
	assert(t.isValid());
	return Time(inSeconds_ + t.inSeconds_);
}

bool Time::isValid() const {
	//true if valid time
	return (inSeconds_ >= 0) && (inSeconds_ < (24 * 3600));
}

//private support functions_______________________________________________

string Time::toString() const {	//return formatted string from Time ("HH:MM:SS")
	ostringstream os;
	os << setfill('0')
		<< setw(2) << getHours() << ":"
		<< setw(2) << getMinutes() << ":"
		<< setw(2) << getSeconds();
	return os.str();
}