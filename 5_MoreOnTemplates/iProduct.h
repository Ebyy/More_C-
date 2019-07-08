/*
 ============================================================================
 Name        : iProduct.h
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : July 5, 2019
 Workshop    : Workshop 6 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : iProduct header file with interface
  ============================================================================
*/

#ifndef MYPROD_INTERFACE
#define MYPROD_INTERFACE

#include <iostream>

namespace sict {
	//iProduct interface
	class iProduct {
	public:
		virtual double price()const = 0;
		virtual void display(std::ostream&)const = 0;
		
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readRecord(std::ifstream&);
}

#endif
