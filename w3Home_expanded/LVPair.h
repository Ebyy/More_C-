/*
 ============================================================================
 Name        : LVPair.h
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
  Description : Contains class templates that manages label-value pair objects 
				and also the summing up of those pairs with the derived Summable
				LVPair class template
  ============================================================================
 */
#ifndef _SICT_LVP_H
#define _SICT_LVP_H

#include <iostream>


//using namespace std;

namespace sict
{
	template<typename L, typename V>
	class LVPair {
		L myLabel;
		V myValue;
	public:
		//sets empty for LV pair objects
		LVPair() :  myLabel{'\0'}, myValue{0} {

		}

		//instatiates an LVPair object with values
		LVPair(const L& label, const V& v) : myLabel{ label }, myValue{ v } {
			
		}
		//returns label data member
		const L getLabel()const { 
			return myLabel; 
		}

		//returns value data memeber
		const V getValue() const { return myValue; }

		//specifies format for the display of the object
		virtual void display(std::ostream& os)const {
			os << myLabel << " : " << myValue << std::endl;
		}
		
	};

	//Non friend helper function with overloaded <<operator to the ostream that calls display
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L,V> {
		static V initialSumVal;
		static size_t minFieldWidth;
	public:
    // No arg constructor sets empty state
        SummableLVPair(){


		}
		// 2-arg constructor sets initialises object of this class and sets values
		SummableLVPair(const L& label, const V& v) : LVPair<L,V>(label, v) {
			if (minFieldWidth < label.size()) {
				minFieldWidth = label.size();
			}
		}

		const V& getInitialValue() {
			return initialSumVal;
		}

		//returns V object the sum of the current object and the accumulated sum
		V sum(const L& label, const V& sum) const {
			V xVal = sum;
			if (LVPair<L, V>::getLabel() == label) {
				xVal = sum + this->getValue();
			}
			return xVal;
		}
   
    //display in specified format
		void display(std::ostream& os)const {
			os.setf(std::ios::left);
			os.width(minFieldWidth);
			LVPair<L, V>::display(os);	
			os.unsetf(std::ios::left);
		}
	};

  //template specialization to resolve ambiguity of sum() function call on V value with std::string
	template <>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {

		return sum + " " + this->getValue();
	}
  
 	//template specification to resolve for ambiguity in initialization of static variables
 	template<typename L, typename V>	
	size_t SummableLVPair<L,V>::minFieldWidth = 0U;
  
  template<>
  std::string SummableLVPair<std::string, std::string>::initialSumVal = "";
  
  template<>
	int SummableLVPair<std::string, int>::initialSumVal = 0;

}

#endif // !_SICT_LVP_H
