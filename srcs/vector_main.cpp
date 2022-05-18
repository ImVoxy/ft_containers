#include <iostream>
#include <vector>
#include <string>
#include "vector/includes/vector.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

// void display_vec_int(std::vector<int> vector_int)
// {
//     for (int i : vector_int)
//         std::cout << i << ", ";
//     std::cout << std::endl;
// }

void display_vec_int(std::vector<int> vector_int)
{   
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (unsigned i = 0 ; i < vector_int.size(); i++)
        std::cout << vector_int.at(i) << ", ";
    std::cout << std::endl;
}

int vector_test()
{
    std::vector<std::string> vector_str;
	std::vector<int> vector_int;
    std::vector<int> input_vector_int;
    std::vector<int>::iterator in_it_e = input_vector_int.end();
    std::vector<int>::iterator in_it_b = input_vector_int.begin();
    std::vector<int>::iterator it_e = vector_int.end();
    std::vector<int>::iterator it_b = vector_int.begin();
    std::vector<int>::reverse_iterator in_it_re = input_vector_int.rend();
    std::vector<int>::reverse_iterator in_it_rb = input_vector_int.rbegin();
    std::vector<int> alloc_test;
    std::vector<Buffer> vector_buffer;
    unsigned int max_size = 0;

    vector_int.push_back(10);
    vector_int.push_back(42);
    vector_int.push_back(32);
    vector_int.push_back(68);
    vector_int.push_back(18);
    input_vector_int.push_back(1);
    input_vector_int.push_back(2);
    input_vector_int.push_back(3);
    input_vector_int.push_back(4);

    std::cout << "vector_int = ";
    display_vec_int(vector_int);

    vector_int.insert(it_e, 32);
    vector_int.push_back(57);
    it_e = vector_int.end();
    vector_int.insert(it_e, 32);
    std::cout << "vector_int = ";
    display_vec_int(vector_int);

    vector_int.insert(it_e + 1, in_it_b, in_it_e);
    std::cout << "vector_int = ";
    display_vec_int(vector_int);

    it_e = vector_int.end();
    vector_int.erase(it_e - 4, it_e);
    std::cout << "vector_int = ";
    display_vec_int(vector_int);

    in_it_re = input_vector_int.rend();
    it_b = vector_int.begin();
    vector_int.assign(in_it_rb, in_it_rb + 3);
    std::cout << "vector_int = ";
    display_vec_int(vector_int);

    it_b = vector_int.begin();
    std::cout << "Back element = " << vector_int.back() << std::endl;
    std::cout << "Front element = " << vector_int.front() << std::endl;
    vector_int.assign(in_it_re - 2, in_it_re);
    std::cout << "vector_int = ";
    display_vec_int(vector_int);
    std::cout << "Back element = " << vector_int.back() << std::endl;
    std::cout << "Front element = " << vector_int.front() << std::endl;

    std::cout << "vector_int = ";
    display_vec_int(vector_int);
    std::cout << "input_vector_int = ";
    display_vec_int(input_vector_int);
    input_vector_int.swap(vector_int);
    std::cout << "input_vector_int.swap(vector_int)" << std::endl;
    std::cout << "vector_int = ";
    display_vec_int(vector_int);
    std::cout << "input_vector_int = ";
    display_vec_int(input_vector_int);
    std::cout << "vector_int.swap(input_vector_int)" << std::endl;
    vector_int.swap(input_vector_int);
    std::cout << "vector_int = ";
    std::cout << "vector_int = ";
    display_vec_int(vector_int);
    std::cout << "input_vector_int = ";
    display_vec_int(input_vector_int); 

    std::cout << "is vector_str empty ?: " << vector_str.empty() << std::endl;
    std::cout << "is vector_int empty ?: " << vector_int.empty() << std::endl;
    std::cout << "size of vector_int = " << vector_int.size() << std::endl;
    max_size = vector_int.max_size();
    std::cout << "max_size of vector_int = " << max_size << std::endl;
    vector_int.resize(10, 12);
    display_vec_int(vector_int);

    std::cout << "vector_int.capacity = " << (int) vector_int.capacity() << std::endl;
    std::cout << "size of vector_int = " << vector_int.size() << std::endl;
    vector_int.reserve(5000000);
    std::cout << "vector_int.capacity = " << (int) vector_int.capacity() << std::endl;
    std::cout << "size of vector_int = " << vector_int.size() << std::endl;

    int *p;
    p = alloc_test.get_allocator().allocate(10);
    for (int i = 0; i < 10; i++)
        std::cout << p[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        alloc_test.get_allocator().construct(&p[i], i);
    for (int i = 0; i < 10; i++)
        std::cout << p[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        alloc_test.get_allocator().destroy(&p[i]);
    alloc_test.get_allocator().deallocate(p, 10);

    return (0);
}
    