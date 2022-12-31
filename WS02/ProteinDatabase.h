/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-05-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef PROTEINDATABASE_H
#define PROTEINDATABASE_H
#include <string>

namespace sdds {
	class ProteinDatabase {
		std::string* protein_array{};

		size_t p_size = 0;

	public:
		ProteinDatabase();
		virtual ~ProteinDatabase();
		ProteinDatabase(const char *file_name);
		ProteinDatabase(const ProteinDatabase& src);
		ProteinDatabase& operator=(const ProteinDatabase& src);
		ProteinDatabase(ProteinDatabase&& src);
		ProteinDatabase& operator= ( ProteinDatabase&& src);
		size_t size()const;
		std::string operator[](size_t)const;
	private:
		void read(const char* file_name);
		void operator~();
	};
}
#endif // !PROTEINDATABASE_H

