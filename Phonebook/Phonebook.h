#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::string;
class Person
{
public:
	Person() {};
	Person(const string& name, const string& lastname,
		const string& phone, const string& city);
	Person(const Person& rhs);
	Person& operator=(const Person& rhs);
	~Person() {};
	friend std::ostream& operator<<(std::ostream& out, Person& pa);
	friend std::istream& operator>>(std::istream& in, Person& pb);
	friend const bool operator<(const Person& a, const Person& b);
	friend bool operator==(const Person& lhs, const Person& rhs);
	string getName() const { return m_name; }
	string getLastName() const { return m_lastName; }
	string getPhone() const { return m_phone; }
	string getCity() const { return m_city; }
	void setName(const string& name) { m_name = name; }
	void setLastName(const string& lastName) { m_lastName = lastName; };
	void setPhone(const string& phone) { m_phone = phone; };
	void setCity(const string& city) { m_city = city; };
private:
	string m_name;
	string m_lastName;
	string m_phone;
	string m_city;
};

class Phonebook
{
	std::vector<Person>  m_persons;
	string m_path;

public:
	Phonebook(const string& path) :m_path(path) {};
	std::vector<Person> getPersons() const
	{
		return m_persons;
	}
	void load();
	void save();
	void savePerson(const Person& ps);
	void showPerson();
	bool addPerson(const Person& ps);
	std::vector<Person> findPersons(const string& key) const;
	std::vector<Person> deletePersons(const string& key);
};