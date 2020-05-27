////////////////////////////////////////////////////////////////////////////////////
// OOP Tutorial 4: Object Creation using a Time class (version 0: to be modified) //
////////////////////////////////////////////////////////////////////////////////////

//--------include libraries
#include <ctime>	//for time
#include <iostream>	//for cin >> and cout <<
#include <sstream>	//for string stream processing
#include <string>	//for string routines
#include <iomanip>	//for setw, setfill
#include <assert.h>
//#include "SFML/Graphics.hpp"
using namespace std;


//--------Time class
//class Time {
//public:
//    Time();				//default constructor
//    Time(const Time&);	//copy constructor
//    Time(int, int, int);	//simple constructor
//    Time(long);			//conversion constructor
//    Time(const string&);	//conversion constructor
//    ~Time();				//destructor
//    int getHours() const;	//return a data member value, hrs_
//    int getMinutes() const;	//return a data member value, mins_
//    int getSeconds() const;	//return a data member value, secs_
//    void setTime(int, int, int);	//set the time to 3 given values
//    void readInTime();	//input time from user
//    void displayTime() const;	//display in 00:00:00 digital clock format
//    bool isSameAs(const Time&) const;	//check if same as another
//    bool isEarlierThan(const Time&) const;	//check if strictly earlier than
//    bool isValid() const; 	//check if is valid
//    void increment(long);	//add a number of seconds to time
//    Time plus(long s) const; 	//create a time from handle + s
//    Time plus(const Time& t) const; 	//create a time from handle + t
//
//private:
//    long inSeconds_;
//    string toString() const;	//return formatted string from Time ("HH:MM:SS")
//};

//public functions_______________________________________________

//Q6

//int getCurrentHours() {
//    time_t now = time(0);
//    struct tm& t = *localtime(&now);
//    /*Alternatively to remove reporting these as errors or warnings
//    open Project Properties > Configuration Properties > C/C++ > Preprocessor (as above)
//    and paste in ;_CRT_SECURE_NO_WARNINGS into the Preprocessor Definitions box
//    */
//    //struct tm t;
//    //localtime_s(&t, &now);
//    return t.tm_hour;
//}
//int getCurrentMinutes() {
//    time_t now = time(0);
//    struct tm t;
//    localtime_s(&t, &now);
//    return t.tm_min;
//}
//int getCurrentSeconds() {
//    time_t now = time(0);
//    struct tm t;
//    localtime_s(&t, &now);
//    return t.tm_sec;
//}
//Time::Time() {	//default constructor
//    time_t now = time(0);
//    struct tm t;
//    localtime_s(&t, &now);
//    setTime(t.tm_hour, t.tm_min, t.tm_sec);
//}
//
//
////using memberwise initialisation
//Time::Time(const Time& t)
//    : inSeconds_(t.inSeconds_)
//{}
////Q1
////create Time from 3 integers representing its hours, minutes and seconds
//Time::Time(int h, int m, int s)
//    : inSeconds_((h * 3600) + (m * 60) + s)
//{}
////create Time from a long long number of seconds
//Time::Time(long timeInSecs)
//    :inSeconds_(timeInSecs)
//{}
////create Time from a formatted string ("HH:MM:SS")
//Time::Time(const string& str) { 	//requires sstream library
//    istringstream is(str);
//    char ch;				//(any) colon field delimiter
//    int h, m, s;
//    is >> h >> ch >> m >> ch >> s;
//    inSeconds_ = (h * 3600) + (m * 60) + s;
//}
////
//
//Time::~Time() {
//}
//int Time::getHours() const { 	//return a data member value, hrs_
//    return inSeconds_ / 3600;
//}
//int Time::getMinutes() const {	//return a data member value, mins_
//    return (inSeconds_ % 3600) / 60;
//}
//int Time::getSeconds() const {	//return a data member value, secs_
//    return inSeconds_ % 60;
//}
//void Time::setTime(int h, int m, int s) {	//set the time
//    inSeconds_ = (h * 3600) + (m * 60) + s;
//}
//void Time::readInTime() {  	//read in time form user
//    int h, m, s;
//    cout << "Enter the hours: ";
//    cin >> h;
//    cout << "Enter the minutes: ";
//    cin >> m;
//    cout << "Enter the seconds: ";
//    cin >> s;
//    inSeconds_ = (h * 3600) + (m * 60) + s;
//}
//void Time::displayTime() const {	 //display time (00:00:00)
//    cout << toString();
//}
//
//bool Time::isSameAs(const Time& t) const {
//    assert(t.isValid());
//    return inSeconds_ == t.inSeconds_;
//}
//
//bool Time::isEarlierThan(const Time& t) const {
//    assert(t.isValid());
//    return inSeconds_ < t.inSeconds_;
//}
//
//void Time::increment(long s) {	//add seconds to time
//    inSeconds_ += s;
//}
//
//
//Time Time::plus(long s) const {	//create a time from handle + s
//    return Time(inSeconds_ + s);
//}
//
//Time Time::plus(const Time& t) const {	//create a time from handle + t
//    assert(t.isValid());
//    return Time(inSeconds_ + t.inSeconds_);
//}
//
//bool Time::isValid() const {
//    //true if valid time
//    return (inSeconds_ >= 0) && (inSeconds_ < (24 * 3600));
//}
//
////private support functions_______________________________________________
//
//string Time::toString() const {	//return formatted string from Time ("HH:MM:SS")
//    ostringstream os;
//    os << setfill('0')
//        << setw(2) << getHours() << ":"
//        << setw(2) << getMinutes() << ":"
//        << setw(2) << getSeconds();
//    return os.str();
//}

