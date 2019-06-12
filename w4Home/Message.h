/*
 ============================================================================
 Name        : Message.h
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
  Description : Message header file with class and prototypes
  ============================================================================
 */
#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <iostream>
#include <string>

namespace sict
{
	class Message {
		std::string user;
		std::string message;
		std::string reply;

	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
		~Message();
	};
}

#endif // !_MESSAGE_H
