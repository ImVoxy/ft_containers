#include <iostream>
#include <vector>
#include <string>
#include "vector/includes/vector.hpp"

#define TEST ft

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))


void display_vec_int(TEST::vector<int> vector_int)
{   
    for (int i = 0 ; i < (int)vector_int.size(); i += 1)
        std::cout << vector_int[i] << ", ";
    std::cout << std::endl;
}

int main()
{
    TEST::vector<int> testnul(5);
    TEST::vector<int> vector_int;
    TEST::vector<int> vector_int2;
    TEST::vector<int> vector_int3;
    vector_int3.push_back(1);
    vector_int3.push_back(2);
    vector_int3.push_back(3);
    vector_int3.push_back(4);
    vector_int.assign(5, 10);
    TEST::vector<int>::iterator it3_e = vector_int3.end();
    TEST::vector<int>::iterator it3_b = vector_int3.begin();
    TEST::vector<int>::iterator it_e = vector_int.end();
    TEST::vector<int>::iterator it_b = vector_int.begin();
    display_vec_int(vector_int);
    vector_int2.assign(it_b, it_e);
    display_vec_int(vector_int2);
    vector_int.push_back(42);
    display_vec_int(vector_int);
    vector_int.pop_back();
    display_vec_int(vector_int);

    it_e--;
    it_e--;
    it_e--;
    
    it_b = vector_int.begin();
    vector_int.insert(it_b, 22);
    display_vec_int(vector_int);
    it_b = vector_int.begin();
    it_e = vector_int.end();

    vector_int.insert(it_e - 3, it3_b, it3_e);
    display_vec_int(vector_int);
    it_b = vector_int.begin();
    vector_int.erase(it_b + 5);
    display_vec_int(vector_int);
    
    it_b = vector_int.begin();
    it_e = vector_int.end();
    vector_int.erase(it_b + 6, it_e - 3);
    display_vec_int(vector_int);

    TEST::vector<int> vector_int4;
    vector_int4.push_back(1);
    vector_int4.push_back(2);
    vector_int4.push_back(3);
    vector_int4.push_back(4);
    TEST::vector<int> vector_int5;
    vector_int5.push_back(5);
    vector_int5.push_back(6);
    vector_int5.push_back(7);
    display_vec_int(vector_int4);
    display_vec_int(vector_int5);
    vector_int4.swap(vector_int5);
    display_vec_int(vector_int4);
    display_vec_int(vector_int5);

    std::cout << std::endl;
    
    TEST::vector<std::string> test_vector_str;
	TEST::vector<int> test_vector_int;
    TEST::vector<int> test_input_vector_int;
    test_vector_int.push_back(10);
    test_vector_int.push_back(42);
    test_vector_int.push_back(32);
    test_vector_int.push_back(68);
    test_vector_int.push_back(18);
    test_input_vector_int.push_back(1);
    test_input_vector_int.push_back(2);
    test_input_vector_int.push_back(3);
    test_input_vector_int.push_back(4);

    TEST::vector<int>::iterator test_in_it_e = test_input_vector_int.end();
    TEST::vector<int>::iterator test_in_it_b = test_input_vector_int.begin();
    TEST::vector<int>::iterator test_it_e = test_vector_int.end();
    TEST::vector<int>::iterator test_it_b = test_vector_int.begin();
    TEST::vector<int>::reverse_iterator test_in_it_re = test_input_vector_int.rend();
    TEST::vector<int>::reverse_iterator test_in_it_rb = test_input_vector_int.rbegin();
    TEST::vector<int> test_alloc_test;
    TEST::vector<Buffer> test_vector_buffer;
    unsigned int test_max_size = 0;

    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);
    test_vector_int.insert(test_it_e, 32);
    test_vector_int.push_back(57);
    
    test_it_e = test_vector_int.end();
    test_vector_int.insert(test_it_e, 32);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);
    
    test_it_e++;
    std::cout << "vector_int.capacity = " << (int) test_vector_int.capacity() << std::endl;
    test_vector_int.insert(test_it_e, test_in_it_b, test_in_it_e);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);

    test_it_e = test_vector_int.end();
    std::cout << "vector_int.capacity = " << (int) test_vector_int.capacity() << std::endl;
    test_vector_int.erase(test_it_e - 4, test_it_e);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);

    test_in_it_re = test_input_vector_int.rend();
    test_it_b = test_vector_int.begin();
    std::cout << "vector_int.capacity = " << (int) test_vector_int.capacity() << std::endl;
    test_vector_int.assign(test_in_it_rb, test_in_it_rb + 3);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);

    test_it_b = test_vector_int.begin();
    std::cout << "Back element = " << test_vector_int.back() << std::endl;
    std::cout << "Front element = " << test_vector_int.front() << std::endl;
    test_vector_int.assign(test_in_it_re - 2, test_in_it_re);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);
    std::cout << "Back element = " << test_vector_int.back() << std::endl;
    std::cout << "Front element = " << test_vector_int.front() << std::endl;

    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);
    std::cout << "input_vector_int = ";
    display_vec_int(test_input_vector_int);
    test_input_vector_int.swap(test_vector_int);
    std::cout << "input_vector_int.swap(vector_int)" << std::endl;
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);
    std::cout << "input_vector_int = ";
    display_vec_int(test_input_vector_int);
    std::cout << "vector_int.swap(input_vector_int)" << std::endl;
    test_vector_int.swap(test_input_vector_int);
    std::cout << "vector_int = ";
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);
    std::cout << "input_vector_int = ";
    display_vec_int(test_input_vector_int); 

    std::cout << "is vector_str empty ?: " << test_vector_str.empty() << std::endl;
    std::cout << "is vector_int empty ?: " << test_vector_int.empty() << std::endl;
    std::cout << "size of vector_int = " << test_vector_int.size() << std::endl;
    test_max_size = test_vector_int.max_size();
    std::cout << "max_size of vector_int = " << test_max_size << std::endl;
    test_vector_int.resize(10, 12);
    display_vec_int(test_vector_int);

    std::cout << "vector_int.capacity = " << (int) test_vector_int.capacity() << std::endl;
    std::cout << "size of vector_int = " << test_vector_int.size() << std::endl;
    test_vector_int.reserve(5000000);
    std::cout << "vector_int.capacity = " << (int) test_vector_int.capacity() << std::endl;
    std::cout << "size of vector_int = " << test_vector_int.size() << std::endl;

    int *test_p;
    test_p = test_alloc_test.get_allocator().allocate(10);
    for (int i = 0; i < 10; i++)
        test_alloc_test.get_allocator().construct(&test_p[i], i);
    for (int i = 0; i < 10; i++)
        std::cout << test_p[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        test_alloc_test.get_allocator().destroy(&test_p[i]);
    test_alloc_test.get_allocator().deallocate(test_p, 10);

    return (0);
}
    