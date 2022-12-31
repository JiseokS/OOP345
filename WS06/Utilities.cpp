//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <sstream>
#include <iostream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Luxuryvan.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptr = nullptr;
		string temp;
		stringstream str;
		getline(in, temp);
		temp.erase(0, temp.find_first_not_of(' '));
		str.str(temp);
		if (!temp.empty()) {
			if (temp[0] == 'c' || temp[0] == 'C')
				ptr = new Car(str);
			else if (temp[0] == 'v' || temp[0] == 'V')
				ptr = new Van(str);
			else if (temp[0] == 'r' || temp[0] == 'R')
				ptr = new Racecar(str);
			else if (temp[0] == 'l' || temp[0] == 'L')
				ptr = new Luxuryvan(str);
			else
				throw char(temp[0]);
		}
		
		return ptr;
	}
}