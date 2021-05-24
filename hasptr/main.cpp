# include <iostream>
#include "HasPtr.h"

int main() {
	int* pi = new int(0);
	HasPtr hp1(pi, 100);
	HasPtr hp2(hp1);
	HasPtr hp3(hp2);
	HasPtr hp4(hp1);
	//*hp2 = *hp3;
//	int* pi2 = new int(20);
//	HasPtr php1(pi, 20);
//	*hp2 = *php1;
	std::cout << hp1.get_ptr_val() << " " << hp2.get_ptr_val() << std::endl;
	hp3.set_ptr_val(10000);
	std::cout << hp1.get_ptr_val() << " " << hp2.get_ptr_val() << std::endl;
	hp4.set_ptr_val(10);
	std::cout << hp1.get_ptr_val() << " " << hp2.get_ptr_val() << std::endl;
	
//	std::cout << hp4.get_ptr_val() << std::endl;
	return 0;
}