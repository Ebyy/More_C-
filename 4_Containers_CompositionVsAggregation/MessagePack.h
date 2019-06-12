/*
 ============================================================================
 Name        : MessagePack.h
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
  Description : MessagePack header file with class and prototypes
  ============================================================================
 */

#ifndef _MSGPACK_H_
#define _MSGPACK_H_
#include "Message.h"

namespace sict {
	class MessagePack {
		Message* messages;
		size_t numOfObjectsStored;
	public:
		MessagePack();
		~MessagePack();
		MessagePack(Message** msg, size_t num);
		MessagePack(const MessagePack& rhs);
		MessagePack& operator=(const MessagePack& other);
		MessagePack(MessagePack&& other); //move constructor
		MessagePack& operator=(MessagePack&& other);
		void display(std::ostream& os)const;
		size_t size()const;

	};
	//Non-friend helper - overloaded << operator that insert MessagePack objects into os stream
	std::ostream& operator<<(std::ostream&, const MessagePack&);
}
#endif // !_MSGPACK_H