#include "BitcoinExchange.hpp"

#define RED "\033[31m"
#define END "\033[0m"

Bitcoin::Bitcoin()
{
	// std::cout << "Constructor called!" << std::endl;
}

Bitcoin::Bitcoin(const Bitcoin &p)
{
	// std::cout << "Copy constructor called!" << std::endl;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &p)
{
	// std::cout << "Copy assignement operator called!" << std::endl;
	return *this;
}

Bitcoin::~Bitcoin()
{
	// std::cout << "Destructor called!" << std::endl;
}

void Bitcoin::DataBase(std::string dataBase)
{
	std::ifstream file(dataBase);
	std::string string;
	int check = 0;

	while(getline(file, string))
	{
		if (check != 0)
		{
			int pos = string.find(",");
			std::string str1 = string.substr(pos + 1);
			std::string str2 = string.substr(0, pos);
			m_DataBase.insert(make_pair(str2, std::atof(str1.c_str())));
		}
		check++;
	}
}

int Bitcoin::Checkdate(std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 9);

	float _year = std::atof(year.c_str());
	float _month = std::atof(month.c_str());
	float _day = std::atof(day.c_str());

	if (_year < 2009 || _year > 2022) 
		return (-1);
	if (_month < 1 || _month > 12)
		return (-1);
	if (_day < 1 || _day > 31)
		return (-1);
	return (0);
}

void Bitcoin::Input(std::string Input)
{
	std::ifstream file(Input);
	std::string string;
	int check = 0;

	while(42)
	{
		getline(file, string);
		if (string.size() == 0)
			break ;
		if (check != 0)
		{
			int pos = string.find("|");

			std::string str1 = string.substr(pos + 2);
			std::string str2 = string.substr(0, pos - 1);

			float value = std::atof(str1.c_str());

			if (value < 0)
				std::cout << RED << "Error: not a positive number." << END << std::endl;
			else if (value > 1000)
				std::cout << RED << "Error: too large a number." << END << std::endl;
			else if (pos == -1 || Checkdate(str2))
				std::cout << RED << "Error: bad input => " << str2 << END << std::endl;
			else
				std::cout << str2 << " => " << str1 << " = " << std::fixed << std::setprecision(2) << value * SearchDate(str2) << std::endl;
		}
		check++;
	}
}

float Bitcoin::SearchDate(std::string date)
{
	std::map<std::string, float>::iterator it;

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8,9);

	for(it=m_DataBase.begin(); it!=m_DataBase.end(); ++it){
		if (date == it->first)
			return (it->second);
   	}

	for(it=m_DataBase.begin();it!=m_DataBase.end();++it)
	{
		if (year == it->first.substr(0,4) && month == it->first.substr(5,2))
		{
			float float1 = std::stof(it->first.substr(8,9));
			float float2 = std::stof(day);
			if (float1 > float2)
			{
				it--;
				return (it->second);
			}
		}
	}
	return (0);
}
