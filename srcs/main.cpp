#include <iostream>
#include "others/includes/is_integral.hpp"
#include "others/includes/enable_if.hpp"
#include "others/includes/iterator_traits.hpp"
#include "others/includes/reverse_iterator.hpp"
#include "others/includes/make_pair.hpp"
#include "others/includes/lexicographical_compare.hpp"
#include "others/includes/pair.hpp"
#include "stack/includes/stack.hpp"
#include "vector/includes/vector.hpp"

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::endl << "\033[1;32m     STACK TESTS     \033[0m" << std::endl << std::endl;
    stack_test();
    std::cout << std::endl << "\033[1;32m     VECTOR TESTS     \033[0m" << std::endl << std::endl;
    // vector_test();
    std::cout << std::endl << "\033[1;32m     ITERATOR TESTS     \033[0m" << std::endl << std::endl;
    iterator_test();
    std::cout << std::endl << "\033[1;32m     REVERSE_ITERATOR TESTS     \033[0m" << std::endl << std::endl;
    reverse_iterator_test();
    std::cout << std::endl << "\033[1;32m     PAIR TESTS     \033[0m" << std::endl << std::endl;
    pair_test();
    std::cout << std::endl << "\033[1;32m     LEXICOGRAPHICAL_COMPARE TESTS     \033[0m" << std::endl << std::endl;
    lexicographical_compare_test();
    std::cout << std::endl << "\033[1;32m     ENABLE_IF TESTS     \033[0m" << std::endl << std::endl;
    enable_if_test();
    std::cout << std::endl << "\033[1;32m     IS INTEGRAL TESTS     \033[0m" << std::endl << std::endl;
    is_integral_test();

    return (0);
}