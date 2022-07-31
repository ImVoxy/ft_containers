#include <iostream>
#include <iomanip>
#include "others/includes/is_integral.hpp"
 
#define TEST ft

class A {};
 
enum E : int {};
 
int is_integral_test()
{
    std::cout << "is_integral<A>::value ==              " << TEST::is_integral<A>::value << std::endl;
    std::cout << "is_integral<E>::value ==              " << TEST::is_integral<E>::value << std::endl;
    std::cout << "is_integral<float>::value ==          " << TEST::is_integral<float>::value << std::endl;
    std::cout << "is_integral<const float>::value ==    " << TEST::is_integral<const float>::value << std::endl;
    std::cout << "is_integral<int>::value ==            " << TEST::is_integral<int>::value << std::endl;
    std::cout << "is_integral<const int>::value ==      " << TEST::is_integral<const int>::value << std::endl;
    std::cout << "is_integral<volatile int>::value ==   " << TEST::is_integral<volatile int>::value << std::endl;
    std::cout << "is_integral<bool>::value ==           " << TEST::is_integral<bool>::value << std::endl;

    return (0);
}