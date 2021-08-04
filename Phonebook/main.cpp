#include "Phonebook.h"
void show(Phonebook& pb)
{
	pb.showPerson();
}

void add(Phonebook& pb)
{
	string name, lastName, phone, city;

	std::cout << "Please type in your name,last name, phone, city:" << std::endl;
	std::cin >> name >> lastName >> phone >> city;
	Person p(name, lastName, phone, city);
	std::cout << "Would you like to save the new contact ?" << std::endl;
	if (!pb.addPerson(p))
	{
		pb.savePerson(p);
		std::cout << "The new contact has been successfully saved." << std::endl;
	}
	else
	{
		std::cout << "This contact already exists and was not saved successfully.." << std::endl;
	}
}


bool find(const Phonebook& pb, const string& name)//const
{
	std::vector<Person> ps = pb.findPersons(name);
	if (ps.empty())
	{
		std::cout << "Not found." << std::endl;
		return false;
	}
	else {
		sort(ps.begin(), ps.end());
		auto sit = ps.begin();
		while (sit != ps.end())
		{
			std::cout << *sit << std::endl;
			++sit;
		}
		return true;
	}
}

void deletePersonss(Phonebook& pb, const string& name)
{	
	if (find(pb, name)) {
		std::cout << "Do you want to delete these records?(Yes/No):";
		string yes;
		std::cin >> yes;
		if (yes[0] == 'y' || yes[0] == 'Y')
		{
			pb.deletePersons(name);
			pb.save();
			std::cout << "successfully deleted." << std::endl;
		}
		else
			std::cout << "failed to delete." << std::endl;
	}
}


int main(int argc, char** argv)
{
	bool validShow = argc == 2 && std::string(argv[1]) == "-show";
	bool validFind = argc == 3 && std::string(argv[1]) == "-find";
	bool validAdd = argc == 2 && std::string(argv[1]) == "-add";
	bool validDelete = argc == 3 && std::string(argv[1]) == "-delete";
	bool ok = validShow || validFind || validAdd || validDelete;

	if (!ok)
	{
		std::cout << "Please enter the correct command."
			<< "\nEnter -find findname or -show or -add or -delete" << std::endl;
	}

	Phonebook pb("C:/Users/Administrator/Desktop/phonebook.txt");
	pb.load();

	if (validShow)
	{
		show(pb);
	}
	else if (validFind)
	{
		find(pb, argv[2]);
	}
	else if (validAdd)
	{
		add(pb);
	}
	else if (validDelete)
	{
		deletePersonss(pb, argv[2]);
	};	
	return 0;
}