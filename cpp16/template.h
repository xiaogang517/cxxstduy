#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include <algorithm>
using std::vector;
template <typename T> 
inline T abs(T tval)
{
	return tval > 0 ? tval : -1 * tval;
}

template <typename T> 
int compare(const T& v1, const T& v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

template <typename A, typename B> 
int compares(const A& v1, const B& v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

template <typename T> 
inline void testostream(std::ostream& os, T tval)
{
	os << tval;
}

template <typename T >  
typename T::value_type findMost(T first, T last)

{
    std::size_t amount = 0;
    T start = first;
    while (start != last)
    {
        amount++;
        start++;
    }

    typedef std::vector<typename T::value_type> VecType;

    VecType vec(amount);
    typename VecType::iterator newFirst = vec.begin();
    typename VecType::iterator newLast = vec.end();

    std::uninitialized_copy(first, last, newFirst);
    std::sort(newFirst, newLast);  // 对副本序列排序，使得相同的值出现在相邻位置
    std::size_t maxOccu = 0, occu = 0; // 出现最频繁的次数，当前值的出现次数
    typename VecType::iterator preIter = newFirst; //指向当前值的前一个值
    typename VecType::iterator maxOccuElement = newFirst; // 指向当前出现最频繁的值
    while (newFirst != newLast)
    {
        if (*newFirst != *preIter)  // 当前值与前一值不同
        {
            if (occu > maxOccu)                  // 当前值的出现次数为目前最大次数
            {
                maxOccu = occu;                    // 修改最大次数
                maxOccuElement = preIter;    // 修改指向当前出现最频繁的值的迭代器
            }
            occu = 0;
        }
        ++occu;
        preIter = newFirst;
        ++newFirst;
    }
    // 最后一个值的出现次数与目前的最大次数进行比较

    if (occu > maxOccu)
    {
        maxOccu = occu;
        maxOccuElement = preIter;
    }
    return*maxOccuElement;
}

template <typename T, std::size_t N> 
void array_init(T(&parm)[N])
{
    for (std::size_t i = 0; i != N; ++i) {
        std::cout << parm[i] << " ";
    }
}

/*template <class T> class A;
template <class T> class B {
public:
    friend class A<T>; // ok: A is known to be a template 
    friend class C; // ok: C must be an ordinary, nontemplate class
    template <class> friend class D; // ok: D is a template 
    //friend class E<T>; // error: E wasn't declared as a template
    //friend class F<int>; // error: F wasn't declared as a template
};*/

class Test {
public:
    Test(int a):m_t(a) {  }

protected:
    int m_t;
  //  friend class Person;

};
class Person:public Test {
public:
    Person() :Test(0) { m_t = 100; }
    void printTest(const Test& t)
    {
        //std::cout << t.m_t << std::endl;
    }

};

/*template <typename S> class B;
template <typename T> class A
{
public:
   
    void printTest(const B<T>& b)
    {
        std::cout << b.m_t << std::endl;
    }
    template <typename S>
    void printTest2(const B<S>& b)
    {
        std::cout << b.m_t << std::endl;
    }
};

template <typename T> class B {
public:
    B(int a):m_t(a){}
    //friend class A<T>;
    template <typename S> friend class A;
private:
    int m_t;
};*/



template <typename T> class B {
public:
    B(double a):m_t(a) { }
    template <typename S> friend class A;
    template <typename S> friend class C;
    friend class Test;
private:
    double m_t;
};

template <typename T> class A
{
public:
    void printTest(const B<T>& b)
    {
        std::cout << b.m_t << std::endl;
    }
};

template <typename T> class C
{

public:
    void printTest(const B<T>& b)
    {
        std::cout << b.m_t << std::endl;
    }
};

template <typename N,typename A>
class Person1 {
    friend void print(Person1<N, A> p)
    {
        std::cout << "name:" << p.m_name << "\tAge:" << p.m_age << '\n';
    }
public:
    Person1(N name, A age):m_name(name),m_age(age){}
private:
    N m_name;
    A m_age;
};

template <typename I,typename N, typename A>
class Person2
{
public:
    Person2(I id, N name,A age):m_id(id),m_name(name),m_age(age){}
    void print(const Person2<I,N, A>& p)
    {
        std::cout << "ID:" << p.m_id <<"\tname:" << p.m_name << "\tAge:" << p.m_age << '\n';
    }
private:
    I m_id;
    N m_name;
    A m_age;
};



template <class Type> class Queue;

template <class T>
std::ostream& operator<< (std::ostream&, const Queue<T>&);

template <class T>
std::ostream& operator>> (std::istream&,Queue<T>&);

template <class Type> class QueueItem {
    friend class Queue<Type>;
    friend std::ostream& operator<< <Type> (std::ostream&, const Queue<Type>&);
    friend std::istream& operator>> <Type> (std::istream&, Queue<Type>&);
    QueueItem(const Type& t) : item(t), next(0) { }
    Type item; 
    QueueItem* next;  
};
template <class Type> 
class Queue {
    friend std::ostream&
        operator<< <Type> (std::ostream&, const Queue<Type>&);
    friend std::istream&
        operator>> <Type> (std::istream&, Queue<Type>&);
public:
    Queue() : head(0), tail(0) { }
    template <class It>
    Queue(It beg, It end) : head(0), tail(0)
    {
        copy_elems(beg, end);
    }
    Queue(const Queue& Q) : head(0), tail(0)
    {
        copy_elems(Q);
    }

    Queue& operator=(const Queue&);

    ~Queue()
    {
        while (!empty())
        {
            QueueItem<Type>* p = head;
            head = head->next;
            delete p;
        }
    }

    Type& front()
    {
        return head->item;
        std::cout << "no const" << std::endl;
    }

    const Type& front() const
    {
        return head->item;
        std::cout << "const" << std::endl;
    }
    void push(const Type&);
    void pop();
    bool empty() const {
        return head == 0;
    }
    void setValue(int);
    void setValues(const Type&, int);

    int compare(const Type& v1, const Type& v2); 
    
    template <typename T>
    int compares(const T& v1, const T& v2)
    {
        if (v1 < v2) return -1;
        if (v2 < v1) return 1;
        return 0;
    }
    
private:
    QueueItem<Type>* head;
    QueueItem<Type>* tail;
    Type m_t;
    void destroy(); 
    void copy_elems(const Queue&);
};

template <class Type>
void Queue<Type>::setValue(int a)
{
    m_t = a;
}

template <class Type>
void Queue<Type>::setValues(const Type& i, int a) {
    m_t = a;
}

template <class Type> void Queue<Type>::push(const Type& val)
{    
    QueueItem<Type>* pt = new QueueItem<Type>(val);
    if (empty())
        head = tail = pt;
    else {
        tail->next = pt;
        tail = pt;
    }
}

template <class Type>
void Queue<Type>::copy_elems(const Queue& orig)
{
    for (QueueItem<Type>* pt = orig.head; pt; pt = pt->next)
        push(pt->item);
}

template <class Type> 
void Queue<Type>::destroy()
{
    while (!empty())
        pop();
}

template <class Type> 
void Queue<Type>::pop()
{
    QueueItem<Type>* p = head; 
    head = head->next;
    delete p;
    
}

template <typename Type>
int  Queue<Type>::compare(const Type& v1, const Type& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <typename Type> 
std::ostream& operator<< (std::ostream& os, const Queue<Type>& q)
{
    os << "<";
    QueueItem<Type>* p;
    for (p = q.head; p; p = p->next)
    {
        os << p->item << " ";
    }
    os << ">";
     return os;
}


template <typename Type>
std::istream& operator>> (std::istream& is, Queue<Type>& q)
{
    Type val;
    while (is >> val)
    {
        q.push(val);
    }
    return is;
}

template <typename Type>
Queue<Type>& Queue<Type>::operator= (const Queue& orig)
{
    QueueItem<Type>* p = orig.head;
    QueueItem<Type>* q;
    while (p != 0)
    {
        q = new QueueItem<Type>(p->item);
        if (p == orig.head)
        {
            head = tail = q;
        }
        tail->next = q;
        tail = q;
        p = p->next;
    }
    return *this;
}



template <typename InIt, typename T>
InIt findelem(InIt first, InIt last, const T& val)
{
    while (first != last)
    {
        if ((*first) == val)
        {
            return first;
        }
        ++first;
    }
    return last;
}

template <typename Parm>
void print(const Parm& c)
{
    typename Parm::size_type index = 0;
    while (index != c.size())
    {
        std::cout << c[index] << " ";
        ++index;
    }
}

template <typename Parm>
void print1(const Parm& c)
{
    typename Parm::const_iterator iter;
    for(iter = c.begin(); iter != c.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
}

/*template <typename T>
bool median(const std::vector<T>& c, T& m)
{
    std::vector<T> tmep(c);
    if (temp.size() % 2 == 0)//如果容器中包含偶数个元素，则没有中间值，返回FALSE
        return false;
    sort(temp.begin(), temp.end());//元素排序
    vector<T>::size_type index = temp.size() / 2;
    if (temp[index] > temp[index - 1] && temp[index] < temp[index - 1])
    {
        m = temp[index];
        return true;
    }
    esle
        return false;
}*/


class Q
{
public:
    Q() {}
    const int* front() const
    {
        
        std::cout << "void front() const" << std::endl;
        return m_head;

    }
    int* front()
    {
        
        std::cout << "void front()       " << std::endl;
        return m_head;
    }
private:
    int* m_head;
};

template <>
int compare<const char*>(const char* const& v1, const char* const& v2)
{
    return strcmp(v1, v2);
}