/*
 ============================================================================
 Name        : List.h
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : May 30, 2019
 Workshop    : Workshop 3 - Lab
 ============================================================================
 */

 /*
  ============================================================================
 Description : Contains class templates that manages an array of any datatype 
				and also has a derived class template that accumulates values of the list 
				according to their labels
  ============================================================================
 */
#ifndef _SICT_LIST_H
#define _SICT_LIST_H

#include <iostream>
#include "LVPair.h"

namespace sict
{
	template<typename T, size_t N>
	class List {
		T myArray[N];
		size_t numStored = 0u;
	public:
		//returns the number of elements stored in the array
		size_t size()const {
			return numStored;
		}

		//returns a reference to an unmodifiable object of the array at an index location
		const T& operator[](size_t i)const {
			return myArray[i];
		}

		//adds a List object to the array after checking if there is space for it
		void operator+=(const T& t) {
			if (size() < N) {
				myArray[size()] = t;
				numStored++;
			}
		}
	};

// accumulate values of the lists according to the types
	template<typename T, typename L, typename V, size_t N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
            SummableLVPair<L,V> accumulator;
            V sumOfListObjs = accumulator.getInitialValue();
			      size_t numOfElements = this->size();

            for(size_t i = 0; i < numOfElements; i++){
				      auto &currentElement = (*this)[i];
					    sumOfListObjs = currentElement.sum(label, sumOfListObjs);		
            }
            return sumOfListObjs;
		}
	};
}

#endif // !_SICT_LIST_H
