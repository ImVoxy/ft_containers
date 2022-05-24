#include "others/includes/iterator_traits.hpp"
#include "others/includes/reverse_iterator.hpp"
// #include "vector/includes/vector.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
 
template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}
 
int iterator_test()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::cout << "iterator test on std::vector :" << std::endl;
    my_reverse(v.begin(), v.end());
    for (int i = 0 ; i < 5 ; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
 
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    std::cout << "iterator test on std::list :" << std::endl;
    my_reverse(l.begin(), l.end());
    for (int i = 0 ; i < 5; i++) {
        std::cout << l.front() << ' ';
        l.pop_front();
    }
    std::cout << '\n';
 
    int a[] = {1, 2, 3, 4, 5};
    my_reverse(a, a + 5);
    std::cout << "iterator test on int a[] :" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
 
//    std::istreambuf_iterator<char> i1(std::cin), i2;
//    my_reverse(i1, i2); // compilation error
    return (0);
 
}