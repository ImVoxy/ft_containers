#include "others/includes/reverse_iterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <map>

int main()
{
    std::vector<int> v;
    std::vector<int> v2;
    std::vector<int> v3;
    std::map<int,std::string> numbers;
    numbers.insert (std::make_pair(1,"one"));
    numbers.insert (std::make_pair(2,"two"));
    numbers.insert (std::make_pair(3,"three"));
    for (int i=0; i<10; i++)
        v.push_back(i);
    for (int i=0; i<10; i++)
        v2.push_back(i);

    typedef std::vector<int>::iterator iter_type;
    typedef std::map<int,std::string>::iterator map_iter;

    std::reverse_iterator<iter_type> rev_end (v.begin());
    std::reverse_iterator<iter_type> rev_begin (v.end());
    ft::reverse_iterator<iter_type> ft_rev_end (v.begin());
    ft::reverse_iterator<iter_type> ft_rev_begin (v.end());

    std::cout << "v:   ";
    for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "ft_v:";
    for (iter_type it = ft_rev_end.base(); it != ft_rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;

    iter_type from (v2.begin());
    iter_type until (v2.end());
    std::reverse_iterator<iter_type> rev_it;
    ft::reverse_iterator<iter_type> ft_rev_it;
    std::reverse_iterator<iter_type> rev_until (from);
    std::reverse_iterator<iter_type> rev_from (until);
    ft::reverse_iterator<iter_type> ft_rev_until (from);
    ft::reverse_iterator<iter_type> ft_rev_from (until);

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
    std::cout << "ft:The fourth element from the end  is: " << ft_rev_from[3] << std::endl;
    std::cout << "ft:The fourth element from the end  is: " << *(ft_rev_from + 3) << std::endl;
    std::cout << "ft_v:";
    std::cout << ' ' << *ft_rev_from++;
    std::cout << ' ' << *ft_rev_from--;
    *ft_rev_from++;
    std::cout << ' ' << *ft_rev_from;
    std::cout << ' ' << *ft_rev_from++;
    std::cout << ' ' << *ft_rev_from++;
    std::cout << ' ' << --(*ft_rev_from);
    std::cout << ' ' << ++(*ft_rev_from);
    *ft_rev_from++;
    std::cout << ' ' << *ft_rev_from;
    ft_rev_from += 2;
    std::cout << ' ' << *(ft_rev_from);
    ft_rev_from -= 2;
    std::cout << std::endl << "ft_until - ft_from = " << (ft_rev_until - ft_rev_from) << " elements." << std::endl;
    std::cout << ' ' << *(ft_rev_from);
    std::cout << ' ' << *(ft_rev_from + 2);
    std::cout << ' ' << *(ft_rev_from - 2);
    while (ft_rev_from != ft_rev_until)
        std::cout << ' ' << *ft_rev_from++;
    std::cout << std::endl << std::endl;
    std::reverse_iterator<map_iter> m_rev_end (numbers.begin());
    std::reverse_iterator<map_iter> rev_iterator (numbers.end());
    std::cout << "m   : ";
    for ( ; rev_iterator != m_rev_end ; ++rev_iterator )
        std::cout << rev_iterator->first << ' ' << rev_iterator->second << ' ';
    std::cout << std::endl;
    ft::reverse_iterator<map_iter> ft_m_rev_end (numbers.begin());
    ft::reverse_iterator<map_iter> ft_rev_iterator (numbers.end());
    std::cout << "ft_m: ";
    for ( ; ft_rev_iterator != ft_m_rev_end ; ++ft_rev_iterator )
        std::cout << ft_rev_iterator->first << ' ' << ft_rev_iterator->second << ' ';
    std::cout << std::endl << std::endl;;

    std::cout << "\033[1;33m     RELATIONAL OPERATORS     \033[0m" << std::endl << std::endl;

    std::cout << "rev_from = " << *rev_from << " rev_until = " << *rev_until << std::endl;
    std::cout << "ft_rev_from = " << *ft_rev_from << " ft_rev_until = " << *ft_rev_until << std::endl;
    std::cout << "rev_from == rev_until -> " << (*rev_from == *rev_until) << std::endl;
    std::cout << "ft_rev_from == ft_rev_until -> " << (*ft_rev_from == *ft_rev_until) << std::endl;
    std::cout << "rev_from != rev_until -> " << (*rev_from != *rev_until) << std::endl;
    std::cout << "ft_rev_from != ft_rev_until -> " << (*ft_rev_from != *ft_rev_until) << std::endl;
    std::cout << "rev_from < rev_until -> " << (*rev_from < *rev_until) << std::endl;
    std::cout << "ft_rev_from < ft_rev_until -> " << (*ft_rev_from < *ft_rev_until) << std::endl;
    std::cout << "rev_from <= rev_until -> " << (*rev_from <= *rev_until) << std::endl;
    std::cout << "ft_rev_from <= ft_rev_until -> " << (*ft_rev_from <= *ft_rev_until) << std::endl;
    std::cout << "rev_from > rev_until -> " << (*rev_from > *rev_until) << std::endl;
    std::cout << "ft_rev_from > ft_rev_until -> " << (*ft_rev_from > *ft_rev_until) << std::endl;
    std::cout << "rev_from >= rev_until -> " << (*rev_from >= *rev_until) << std::endl;
    std::cout << "ft_rev_from >= ft_rev_until -> " << (*ft_rev_from >= *ft_rev_until) << std::endl;
    
    rev_until -= 3;
    ft_rev_until -= 3;
    std::cout << std::endl;
    std::cout << "rev_from = " << *rev_from << " rev_until = " << *rev_until << std::endl;
    std::cout << "ft_rev_from = " << *ft_rev_from << " ft_rev_until = " << *ft_rev_until << std::endl;
    std::cout << "rev_from == rev_until -> " << (*rev_from == *rev_until) << std::endl;
    std::cout << "ft_rev_from == ft_rev_until -> " << (*ft_rev_from == *ft_rev_until) << std::endl;
    std::cout << "rev_from != rev_until -> " << (*rev_from != *rev_until) << std::endl;
    std::cout << "ft_rev_from != ft_rev_until -> " << (*ft_rev_from != *ft_rev_until) << std::endl;
    std::cout << "rev_from < rev_until -> " << (*rev_from < *rev_until) << std::endl;
    std::cout << "ft_rev_from < ft_rev_until -> " << (*ft_rev_from < *ft_rev_until) << std::endl;
    std::cout << "rev_from <= rev_until -> " << (*rev_from <= *rev_until) << std::endl;
    std::cout << "ft_rev_from <= ft_rev_until -> " << (*ft_rev_from <= *ft_rev_until) << std::endl;
    std::cout << "rev_from > rev_until -> " << (*rev_from > *rev_until) << std::endl;
    std::cout << "ft_rev_from > ft_rev_until -> " << (*ft_rev_from > *ft_rev_until) << std::endl;
    std::cout << "rev_from >= rev_until -> " << (*rev_from >= *rev_until) << std::endl;
    std::cout << "ft_rev_from >= ft_rev_until -> " << (*ft_rev_from >= *ft_rev_until) << std::endl;

    rev_from -= 5;
    ft_rev_from -= 5;
    std::cout << std::endl;
    std::cout << "rev_from = " << *rev_from << " rev_until = " << *rev_until << std::endl;
    std::cout << "ft_rev_from = " << *ft_rev_from << " ft_rev_until = " << *ft_rev_until << std::endl;
    std::cout << "rev_from == rev_until -> " << (*rev_from == *rev_until) << std::endl;
    std::cout << "ft_rev_from == ft_rev_until -> " << (*ft_rev_from == *ft_rev_until) << std::endl;
    std::cout << "rev_from != rev_until -> " << (*rev_from != *rev_until) << std::endl;
    std::cout << "ft_rev_from != ft_rev_until -> " << (*ft_rev_from != *ft_rev_until) << std::endl;
    std::cout << "rev_from < rev_until -> " << (*rev_from < *rev_until) << std::endl;
    std::cout << "ft_rev_from < ft_rev_until -> " << (*ft_rev_from < *ft_rev_until) << std::endl;
    std::cout << "rev_from <= rev_until -> " << (*rev_from <= *rev_until) << std::endl;
    std::cout << "ft_rev_from <= ft_rev_until -> " << (*ft_rev_from <= *ft_rev_until) << std::endl;
    std::cout << "rev_from > rev_until -> " << (*rev_from > *rev_until) << std::endl;
    std::cout << "ft_rev_from > ft_rev_until -> " << (*ft_rev_from > *ft_rev_until) << std::endl;
    std::cout << "rev_from >= rev_until -> " << (*rev_from >= *rev_until) << std::endl;
    std::cout << "ft_rev_from >= ft_rev_until -> " << (*ft_rev_from >= *ft_rev_until) << std::endl;
    return (0);
}