//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <sstream>
#include <iomanip>
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds
{
	Racecar::Racecar()
	{
	}
	Racecar::Racecar(std::istream& in) :Car(in)
	{
		string temp;
		getline(in, temp);
		m_booster = stod(temp.substr(0, temp.find('\n')));
	}
	void Racecar::display(std::ostream& out) const
	{
		std::string racecar;
		std::stringstream str_racecar;

		Car::display(str_racecar);
		racecar = str_racecar.str();
		racecar.erase(racecar.size() - 9);
		out << racecar;
		out << setw(6) << setprecision(2) << fixed << topSpeed();
		out << " |*" << endl;
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}