//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-10-16
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book
	{
		std::string author{};
		std::string Book_title{};
		std::string Book_country{};
		size_t m_year{0};
		double m_price{0.0};
		std::string Book_description{};
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		//~Book();
		friend std::ostream& operator<<(std::ostream & os, const Book & book);

		template<typename T>
		//add in part2
		void fixSpelling(T& spellChecker)
		{
			spellChecker(Book_description);
		}
	};

}
#endif // !SDDS_BOOK_H
