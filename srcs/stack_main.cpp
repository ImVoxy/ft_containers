#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include "stack/includes/stack.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int stack_test()
{
    std::vector<int> vector_int;
    ft::stack<std::string> ft_stack_str;
    ft::stack<int> ft_stack_int;
    ft::stack<int> ft_lhs_stack;
    ft::stack<int> ft_rhs_stack;
    ft::stack<int, std::vector<int> > ft_stack_vec_int;
    std::stack<std::string> stack_str;
    std::stack<int> stack_int;
    std::stack<int> lhs_stack;
    std::stack<int> rhs_stack;
    std::stack<int, std::vector<int> > stack_vec_int;
    std::cout << "\033[1;33m     STACK INT     \033[0m" << std::endl << std::endl;

    vector_int.push_back(10);
    vector_int.push_back(42);
    vector_int.push_back(32);
    vector_int.push_back(68);
    vector_int.push_back(18);
    stack_int.push(123);
    ft_stack_int.push(123);
    std::cout << "is stack_str empty ?: " << stack_str.empty() << std::endl;
    std::cout << "is ft_stack_str empty ?: " << ft_stack_str.empty() << std::endl;
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;
    std::cout << "is ft_stack_int empty ?: " << ft_stack_int.empty() << std::endl;
    std::cout << "Top element = " << stack_int.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_int.top() << std::endl;
    std::cout << "size of stack_int = " << stack_int.size() << std::endl;
    std::cout << "size of ft_stack_int = " << ft_stack_int.size() << std::endl;

    stack_int.push(48);
    stack_int.push(13);
    stack_int.push(12);
    stack_int.push(205);
    stack_int.push(51);
    ft_stack_int.push(48);
    ft_stack_int.push(13);
    ft_stack_int.push(12);
    ft_stack_int.push(205);
    ft_stack_int.push(51);
    std::cout << "size of stack_int = " << stack_int.size() << std::endl;
    std::cout << "size of ft_stack_int = " << ft_stack_int.size() << std::endl;
    std::cout << "Top element = " << stack_int.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_int.top() << std::endl;

    stack_int.pop();
    ft_stack_int.pop();
    std::cout << "size of stack_int = " << stack_int.size() << std::endl;
    std::cout << "size of ft_stack_int = " << ft_stack_int.size() << std::endl;
    std::cout << "Top element = " << stack_int.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_int.top() << std::endl;

    while (!stack_int.empty())
        stack_int.pop();
    while (!ft_stack_int.empty())
        ft_stack_int.pop();
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;
    std::cout << "is ft_stack_int empty ?: " << ft_stack_int.empty() << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "\033[1;33m     STACK STR     \033[0m" << std::endl << std::endl;

    stack_str.push("Hello this is a random test");
    ft_stack_str.push("Hello this is a random test");
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;
    std::cout << "is ft_stack_int empty ?: " << ft_stack_int.empty() << std::endl;
    std::cout << "is stack_str empty ?: " << stack_str.empty() << std::endl;
    std::cout << "is ft_stack_str empty ?: " << ft_stack_str.empty() << std::endl;
    std::cout << "Top element = " << stack_str.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_str.top() << std::endl;
    std::cout << "size of stack_str = " << stack_str.size() << std::endl;
    std::cout << "size of ft_stack_str = " << ft_stack_str.size() << std::endl;

    stack_str.push("bonjour");
    stack_str.push("coucou");
    stack_str.push("test");
    stack_str.push("the end");
    stack_str.push("");
    ft_stack_str.push("bonjour");
    ft_stack_str.push("coucou");
    ft_stack_str.push("test");
    ft_stack_str.push("the end");
    ft_stack_str.push("");
    std::cout << "size of stack_str = " << stack_str.size() << std::endl;
    std::cout << "size of ft_stack_str = " << ft_stack_str.size() << std::endl;
    std::cout << "Top element = " << stack_str.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_str.top() << std::endl;

    stack_str.pop();
    ft_stack_str.pop();
    std::cout << "size of stack_str = " << stack_str.size() << std::endl;
    std::cout << "size of ft_stack_str = " << ft_stack_str.size() << std::endl;
    std::cout << "Top element = " << stack_str.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_str.top() << std::endl;

    

    std::cout << std::endl << std::endl;

    std::cout << "\033[1;33m     STACK VEC INT     \033[0m" << std::endl << std::endl;

    stack_vec_int.push(123);
    ft_stack_vec_int.push(123);
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;
    std::cout << "is ft_stack_int empty ?: " << ft_stack_int.empty() << std::endl;
    std::cout << "is stack_vec_int empty ?: " << stack_vec_int.empty() << std::endl;
    std::cout << "is ft_stack_vec_int empty ?: " << ft_stack_vec_int.empty() << std::endl;
    std::cout << "Top element = " << stack_vec_int.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_vec_int.top() << std::endl;
    std::cout << "size of stack_vec_int = " << stack_vec_int.size() << std::endl;
    std::cout << "size of ft_stack_vec_int = " << ft_stack_vec_int.size() << std::endl;

    stack_vec_int.push(48);
    stack_vec_int.push(13);
    stack_vec_int.push(12);
    stack_vec_int.push(205);
    stack_vec_int.push(51);
    ft_stack_vec_int.push(48);
    ft_stack_vec_int.push(13);
    ft_stack_vec_int.push(12);
    ft_stack_vec_int.push(205);
    ft_stack_vec_int.push(51);
    std::cout << "size of stack_vec_int = " << stack_vec_int.size() << std::endl;
    std::cout << "size of ft_stack_vec_int = " << ft_stack_vec_int.size() << std::endl;
    std::cout << "Top element = " << stack_vec_int.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_vec_int.top() << std::endl;

    stack_vec_int.pop();
    ft_stack_vec_int.pop();
    std::cout << "size of stack_vec_int = " << stack_vec_int.size() << std::endl;
    std::cout << "size of ft_stack_vec_int = " << ft_stack_vec_int.size() << std::endl;
    std::cout << "Top element = " << stack_vec_int.top() << std::endl;
    std::cout << "Top element ft = " << ft_stack_vec_int.top() << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "\033[1;33m     RELATIONAL OPERATORS     \033[0m" << std::endl << std::endl;

    rhs_stack.push(5);
    lhs_stack.push(10);
    ft_rhs_stack.push(5);
    ft_lhs_stack.push(10);
    std::cout << "lhs.top = " << lhs_stack.top() << " rhs.top = " << rhs_stack.top() << std::endl;
    std::cout << "ft_lhs.top = " << ft_lhs_stack.top() << " ft_rhs.top = " << ft_rhs_stack.top() << std::endl;
    std::cout << "lhs == rhs ? " << (lhs_stack == rhs_stack) << std::endl;
    std::cout << "ft_lhs == ft_rhs ? " << (ft_lhs_stack == ft_rhs_stack) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs_stack != rhs_stack) << std::endl;
    std::cout << "ft_lhs != ft_rhs ? " << (ft_lhs_stack != ft_rhs_stack) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs_stack < rhs_stack) << std::endl;
    std::cout << "ft_lhs < ft_rhs ? " << (ft_lhs_stack < ft_rhs_stack) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs_stack <= rhs_stack) << std::endl;
    std::cout << "ft_lhs <= ft_rhs ? " << (ft_lhs_stack <= ft_rhs_stack) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs_stack > rhs_stack) << std::endl;
    std::cout << "ft_lhs > ft_rhs ? " << (ft_lhs_stack > ft_rhs_stack) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs_stack >= rhs_stack) << std::endl;
    std::cout << "ft_lhs >= ft_rhs ? " << (ft_lhs_stack >= ft_rhs_stack) << std::endl << std::endl;
    
    lhs_stack.pop();
    lhs_stack.push(5);
    ft_lhs_stack.pop();
    ft_lhs_stack.push(5);
    std::cout << "lhs.top = " << lhs_stack.top() << " rhs.top = " << rhs_stack.top() << std::endl;
    std::cout << "ft_lhs.top = " << ft_lhs_stack.top() << " ft_rhs.top = " << ft_rhs_stack.top() << std::endl;
    std::cout << "lhs == rhs ? " << (lhs_stack == rhs_stack) << std::endl;
    std::cout << "ft_lhs == ft_rhs ? " << (ft_lhs_stack == ft_rhs_stack) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs_stack != rhs_stack) << std::endl;
    std::cout << "ft_lhs != ft_rhs ? " << (ft_lhs_stack != ft_rhs_stack) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs_stack < rhs_stack) << std::endl;
    std::cout << "ft_lhs < ft_rhs ? " << (ft_lhs_stack < ft_rhs_stack) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs_stack <= rhs_stack) << std::endl;
    std::cout << "ft_lhs <= ft_rhs ? " << (ft_lhs_stack <= ft_rhs_stack) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs_stack > rhs_stack) << std::endl;
    std::cout << "ft_lhs > ft_rhs ? " << (ft_lhs_stack > ft_rhs_stack) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs_stack >= rhs_stack) << std::endl;
    std::cout << "ft_lhs >= ft_rhs ? " << (ft_lhs_stack >= ft_rhs_stack) << std::endl << std::endl;

    rhs_stack.pop();
    rhs_stack.push(10);
    ft_rhs_stack.pop();
    ft_rhs_stack.push(10);
    std::cout << "lhs.top = " << lhs_stack.top() << " rhs.top = " << rhs_stack.top() << std::endl;
    std::cout << "ft_lhs.top = " << ft_lhs_stack.top() << " ft_rhs.top = " << ft_rhs_stack.top() << std::endl;
    std::cout << "lhs == rhs ? " << (lhs_stack == rhs_stack) << std::endl;
    std::cout << "ft_lhs == ft_rhs ? " << (ft_lhs_stack == ft_rhs_stack) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs_stack != rhs_stack) << std::endl;
    std::cout << "ft_lhs != ft_rhs ? " << (ft_lhs_stack != ft_rhs_stack) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs_stack < rhs_stack) << std::endl;
    std::cout << "ft_lhs < ft_rhs ? " << (ft_lhs_stack < ft_rhs_stack) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs_stack <= rhs_stack) << std::endl;
    std::cout << "ft_lhs <= ft_rhs ? " << (ft_lhs_stack <= ft_rhs_stack) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs_stack > rhs_stack) << std::endl;
    std::cout << "ft_lhs > ft_rhs ? " << (ft_lhs_stack > ft_rhs_stack) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs_stack >= rhs_stack) << std::endl;
    std::cout << "ft_lhs >= ft_rhs ? " << (ft_lhs_stack >= ft_rhs_stack) << std::endl << std::endl;

    return (0);
}
