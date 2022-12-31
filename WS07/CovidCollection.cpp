/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-07-17
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <string>
#include <algorithm>
#include "CovidCollection.h"
using namespace std;
namespace sdds
{
	static size_t findNonWhiteSpace(std::string str, bool reversed = false) {
		if (reversed) {
			for (size_t i = str.length() - 1; i >= 0; i--)
			{
				if (str[i] != ' ')
					return i;
			}
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
				return i;
		}
		return 0;
	}

	CovidCollection::CovidCollection(std::string fileName) {
		std::ifstream fileToRead(fileName);
		if (!fileToRead)
		{
			throw std::invalid_argument("File cannot be opened.");
		}
		size_t count = 0;
		std::string record;
		do
		{
			std::getline(fileToRead, record);
			if (fileToRead)
				++count;
		} while (fileToRead);
		fileToRead.clear();
		fileToRead.seekg(std::ios::beg);

		size_t start_pos{};
		size_t end_pos{};

		for (size_t i = 0; i < count; i++)
		{
			Covid infection;
			start_pos = 0;
			end_pos = 0;
			std::getline(fileToRead, record);
			start_pos = findNonWhiteSpace(record);
			record = record.substr(start_pos);

			start_pos = 0;
			end_pos = record.find(' ');

			if (record[end_pos + 1] != ' ') {
				end_pos = record.find(' ', end_pos + 1);
			}

			infection.m_country = record.substr(start_pos, end_pos);
			record = record.substr(end_pos);
			start_pos = findNonWhiteSpace(record);
			record = record.substr(start_pos);

			start_pos = 0;
			end_pos = record.find(' ');

			if (record[end_pos + 1] != ' ') {
				end_pos = record.find(' ', end_pos + 1);
			}

			infection.m_city = record.substr(start_pos, end_pos);

			record = record.substr(end_pos);
			start_pos = findNonWhiteSpace(record);
			record = record.substr(start_pos);

			start_pos = 0;
			end_pos = record.find(' ');
			infection.m_variant = record.substr(start_pos, end_pos);


			record = record.substr(end_pos);
			start_pos = findNonWhiteSpace(record);
			record = record.substr(start_pos);
			infection.m_year = stoi(record);

			end_pos = record.find(' ');
			record = record.substr(end_pos);
			start_pos = findNonWhiteSpace(record);
			record = record.substr(start_pos);
			infection.m_cases = stoi(record);

			end_pos = record.find(' ');
			record = record.substr(end_pos);
			start_pos = findNonWhiteSpace(record);
			record = record.substr(start_pos);
			infection.m_deaths = stoi(record);

			m_infections.push_back(infection);
		}
	}
	void CovidCollection::display(std::ostream& out) const {
		size_t totalCases{};
		size_t totalDeaths{};
		for_each(m_infections.begin(), m_infections.end(), [=, &totalDeaths, &totalCases, &out](Covid n) -> void
			{
				totalCases += n.m_cases;
				totalDeaths += n.m_deaths;
				out << n << endl;
			});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| ";
		out.unsetf(ios::right);
		out.width(77);
		out << "Total Cases Around the World:";
		out.width(7);
		out << totalCases << " |" << endl;
		out << "| ";
		out.unsetf(ios::right);
		out.width(77);
		out << "Total Deaths Around the World:";
		out.width(7);
		out << totalDeaths << " |" << endl;
	}
	void CovidCollection::sort(std::string name) {
		if (name == "country") {
			std::sort(m_infections.begin(), m_infections.end(), [](const Covid cov1, const Covid cov2)
				{
					return cov1.m_country < cov2.m_country;
				});
		}
		else if (name == "variant") {
			std::sort(m_infections.begin(), m_infections.end(), [](const Covid cov1, const Covid cov2)
				{
					return cov1.m_variant < cov2.m_variant;
				});
		}
		else if (name == "cases") {
			std::sort(m_infections.begin(), m_infections.end(), [](const Covid cov1, const Covid cov2)
				{
					return cov1.m_cases < cov2.m_cases;
				});
		}
		else if (name == "deaths") {
			std::sort(m_infections.begin(), m_infections.end(), [](const Covid cov1, const Covid cov2)
				{
					return cov1.m_deaths < cov2.m_deaths;
				});
		}

	}

	void CovidCollection::cleanList() {
		for_each(m_infections.begin(), m_infections.end(), [=](Covid& cov) -> void
			{
				if (cov.m_variant == "[None]")
					cov.m_variant = "";
			});
	}
	bool CovidCollection::inCollection(string name) const {
		bool found = false;
		for_each(m_infections.begin(), m_infections.end(), [=, &found](Covid cov) -> void
			{
				if (cov.m_variant == name)
					found = true;
			});
		return found;
	}
	std::list<Covid> CovidCollection::getListForCountry(string name) const {
		list<Covid> l;
		for_each(m_infections.begin(), m_infections.end(), [=, &l](Covid cov) -> void
			{
				if (cov.m_country == name)
					l.push_back(cov);

			});
		return l;
	}
	std::list<Covid> CovidCollection::getListForVariant(string name) const {
		list<Covid> l;
		for_each(m_infections.begin(), m_infections.end(), [=, &l](Covid cov) -> void
			{
				if (cov.m_variant == name)
					l.push_back(cov);

			});
		return l;
	}
	ostream& operator<<(ostream& out, const Covid& theCovid) {
		out << "| ";
		out.unsetf(ios::right);
		out.setf(ios::left);
		out.width(21);
		out << theCovid.m_country;
		out << " | ";
		out.width(15);
		out << theCovid.m_city;
		out << " | ";
		out.width(20);
		out << theCovid.m_variant;
		out << " | ";
		out.unsetf(ios::left);
		out.setf(ios::right);
		out.width(6);
		theCovid.m_year < 0 ? out << ' ' : out << theCovid.m_year;
		out << " | ";
		out.width(4);
		out << theCovid.m_cases;
		out << " | ";
		out.width(3);
		out << theCovid.m_deaths;
		out << " |";
		out.unsetf(ios::right);
		return out;
	}
};