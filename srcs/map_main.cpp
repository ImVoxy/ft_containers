#include "others/includes/rb_tree.hpp"
#include "map/includes/map.hpp"
#include "others/includes/make_pair.hpp"
#include "others/includes/pair.hpp"
#include <iostream>
#include <map>
#include <vector>

#define TEST ft

void display_vec_int(TEST::vector<int> vector_int)
{   
    for (int i = 0 ; i < (int)vector_int.size(); i += 1)
        std::cout << vector_int[i] << ", ";
    std::cout << std::endl;
}

template <typename T>
void    printElem(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second << std::endl;
}

template <typename T>
void    printElem2(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: ";
    display_vec_int(iterator->second);
}

template<typename Tmap>
void    printMap(Tmap &mp)
{
    typename Tmap::const_iterator it = mp.begin(), ite = mp.end();
    std::cout << std::endl << "Content is:" << std::endl;
    for (; it != ite; ++it)
    {
        std::cout << "- ";
        printElem(it);
    }
    std::cout << std::endl;
}

template<typename Tmap>
void    printMapVec(Tmap &mp)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
    typename Tmap::const_iterator it = mp.begin(), ite = mp.end();
    std::cout << std::endl << "Content is:" << std::endl;
    for (; it != ite; ++it)
    {
        std::cout << "- ";
        printElem2(it);
    }
    std::cout << std::endl;
}

