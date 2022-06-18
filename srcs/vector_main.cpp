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
//     for (int i = 0 : vector_int)
//         std::cout << i << ", ";
//     std::cout << std::endl;
// }

void display_vec_int(ft::vector<int> vector_int)
{   
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (int i = 0 ; i < (int)vector_int.size(); i += 1)
        std::cout << vector_int[i] << ", ";
    std::cout << std::endl;
}

void display_svec_int(std::vector<int> vector_int)
{   
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (int i = 0 ; i < (int)vector_int.size(); i += 1)
        std::cout << vector_int[i] << ", ";
    std::cout << std::endl;
}

int main()
{
    ft::vector<int> testnul(5);
    ft::vector<int> vector_int;
    ft::vector<int> vector_int2;
    ft::vector<int> vector_int3;
    vector_int3.push_back(1);
    vector_int3.push_back(2);
    vector_int3.push_back(3);
    vector_int3.push_back(4);
    std::vector<int> svector_int3;
    svector_int3.push_back(1);
    svector_int3.push_back(2);
    svector_int3.push_back(3);
    svector_int3.push_back(4);
    vector_int.assign(5, 10);
    std::vector<int> svector_int;
    svector_int.assign(5, 10);
    std::vector<int>::iterator sit_e = svector_int.end();
    ft::vector<int>::iterator it3_e = vector_int3.end();
    ft::vector<int>::iterator it3_b = vector_int3.begin();
    ft::vector<int>::iterator it_e = vector_int.end();
    ft::vector<int>::iterator it_b = vector_int.begin();
    std::vector<int>::iterator sit3_e = svector_int3.end();
    std::vector<int>::iterator sit3_b = svector_int3.begin();
    display_vec_int(vector_int);
    vector_int2.assign(it_b, it_e);
    display_vec_int(vector_int2);
    vector_int.push_back(42);
    display_vec_int(vector_int);
    vector_int.pop_back();
    display_vec_int(vector_int);

    it_e--;
    sit_e--;
    it_e--;
    sit_e--;
    it_e--;
    sit_e--;
    vector_int.insert(it_e, 3, 54);
    display_vec_int(vector_int);
    svector_int.insert(sit_e, 3, 54);
    display_svec_int(svector_int);
    
    it_b = vector_int.begin();
    vector_int.insert(it_b, 22);
    display_vec_int(vector_int);
    std::vector<int>::iterator sit_b = svector_int.begin();
    it_b = vector_int.begin();
    svector_int.insert(sit_b, 22);
    display_svec_int(svector_int);
    sit_e = svector_int.end();
    it_e = vector_int.end();

    vector_int.insert(it_e - 3, it3_b, it3_e);
    display_vec_int(vector_int);
    svector_int.insert(sit_e - 3, sit3_b, sit3_e);
    display_svec_int(svector_int);
    it_b = vector_int.begin();
    vector_int.erase(it_b + 5);
    display_vec_int(vector_int);
    sit_b = svector_int.begin();
    svector_int.erase(sit_b + 5);
    display_svec_int(svector_int);
    
    it_b = vector_int.begin();
    it_e = vector_int.end();
    vector_int.erase(it_b + 6, it_e - 3);
    display_vec_int(vector_int);
    sit_b = svector_int.begin();
    sit_e = svector_int.end();
    svector_int.erase(sit_b + 6, sit_e - 3);
    display_svec_int(svector_int);

    std::vector<int> svector_int4;
    svector_int4.push_back(1);
    svector_int4.push_back(2);
    svector_int4.push_back(3);
    svector_int4.push_back(4);
    std::vector<int> svector_int5;
    svector_int5.push_back(5);
    svector_int5.push_back(6);
    svector_int5.push_back(7);
    display_svec_int(svector_int4);
    display_svec_int(svector_int5);
    svector_int4.swap(svector_int5);
    display_svec_int(svector_int4);
    display_svec_int(svector_int5);

    ft::vector<int> vector_int4;
    vector_int4.push_back(1);
    vector_int4.push_back(2);
    vector_int4.push_back(3);
    vector_int4.push_back(4);
    ft::vector<int> vector_int5;
    vector_int5.push_back(5);
    vector_int5.push_back(6);
    vector_int5.push_back(7);
    display_vec_int(vector_int4);
    display_vec_int(vector_int5);
    vector_int4.swap(vector_int5);
    display_vec_int(vector_int4);
    display_vec_int(vector_int5);



    std::cout << std::endl << "\033[1;33m     STD VEC     \033[0m" << std::endl << std::endl;


    std::vector<std::string> stest_vector_str;
	std::vector<int> stest_vector_int;
    std::vector<int> stest_input_vector_int;
    stest_vector_int.push_back(10);
    stest_vector_int.push_back(42);
    stest_vector_int.push_back(32);
    stest_vector_int.push_back(68);
    stest_vector_int.push_back(18);
    stest_input_vector_int.push_back(1);
    stest_input_vector_int.push_back(2);
    stest_input_vector_int.push_back(3);
    stest_input_vector_int.push_back(4);

    std::vector<int>::iterator stest_in_it_e = stest_input_vector_int.end();
    std::vector<int>::iterator stest_in_it_b = stest_input_vector_int.begin();
    std::vector<int>::iterator stest_it_e = stest_vector_int.end();
    std::vector<int>::iterator stest_it_b = stest_vector_int.begin();
    std::vector<int>::reverse_iterator stest_in_it_re = stest_input_vector_int.rend();
    std::vector<int>::reverse_iterator stest_in_it_rb = stest_input_vector_int.rbegin();
    std::vector<int> stest_alloc_test;
    std::vector<Buffer> stest_vector_buffer;
    unsigned int stest_max_size = 0;

    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);
    
    stest_vector_int.insert(stest_it_e, 32);
    stest_vector_int.push_back(57);
    stest_it_e = stest_vector_int.end();
    stest_vector_int.insert(stest_it_e, 32);
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);

    stest_it_e++;
    stest_vector_int.insert(stest_it_e, stest_in_it_b, stest_in_it_e);
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);

    stest_it_e = stest_vector_int.end();
    stest_vector_int.erase(stest_it_e - 4, stest_it_e);
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);

    stest_in_it_re = stest_input_vector_int.rend();
    stest_it_b = stest_vector_int.begin();
    stest_vector_int.assign(stest_in_it_rb, stest_in_it_rb + 3);
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);

    stest_it_b = stest_vector_int.begin();
    std::cout << "Back element = " << stest_vector_int.back() << std::endl;
    std::cout << "Front element = " << stest_vector_int.front() << std::endl;
    stest_vector_int.assign(stest_in_it_re - 2, stest_in_it_re);
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);
    std::cout << "Back element = " << stest_vector_int.back() << std::endl;
    std::cout << "Front element = " << stest_vector_int.front() << std::endl;

    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);
    std::cout << "input_vector_int = ";
    display_svec_int(stest_input_vector_int);
    stest_input_vector_int.swap(stest_vector_int);
    std::cout << "input_vector_int.swap(vector_int)" << std::endl;
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);
    std::cout << "input_vector_int = ";
    display_svec_int(stest_input_vector_int);
    std::cout << "vector_int.swap(input_vector_int)" << std::endl;
    stest_vector_int.swap(stest_input_vector_int);
    std::cout << "vector_int = ";
    std::cout << "vector_int = ";
    display_svec_int(stest_vector_int);
    std::cout << "input_vector_int = ";
    display_svec_int(stest_input_vector_int); 

    std::cout << "is vector_str empty ?: " << stest_vector_str.empty() << std::endl;
    std::cout << "is vector_int empty ?: " << stest_vector_int.empty() << std::endl;
    std::cout << "size of vector_int = " << stest_vector_int.size() << std::endl;
    stest_max_size = stest_vector_int.max_size();
    std::cout << "max_size of vector_int = " << stest_max_size << std::endl;
    stest_vector_int.resize(10, 12);
    display_svec_int(stest_vector_int);

    std::cout << "vector_int.capacity = " << (int)stest_vector_int.capacity() << std::endl;
    std::cout << "size of vector_int = " << stest_vector_int.size() << std::endl;
    stest_vector_int.reserve(5000000);
    std::cout << "vector_int.capacity = " << (int) stest_vector_int.capacity() << std::endl;
    std::cout << "size of vector_int = " << stest_vector_int.size() << std::endl;

    int *stest_p;
    stest_p = stest_alloc_test.get_allocator().allocate(10);
    for (int i = 0; i < 10; i++)
        stest_alloc_test.get_allocator().construct(&stest_p[i], i);
    for (int i = 0; i < 10; i++)
        std::cout << stest_p[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        stest_alloc_test.get_allocator().destroy(&stest_p[i]);
    stest_alloc_test.get_allocator().deallocate(stest_p, 10);

    std::cout << std::endl;
    std::cout << "\033[1;33m     FT VEC     \033[0m" << std::endl << std::endl;
    
    ft::vector<std::string> test_vector_str;
	ft::vector<int> test_vector_int;
    ft::vector<int> test_input_vector_int;
    test_vector_int.push_back(10);
    test_vector_int.push_back(42);
    test_vector_int.push_back(32);
    test_vector_int.push_back(68);
    test_vector_int.push_back(18);
    test_input_vector_int.push_back(1);
    test_input_vector_int.push_back(2);
    test_input_vector_int.push_back(3);
    test_input_vector_int.push_back(4);

    ft::vector<int>::iterator test_in_it_e = test_input_vector_int.end();
    ft::vector<int>::iterator test_in_it_b = test_input_vector_int.begin();
    ft::vector<int>::iterator test_it_e = test_vector_int.end();
    ft::vector<int>::iterator test_it_b = test_vector_int.begin();
    ft::vector<int>::reverse_iterator test_in_it_re = test_input_vector_int.rend();
    ft::vector<int>::reverse_iterator test_in_it_rb = test_input_vector_int.rbegin();
    ft::vector<int> test_alloc_test;
    ft::vector<Buffer> test_vector_buffer;
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
    test_vector_int.insert(test_it_e, test_in_it_b, test_in_it_e);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);

    test_it_e = test_vector_int.end();
    test_vector_int.erase(test_it_e - 4, test_it_e);
    std::cout << "vector_int = ";
    display_vec_int(test_vector_int);

    test_in_it_re = test_input_vector_int.rend();
    test_it_b = test_vector_int.begin();
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
    