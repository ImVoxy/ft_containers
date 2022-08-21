#include "others/includes/pair.hpp"
#include "others/includes/make_pair.hpp"
#include "stack/includes/stack.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

// #define TEST ft

int pair_test()
{
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
    TEST::pair <std::string,double> product1;                     // default constructor
    TEST::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    TEST::pair <std::string,double> product3 (product2);          // copy constructor
    TEST::pair <std::string,double> lhs;
    TEST::pair <std::string,double> rhs;

    std::cout << "\033[1;33m     MAKE_PAIR     \033[0m" << std::endl << std::endl;
    std::cout << "build a pair from two ints" << std::endl;
    TEST::pair<int, int> p1 = TEST::make_pair(n, a[1]);
    std::cout << "The value of p1 is "
              << "(" << p1.first << ", " << p1.second << ")\n";
 
    std::cout << "build a pair from an int and an array (decayed to pointer)" << std::endl;
    TEST::pair<int, int*> p2 = TEST::make_pair(n, a);
    n = 7;
    std::cout << "The value of p2 is "
              << "(" << p2.first << ", " << *(p2.second + 2) << ")\n";

    std::cout << "build a pair from an int and a stack" << std::endl;
    TEST::stack<int, TEST::vector<int> > st;
    st.push(51);
    TEST::pair<int, TEST::stack<int, TEST::vector<int> > > p3 = TEST::make_pair(n, st);
    std::cout << "The value of p3 is "
              << "(" << p3.first << ", " << p3.second.top() << ")\n";
    

    std::cout << std::endl << "\033[1;33m     PAIR     \033[0m" << std::endl << std::endl;

    product1 = TEST::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    product2.first = "shoes";                  // the type of first is string
    product2.second = 39.90;                   // the type of second is double

    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << "\n\n";

    std::cout << "\033[1;33m     RELATIONAL OPERATORS     \033[0m" << std::endl << std::endl;

    lhs = TEST::make_pair(std::string("bonjour"), 42);
    rhs = TEST::make_pair(std::string("bonjour"), 42);

    std::cout << "lhs.first = " << lhs.first << " lhs.second = " << lhs.second << std::endl;
    std::cout << "rhs.first = " << rhs.first << " rhs.second = " << rhs.second << std::endl;
    std::cout << "lhs == rhs ? " << (lhs == rhs) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs != rhs) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs < rhs) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs <= rhs) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs > rhs) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs >= rhs) << std::endl;

    lhs = TEST::make_pair(std::string("test"), 42);
    rhs = TEST::make_pair(std::string("bonjour"), 42);

    std::cout << "lhs.first = " << lhs.first << " lhs.second = " << lhs.second << std::endl;
    std::cout << "rhs.first = " << rhs.first << " rhs.second = " << rhs.second << std::endl;
    std::cout << "lhs == rhs ? " << (lhs == rhs) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs != rhs) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs < rhs) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs <= rhs) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs > rhs) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs >= rhs) << std::endl;

    lhs = TEST::make_pair(std::string("bonjour"), 42);
    rhs = TEST::make_pair(std::string("test"), 42);

    std::cout << "lhs.first = " << lhs.first << " lhs.second = " << lhs.second << std::endl;
    std::cout << "rhs.first = " << rhs.first << " rhs.second = " << rhs.second << std::endl;
    std::cout << "lhs == rhs ? " << (lhs == rhs) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs != rhs) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs < rhs) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs <= rhs) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs > rhs) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs >= rhs) << std::endl;

    lhs = TEST::make_pair(std::string("bonjour"), 52);
    rhs = TEST::make_pair(std::string("bonjour"), 42);

    std::cout << "lhs.first = " << lhs.first << " lhs.second = " << lhs.second << std::endl;
    std::cout << "rhs.first = " << rhs.first << " rhs.second = " << rhs.second << std::endl;
    std::cout << "lhs == rhs ? " << (lhs == rhs) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs != rhs) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs < rhs) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs <= rhs) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs > rhs) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs >= rhs) << std::endl;

    return (0);
}