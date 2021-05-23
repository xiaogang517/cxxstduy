#include <iostream>

void Swap1(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap2(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap3(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    a = 0;
    b = 0;
}

void Swap4(int* &a, int* &b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    a = 0;
    b = 0;
}


int main()
{
    int a = 3;
    int b = 5;
    Swap1(a,b);
    std::cout << a << b << std::endl;

    Swap2(a,b);
    std::cout << a << b << std::endl;
    int *pa = &a;
    int *pb = &b;
    std::cout << "pa= " << pa << ",pb= " << pb << std::endl;
    Swap3(pa,pb);
    std::cout << "pa= " << pa << ",pb= " << pb << std::endl;
    std::cout << a << b << std::endl;

    std::cout << "before swap4 pa= " << pa << ",pb= " << pb << std::endl;
    Swap4(pa,pb);
    std::cout << "after swap4 pa= " << pa << ",pb= " << pb << std::endl;
    std::cout << a << b << std::endl;
    return 0;
}
