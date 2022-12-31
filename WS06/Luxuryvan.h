//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include "Van.h"

namespace sdds
{
	class Luxuryvan : public Van
	{
		std::string m_consumption = "";
	public:
		Luxuryvan();
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}
#endif // !SDDS_LUXURYVAN_H
