/*
 ============================================================================
 Name        : Text.cpp
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : May 28, 2019
 Workshop    : Workshop 2 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : Contains implementations for Text class declared prototypes that 
  consist of its member functions and helpers if any
  ============================================================================
 */
#define  _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Text.h"

namespace sict
{
	int Text::totalCount = 0; //initialise class variable
	//set empty state
	Text::Text() : stringObjs(nullptr)
	{

	}

	Text::~Text()
	{
		delete[] stringObjs;
		stringObjs = nullptr;
	}

	Text::Text(const char * filename)
	{
		std::string temp = "";
		std::ifstream file;
		file.open(filename);
    int loopCounter = 0;

		// count lines in file
		if (file.is_open())
		{
			while (std::getline(file, temp, '\n'))
			{
				++totalCount;
			}
			
		}
		//return cursor while is at the end of the file to beginning of the file
		file.seekg(0); 

		// now allocate memory for strObjs
		stringObjs = new std::string[totalCount];
    	
		while (std::getline(file, stringObjs[loopCounter], '\n'))//while trying to get a line works keep looping
		{			
			loopCounter++;
		}
		file.close();//close file
	}
	//copy constructor defined with a direct call to the copy assignment
	Text::Text(const Text& rhs)
	{
		stringObjs = nullptr;
		*this = rhs;//call overloaded assignment operator
	}
	//copy assignment operator
	Text& Text::operator=(const Text& rhs)
	{
		if (this != &rhs) //self assignment check
		{
			// shallow copy other static variables
			totalCount = rhs.totalCount;

			//deep copy dynamically allocated variable to stringObjs
			delete[] stringObjs;
			if (rhs.stringObjs != nullptr) {
				stringObjs = new std::string[rhs.size()];
				for (size_t i = 0; i < rhs.size(); i++) {
					stringObjs[i] = rhs.stringObjs[i];
				}
					
			}

		}
		return *this;
	}
	//execute move using a direct call to the move assignment operator
	Text::Text(Text&& otherObject) : stringObjs(nullptr) 
	{
		*this = std::move(otherObject); //call overloaded =operator
	}

	//move assignment operator - transfer contect on the right to the current object
	Text& Text::operator=(Text&& otherObject) {
		if (this != &otherObject) {
			delete[] stringObjs;
			stringObjs = otherObject.stringObjs;
			otherObject.stringObjs = nullptr;
		}
		return *this;
	}

	//returns totalCount
	size_t Text::size() const
	{
		return totalCount;
	}
}