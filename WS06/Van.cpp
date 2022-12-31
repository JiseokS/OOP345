//Name: Jiseok Shim
//Student ID: 122758170
//Email: jshim13@myseneca.ca
//Date: 2022-11-06
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
#include <iomanip>
#include <iostream>
#include "Van.h"

using namespace std;
namespace sdds {
	Van::Van(){}
	Van::Van(std::istream& in)
	{
		std::string tag, type, condition, purpose, tspeed;
		extern string teg;
		getline(in, tag, ',');
		tag.erase(0, tag.find_first_not_of(" "));
		tag.erase(tag.find_last_not_of(" ") + 1);

		if (tag == "v" || tag == "V" || tag == "L" || tag == "l")
		{

			getline(in, v_maker, ',');
			v_maker.erase(0, v_maker.find_first_not_of(" "));
			v_maker.erase(v_maker.find_last_not_of(" ") + 1);


			getline(in, type, ',');
			type.erase(0, type.find_first_not_of(" "));
			type.erase(type.find_last_not_of(" ") + 1);
			if (type == "p")
			{
				v_type = "pickup";
			}
			else if (type == "m")
			{
				v_type = "mini-bus";
			}
			else if (type == "c")
			{
				v_type = "camper";
			}
			else
			{
				throw string("Invalid record!");
			}


			getline(in, purpose, ',');
			purpose.erase(0, purpose.find_first_not_of(" "));
			purpose.erase(purpose.find_last_not_of(" ") + 1);
			if (purpose == "d")
			{
				v_purpose = "delivery";
			}
			else if (purpose == "p")
			{
				v_purpose = "passenger";
			}
			else if (purpose == "c")
			{
				v_purpose = "camping";
			}
			else
			{
				throw string("Invalid record!");
			}

			getline(in, condition, ',');
			condition.erase(0, condition.find_first_not_of(" "));
			condition.erase(condition.find_last_not_of(" ") + 1);
			if (condition == "n" || condition == "N" || condition == "" || condition == " ")
				v_condition = "new";
			if (condition == "u" || condition == "U")
				v_condition = "used";
			if (condition == "b" || condition == "B")
				v_condition = "broken";
			if (v_condition != "new" && v_condition != "used" && v_condition != "broken")
				throw string("Invalid record!");

			getline(in, tspeed, ',');
			tspeed.erase(0, tspeed.find_first_not_of(" "));
			tspeed.erase(tspeed.find_last_not_of(" ") + 1);
			if (isdigit(*tspeed.c_str())) {
				v_top_speed = stod(tspeed);
			}
			else {
				throw string("Invalid record!");
			}


		}
		
	}
	std::string Van::condition() const
	{
		return v_condition;
	}
	double Van::topSpeed() const
	{
		return v_top_speed;
	}
	std::string Van::type() const
	{
		return v_type;
	}
	std::string Van::usage() const
	{
		return v_purpose;
	}
	void Van::display(std::ostream& out) const
	{
		out << "| " << setw(8) << right << v_maker << " | "
			<< setw(12) << left << v_type << " | "
			<< setw(12) << left << v_purpose << " | "
			<< setw(6) << left << v_condition << " | "
			<< setw(6) << setprecision(2) << v_top_speed << " |" << endl;
	}
}