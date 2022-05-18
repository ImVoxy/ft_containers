#include <iostream>
#include <iomanip>
#include <type_traits>
#include "others/includes/is_integral.hpp"
 
class A {};
 
enum E : int {};
 
template <class T>
T f(T i)
{
    static_assert(ft::is_integral<T>::value, "Integral required.");
    return i;
}
 
#define SHOW(...) std::cout << std::setw(29) << #__VA_ARGS__ << " == " << __VA_ARGS__ << '\n'
 
int main()
{
    std::cout << std::boolalpha;
 
    SHOW( ft::is_integral<A>::value );
    // SHOW( ft::is_integral<E> );
    // SHOW( ft::is_integral<float> );
    // SHOW( ft::is_integral<int> );
    // SHOW( ft::is_integral<const int> );
    // SHOW( ft::is_integral<bool> );
    SHOW( f(123) );