/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-05-29
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "ProteinDatabase.h"
#include <fstream>

namespace sdds{
	ProteinDatabase::ProteinDatabase() {

	}
	ProteinDatabase::~ProteinDatabase() {
		delete[] protein_array;
		protein_array = nullptr;
	}
	ProteinDatabase::ProteinDatabase(const char* file_name) {
		read(file_name);
	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
		*this = src;
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src) {
		if (this != &src)
		{
			~*this;
			p_size = src.p_size;
			protein_array = new std::string[p_size];
			for (size_t i = 0; i < p_size; i++)
			{
				protein_array[i] = src.protein_array[i];
			}

		}
		return *this;
	}
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) {
		*this = std::move(src);
	}
	ProteinDatabase& ProteinDatabase::operator= ( ProteinDatabase&& src) {
		if (this != &src)
		{
			p_size = src.p_size;
			protein_array = src.protein_array;
			src.protein_array = nullptr;
			src.p_size = 0;
		}
		return *this;
	}
	size_t ProteinDatabase::size()const {
		return p_size;
	}
	std::string ProteinDatabase::operator[](size_t index)const {
		std::string str = (index < p_size) ? protein_array[index] : "";
		return str;
	}
	void ProteinDatabase::read(const char* file_name) {
		std::ifstream ifstr(file_name);
		std::string temp;
		if (ifstr)
		{
			while (getline(ifstr, temp, '\n'))
			{
				if (temp[0] == '>') p_size++;
			}
			if (p_size > 0)
			{
				ifstr.clear();
				ifstr.seekg(0);
				protein_array = new std::string[p_size];

				int index = -1;
				while (getline(ifstr, temp, '\n'))
				{
					if (temp[0] == '>')
					{
						index++;
					}
					else {
						protein_array[index] += temp;
					}
				}
			}
		}
	}
	void ProteinDatabase::operator~() {
		delete[] protein_array;
		protein_array = nullptr;
		p_size = 0;
	}
}
