#ifndef __TIMER__
#define __TIMER__
#include <ctime> //to get current time
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <chrono>         // std::chrono::system_clock
#include <thread>         // std::this_thread::sleep_until

using namespace std;
class Timer
{
	long Interval = 10000; //each 10 sec 
	int CountedFrame;
	SYSTEMTIME st, lt;
public:
	clock_t Start_Clock;
	clock_t CurrentTime;
	void getCurrentTime();

	void TimerWait(DWORD interval);
	void DisplayCurrentTime();

	DWORD interval = 20;	// 10th of a second
	DWORD start = GetTickCount(); // program starts
	void PromtUserForTimeAndwaitTillit();

	long Timer::timediff(clock_t t1, clock_t t2); // function which will check how many msk has passed 
	bool IntervalTimePassed();
};
#endif // __TIMER__