int main()
{
    TEST::map<int, int> bst;
    TEST::map<std::string, char> bst2;
    TEST::vector<int> vec1;
    TEST::vector<int> vec2;
    TEST::vector<int> vec3;
    TEST::map<std::string, TEST::vector<int> > vecmap;

    std::cout << "is bst empty ? " << bst.empty() << std::endl;
	bst.insert(TEST::make_pair(8, 1));
    std::cout << "is bst empty ? " << bst.empty() << std::endl << std::endl;
	bst.insert(TEST::make_pair(18, 2));
    printMap(bst);
	bst.insert(TEST::make_pair(5, 3));
    printMap(bst);
	bst.insert(TEST::make_pair(15, 4));
    printMap(bst);
    bst.insert(TEST::make_pair(17, 5));
    printMap(bst);
	bst.insert(TEST::make_pair(25, 6));
    printMap(bst);
	bst.insert(TEST::make_pair(40, 7));
    printMap(bst);
	bst.insert(TEST::make_pair(80, 8));
    printMap(bst);
    bst.insert(TEST::make_pair(42, 9));
    printMap(bst);
	bst.insert(TEST::make_pair(11, 10));
    printMap(bst);
	bst.insert(TEST::make_pair(8, 11));
    printMap(bst);
	bst.insert(TEST::make_pair(204, 12));
    printMap(bst);
	bst.insert(TEST::make_pair(111, 13));
    printMap(bst);
	bst.erase(15);
    bst.erase(5);
    printMap(bst);
    bst.erase(++(++(bst.begin())), --(--(bst.end())));
    printMap(bst);

    TEST::map<int, int> testeq = bst;
    printMap(testeq);
    testeq.clear();

    TEST::map<int, int> testcpy(bst);
    printMap(testcpy);
    testcpy.clear();
    
    
    TEST::map<int, int> cpy(bst);
    printMap(cpy);

    TEST::map<int, int>::iterator it = cpy.begin();
    TEST::map<int, int>::iterator ite = cpy.end();

    TEST::map<int, int> test(it, ite);
    printMap(test);

    TEST::map<int, int>::iterator it_test = test.begin();
    TEST::map<int, int>::iterator ite_test = test.end();

    it++;
    std::cout << "begin key = " << it->first << " val = " << it->second << std::endl ;
    it++;
    std::cout << "begin key = " << it->first << " val = " << it->second << std::endl ;
    it++;
    std::cout << "begin key = " << it->first << " val = " << it->second << std::endl ;
    it++;
    std::cout << "begin key = " << it->first << " val = " << it->second << std::endl ;
    it++;
    std::cout << "begin key = " << it->first << " val = " << it->second << std::endl ;
    it++;
    std::cout << "begin key = " << it->first << " val = " << it->second << std::endl ;

    ite--;
    std::cout << "end key   = " << ite->first << " val = " << ite->second << std::endl ;
    ite--;
    std::cout << "end key   = " << ite->first << " val = " << ite->second << std::endl ;
    ite--;
    std::cout << "end key   = " << ite->first << " val = " << ite->second << std::endl ;
    ite--;
    std::cout << "end key   = " << ite->first << " val = " << ite->second << std::endl ;
    ite--;
    std::cout << "end key   = " << ite->first << " val = " << ite->second << std::endl ;
    ite--;
    std::cout << "end key   = " << ite->first << " val = " << ite->second << std::endl << std::endl;

    it_test++;
    std::cout << "begin key = " << it_test->first << " val = " << it_test->second << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test->first << " val = " << it_test->second << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test->first << " val = " << it_test->second << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test->first << " val = " << it_test->second << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test->first << " val = " << it_test->second << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test->first << " val = " << it_test->second << std::endl ;

    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl ;
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl ;
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl ;
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl ;
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl ;
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl; 
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl;
    ite_test--;
    std::cout << "end key   = " << ite_test->first << " val = " << ite_test->second << std::endl << std::endl;


    std::cout << "count existing          -> " << test.count(11) << std::endl;
    std::cout << "count not existing      -> " << test.count(500) << std::endl;

    std::cout << "find existing           -> " << test.find(11)->first << std::endl;
    std::cout << "find not existing       -> " << (test.find(500) != test.end()) << " (comparison with past the end elem)" << std::endl;

    TEST::map<int, int>::iterator find_test = test.find(11);
    std::cout << "find existing           -> " << find_test->first << std::endl << std::endl;

    std::cout << "size = " << bst.size() << " maxsixe = " << bst.max_size() << std::endl;
    std::cout << "equalrange existing     -> " << bst.equal_range(11).first->first << " ; " << bst.equal_range(11).second->first << std::endl;
    std::cout << "equalrange not existing -> " << bst.equal_range(10).first->first << " ; " << bst.equal_range(10).second->first << std::endl;
    std::cout << "equalrange not existing -> " << (bst.equal_range(250).first != bst.end()) << " (comparison with past the end elem)" << std::endl;
    std::cout << "lowerbound not existing -> " << bst.lower_bound(11)->first << std::endl;
    std::cout << "lowerbound not existing -> " << bst.lower_bound(10)->first << std::endl;
    std::cout << "lowerbound not existing -> " << (bst.lower_bound(250) != bst.end()) << " (comparison with past the end elem)" << std::endl;
    std::cout << "upperbound not existing -> " << bst.upper_bound(11)->first << std::endl;
    std::cout << "upperbound not existing -> " << bst.upper_bound(10)->first << std::endl;
    std::cout << "upperbound not existing -> " << bst.upper_bound(0)->first << std::endl;
    

    //

    vec1.push_back(10);
    vec1.push_back(42);
    vec1.push_back(32);
    vec1.push_back(68);
    vec2.push_back(66);
    vec2.push_back(19);
    vec2.push_back(18);
    vec2.push_back(26);
    vec3.push_back(87);
    vec3.push_back(18);
    vec3.push_back(53);
    vec3.push_back(36);
    vec1.push_back(48);
    vec2.push_back(94);
    vec3.push_back(12);
    TEST::pair<std::string, TEST::vector<int> > pairtest1("bonjour", vec1);
    TEST::pair<std::string, TEST::vector<int> > pairtest2("hello", vec2);
    TEST::pair<std::string, TEST::vector<int> > pairtest3("bye", vec3);
    vecmap.insert(pairtest1);
    vecmap.insert(pairtest2);
    vecmap.insert(pairtest3);
    printMapVec(vecmap);

}
