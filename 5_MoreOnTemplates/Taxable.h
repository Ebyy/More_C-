/*
 ============================================================================
 Name        : Taxable.h
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : June 13, 2019
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : KVPair header file with templated class implementation
  ============================================================================
*/

#ifndef _ATAX_H
#define _ATAX_H

namespace sict {
	class Taxable {
		float taxRate;
	public:
		//1 arg constructor
		Taxable(float rate) : taxRate{ rate } {}
		//overloaded ()operator that returns a float price that has the tax included 
		float operator()(float price){
			return price * (1 + taxRate);

		}

	};
}
#endif // !_TAX_H

