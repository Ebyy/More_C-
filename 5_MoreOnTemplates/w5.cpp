// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	//handle commandline exceptions and display exceptions thrown
	try {
		// check for command line errors
		if (argc != 3) { 
			throw "Less number of arguments! Check if two given text files are included.";
			exit(1);
		}

		// set for fixed, 2-decimal point output
		std::cout << std::fixed << std::setprecision(2);

		// process price list file
		KVList<KVPair<std::string, float>> priceList = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[1]);
		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));

		// process student list file
		KVList<KVPair<std::string, float>> students = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[2]);

		std::cout << "\nStudent List Letter Grades Included\n===================================\n";
		std::cout << "Student No :  " << std::right << std::setw(fieldWidth) << "Grade ";
		std::cout << std::right << std::setw(fieldWidth) << "Letter\n";
		students.display(std::cout, [](float grade)->std::string {

			if (grade < 0 && grade > 100) {
				throw "Grade out of bounds! Only 0 - 100 allowed.";
			}
			else if (grade <= 100 && grade >= 90) {
				return "A+";
			}
			else if (grade <= 89.9 && grade >= 80)
			{
				return "A ";
			}
			else if (grade <= 79.9 && grade >= 75)
			{
				return "B+";
			}
			else if (grade <= 74.9 && grade >= 70)
			{
				return "B ";
			}
			else if (grade <= 69.9 && grade >= 65)
			{
				return "C+";
			}
			else if (grade <= 64.9 && grade >= 60)
			{
				return "C ";
			}
			else if (grade <= 59.9 && grade >= 55)
			{
				return "D+";
			}
			else if (grade <= 54.9 && grade >= 50)
			{
				return "D ";
			}
			else if (grade <= 49.9 && grade >= 0)
			{
				return "F ";
			}
			else {
				throw "Grade is not a number! Please try again!";
			}
		});
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what(); //display exceptions accordingly
		exit(3);
	}

}