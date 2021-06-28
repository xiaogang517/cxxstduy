#include "template.h"
#include "Person.h"
void f1()
{
	short si;
	std::cout << "\n\tabs(false)is:\t" << abs(false) << '\n';
	std::cout << "\n\tabs(-3)is:\t" << abs(-3) << '\n';
	std::cout << "\n\tabs(-8.6)is:\t" << abs(-8.6) << '\n';
	std::cout << "\n\tcompare(-5,8)is:\t" << compare(-5, 8) << '\n';
	std::cout << "\n\tcompares(si,1024)is:\t" << compares(si, 1024) << '\n';
	
}
void f2()
{
	//cout
	std::cout << "Test of testostream(cout,6):\t";
	testostream(std::cout, 6);
	std::cout << "\nTest of testostream(cout,true):\t";
	testostream(std::cout, true);
	std::cout << "\nTest of testostream(cout,8.6):\t";
	testostream(std::cout, 8.6);
	std::cout << "\nTest of testostream(cout,Good):\t";
	testostream(std::cout, "Good!");
	std::cout << std::endl;

	//ostream
	std::ofstream outfile;
	outfile.open("C:/Users/Administrator/Desktop/1.txt");
	assert(outfile);
	if (!outfile)
	{
		return ;
	}
	std::cout << "\n\tTest of ofstream,Please check the file just create.\n";
	testostream(outfile, "\n\Test of testostream(outfile,6):\t");
	testostream(outfile, 6);
	testostream(outfile, "\n\Test of testostream(outfile,true):\t");
	testostream(outfile, true);
	testostream(outfile, "\n\Test of testostream(outfile,8.6):\t");
	testostream(outfile, 8.6);
	testostream(outfile, "\n\Test of testostream(outfile,\"Good!\"):\t");
	testostream(outfile, "Good!");
	outfile.close();
	std::cout << std::endl;

	//stringstream
	std::stringstream oss;
	std::cout << "\n Test of testostream(oss,6)/(oss,true)/(oss,8.6)/(oss,\"Good!\"):" << '\n';
	testostream(oss, 6);
	testostream(oss, "\n");
	testostream(oss, true);
	testostream(oss, "\n");
	testostream(oss, 8.6);
	testostream(oss, "\n");
	testostream(oss, "Good!");
	testostream(oss, "\n");
	std::cout << oss.str() << std::endl;
}

void f9()
{
	int ia[] = { 1,2,3,4,5,6,7 };
	std::string  sa[] = { "this","is","my","test","example" };
	std::vector<int> ivec(ia,ia+7);
	std::vector<std::string> svec(sa, sa + 5);
	std::vector<int>::iterator iit;
	if ((iit = findelem(ivec.begin(), ivec.end(), 4)) != ivec.end())
		std::cout << "found this element:  " << *iit << std::endl;
	else
		std::cout << "no such element" << std::endl;

	std::vector<std::string>::iterator sit;
	if ((sit = findelem(svec.begin(), svec.end(), "test")) != svec.end())
		std::cout << "found this element:  " << *sit << std::endl;
	else
		std::cout << "no such element" << std::endl;
}

void f12()
{
	int ia[] = { 1,5,1,2,5,2,7,9,5,6,4,6,8,1,5,6,8,3,9,8,7,5,6,1,2,4,5,6,8 };
	int cnt = sizeof(ia) / sizeof(int);
	std::cout << "cnt:" << cnt << std::endl;
	std::vector<int> ivec(ia, ia + cnt);
	std::cout << "most find element is:" << findMost(ivec.begin(), ivec.end()) << std::endl;
}

void f13()
{
	int ia[] = { 1,2,3,4,5,6,7 };
	std::string  sa[] = { "this","is","my","test","example" };
	std::vector<int> ivec(ia, ia + 7);
	std::vector<std::string> svec(sa, sa + 5);
	print(ivec);
	std::cout << std::endl;
	print(svec);
	std::cout << std::endl;
	array_init(ia);
	std::cout << std::endl;
	array_init(sa);
	std::cout << std::endl;
}

void f24()
{
	short sval = 123;
	int ival = 1024;
	std::cout << compare(static_cast<int>(sval), ival) << std::endl;
	std::cout << compare(sval, static_cast<short>(ival)) << std::endl;
	std::cout << compare<short>(sval, ival) << std::endl;
	std::cout << compare<int>(sval, ival) << std::endl;
	std::cout << compare<std::string>("Mary","mac") << std::endl;
}

/*void f27()
{
	int ia1[] = { 1, 2, 3, 4, 5, 6, 7 };
	int ia2[] = { 1, 2, 3, 4 };
	int ia3[] = { 1, 2, 2, 4, 5, 6, 7 };
	std::vector<int> ivec1(ia1, ia1 + 7);
	std::vector<int> ivec2(ia2, ia1 + 4);
	std::vector<int> ivec3(ia3, ia1 + 7);
	int m;
	
	if (median(ivec1, m))
	{
		std::cout << "median: " << m << std::endl;
	}
	else {
		std::cout << "no median" << std::endl;
	}

	if (median(ivec2, m))
	{
		std::cout << "median: " << m << std::endl;
	}
	else {
		std::cout << "no median" << std::endl;
	}

	if (median(ivec3, m))
	{
		std::cout << "median: " << m << std::endl;
	}
	else {
		std::cout << "no median" << std::endl;
	}
}*/

void t1()
{
	int x[42];
	double y[10];
	array_init(x); // instantiates array_init(int(&)[42] 
	array_init(y);
	int a = 42;
	int* p1 = new int[a];
	int v1 = sizeof(x) / sizeof(x[0]);
	int v2 = sizeof(p1) / sizeof(p1[0]);
	int v3 = sizeof(y) / sizeof(y[0]);
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
}

void t2()
{
	/*	Test t1(10);
	Person P1;
	P1.printTest(t1);*/
	C<int> c1;
	C<double> c2;
	B<int> b1(100);
	B<double> b2(1000);
	A<int> a1;
	A<double> a3;
	A<B<int>> a2;
	a1.printTest(b1);
	a2.printTest(12);
	a3.printTest(2.6);
	c1.printTest(b1);
	c2.printTest(b2);
}

void t3()
{
	
	Person1<std::string, int> p1("Jack", 21);
	Person1<std::string, double> p2("Jack", 21.5);
	print(p1);
	print(p2);
}

void t4()
{
	Person2<std::string, std::string, int> p1("421022199409107558", "Anna", 24);
	p1.print(p1);
}

void t5()
{
	Q q1;
	const Q cq1;
	int* r = q1.front();
	//int* r1 = cq1.front();
	const int* cr = cq1.front();
	const int* cr1 = q1.front();
	q1.front();
	cq1.front();
	
}

void t6()
{
	Queue<int> q1;
	for (int ix = 0; ix != 10; ++ix)
		q1.push(ix);
	Queue<int> q2(q1);
	std::cout << q1 << std::endl;
	std::cout << q2 << std::endl;
	std::cout << std::endl;
	for (int ix = 0; ix != 10; ++ix)
	{
		
		int i = q1.front();
		if (i != ix)
			std::cout << "something's wrong! i = " << i << "ix = " << ix << '\n';
		//q1.pop();
	}
	Queue<int> qi;
	qi.setValues(2, 3);
	Queue<std::string> qs;
	qs.setValue(3);
	qs.setValues("sdf",2);
}


void t7()
{
	Queue<person> qp ;
	std::cout << qp;
}

int main()
{
	
	t7();
	return 0;
}


