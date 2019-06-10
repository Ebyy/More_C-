/*
 ============================================================================
 Name        : Text.h
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
  Description : Contains Text class that manages a dynamically allocated array of 
  string objects and keeps track of number of strings currently stored. 
  ============================================================================
 */
#ifndef _SICT_TEXT_H
#define _SICT_TEXT_H

#include <string>

namespace sict
{
	class Text
	{
		static int totalCount;
		std::string* stringObjs;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}

#endif // !_SICT_TEXT_H
