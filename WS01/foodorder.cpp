/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-05-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include <string>
#include "foodorder.h"

double g_taxrate = 0.0, g_dailydiscount = 0.0;

using namespace std;
namespace sdds {
	FoodOrder::FoodOrder(){
		order_name[0] = '\0';
		food_price = 0.0;
		daily_speical = false;
	}
	FoodOrder::FoodOrder(const FoodOrder& src){
		operator =(src);
	
	}
	FoodOrder&FoodOrder:: operator=(const FoodOrder& src) {
		if (this != &src) {
			copy(food_description, src.food_description);
			strcpy(order_name, src.order_name);
			food_price = src.food_price;
			daily_speical = src.daily_speical;
		}
		return *this;
	}
	istream& FoodOrder::read(istream& is ) {
		if (is)
		{
			string read;
			is.getline(order_name, 10, ',');
			getline(is, read, ',');
			copy(food_description, read.c_str());
			is >> food_price;
			is.ignore();
			daily_speical = (is.peek() == 'Y') ? true : false;
			is.ignore(100, '\n');
		}
		return is;
	}
	ostream&FoodOrder::display(ostream& os )const {
		static int counter = 0;
		if (*this)
		{
			os.setf(ios::left);
			os.setf(ios::fixed);
			os.width(2);
			os << ++counter << ". ";
			os.width(10);
			os << order_name << "|";
			os.width(25);
			os << food_description << "|";
			os.width(12);
			os.precision(2);
			os << food_price *(1.0+ g_taxrate) << "|";
			os.unsetf(ios::left);
			if (daily_speical) {
				os.width(13);
				os << food_price*(1.0 +g_taxrate)- g_dailydiscount;
			}
			os << endl;
		}
		else
		{
			os.setf(ios::left);
			os.width(2);
			os << ++counter << ". ";
			os << "No Order" << endl;
			os.unsetf(ios::left);
		}
		return os;
	}
	FoodOrder::~FoodOrder() {
		delete[] food_description;
	}
	FoodOrder::operator bool()const {
		return order_name[0] ? true : false;
	}
	void FoodOrder::copy(char*& des, const char* src) {
		delete[] des;
		des = nullptr;
		des = new char[strlen(src) + 1];
		strcpy(des, src);

	}
}
