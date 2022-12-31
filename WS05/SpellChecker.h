//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-10-16
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>

const auto SIZE = 6;
namespace sdds
{
	class SpellChecker
	{
		std::string m_badwords[SIZE]{};
		std::string m_goodwords[SIZE]{};
		size_t m_count[SIZE]{};

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
