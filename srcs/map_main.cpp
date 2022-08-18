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

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp1;
	TESTED_NAMESPACE::map<T1, T2> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	cmp(mp1, mp1); // 0
	cmp(mp1, mp2); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	cmp(mp1, mp2); // 2
	cmp(mp2, mp1); // 3

	(++(++mp1.begin()))->second = 42;

	cmp(mp1, mp2); // 4
	cmp(mp2, mp1); // 5

	swap(mp1, mp2);

	cmp(mp1, mp2); // 6
	cmp(mp2, mp1); // 7

	return (0);
}