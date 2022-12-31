/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-05-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "TimedTask.h"

namespace sdds {
	TimedTask::TimedTask() {}
	TimedTask::~TimedTask() {}
	void TimedTask::startClock() {
		start_time = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock() {
		end_time = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* taskname) 
	{
		if (record_number < MAX_OBJ)
		{
			task[record_number].task_name = taskname;
			task[record_number].unit_time = "nanoseconds";
			task[record_number].task_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
			record_number++;
		}
	}
	std::ostream& operator<<(std::ostream& os,const TimedTask& src) {
		if (os)
		{
			os << "--------------------------" << std::endl;
			os << "Execution Times:" << std::endl;
			os << "--------------------------" << std::endl;
			for (size_t i = 0; i < src.record_number; i++)
			{
				os.width(21);
				os.setf(std::ios::left);
				os << src.task[i].task_name << " ";
				os.width(21);
				os.unsetf(std::ios::left);
				os << src.task[i].task_duration.count() << " ";
				os << src.task[i].unit_time << std::endl;
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}
}