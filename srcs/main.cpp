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
void	checkErase(ft::vector<std::string> const &vct,
					ft::vector<std::string>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int		main(void)
{
	ft::vector<std::string> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSize(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSize(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	printSize(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));

	return (0);
}