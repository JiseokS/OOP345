//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car :public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed = 0;
	public:
		Car();
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H_