#pragma once
#include <iostream>
#include "U_Ptr.h"
class HasPtr {
public:
	HasPtr(int* p, int i);
    HasPtr(const HasPtr& rhs);	
	HasPtr& operator=(const HasPtr& rhs);
	~HasPtr();
	
	int* get_ptr() const;
	int get_int() const;

	void set_ptr(int* p);
	void set_int(int i);
 
	int get_ptr_val() const;
	void set_ptr_val(int i) const;
private:
	U_Ptr* m_ptr; // points to use-counted U_Ptr class 
	int m_val;
	std::string ok;
};