//--------end of Time class


//bool isPM(const Time& t) {
//    cout << "\nInside isPM.... ";
//    return (t.getHours() >= 12);
//    cout << "\nAt the end of isPM....";
//}
//
//Time getCurrentTime() {
//    cout << "\nInside getCurrentTime.... ";
//    time_t now = time(0);
//    struct tm t;
//    localtime_s(&t, &now);
//    Time aTime(t.tm_hour, t.tm_min, t.tm_sec);	//line5
//    cout << "\nAt the end of getCurrentTime....";
//    return(aTime);	//line6
//}

//string getTimeString(int min, int hour) {
//    string currentTime = "";
//
//    if (to_string(hour).length() <= 1) {
//        currentTime += "0" + to_string(hour) + " : ";
//    }
//    else {
//        if (hour > 12) {
//            if (to_string(hour - 12).length() <= 1) {
//                currentTime += "0" + to_string(hour - 12) + " : ";
//            }
//            else {
//                currentTime += to_string(hour - 12) + " : ";
//            }
//        }
//        else {
//            currentTime += to_string(hour) + " : ";
//        }
//    }
//    
//    if (to_string(min).length() <= 1) {
//        currentTime += "0" + to_string(min) + " : ";
//    }
//    else {
//        currentTime += to_string(min) + " : ";
//    }
//
//    if (to_string(getCurrentSeconds()).length() <= 1) {
//        currentTime += "0" + to_string(getCurrentSeconds());
//    }
//    else {
//        currentTime += to_string(getCurrentSeconds());
//    }
//
//    return currentTime;
//}
//
//string getAM_PM(int hour) {
//    string AMPM;
//    if (hour < 12) {
//        AMPM += " AM";
//    }
//    else {
//        AMPM += " PM";
//    }
//
//    return AMPM;
//}
//
//void seedGetRandom() {
//    srand(static_cast<unsigned>(time(0)));
//}
//
//int getRandomNum(int min, int max) {
//    return (rand() % (max + 1 - min) + min);
//}
//
//// Get rotation for minite clock hand for current time
//int getCorrectMinuteRotation() {
//	int rotation;
//	int minute = getCurrentMinutes();
//
//    rotation = (360 / 60) * minute;
//
//    return rotation;
//}
//// Get rotation for hour clock hand for current time
//int getCorrectHourRotation() {
//	int rotation;
//	int hour = getCurrentHours();
//
//    if (hour > 12) {
//        hour -= 12;
//    }
//
//    rotation = (360 / 12) * hour;
//
//    rotation += getCorrectMinuteRotation() / 12.f;
//
//    return rotation;
//}
//
//int getRandomMinute() {
//	int minute;
//
//	minute = getRandomNum(1, 60);
//
//	return minute;
//}
//
//int getRandomHour() {
//	int hour;
//
//	hour = getRandomNum(1, 12);
//
//	return hour;
//}
//
//int minuteToRotation(int mins) {
//	int rotation;
//
//	rotation = (360 / 60) * mins;
//
//	return rotation;
//}
//
//int hourToRotation(int mins, int hour) {
//	int minuteRotation;
//	int rotation;
//
//	minuteRotation = (360 / 60) * mins;
//
//	rotation = (360 / 12) * hour;
//
//	rotation += minuteRotation / 12.f;
//
//	return rotation;
//}
//
//int UpdateHour(int hour, int min, bool update) {
//	int hours = hour;
//
//	if (min == 0 && update) {
//		hours += 1;
//
//		if (hours > 24) {
//			hours = 1;
//		}
//	}
//
//	return hours;
//}
//
//int UpdateMinute(int min, bool update) {
//	int mins = min;
//	if (getCurrentSeconds() == 0 && update) {
//		mins += 1;
//
//		if (mins > 60) {
//			mins = 1;
//		}
//	}
//
//	return mins;
//}



