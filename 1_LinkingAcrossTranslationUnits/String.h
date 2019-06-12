// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.h
/*
 ============================================================================
 Name        : String.h
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : May 17, 2019
 Workshop    : Workshop 1 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : Contains string class and the class helper function
  ============================================================================
 */
//header guards included
#ifndef _STRINGY_H_
#define _STRINGY_H_
//include libraries
#include <iostream>
using namespace std;

namespace sict {
//	const int MAX = 3; //constant specifying size of char data member str  in string class
	//string class created
	class String {
		char* str;
	public:
		String(const char *);
    ~String();
		void display(ostream& out)const;

	};
	ostream& operator<<(ostream& os,String& rhs);
}

#endif // !_PROCESS_H_
