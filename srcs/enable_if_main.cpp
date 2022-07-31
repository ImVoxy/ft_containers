#include <iostream>
// #include <type_traits>
#include "others/includes/enable_if.hpp"
#include "others/includes/is_integral.hpp"

#define TEST ft

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename TEST::enable_if<TEST::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is onsly valid if T is an integral type:
template <class T>
typename TEST::enable_if<TEST::is_integral<T>::value,bool>::type
  is_even (T i) {return !bool(i%2);}

int enable_if_test() {

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}