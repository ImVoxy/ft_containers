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

#include <list>

#define TESTED_TYPE int

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

int		main(void)
{
	const int start_size = 7;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	printSize(vct, true);

	vct.resize(10, 42);
	printSize(vct, true);

	vct.resize(18, 43);
	printSize(vct, true);
	vct.resize(10);
	printSize(vct, true);
	vct.resize(23, 44);
	printSize(vct, true);
	vct.resize(5);
	printSize(vct, true);
	vct.reserve(5);
	vct.reserve(3);
	printSize(vct, true);
	vct.resize(87);
	vct.resize(5);
	printSize(vct, true);

	is_empty(vct2);
	vct2 = vct;
	is_empty(vct2);
	vct.reserve(vct.capacity() + 1);
	printSize(vct, true);
	printSize(vct2, true);

	vct2.resize(0);
	is_empty(vct2);
	printSize(vct2, true);
	return (0);
}
