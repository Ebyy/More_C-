/*
 ============================================================================
 Name        : w01.cpp
 Author      : Eberechi Ogunedo
 Email       : eokengwu@myseneca.ca
 Student #   : 117277160
 Course Code : OOP345
 Section     : SCC
 Date        : May 17, 2019
 Workshop    : Workshop 1 - Home
 ============================================================================
 */

 /*
  ============================================================================
  Description : Displays the first three characters of any number of command line arguments entered
  ============================================================================
 */
#include <iostream>
#include "process.h"
using namespace sict;

extern int INITIAL; //extend availability of this variable to other translation units
int main(int argc, char *argv[]) {

	int i;
	std::cout << "Command Line : " << argv[0] << ' ';       
	for (i = 1; i < argc; i++){ 
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if(argc > 1){
		for (i = 1; i < argc; i++) {
			
			process(argv[i]);

		}
	}
	else {
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}
	return 0;
}