/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-07-17
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{

	struct Covid
	{
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		size_t m_cases{};
		int m_year{};
		size_t m_deaths{};
	};

	class CovidCollection
	{
	private:
		std::vector<Covid> m_infections;
	public:
		CovidCollection(std::string fileName);
		void display(std::ostream& out) const;
		void sort(std::string name);
		void cleanList();
		bool inCollection(std::string name) const;
		std::list<Covid> getListForCountry(std::string name) const;
		std::list<Covid> getListForVariant(std::string name) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif // !SDDS_COVIDCOLLECTION_H__