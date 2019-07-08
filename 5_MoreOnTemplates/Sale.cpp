/*
 ============================================================================
 Name        : Sales.cpp
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
  Description : Sales implementation file that aggregates the vector data member 
  and displays output according to format given.
  ============================================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sale.h"


namespace sict {
	//Sales constructor that aggregates vector data members allProducts
	Sale::Sale(const char* file) {
		if (file != nullptr) {
			iProduct* temp = nullptr;
			std::ifstream fs;
			fs.open(file);
			if (fs.is_open()) {
				while ((temp = readRecord(fs))) {
					allProducts.push_back(temp);
				}
				fs.close();
			}
		}
	}

	//accumulates sum of the prices in our vector and displays according to given format
	void Sale::display(std::ostream& os)const {
		double pTotal{ 0.0 };
		os << std::endl << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << std::endl;
		for (auto& i : allProducts) {
			os << *i << std::fixed << std::setprecision(2) << std::endl;
			pTotal += i->price();
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << pTotal << std::endl;

	}
}