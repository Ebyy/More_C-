/*
 ============================================================================
 Name        : Notifications.h
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
  Description : Notitifications header file with class and prototypes
  ============================================================================
 */
#ifndef _NOTIFY_H_
#define _NOTIFY_H_

#include "Message.h"

namespace sict {
	class Notifications {
		const Message** notifications;
		size_t numStored;
		size_t maxNumAggregated;
	public:
		Notifications();
		~Notifications();
		Notifications(const Notifications& rhs);
		Notifications& operator=(const Notifications& other);
		Notifications(Notifications&& other); //move constructor
		Notifications& operator=(Notifications&& other);
		Notifications(size_t num);
		Notifications& operator-=(const Message&);
		Notifications& operator+=(const Message&);
		void display(std::ostream& os)const;
		size_t size()const;
	};

	//Non-friend helper - overloaded << operator that insert MessagePack objects into os stream
	std::ostream& operator<<(std::ostream&, const Notifications&);
}
#endif // !_NOTIFY_H
