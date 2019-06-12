/*
 ============================================================================
 Name        : Timekeeper.h
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : May 28, 2019
 Workshop    : Workshop 2 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : Contains Timekeeper class that manages a statically allocated array of record objects
  ============================================================================
 */
#ifndef _SICT_TIMEKEEPER_H
#define _SICT_TIMEKEEPER_H

#include <chrono>
#include <iostream>

namespace sict
{
	const int MAXRECORDS = 10;

	class Timekeeper
	{
		static size_t totalCounter;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;

		struct
		{
			char* message;
			const char* units = "seconds";
			std::chrono::steady_clock::duration totalDuration;
		} records[MAXRECORDS];

	public:
		Timekeeper();                                                                                                                                                                                                                
		void start();
		void stop();
		void recordEvent(const char*);
		std::ostream& report(std::ostream&);
		~Timekeeper();
	};
}

#endif // !_SICT_TIMEKEEPER_H