/*
 ============================================================================
 Name        : String.cpp
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
  Description : Definitions of the string class and functions in my string header file
  ============================================================================
 */
//necessary libraries included and headers
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

namespace sict {
	int INITIAL = 3; //using same variable from w1.cpp extended by EXTERN
	//one argument constructor of the string class defined and empt state handled
	String::String(const char * other) {
     str = nullptr;
		if (other != nullptr) {
			str = new char[strlen(other+1)];
			strncpy(str, other, strlen(other));
			str[strlen(other)] = '\0';
		}

	}
 // deallocate memory to avoid memory leak problems with a custom destructor
  String::~String(){
     if(str != nullptr){
        delete[] str;
     }
  }
	//display memebr function that calls the helper operator defined
	void String::display(ostream& out)const {
		out << str;
	}
	//helper function defined 
	ostream& operator<<(ostream&os, String& rhs) {
		std::cout << INITIAL++ << ": ";
		rhs.display(os);
		
		return os;
	}
}