//---------------------------------------------------------------------------
//int main()
//
//{
//    sf::ContextSettings settings;
//    settings.antialiasingLevel = 16;
//
//    sf::RenderWindow window(sf::VideoMode(1200, 800), "TO2 Clocks");
//
//    seedGetRandom(); 
//
//    // Digital clock setup
//    sf::Font digitalFont;
//    digitalFont.loadFromFile("data/digital-7.ttf");
//
//    sf::Text digitalText;
//    digitalText.setCharacterSize(45);
//    digitalText.setFont(digitalFont);
//    digitalText.setString("HH:MM:SS");
//    digitalText.setPosition(515, 100);
//
//    sf::Text AMorPM;
//    AMorPM.setCharacterSize(30);
//    AMorPM.setFont(digitalFont);
//    AMorPM.setString("AM/PM");
//    AMorPM.setPosition(650, 150);
//
//    sf::Texture digitalClock;
//    digitalClock.loadFromFile("data/digital_clock.png");
//
//    sf::Sprite DCSprite;
//    DCSprite.setTexture(digitalClock);
//    DCSprite.setScale(0.5, 0.5);
//    DCSprite.setPosition(480, 50);
//
//    // Analogue clock face setup
//    sf::Texture analogueClock;
//    analogueClock.loadFromFile("data/clock_face.png");
//
//    sf::Sprite clockFace1;
//    clockFace1.setTexture(analogueClock);
//    clockFace1.setPosition(180, 300);
//    clockFace1.setScale(0.5, 0.5);
//
//    sf::Sprite clockFace2;
//    clockFace2.setTexture(analogueClock);
//    clockFace2.setPosition(480, 300);
//    clockFace2.setScale(0.5, 0.5);
//
//    sf::Sprite clockFace3;
//    clockFace3.setTexture(analogueClock);
//    clockFace3.setPosition(780, 300);
//    clockFace3.setScale(0.5, 0.5);
//
//    // Analogue clock hour hands setup
//    sf::Texture hourHand;
//    hourHand.loadFromFile("data/hour_hand.png");
//
//    sf::Sprite hourHands[3];
//    
//    hourHands[0].setTexture(hourHand);
//    hourHands[0].setPosition(308, 430);
//    hourHands[0].setOrigin(37, 317);
//    hourHands[0].setScale(0.25, 0.25);
//
//    hourHands[1].setTexture(hourHand);
//    hourHands[1].setPosition(608, 430);
//    hourHands[1].setOrigin(37, 317);
//    hourHands[1].setScale(0.25, 0.25);
//
//    hourHands[2].setTexture(hourHand);
//    hourHands[2].setPosition(908, 430);
//    hourHands[2].setOrigin(37, 317);
//    hourHands[2].setScale(0.25, 0.25);
//
//    // Analogue clock minute hands setup
//    sf::Texture minuteHand; 
//    minuteHand.loadFromFile("data/minute_hand.png");
//
//    sf::Sprite minuteHands[3];
//    
//    minuteHands[0].setTexture(minuteHand);
//    minuteHands[0].setPosition(308, 430);
//    minuteHands[0].setOrigin(23, 451);
//    minuteHands[0].setScale(0.25, 0.25);
//
//    minuteHands[1].setTexture(minuteHand);
//    minuteHands[1].setPosition(608, 430);
//    minuteHands[1].setOrigin(23, 451);
//    minuteHands[1].setScale(0.25, 0.25);
//
//    minuteHands[2].setTexture(minuteHand);
//    minuteHands[2].setPosition(908, 430);
//    minuteHands[2].setOrigin(23, 451);
//    minuteHands[2].setScale(0.25, 0.25);
//
//    // On screen text setup
//    sf::Text headerText;
//    headerText.setCharacterSize(50);
//    headerText.setFont(digitalFont);
//    headerText.setString("Ready to play?");
//    headerText.setPosition(50, 25);
//
//    sf::Text clockNumbers[3];
//
//    clockNumbers[0].setFont(digitalFont);
//    clockNumbers[0].setCharacterSize(50);
//    clockNumbers[0].setString("1");
//    clockNumbers[0].setPosition(175, 295);
//
//    clockNumbers[1].setFont(digitalFont);
//    clockNumbers[1].setCharacterSize(50);
//    clockNumbers[1].setString("2");
//    clockNumbers[1].setPosition(475, 295);
//
//    clockNumbers[2].setFont(digitalFont);
//    clockNumbers[2].setCharacterSize(50);
//    clockNumbers[2].setString("3");
//    clockNumbers[2].setPosition(775, 295);
//
//    sf::Text questionText;
//    questionText.setFont(digitalFont);
//    questionText.setCharacterSize(35);
//    questionText.setString("Which clock shows the same time as the digital one? 1 or 2 or 3");
//    questionText.setPosition(50, 600);
//
//
//    enum State { PLAYING , GAMEOVER , INITIALIZE };
//    State state = INITIALIZE;
//
//    int correctClock = 0;
//    int answer = 3;
//    int playAgain = 3;
//	bool firstRound = true;
//	bool update = true;
//
//	int min1;
//	int min2;
//	int min3;
//
//	int hour1;
//	int hour2;
//	int hour3;
//
//	int hourR;
//	int minR;
//
//    while (window.isOpen())
//    {
//		
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();
//            
//            if (state == INITIALIZE) {
//                correctClock = getRandomNum(0, 2);
//
//				min1 = getRandomMinute();
//				hour1 = getRandomHour();
//
//				minR = minuteToRotation(min1);
//				hourR = hourToRotation(min1, hour1);
//
//				minuteHands[0].setRotation(minR);
//				hourHands[0].setRotation(hourR);
//
//				min2 = getRandomMinute();
//				hour2 = getRandomHour();
//
//				minR = minuteToRotation(min2);
//				hourR = hourToRotation(min2, hour2);
//
//                minuteHands[1].setRotation(minR);
//                hourHands[1].setRotation(hourR);
//
//				min3 = getRandomMinute();
//				hour3 = getRandomHour();
//
//				minR = minuteToRotation(min3);
//				hourR = hourToRotation(min3, hour3);
//
//                minuteHands[2].setRotation(minR);
//                hourHands[2].setRotation(hourR);
//
//				switch (correctClock) {
//				case 0:
//					digitalText.setString(getTimeString(min1, hour1));
//					break;
//
//				case 1:
//					digitalText.setString(getTimeString(min2, hour2));
//					break;
//
//				case 2:
//					digitalText.setString(getTimeString(min3, hour3));
//					break;
//				}
//
//                questionText.setString("Which clock shows the same time as the digital one? 1 or 2 or 3");
//                answer = 3;
//                playAgain = 3;
//
//                state = PLAYING;
//            }
//
//            if (event.type == sf::Event::KeyPressed) {
//                if (state == PLAYING) {
//                    if (event.key.code == sf::Keyboard::Num1) {
//                        answer = 0;
//                    }
//                    if (event.key.code == sf::Keyboard::Num2) {
//                        answer = 1;
//                    }
//                    if (event.key.code == sf::Keyboard::Num3) {
//                        answer = 2;
//                    }
//
//                    if (answer < 3) {
//                        if (answer == correctClock) {
//                            questionText.setString("Correct! Try again?  y or n");
//                        }
//                        else {
//                            questionText.setString("Wrong! Try again?  y or n");
//                        }
//
//                        if (event.key.code == sf::Keyboard::Y) {
//                            playAgain = 1;
//							firstRound = false;
//                            state = INITIALIZE;
//                        }
//                        else if (event.key.code == sf::Keyboard::N) {
//                            playAgain = 2;
//                            state = GAMEOVER;
//                        }
//                    }
//                }
//
//                if (state == GAMEOVER) {
//                    window.close();
//                    cout << endl << endl;
//                    return 0;
//                }
//            }
//        }
//
//		if (firstRound) {
//			digitalText.setString(getTimeString(getCurrentMinutes(), getCurrentHours()));
//			AMorPM.setString(getAM_PM(getCurrentHours()));
//			hourHands[correctClock].setRotation(getCorrectHourRotation());
//			minuteHands[correctClock].setRotation(getCorrectMinuteRotation());
//		}
//		else {
//	
//
//			min1 = UpdateMinute(min1, update);
//			hour1 = UpdateHour(hour1, min1, update);
//
//			minR = minuteToRotation(min1);
//			hourR = hourToRotation(min1, hour1);
//
//			minuteHands[0].setRotation(minR);
//			hourHands[0].setRotation(hourR);
//
//			min2 = UpdateMinute(min2, update);
//			hour2 = UpdateHour(hour2, min2, update);
//
//			minR = minuteToRotation(min2);
//			hourR = hourToRotation(min2, hour2);
//
//			minuteHands[1].setRotation(minR);
//			hourHands[1].setRotation(hourR);
//
//			min3 = UpdateMinute(min3, update);
//			hour3 = UpdateHour(hour3, min3, update);
//
//			minR = minuteToRotation(min3);
//			hourR = hourToRotation(min3, hour3);
//
//			minuteHands[2].setRotation(minR);
//			hourHands[2].setRotation(hourR);
//
//			if (getCurrentSeconds() == 0) {
//				update = false;
//			}
//			else {
//				update = true;
//			}
//
//			switch (correctClock) {
//			case 0:
//				digitalText.setString(getTimeString(min1, hour1));
//				AMorPM.setString(getAM_PM(hour1));
//				break;
//
//			case 1:
//				digitalText.setString(getTimeString(min2, hour2));
//				AMorPM.setString(getAM_PM(hour2));
//				break;
//
//			case 2:
//				digitalText.setString(getTimeString(min3, hour3));
//				AMorPM.setString(getAM_PM(hour3));
//				break;
//			}
//		}
//		
//		
//
//        window.clear();
//
//        window.draw(DCSprite);
//        window.draw(digitalText);
//        window.draw(AMorPM);
//        window.draw(headerText);
//        window.draw(clockFace1);
//        window.draw(clockFace2);
//        window.draw(clockFace3);
//        window.draw(hourHands[0]);
//        window.draw(hourHands[1]);
//        window.draw(hourHands[2]);
//        window.draw(minuteHands[0]);
//        window.draw(minuteHands[1]);
//        window.draw(minuteHands[2]);
//        window.draw(clockNumbers[0]);
//        window.draw(clockNumbers[1]);
//        window.draw(clockNumbers[2]);
//        window.draw(questionText);
//
//        window.display();
//    }
//}

//////////////////////////////
// TODO:
/*
1. Make GetRandom functions - Done

2. Get System Time / look at how they are already doing it - Done

3. Digital clock displaying current time - Done
    1. set up sprites for clock - Done
    2. get current time and format into AM and PM - Done
    3. get sprites to show the correct time - Donw

4. Set up analog clock sprites - Done

5. random clock shows correct current time, others show random time using getrandom functions - Done

6. Get user input to choose the correct clock
    Reference sixes game code
    Probably use switch statement

7. display message for correct and incorrect answers

8. player can play again or close game
*/