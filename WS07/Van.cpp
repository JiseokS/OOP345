#include <iostream>
#include <fstream>
#include <iomanip>
#include "Van.h"

using namespace std;

namespace sdds
{
	Van::Van(){}
	Van::Van(std::istream& in) 
	{
		std::string temp, tag, type, condition, purpose, topspeed;
		/*int pos;
		getline(in, temp, '\n');

		temp.erase(0, temp.find_first_not_of(" "));
		pos = temp.find(",");
		tag = temp.substr(0, pos);
		tag.erase(tag.find_last_not_of(" ") + 1);*/

		getline(in, tag, ',');
		tag.erase(0, tag.find_first_not_of(" "));
		tag.erase(tag.find_last_not_of(" ") + 1);

		if (tag == "v" || tag == "V" || tag == "L" || tag == "l")
		{
			/*temp.erase(0, pos + 1);
			temp.erase(0, temp.find_first_not_of(" "));
			pos = temp.find(",");
			m_maker = temp.substr(0, pos);
			m_maker.erase(m_maker.find_last_not_of(" ") + 1);*/

			getline(in, m_maker, ',');
			m_maker.erase(0, m_maker.find_first_not_of(" "));
			m_maker.erase(m_maker.find_last_not_of(" ") + 1);

			/*temp.erase(0, pos + 1);
			temp.erase(0, temp.find_first_not_of(" "));
			pos = temp.find(",");
			type = temp.substr(0, pos);
			type.erase(type.find_last_not_of(" ") + 1);*/

			getline(in, type, ',');
			type.erase(0, type.find_first_not_of(" "));
			type.erase(type.find_last_not_of(" ") + 1);
			if (type == "p")
			{
				m_type = "pickup";
			}
			else if (type == "m")
			{
				m_type = "minibus";
			}
			else if (type == "c")
			{
				m_type = "camper";
			}
			else
			{
				throw string("Invalid record!");
			}

			/*temp.erase(0, pos + 1);
			temp.erase(0, temp.find_first_not_of(" "));
			pos = temp.find(",");
			purpose = temp.substr(0, pos);
			purpose.erase(purpose.find_last_not_of(" ") + 1);*/

			getline(in, purpose, ',');
			purpose.erase(0, purpose.find_first_not_of(" "));
			purpose.erase(purpose.find_last_not_of(" ") + 1);
			if (purpose == "d")
			{
				m_purpose = "delivery";
			}
			else if (purpose == "p")
			{
				m_purpose = "passenger";
			}
			else if (purpose == "c")
			{
				m_purpose = "camping";
			}
			else
			{
				throw string("Invalid record!");
			}
			/*temp.erase(0, pos + 1);
			temp.erase(0, temp.find_first_not_of(" "));
			pos = temp.find(",");
			condition = temp.substr(0, pos);
			condition.erase(condition.find_last_not_of(" ") + 1);*/

			getline(in, condition, ',');
			condition.erase(0, condition.find_first_not_of(" "));
			condition.erase(condition.find_last_not_of(" ") + 1);
			if (condition == "n" || condition == "N" || condition == "" || condition == " ")
				m_condition = "new";
			if (condition == "u" || condition == "U")
				m_condition = "used";
			if (condition == "b" || condition == "B")
				m_condition = "broken";
			if (m_condition != "new" && m_condition != "used" && m_condition != "broken")
				throw string("Invalid record!");
			/*temp.erase(0, pos + 1);
			temp.erase(0, temp.find_first_not_of(" "));*/


			getline(in, topspeed, ',');
			topspeed.erase(0, topspeed.find_first_not_of(" "));
			topspeed.erase(topspeed.find_last_not_of(" ") + 1);
			if (isdigit(*topspeed.c_str())) {
				top_speed = stod(topspeed);
			}
			else {
				throw string("Invalid record!");
			}
		}
	}
	std::string Van::condition() const 
	{
		return m_condition;
	}
	double Van::topSpeed() const 
	{
		return top_speed;
	}
	std::string Van::type() const 
	{
		return m_type;
	}
	std::string Van::usage() const
	{
		return m_purpose;
	}
	void Van::display(std::ostream& out) const
	{
		out << "| " << setw(8) << right << m_maker << " | "
			<< setw(12) << left << m_type << " | "
			<< setw(12) << left << m_purpose << " | "
			<< setw(6) << left << m_condition << " | "
			<< setw(6) << setprecision(2) << top_speed << " |";
	}
}
