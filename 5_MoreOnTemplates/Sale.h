/*
 ============================================================================
 Name        : Sale.h
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
  Description : Sales header file with class
  ============================================================================
*/

#ifndef MYSALE
#define MYSALE

#include <vector>
#include "Product.h"

namespace sict {
	class Sale {
		std::vector<iProduct*> allProducts;
	public:
		Sale(const char*);
		void display(std::ostream& os) const;
	};
}
#endif // !MYSALE
