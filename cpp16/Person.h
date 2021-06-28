#pragma once
#include <iostream>
#include <ostream>
class person
{
public:
	
	friend std::ostream& operator<< (std::ostream&, const person&);
private:
	std::string m_name;
	std::string m_id;
};

std::ostream& operator<< (std::ostream& out, const person& p)
{
	out << "name:" << p.m_name << '\t' << "Id:" << p.m_id << std::endl;
	return out;
}