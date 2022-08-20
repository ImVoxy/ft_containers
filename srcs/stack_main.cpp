#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include "vector/includes/vector.hpp"
#include "stack/includes/stack.hpp"

#define TEST ft

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };
// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

int stack_test()
{
    TEST::vector<int> vector_int;
    TEST::stack<std::string> stack_str;
    TEST::stack<int> stack_int;
    TEST::stack<int> lhs_stack;
    TEST::stack<int> rhs_stack;
    TEST::stack<int, std::vector<int> > stack_vec_int;

    std::cout << "\033[1;33m     STACK INT     \033[0m" << std::endl << std::endl;

    vector_int.push_back(10);
    vector_int.push_back(42);
    vector_int.push_back(32);
    vector_int.push_back(68);
    vector_int.push_back(18);
    stack_int.push(123);
    std::cout << "is stack_str empty ?: " << stack_str.empty() << std::endl;
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;
    std::cout << "Top element  = " << stack_int.top() << std::endl;
    std::cout << "size of stack_int = " << stack_int.size() << std::endl;

    stack_int.push(48);
    stack_int.push(13);
    stack_int.push(12);
    stack_int.push(205);
    stack_int.push(51);
    std::cout << "size of stack_int = " << stack_int.size() << std::endl;
    std::cout << "Top element  = " << stack_int.top() << std::endl;

    stack_int.pop();
    std::cout << "size of stack_int = " << stack_int.size() << std::endl;
    std::cout << "Top element  = " << stack_int.top() << std::endl;

    while (!stack_int.empty())
        stack_int.pop();
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "\033[1;33m     STACK STR     \033[0m" << std::endl << std::endl;

    stack_str.push("Hello this is a random test");
    std::cout << "is stack_str empty ?: " << stack_str.empty() << std::endl;
    std::cout << "size of stack_str = " << stack_str.size() << std::endl;

    stack_str.push("bonjour");
    stack_str.push("coucou");
    stack_str.push("test");
    stack_str.push("the end");
    stack_str.push("");
    std::cout << "size of stack_str = " << stack_str.size() << std::endl;
    std::cout << "Top element  = " << stack_str.top() << std::endl;

    stack_str.pop();
    std::cout << "size of stack_str = " << stack_str.size() << std::endl;
    std::cout << "Top element  = " << stack_str.top() << std::endl;

    

    std::cout << std::endl << std::endl;

    std::cout << "\033[1;33m     STACK VEC INT     \033[0m" << std::endl << std::endl;

    stack_vec_int.push(123);
    std::cout << "is stack_int empty ?: " << stack_int.empty() << std::endl;
    std::cout << "is stack_vec_int empty ?: " << stack_vec_int.empty() << std::endl;
    std::cout << "Top element  = " << stack_vec_int.top() << std::endl;
    std::cout << "size of stack_vec_int = " << stack_vec_int.size() << std::endl;

    stack_vec_int.push(48);
    stack_vec_int.push(13);
    stack_vec_int.push(12);
    stack_vec_int.push(205);
    stack_vec_int.push(51);
    std::cout << "size of stack_vec_int = " << stack_vec_int.size() << std::endl;
    std::cout << "Top element  = " << stack_vec_int.top() << std::endl;

    stack_vec_int.pop();
    std::cout << "size of stack_vec_int = " << stack_vec_int.size() << std::endl;
    std::cout << "Top element  = " << stack_vec_int.top() << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "\033[1;33m     RELATIONAL OPERATORS     \033[0m" << std::endl << std::endl;

    rhs_stack.push(5);
    lhs_stack.push(10);
    std::cout << "lhs.top = " << lhs_stack.top() << " rhs.top = " << rhs_stack.top() << std::endl;
    std::cout << "lhs == rhs ? " << (lhs_stack == rhs_stack) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs_stack != rhs_stack) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs_stack < rhs_stack) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs_stack <= rhs_stack) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs_stack > rhs_stack) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs_stack >= rhs_stack) << std::endl << std::endl;
    
    lhs_stack.pop();
    lhs_stack.push(5);
    std::cout << "lhs.top = " << lhs_stack.top() << " rhs.top = " << rhs_stack.top() << std::endl;
    std::cout << "lhs == rhs ? " << (lhs_stack == rhs_stack) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs_stack != rhs_stack) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs_stack < rhs_stack) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs_stack <= rhs_stack) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs_stack > rhs_stack) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs_stack >= rhs_stack) << std::endl << std::endl;

    rhs_stack.pop();
    rhs_stack.push(10);
    std::cout << "lhs.top = " << lhs_stack.top() << " rhs.top = " << rhs_stack.top() << std::endl;
    std::cout << "lhs == rhs ? " << (lhs_stack == rhs_stack) << std::endl;
    std::cout << "lhs != rhs ? " << (lhs_stack != rhs_stack) << std::endl;
    std::cout << "lhs < rhs ? " << (lhs_stack < rhs_stack) << std::endl;
    std::cout << "lhs <= rhs ? " << (lhs_stack <= rhs_stack) << std::endl;
    std::cout << "lhs > rhs ? " << (lhs_stack > rhs_stack) << std::endl;
    std::cout << "lhs >= rhs ? " << (lhs_stack >= rhs_stack) << std::endl << std::endl;

    return (0);
}
