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

// int main()
// {
//     std::cout << std::boolalpha;
//     std::cout << std::endl << "\033[1;32m     STACK TESTS     \033[0m" << std::endl << std::endl;
//     stack_test();
//     std::cout << std::endl << "\033[1;32m     VECTOR TESTS     \033[0m" << std::endl << std::endl;
//     vector_test();
//     std::cout << std::endl << "\033[1;32m     ITERATOR TESTS     \033[0m" << std::endl << std::endl;
//     iterator_test();
//     std::cout << std::endl << "\033[1;32m     REVERSE_ITERATOR TESTS     \033[0m" << std::endl << std::endl;
//     reverse_iterator_test();
//     std::cout << std::endl << "\033[1;32m     PAIR TESTS     \033[0m" << std::endl << std::endl;
//     pair_test();
//     std::cout << std::endl << "\033[1;32m     LEXICOGRAPHICAL_COMPARE TESTS     \033[0m" << std::endl << std::endl;
//     lexicographical_compare_test();
//     std::cout << std::endl << "\033[1;32m     ENABLE_IF TESTS     \033[0m" << std::endl << std::endl;
//     enable_if_test();
//     std::cout << std::endl << "\033[1;32m     IS INTEGRAL TESTS     \033[0m" << std::endl << std::endl;
//     is_integral_test();

//     return (0);
// }

#include "../containers_test/srcs/vector/common.hpp"
// #include "common.hpp"

#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7

	return (0);
}