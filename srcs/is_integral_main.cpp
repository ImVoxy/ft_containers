#include <iostream>
#include <iomanip>
#include "others/includes/is_integral.hpp"
 
class A {};
 
enum E : int {};
 
int is_integral_test()
{
    std::cout << "ft::is_integral<A>::value ==              " << ft::is_integral<A>::value << std::endl;
    std::cout << "ft::is_integral<E>::value ==              " << ft::is_integral<E>::value << std::endl;
    std::cout << "ft::is_integral<float>::value ==          " << ft::is_integral<float>::value << std::endl;
    std::cout << "ft::is_integral<const float>::value ==    " << ft::is_integral<const float>::value << std::endl;
    std::cout << "ft::is_integral<int>::value ==            " << ft::is_integral<int>::value << std::endl;
    std::cout << "ft::is_integral<const int>::value ==      " << ft::is_integral<const int>::value << std::endl;
    std::cout << "ft::is_integral<volatile int>::value ==   " << ft::is_integral<volatile int>::value << std::endl;
    std::cout << "ft::is_integral<bool>::value ==           " << ft::is_integral<bool>::value << std::endl;

    return (0);
}