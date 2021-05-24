
#include "Hasptr.h";

    
	HasPtr::HasPtr(int* p, int i) : m_ptr(new U_Ptr(p)), m_val(i)
	{
		std::cout << this << "HasPtr(int* p, int i) " << "use = " << m_ptr->use << std::endl;
	}
	HasPtr::HasPtr(const HasPtr& rhs) :m_ptr(rhs.m_ptr), m_val(rhs.m_val)
	{
		++m_ptr->use;
		std::cout << this <<"HasPtr(const HasPtr& rhs) " << "use = " << m_ptr->use << std::endl;
	}
	HasPtr& HasPtr::operator=(const HasPtr& rhs)
	{

		++rhs.m_ptr->use; // increment use count on rhs first 
		std::cout << "HasPtr& operator=(const HasPtr& rhs) " << std::endl;
		if (--m_ptr->use == 0)
			delete m_ptr; // if use count goes to 0 on this object, 

		m_ptr = rhs.m_ptr; // copy the U_Ptr object 
		m_val = rhs.m_val; // copy the int member 
		return *this;
	}
	HasPtr::~HasPtr()
	{
		std::cout << this << "~HasPtr()" << "use = " << m_ptr->use << std::endl;
		if (--m_ptr->use == 0)
		{
			delete m_ptr;
		}
	}
	int* HasPtr::get_ptr() const { return m_ptr->m_ip; }
	int HasPtr::get_int() const { return  m_val; }
	void HasPtr::set_ptr(int* p) { m_ptr->m_ip = p; }
	void HasPtr::set_int(int i) { m_val = i; }
	int HasPtr::get_ptr_val() const { return *m_ptr->m_ip; }
	void HasPtr::set_ptr_val(int i) const { *m_ptr->m_ip = i; }