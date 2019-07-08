/*
 ============================================================================
 Name        : Product.h
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
  Description : Product header file with class derived from the iProduct interface
  ============================================================================
*/
#ifndef MYPRODUCT
#define MYPRODUCT

#include <iostream>
#include "iProduct.h"

extern int FW;
namespace sict {
	
	class Product :public iProduct {
		int productNum;
		double productPrice;
	public:
		Product();
		Product(int, double);
		double price() const;
		void display(std::ostream& os)const;
	};

}
#endif // !MYPRODUCT

