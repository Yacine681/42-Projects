#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class Bitcoin {

	private:
	std::map<std::string,float>m_DataBase;

	public:
	Bitcoin();
	Bitcoin(const Bitcoin &p);
	Bitcoin &operator=(const Bitcoin &p);
	~Bitcoin();

	void DataBase(std::string DataBase);
	void Input(std::string Input);
	void Search(void);

	float SearchDate(std::string date);

	int  Checkdate(std::string date);

};

#endif
