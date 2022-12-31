//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-10-16
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <fstream>
#include "iomanip"
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		int pos = 0;
		int cnt = 0;
		std::string temp = {};
		std::ifstream fileIn(filename);

		if (fileIn.is_open() == false) {
			throw "Bad file name!";
		}
		else {
			for (auto i = 0; i < SIZE; i++) {
				getline(fileIn, temp);

				temp.erase(0, temp.find_first_not_of(" "));
				pos = temp.find(" ");
				m_badwords[cnt] = temp.substr(0, pos);


				temp.erase(0, pos + 1);
				temp.erase(0, temp.find_first_not_of(" "));
				pos = temp.find(" ");
				m_goodwords[cnt] = temp.substr(0, pos);

				++cnt;
			}
		}
	}
	void SpellChecker::operator()(std::string& text)
	{
		size_t found = 0;
		for (size_t i = 0; i < SIZE; i++)
		{
			while ((found = text.find(m_badwords[i])) != std::string::npos) {
				text.replace(found, m_badwords[i].length(), m_goodwords[i]);
				m_count[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (auto i = 0u; i < SIZE; i++)
		{
			out << setw(15) << right;
			out << m_badwords[i] << ": " << m_count[i] << " replacements\n";
		}
	}
}