/*
 ============================================================================
 Name        : Timekeeper.cpp
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
  Description : Contains definitions of the declared prototypes in Timekeeper class 
  ============================================================================
 */
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include "Timekeeper.h"
using namespace std;

namespace sict {
	size_t Timekeeper::totalCounter = 0; //set class variable to 0
	//define empty state for start_time and end_time variables
	Timekeeper::Timekeeper() {
		start_time = {};
		end_time = {};
	}
	//ensure destruction of dynamically allocated memory to avoid leaks
	Timekeeper::~Timekeeper() {
		for (size_t i = 0; i < totalCounter; i++) {
			if (records[i].message != nullptr) {
				delete[] records[i].message;
			}
		}
	}
	//modify start_time to log time started
	void Timekeeper::start() {
		start_time = chrono::steady_clock::now();
	}
	//modify end_time to log time ended.
	void Timekeeper::stop() {
		end_time = chrono::steady_clock::now();

	}
	//track time taken to record an event that was passed into the struct array
	void Timekeeper::recordEvent(const char* descEvent) {		
		records[totalCounter].message = new char[strlen(descEvent)+1];
		strncpy(records[totalCounter].message, descEvent, strlen(descEvent));
		records[totalCounter].message[strlen(descEvent)] = '\0';
		records[totalCounter].totalDuration = end_time - start_time;
		totalCounter++;
	}
	//display output in the format specified
	ostream& Timekeeper::report(ostream& os) {
		os << '\n' << "Execution Times:" << endl;
		for (size_t i = 0; i < totalCounter; i++) {
			os << records[i].message << " " << records[i].totalDuration.count() / 1000 <<  " " << records[i].units << endl;	
		}
		return os;
	}
	
}