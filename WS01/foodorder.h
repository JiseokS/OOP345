/*
Name: Jiseok Shim
StudentID: 122758170
Email: jshim13@myseneca.ca
Section: OOP345NBB
Date: 2022-05-22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <iostream>
extern double g_taxrate, g_dailydiscount;
namespace sdds {
	class FoodOrder {
		char order_name[10];
		char* food_description{};
		double food_price;
		bool daily_speical;
	public:
		FoodOrder();
		FoodOrder(const FoodOrder& src);
		FoodOrder& operator=(const FoodOrder& src);
		std::istream& read(std::istream& is = std::cin);
		std::ostream& display(std::ostream& os = std::cout)const;
		~FoodOrder();
	private:
		operator bool()const;
		static void copy(char*& des, const char* src);
	};

}

#endif // !SDDS_FOODORDER_H
