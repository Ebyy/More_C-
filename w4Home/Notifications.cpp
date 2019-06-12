/*
 ============================================================================
 Name        : Notifications.cpp
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : June 9, 2019
 Workshop    : Workshop 4 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : Notifications implementation file showing aggregation relationship with Message module
  ============================================================================
 */

#include <iostream>
#include "Notifications.h"

namespace sict {
  // No arg constructor sets empty state
	Notifications::Notifications() : notifications{ nullptr } {
		maxNumAggregated = 0u; 
		numStored = 0u;
	}
  // 1 arg constructor sets values
	Notifications::Notifications(size_t numOfAggregatedElements) {
		if (numOfAggregatedElements > 0) {
			notifications = new const Message*[numOfAggregatedElements];
			maxNumAggregated = numOfAggregatedElements;
			numStored = 0u;

		}
		else {
			*this = Notifications();
		}
	}

	//destructor
	Notifications::~Notifications() {

		delete[]notifications;
		notifications = nullptr;
	}
	//copy constructor
	Notifications::Notifications(const Notifications& otherObject) {
		notifications = nullptr;
		*this = otherObject;
	}
	//copy assignment implementation
	Notifications& Notifications::operator=(const Notifications& otherObject) {
		if (this != &otherObject) {
			numStored = otherObject.numStored;
			maxNumAggregated = otherObject.maxNumAggregated;
			//delete[] notifications;
			for (size_t i = 0; i < otherObject.numStored; i++) {
				notifications[i] = otherObject.notifications[i];
			}
			
		}
		else {
			notifications = nullptr;
		}
		return *this;
	}
	//move constructor
	Notifications::Notifications(Notifications&& rhs) {
		*this = std::move(rhs);
	}
	//move assignment implementation
	Notifications& Notifications::operator=(Notifications&& rhs) {
		if (this != &rhs) {
			notifications = rhs.notifications;
			rhs.notifications = nullptr;
			numStored= rhs.numStored;
			rhs.numStored = 0u;
			maxNumAggregated = rhs.maxNumAggregated;
			rhs.maxNumAggregated = 0u;
		}
		return *this;
	}
  // overloaded -= operator implementation to remove a message from aggregated set
	Notifications& Notifications::operator-=(const Message& removeText) {
		for (size_t i = 0; i < numStored; i++) {
			if (notifications[i] == &removeText) {
				notifications[i] = nullptr;
				//rearrange to fill gap by looping through and swapping
				for (size_t j = i; j >= 0 && j < numStored - 1; ++j) {
					notifications[j] = notifications[j + 1]; 
				}
				notifications[numStored-1] = nullptr;
			}
		}
		numStored -= 1;
		return *this;
	}
 
  // overloaded += opertor implementation to add a message to the aggregated set
	Notifications& Notifications::operator+=(const Message& addText) {
		bool check = numStored < maxNumAggregated;
		if (!addText.empty() && check) {
			notifications[numStored] = &addText;
			++numStored;
		}
		return *this;
	}
  // return number of elements stored in the array
	size_t Notifications::size()const {
		return numStored;
	}
  // display to ostream according to format
	void Notifications::display(std::ostream& os)const {
		for (size_t i = 0; i < size(); i++) {
			notifications[i]->display(os);
		}

	}

  //Non friend helper overloaded << operator implementation
	std::ostream& operator<<(std::ostream& os, const Notifications& signal) {
		signal.display(os);
		return os;
	}



}