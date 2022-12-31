/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-05-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef TIMEDTASK_H
#define TIMEDTASK_H
#include <chrono>
#include <string>

namespace sdds {

	const int MAX_OBJ = 10;
	class TimedTask 
	{
		size_t record_number = 0;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;

		struct 
		{
			std::string task_name;
			std::string unit_time;
			std::chrono::steady_clock::duration task_duration;
		} 
		task[MAX_OBJ]{};
	public:
		TimedTask();
		virtual ~TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* taskname);
		friend std::ostream& operator<<(std::ostream& os ,const TimedTask& src);
	};
}
#endif // !TIMEDTASK_H


