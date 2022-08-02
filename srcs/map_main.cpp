// #include "others/includes/rb_tree.hpp"
// #include "map/includes/map.hpp"
// #include "others/includes/make_pair.hpp"

// #define TEST ft

// int main()
// {
//     TEST::map<int, int> bst;
//     TEST::map<std::string, char> bst2;

//     std::cout << "is bst empty ? " << bst.empty() << std::endl;
// 	bst.insert(TEST::make_pair(8, 1));
//     bst._tree.prettyPrint();
//     std::cout << "is bst empty ? " << bst.empty() << std::endl;
// 	bst.insert(TEST::make_pair(18, 2));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(5, 3));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(15, 4));
// 	bst._tree.prettyPrint();
//     bst.insert(TEST::make_pair(17, 5));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(25, 6));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(40, 7));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(80, 8));
//     bst._tree.prettyPrint();
//     bst.insert(TEST::make_pair(42, 9));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(11, 10));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(8, 11));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(204, 12));
//     bst._tree.prettyPrint();
// 	bst.insert(TEST::make_pair(111, 13));
//     bst._tree.prettyPrint();
// 	bst.erase(25);
// 	bst._tree.prettyPrint();
//     bst.erase(5);
//     bst._tree.prettyPrint();

//     TEST::map<int, int> testcpy = bst;
//     testcpy._tree.prettyPrint();
//     testcpy.clear();
    
//     TEST::map<int, int> cpy(bst);
//     cpy._tree.prettyPrint();
//     std::cout << cpy[8] << std::endl;

//     TEST::map<int, int>::iterator it = cpy.begin();
//     TEST::map<int, int>::iterator ite = cpy.end();

//     TEST::map<int, int> test(it, ite);
//     std::cout << test[8] << std::endl;
//     TEST::map<int, int>::iterator it_test = test.begin();
//     TEST::map<int, int>::iterator ite_test = test.end();


//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
//     it++;
//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
//     it++;
//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
//     it++;
//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
//     it++;
//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
//     it++;
//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
//     it++;
//     std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;

//     ite--;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
//     ite--;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
//     ite--;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
//     ite--;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
//     ite--;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
//     ite--;
//     std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl << std::endl;

//     test._tree.prettyPrint();

//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
//     it_test++;
//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
//     it_test++;
//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
//     it_test++;
//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
//     it_test++;
//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
//     it_test++;
//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
//     it_test++;
//     std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;

//     ite_test--;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
//     ite_test--;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
//     ite_test--;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
//     ite_test--;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
//     ite_test--;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
//     ite_test--;
//     std::cout << "end key = " << ite_test.getKey() << " val = " << ite[ite_test.getKey()] << std::endl << std::endl;


//     std::cout << "count existing        -> " << test.count(11) << std::endl;
//     std::cout << "count not existing    -> " << test.count(500) << std::endl;

//     std::cout << "find existing        -> " << test.find(11).getKey() << std::endl;
//     std::cout << "find not existing    -> " << test.find(500).getKey() << std::endl;

//     const TEST::map<int, int>::const_iterator const_test = test.find(11);
//     std::cout << "find existing        -> " << const_test.getKey() << std::endl;

//     std::cout << "size = " << bst.size() << " maxsixe = " << bst.max_size() << std::endl;
// // bst.equal_range(11);
//     std::cout << "equalrange existing ->     " << bst.equal_range(11).first.getKey() << " ; " << bst.equal_range(11).second.getKey() << std::endl;
//     std::cout << "equalrange not existing -> " << bst.equal_range(10).first.getKey() << " ; " << bst.equal_range(10).second.getKey() << std::endl;
//     std::cout << "equalrange not existing -> " << bst.equal_range(250).first.getKey() << " ; " << bst.equal_range(250).second.getKey() << std::endl;
//     std::cout << "lowerbound not existing -> " << bst.lower_bound(11).getKey() << std::endl;
//     std::cout << "lowerbound not existing -> " << bst.lower_bound(10).getKey() << std::endl;
//     std::cout << "lowerbound not existing -> " << bst.lower_bound(250).getKey() << std::endl;
//     std::cout << "upperbound not existing -> " << bst.upper_bound(11).getKey() << std::endl;
//     std::cout << "upperbound not existing -> " << bst.upper_bound(10).getKey() << std::endl;
//     std::cout << "upperbound not existing -> " << bst.upper_bound(0).getKey() << std::endl;
    
// }

#include "../containers_test/srcs/map/common.hpp"
#include <list>

#define T1 int
#define T2 foo<int>
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename MAP>
void    ft_bound(MAP &mp, const T1 &param)
{
        ft_iterator ite = mp.end(), it[2];
        _pair<ft_iterator, ft_iterator> ft_range;

        std::cout << "\t-- [" << iter++ << "] --" << std::endl;
        std::cout << "with key [" << param << "]:" << std::endl;
        it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
        ft_range = mp.equal_range(param);
        std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
        std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
        std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void    ft_const_bound(const MAP &mp, const T1 &param)
{
        ft_const_iterator ite = mp.end(), it[2];
        _pair<ft_const_iterator, ft_const_iterator> ft_range;

        std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
        std::cout << "with key [" << param << "]:" << std::endl;
        it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
        ft_range = mp.equal_range(param);
        std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
        std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
        std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int             main(void)
{
        std::list<T3> lst;
        unsigned int lst_size = 10;
        for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(T3(i + 1, (i + 1) * 3));
        TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
        printSize(mp);

        ft_const_bound(mp, -10);
        ft_const_bound(mp, 1);
        ft_const_bound(mp, 5);
        ft_const_bound(mp, 10);
        ft_const_bound(mp, 50);

        printSize(mp);

        mp.lower_bound(3)->second = 404;
        mp.upper_bound(7)->second = 842;
        ft_bound(mp, 5);
        ft_bound(mp, 7);

        printSize(mp);
        return (0);
}