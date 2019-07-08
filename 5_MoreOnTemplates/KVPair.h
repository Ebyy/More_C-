/*
 ============================================================================
 Name        : KVPair.h
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

#ifndef _KVPAIR_H_
#define _KVPAIR_H_

#include <iostream>
#include <iomanip>

//linking already declared variable with extern keyword
extern int fieldWidth; 

namespace sict {
	template<typename K, typename V>
	class KVPair {
		K myKey;
		V myValue;
	public:
		// No arg constructor sets empty state
		KVPair() : myKey{}, myValue{} {
		
		}

		//empty destructor calls the default one
		~KVPair() {}
		KVPair(const K& key, const V& value) :myKey{ key }, myValue{ value } {

		}

		//display output to screen as formatted
		template<typename F>
		void display(std::ostream& os, F f) const {
			os<<std::left << std::setw(fieldWidth) << myKey << " : ";
			os << std::right << std::setw(fieldWidth) << myValue;
			os << std::right << std::setw(fieldWidth) << f(myValue) << std::endl;
		}
	};
	
}

#endif // !_KVL_H_

