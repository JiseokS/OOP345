//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iomanip>
#include <sstream>
#include "Van.h"
#include "Luxuryvan.h"

using namespace std;

namespace sdds
{
	Luxuryvan::Luxuryvan(){}
	Luxuryvan::Luxuryvan(std::istream& in) : Van(in)
	{
		string temp;
		getline(in, temp);
		m_consumption = temp.substr(0, temp.find('\n'));
		if (m_consumption == " g")
		{
			throw string("Invalid record!");
		}
	}
	void Luxuryvan::display(std::ostream& out) const
	{
		std::string luxury;
		std::stringstream str_luxury;

		Van::display(str_luxury);
		luxury = str_luxury.str();
		luxury.erase(luxury.size() - 10);
		out << luxury;
		out << topSpeed();
		out << " | electric van  *" << endl;

	}
	std::string Luxuryvan::consumption() const
	{
		return m_consumption;
	}
}