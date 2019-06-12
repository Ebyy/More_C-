/*
 ============================================================================
 Name        : MessagePack.cpp
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
  Description : MessagePack Implementations showing compositions relationship with Message Module
  ============================================================================
 */

#include <iostream>
#include <string>
#include "MessagePack.h"

namespace sict {
  //No arg constructor sets empty state
	MessagePack::MessagePack() : messages{ nullptr } {
		numOfObjectsStored = 0u ;
	}
  //2 arg constructor initializes object instance with values
	MessagePack::MessagePack(Message** msgPointer, size_t numOfElementsInArray) {
		if (numOfElementsInArray > 0 && msgPointer != nullptr) {
			numOfObjectsStored = 0u;
			int emptySpot;
			messages = new Message[numOfElementsInArray];
			for (size_t i = 0; i < numOfElementsInArray; i++) {
				if (!(*msgPointer[i]).empty()) {
					messages[i] = *msgPointer[i];
					numOfObjectsStored++;
				}
				else {
					emptySpot = i;
					i = numOfElementsInArray;
				}
			}
      // rearrange array and shift values to cover empty space like a swap
			for (size_t j = emptySpot; j >= 0 && j < numOfElementsInArray - 1; ++j) {
				messages[j] = *msgPointer[j + 1];
				numOfObjectsStored++;
			}
		}
		else {
			*this = MessagePack();
		}
	}

	//destructor to deallocate memory and avoid leakages
	MessagePack::~MessagePack() {
		delete[]messages;
		messages = nullptr;

	}
	//copy constructor
	MessagePack::MessagePack(const MessagePack& otherObject) {
		messages = nullptr;
		*this = otherObject;
	}
	//copy assignment implementation
	MessagePack& MessagePack::operator=(const MessagePack& otherObject) {
		if (this != &otherObject) {
			numOfObjectsStored = otherObject.numOfObjectsStored;
			delete[] messages;
			if (otherObject.messages != nullptr) {
				messages = new Message[otherObject.numOfObjectsStored];
				for (size_t i = 0; i < otherObject.numOfObjectsStored; i++) {
					messages[i] = otherObject.messages[i];
				}
			}
		}

		return *this;
	}
	//move constructor
	MessagePack::MessagePack(MessagePack&& rhs) {
		messages = nullptr;
		*this = std::move(rhs);
	}
	//move assignment implementation
	MessagePack& MessagePack::operator=(MessagePack&& rhs) {
		if (this != &rhs) {
			delete[] messages;
			messages = rhs.messages;
			rhs.messages = nullptr;
			numOfObjectsStored = rhs.numOfObjectsStored;
			rhs.numOfObjectsStored = 0u;
		}
		return *this;
	}
  //returns the num of objects stored in the current object instance
	size_t MessagePack::size()const {
		return numOfObjectsStored;
	}
  //displays to screen according to format
	void MessagePack::display(std::ostream& os)const {
		for (size_t i = 0; i < size(); i++) {
			messages[i].Message::display(os);
		}
		
	}
  //Non friend helper implementation
	std::ostream& operator<<(std::ostream& os, const MessagePack& other) {
		other.display(os);
		return os;
	}
}