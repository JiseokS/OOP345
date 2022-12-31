//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-10-16
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds
{
	Book::Book()
	{
		//default 
	}
	const std::string& Book::title() const
	{
		return Book_title;
	}
	const std::string& Book::country() const
	{
		return Book_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		std::string objBook = strBook;
		int pos = 0;

		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		author = objBook.substr(0, pos);
		author.erase(author.find_last_not_of(" ") + 1);

		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		Book_title = objBook.substr(0, pos);
		Book_title.erase(Book_title.find_last_not_of(" ") + 1);

		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		Book_country = objBook.substr(0, pos);
		Book_country.erase(Book_country.find_last_not_of(" ") + 1);

		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		m_price = std::stod(objBook.substr(0, pos));

		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		m_year = std::stoi(objBook.substr(0, pos));

		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		Book_description = objBook;


	}
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << setw(20) << right << book.author << " | " << setw(22) << book.Book_title << " | "
			<< setw(5) << book.Book_country << " | " << setw(4) << book.m_year << " | " << setw(6)
			<< fixed << setprecision(2) << book.m_price << " | " << book.Book_description << endl;
		return os;
	}
}