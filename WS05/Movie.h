//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-10-16
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t release_year{};
		std::string Movie_description{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(Movie_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& src);
	};
}
#endif // !SDDS_MOVIE_H
