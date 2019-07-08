/*
 ============================================================================
 Name        : Product.cpp
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
  Description : Product implementation file with class implementation that
  initializes an object with class data member in different states, defines 
  functionality available to the object and displays output according to format given.
  ============================================================================
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include "Product.h"


namespace sict {
	//No arg constructor sets empty state
	Product::Product() : productNum{0}, productPrice{0.0}{

	}

	// 2 arg constructor constructs a productor with values
	Product::Product(int num, double cost): productNum{num}, productPrice{cost}{

	}

	//returns value of productPrice
	double Product::price()const { 
		return productPrice; 
	}

	//inserts values of data members to the output stream
	void Product::display(std::ostream& os)const {
		os << std::setw(10) << productNum;
		os << std::setw(10) << std::fixed << std::setprecision(2) << productPrice;
	}

	//uses product object to call display on os stream object and returns the ostream object when done
	std::ostream& operator<<(std::ostream& os, const iProduct& product) {
		product.display(os);
		return os;
	}

	//passes values to data member as it reads from the file and initialises a Product object 
	//that has its address saved in a pointer that it returns
	iProduct* readRecord(std::ifstream& fs) {
		int tempNum;
		double tempPrice;
		iProduct * product=nullptr;

		fs >> tempNum >> tempPrice;
		if (!fs.fail()) {
			product = new Product(tempNum, tempPrice);
		}
		return product;
	}
}