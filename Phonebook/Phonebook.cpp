#include "Phonebook.h"
Person::Person(const string& name, const string& lastName, const string& phone,
	const string& city) :m_name(name), m_lastName(lastName), m_phone(phone), m_city(city)
{}

Person::Person(const Person& rhs) : m_name(rhs.m_name),
m_lastName(rhs.m_lastName), m_phone(rhs.m_phone), m_city(rhs.m_city)
{}

Person& Person::operator=(const Person& rhs)
{
	m_name = rhs.m_name;
	m_lastName = rhs.m_lastName;
	m_phone = rhs.m_phone;
	m_city = rhs.m_city;
	return *this;
}

const bool operator<(const Person& a, const Person& b)
{
	if (a.m_name == b.m_name) return a.m_phone < b.m_phone;
	return a.m_name < b.m_name;
}

inline bool operator==(const Person& lhs, const Person& rhs)
{
	return lhs.m_name == rhs.m_name && lhs.m_lastName == rhs.m_lastName
		&& lhs.m_phone == rhs.m_phone && lhs.m_city == rhs.m_city;
}

std::ostream& operator<<(std::ostream& out, Person& pa)
{
	out << "name: " << pa.m_name << "\tlastname: " << pa.m_lastName
		<< "\tphone: " << pa.m_phone << "\tcity: " << pa.m_city << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Person& pb)
{
	std::cout << "Please cin" << std::endl;
	in >> pb.m_name >> pb.m_lastName >> pb.m_phone >> pb.m_city;
	return in;
}


void Phonebook::load()
{
	string line;
	std::ifstream ifs;
	ifs.open(m_path);
	if (!ifs)
	{
		std::cout << "cannot open file!" << std::endl;
		return;
	}
	while (getline(ifs, line))
	{
		Person info;
		std::istringstream record(line);
		string name, lastName, phone, city;
		record >> name >> lastName >> phone >> city;
		info.setName(name);
		info.setLastName(lastName);
		info.setPhone(phone);
		info.setCity(city);
		m_persons.push_back(info);
	}
	ifs.close();
}

void Phonebook::save()
{
	std::fstream ofs;
	ofs.open(m_path, std::ios::out | std::ios::trunc);
	if (!ofs)
	{
		std::cout << "cannot open file!" << std::endl;
		return;
	}

	auto itp = m_persons.begin();
	for (; itp != m_persons.end(); ++itp)
	{
		ofs << (*itp).getName() << " " << (*itp).getLastName() << " "
			<< (*itp).getPhone() << " " << (*itp).getCity() << std::endl;
	}
	ofs.close();
}

void Phonebook::savePerson(const Person& ps)
{
	std::fstream ofs;
	ofs.open(m_path, std::ios::out | std::ios::app);
	if (!ofs)
	{
		std::cout << "cannot open file!" << std::endl;
		return;
	}
	ofs << ps.getName() << " " << ps.getLastName() << " "
		<< ps.getPhone() << " " << ps.getCity() << std::endl;

	ofs.close();
}

void Phonebook::showPerson()
{
	sort(m_persons.begin(), m_persons.end());
	auto it = m_persons.begin();
	while (it != m_persons.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

std::vector<Person> Phonebook::findPersons(const string& key) const
{
	std::vector<Person> result;
	auto it = m_persons.cbegin();
	for (; it != m_persons.cend(); ++it)
	{
		string::size_type idx;
		idx = ((*it).getName()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			continue;
		}

		idx = ((*it).getLastName()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			continue;
		}

		idx = ((*it).getCity()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			continue;
		}

		idx = ((*it).getPhone()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			continue;
		}
	}
	return result;
}

std::vector<Person> Phonebook::deletePersons(const string& key)
{
	std::vector<Person> result;
	auto it = m_persons.begin();
	while (it != m_persons.end())
	{
		string::size_type idx;
		idx = ((*it).getName()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			it = m_persons.erase(it);
			continue;
		}

		idx = ((*it).getLastName()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			it = m_persons.erase(it);
			continue;
		}

		idx = ((*it).getCity()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			it = m_persons.erase(it);
			continue;
		}

		idx = ((*it).getPhone()).find(key);
		if (idx != string::npos)
		{
			result.push_back(*it);
			it = m_persons.erase(it);
			//	m_persons.erase(it);
			//	--it;
			continue;
		}
		++it;
	}
	return m_persons;
}


bool Phonebook::addPerson(const Person& ps)
{
	auto it = m_persons.begin();
	auto result = false;
	for (; it != m_persons.end(); ++it)
	{
		if (*it == ps) {
			result = true;
			break;
		}
	}
	return result;
}