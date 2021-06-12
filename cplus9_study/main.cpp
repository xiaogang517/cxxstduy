#include <iostream>
#include <list>
#include <vector> 
void f1()
{
    std::list<int> ilist(10, 42);
    for (size_t ix = 0; ix != 5; ++ix)
        ilist.push_back(ix);
    std::cout << ilist.size() << std::endl;
    for (std::list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
    {
        std::cout << *it << '\t';
    }
    std::cout << std::endl;
    ilist.resize(15);
    for (size_t ix = 0; ix != 5; ++ix)
        ilist.push_front(ix);
    std::cout << ilist.size() << std::endl;
    for (std::list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
    {
        std::cout << *it << '\t';
    }
    std::cout << std::endl;
}
void f2()
{
    std::vector<std::string> svec;
    std::cout << svec.size() << std::endl;
    std::cout << svec.capacity() << std::endl;

    svec.push_back("1st");
    std::cout << svec.size() << std::endl;
    std::cout << svec.capacity() << std::endl;

    svec.push_back("No2");
    std::cout << svec.size() << std::endl;
    std::cout << svec.capacity() << std::endl;

    svec.insert(svec.end(), 10, "Anna");
    std::cout << svec.size() << std::endl;
    std::cout << svec.capacity() << std::endl;
    for (std::vector<std::string>::iterator it = svec.begin(); it != svec.end(); ++it)
    {
        std::cout << *it << '\t';
    }
    std::cout << std::endl;
}

void f3()
{
    std::vector<int> ivec1;
    for (int i = 1; i <= 15; i++) ivec1.push_back(i);
    std::vector<int> ivec2;
    for (int i = 16; i <= 30; i++) ivec2.push_back(i);
 /*   for (std::vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
    {
        std::cout << *it << '\t';
    }*/
    //ivec1 = ivec2;
    ivec1.swap(ivec2);
    std::vector<int>::iterator it = ivec1.begin();
    while (it != ivec1.end())
    {
        std::cout << *it << '\t';
      //  it = ivec1.insert(it, 42);
        ++it;        
    }    
    std::vector<int>::iterator it2 = ivec2.begin();
    while (it2 != ivec2.end())
    {
        std::cout << *it2 << '\t';
        //  it = ivec1.insert(it, 42);
        ++it2;
    }
    std::cout << '\n';
    ivec1.assign(ivec2.begin(), ivec2.end());
    std::vector<int>::iterator it1 = ivec1.begin();
    while (it1 != ivec1.end())
    {
        std::cout << *it1 << '\t';
        //  it = ivec1.insert(it, 42);
        ++it1;
    }
}

void f4()
{
    std::string sarray[4] = { "quasi", "simba", "frollo", "scar" };
    std::list<std::string> slist;
    std::list<std::string>::iterator slist_iter = slist.begin();
    
    slist.insert(slist_iter, sarray + 2, sarray + 4);
    for (slist_iter = slist.begin(); slist_iter != slist.end(); ++slist_iter)
    {
        std::cout << *slist_iter << '\t';
    }
    std::cout << std::endl;
    slist.insert(slist.end(), sarray, sarray + 4);
    for (slist_iter = slist.begin(); slist_iter != slist.end(); ++slist_iter)
    {
        std::cout << *slist_iter << '\t';
    }
    std::cout << '\n';
    slist.assign(10, "baby");
    for (slist_iter = slist.begin(); slist_iter != slist.end(); ++slist_iter)
    {
        std::cout << *slist_iter << '\t';
    }
    std::cout << '\n';
}

void f5()
{
    std::vector<int> myvector(14);  
    int i = 0;

    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit != myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (std::vector<int>::reverse_iterator rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
        std::cout << ' ' << *rit;
    std::cout << '\n';

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void f6()
{
    std::vector<int> ivec;
    // size should be zero; capacity is implementation defined
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;
    // give ivec 24 elements 
    for (std::vector<int>::size_type ix = 0; ix != 124; ++ix)
        ivec.push_back(ix);
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;

    ivec.reserve(150); // sets capacity to at least 50; might be more 
 // size should be 24; capacity will be >= 50 and is implementation 
    
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;
    std::cout << "begin()it0: " << (&(ivec[0])) << std::endl;
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    // size should be 50; capacity should be unchanged 
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;
    std::cout << "begin()it1: " << (&(ivec[0])) << std::endl;
    ivec.push_back(42); // add one more element 
 // size should be 51; capacity will be >= 51 and is implementation 
    std::cout << "begin()it2: " << (&(ivec[0])) << std::endl;
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;
}

void f7()
{
    std::vector<int> ivec(10);
    std::cout << ivec.size() << '\n';
   // ivec.resize(5);
    std::cout << ivec.size() << '\n';
    ivec.reserve(5);
    std::cout << ivec.size() << '\n';
}
int main()
{


    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    std::cout << "Hello, Wandbox!" << std::endl;
}