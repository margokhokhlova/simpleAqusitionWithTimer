#include "Timer.h"


void Timer::getCurrentTime() {
	GetSystemTime(&st);
	GetLocalTime(&lt);
}

	void Timer::TimerWait(DWORD interval)
	{
		DWORD startTime = GetTickCount();

		while (GetTickCount() < (startTime + interval))
		{
			//DO NOTHING JUST WAIT
		}
	}

	void Timer::DisplayCurrentTime()
	{
		std::cout << st.wYear << "-" << setfill('0') << setw(2) << st.wMonth << "-" << setfill('0') << setw(2) << st.wDay << " "
			<< setfill('0') << setw(2) << st.wHour << ":" << setfill('0') << setw(2) << st.wMinute << ":"
			<< setfill('0') << setw(2) << st.wSecond << "." << setfill('0') << setw(3) << st.wMilliseconds << "\n";
		fflush(NULL);
       
	}


	void Timer::PromtUserForTimeAndwaitTillit() {
		bool Ready = false;

		using std::chrono::system_clock;
		std::time_t tt = system_clock::to_time_t(system_clock::now());
		struct std::tm * ptm = std::localtime(&tt);

		while (!Ready)
		{
			tt = system_clock::to_time_t(system_clock::now());
			ptm = std::localtime(&tt);
			std::cout << "Current time: " << std::put_time(ptm, "%X") << '\n';
			cout << "Ready to start the calibration from the next minute? 0 No, 1 Yes" << endl;
			cin >> Ready;
		}

		std::cout << "Waiting for the next minute to begin...\n";
		++ptm->tm_min; ptm->tm_sec = 0;
		std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));

		std::cout << std::put_time(ptm, "%X") << " reached!\n";


		Start_Clock = clock(); //get the current time to use from the moment of writing
		CountedFrame = 1; //initialize the number of written frames
	}

	long Timer::timediff(clock_t t1, clock_t t2) {
		long elapsed;
		elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000; // for the moment in mS
	//	cout << elapsed << endl;
		return elapsed;

	}

bool Timer::IntervalTimePassed() {
CurrentTime = clock();
bool Passed = false;
	if (timediff(Start_Clock, CurrentTime) >= Interval*CountedFrame) {
		CountedFrame++;
		Passed = true;
	}
return Passed;
}

	