//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-10-16
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

using namespace std;

namespace sdds
{
	Movie::Movie() 
	{
		//default
	}
	const std::string& Movie::title() const 
	{
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) 
	{
		std::string objMovie = strMovie;
		int pos = 0;

		
		objMovie.erase(0, objMovie.find_first_not_of(" "));
		pos = objMovie.find(",");
		m_title = objMovie.substr(0, pos);
		m_title.erase(m_title.find_last_not_of(" ") + 1);

		
		objMovie.erase(0, pos + 1);
		objMovie.erase(0, objMovie.find_first_not_of(" "));
		pos = objMovie.find(",");
		release_year = std::stoi(objMovie.substr(0, pos));

		objMovie.erase(0, pos + 1);
		objMovie.erase(0, objMovie.find_first_not_of(" "));
		Movie_description = objMovie;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& src)
	{
		os << setw(40) << right << src.m_title << " | ";
		os << left << setw(4) << src.release_year << " | " << src.Movie_description << "\n";

		return os;
	}
}