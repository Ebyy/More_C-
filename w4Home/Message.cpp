/*
 ============================================================================
 Name        : Message.cpp
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : June 5, 2019
 Workshop    : Workshop 3 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : implementations file for message module
  ============================================================================
 */

#include <iostream>
#include "Message.h"

namespace sict
{
	//no arg constructor sets empty state
	Message::Message() :  user{ "" }, message{ "" }, reply{ "" } {

	}
	// 1 arg constructor sets values
	Message::Message(const std::string& str) {		
		if (str != "") {
			int start = 0;
			bool replySent = str.find('@') != str.npos ? true : false;
			size_t cursorHere = str.find(' ');
			if (cursorHere != str.npos) {
				user = str.substr(start, cursorHere);
				if (replySent) {
					cursorHere = str.find('@');
					int cursorHere2 = str.find(' ', cursorHere + 2);
					reply = str.substr(cursorHere + 1, (cursorHere2 - (cursorHere + 1)));
					cursorHere = cursorHere2; //reset position
				}
				message = str.substr(cursorHere + 1, str.length() - 1);
			}
		}
		else {
			*this = Message();
		}

	}
	//destructor
	Message::~Message() {

	}

	//checks if object in empty state
	bool Message::empty() const{
		return user == ""? true : false;
	}

	//display output in the specified format
	void Message::display(std::ostream& os) const{
		if (!empty()) {
			os << ">User  : " << user << std::endl;
			if (reply != "") {
				os << " Reply : " << reply << std::endl;
			}
			os << " Tweet : " << message << std::endl;
		}
	}
}
