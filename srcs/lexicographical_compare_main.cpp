#include <iostream>
#include <vector>
#include <string>
#include "vector/includes/vector.hpp"
#include "others/includes/lexicographical_compare.hpp"
 
// #define TEST ft

int lexicographical_compare_test()
{
    TEST::vector<char> v1;
    TEST::vector<char> v2;
    std::string str;

    str = std::string("abcd");
    for (int i = 0; str[i]; i++)
        v1.push_back(str[i]);
    for (int i = 0; str[i]; i++)
        v2.push_back(str[i]);
    std::cout << "-> v1 = abcd, v2 = abcd" << std::endl;
    std::cout << "exicographical_compare = " <<
    TEST::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
    v1.clear();

    str = "adbc";
        for (int i = 0; str[i]; i++)
    v1.push_back(str[i]);
    std::cout << "-> v1 = adbc, v2 = abcd" << std::endl;
    std::cout << "lexicographical_compare = " <<
    TEST::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
    v1.clear();
    v2.clear();

    for (int i = 0; str[i]; i++)
        v2.push_back(str[i]);
    str = "abcd";
    for (int i = 0; str[i]; i++)
        v1.push_back(str[i]);
    std::cout << "-> v1 = abcd, v2 = adbc" <<std::endl;
    std::cout << "lexicographical_compare = " <<
    TEST::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
    v1.clear();
    v2.clear();
    return (0);
}