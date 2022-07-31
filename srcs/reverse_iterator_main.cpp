#include "others/includes/reverse_iterator.hpp"
#include "others/includes/make_pair.hpp"
#include "vector/includes/vector.hpp"
#include "others/includes/pair.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <map>

#define TEST ft

int reverse_iterator_test()
{
    TEST::vector<int> v;
    TEST::vector<int> v2;
    TEST::vector<int> v3;
    std::map<int,std::string> numbers;
    numbers.insert (std::make_pair(1,"one"));
    numbers.insert (std::make_pair(2,"two"));
    numbers.insert (std::make_pair(3,"three"));
    for (int i=0; i<10; i++)
        v.push_back(i);
    for (int i=0; i<10; i++)
        v2.push_back(i);

    typedef TEST::vector<int>::iterator iter_type;
    typedef std::map<int,std::string>::iterator map_iter;

    TEST::reverse_iterator<iter_type> rev_end (v.begin());
    TEST::reverse_iterator<iter_type> rev_begin (v.end());

    std::cout << "v:   ";
    for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "v:";
    for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;

    iter_type from (v2.begin());
    iter_type until (v2.end());

    TEST::reverse_iterator<iter_type> rev_it;
    TEST::reverse_iterator<iter_type> rev_until (from);
    TEST::reverse_iterator<iter_type> rev_from (until);

    std::cout << "The fourth element from the end is:     " << rev_from[3] << std::endl;
    std::cout << "The fourth element from the end is:     " << *(rev_from + 3) << std::endl;
    std::cout << "v:   ";
    std::cout << ' ' << *rev_from++;
    std::cout << ' ' << *rev_from--;
    *rev_from++;
    std::cout << ' ' << *rev_from;
    std::cout << ' ' << *rev_from++;
    std::cout << ' ' << *rev_from++;
    std::cout << ' ' << --(*rev_from);
    std::cout << ' ' << ++(*rev_from);
    *rev_from++;
    std::cout << ' ' << *rev_from;
    rev_from += 2;
    std::cout << ' ' << *(rev_from);
    rev_from -= 2;
    std::cout << std::endl << "until - from = " << (rev_until - rev_from) << " elements." << std::endl;
    std::cout << ' ' << *(rev_from);
    std::cout << ' ' << *(rev_from + 2
    );
    std::cout << ' ' << *(rev_from - 2);
    while (rev_from != rev_until)
        std::cout << ' ' << *rev_from++;
    std::cout << std::endl << std::endl;
    
    std::cout << std::endl;
    TEST::reverse_iterator<map_iter> m_rev_end (numbers.begin());
    TEST::reverse_iterator<map_iter> rev_iterator (numbers.end());
    std::cout << "m: ";
    for ( ; rev_iterator != m_rev_end ; ++rev_iterator )
        std::cout << rev_iterator->first << ' ' << rev_iterator->second << ' ';
    std::cout << std::endl << std::endl;;

    std::cout << "\033[1;33m     RELATIONAL OPERATORS     \033[0m" << std::endl << std::endl;

    iter_type from2 (v2.begin());
    iter_type until2 (v2.end());
    TEST::reverse_iterator<iter_type> rev_it2;
    TEST::reverse_iterator<iter_type> rev_until2 (from2);
    TEST::reverse_iterator<iter_type> rev_from2 (until2);
    rev_until2--;
    std::cout << "rev_from = " << *rev_from2 << " rev_until = " << *rev_until2 << std::endl;
    std::cout << "rev_from == rev_until -> " << (*rev_from2 == *rev_until2) << std::endl;
    std::cout << "rev_from != rev_until -> " << (*rev_from2 != *rev_until2) << std::endl;
    std::cout << "rev_from < rev_until -> " << (*rev_from2 < *rev_until2) << std::endl;
    std::cout << "rev_from <= rev_until -> " << (*rev_from2 <= *rev_until2) << std::endl;
    std::cout << "rev_from > rev_until -> " << (*rev_from2 > *rev_until2) << std::endl;
    std::cout << "rev_from >= rev_until -> " << (*rev_from2 >= *rev_until2) << std::endl;
    
    rev_until2 -= 3;
    std::cout << std::endl;
    std::cout << "rev_from = " << *rev_from2 << " rev_until = " << *rev_until2 << std::endl;
    std::cout << "rev_from == rev_until -> " << (*rev_from2 == *rev_until2) << std::endl;
    std::cout << "rev_from != rev_until -> " << (*rev_from2 != *rev_until2) << std::endl;
    std::cout << "rev_from < rev_until -> " << (*rev_from2 < *rev_until2) << std::endl;
    std::cout << "rev_from <= rev_until -> " << (*rev_from2 <= *rev_until2) << std::endl;
    std::cout << "rev_from > rev_until -> " << (*rev_from2 > *rev_until2) << std::endl;
    std::cout << "rev_from >= rev_until -> " << (*rev_from2 >= *rev_until2) << std::endl;

    rev_from2 += 2;
    std::cout << std::endl;
    std::cout << "rev_from = " << *rev_from2 << " rev_until = " << *rev_until2 << std::endl;
    std::cout << "rev_from == rev_until -> " << (*rev_from2 == *rev_until2) << std::endl;
    std::cout << "rev_from != rev_until -> " << (*rev_from2 != *rev_until2) << std::endl;
    std::cout << "rev_from < rev_until -> " << (*rev_from2 < *rev_until2) << std::endl;
    std::cout << "rev_from <= rev_until -> " << (*rev_from2 <= *rev_until2) << std::endl;
    std::cout << "rev_from > rev_until -> " << (*rev_from2 > *rev_until2) << std::endl;
    std::cout << "rev_from >= rev_until -> " << (*rev_from2 >= *rev_until2) << std::endl;
    return (0);
}