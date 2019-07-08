/*
 ============================================================================
 Name        : KVList.h
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
  Description : KVList header file with templated class implementation
  ============================================================================
*/

#ifndef _KVLIST_H_
#define _KVLIST_H_

#include <iostream>

namespace sict {

	template<typename T>
	class KVList {
		T* myArray;
		int size;
		int numStored;
	public:
		// No arg constructor sets empty state
		KVList() : myArray{ nullptr }, numStored{ 0 }, size{ 0 } {}
		
		//1 arg constructor allocates dynamic memmory for the array data member
		KVList(int n) : numStored{ 0 } {
			if (n > 0) {
				myArray = new T[n];
				size = n;
			}
		}

		//destructor
		~KVList() {
			delete[] myArray;
			myArray = nullptr;
		}

		//move constructor
		KVList(KVList && itemToMove){
			if (this != &itemToMove) {
				//delete[] myArray;
				myArray = itemToMove.myArray;
				size = itemToMove.size;
				numStored = itemToMove.numStored;
				itemToMove.myArray = nullptr;
				itemToMove.size = 0;
				itemToMove.numStored = 0;
			}
		}

		// returns an element at the i-th position in the array
		const T& operator[](size_t i)const {
			if (i > size) {
				throw "Not allowed - i is out of bounds of the array!!!";
				exit(4);
			}
			return i>0 && i<size? myArray[i]:0;
		}

		//display according to format
		template<typename F>
		void display(std::ostream& os, F f) const {
			for (int i = 0; i < size; i++) {
				myArray[i].display(os, f);
			}
		}
		
		//adds an element to the array if there is space left
		void push_back(const T& t){
			if (numStored < size) {
				myArray[numStored] = t;
			}
			++numStored;
		}

		//prohibited functions - copy constructor, copy assignment, move assignment
		KVList operator=(const KVList&&) = delete;
		KVList(const KVList&) = delete;
		KVList operator=(const KVList&) = delete;
		
	};
}
#endif // !_KVLIST_H_
