#include <iostream>
#include "U_Ptr.h"
U_Ptr::U_Ptr(int* p) :m_ip(p), use(1) {
	std::cout << "U_Ptr(int* p) " <<use << std::endl;
}
U_Ptr::~U_Ptr() {
	delete m_ip;
	std::cout << "~U_Ptr() " << use << std::endl;
}