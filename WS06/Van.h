//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Van : public Vehicle
	{
		std::string v_maker = "";
		std::string v_type = "";
		std::string v_condition = "";
		std::string v_purpose = "";
		double v_top_speed = 0;
	public:
		Van();
		Van(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_VAN_H
