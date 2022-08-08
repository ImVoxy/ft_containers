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
#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP>
void	ft_erase(MAP &mp, const T1 param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	
	mp.erase(param);
	mp._tree.prettyPrint();
	printSize(mp);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;

	mp[42] = "lol";

	mp[50] = "mdr";

	mp[25] = "funny";

	mp[46] = "bunny";

	mp[21] = "fizz";

	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

	printSize(mp);

	/* A classic btree should give this:
	 *                                      42
	 *                     /                                            \
	 *                    25                                            50
	 *           /                 \                         /                       \
	 *          21                 30                       46                       55
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
	 *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
	 *
	 * */
	mp._tree.prettyPrint();
	ft_erase(mp, 25); // right != NULL; left != NULL
	// ft_erase(mp, 55); // right != NULL; left != NULL

	// /* After deleting 25 and 55, I would get:
	//  *                                      42
	//  *                     /                                            \
	//  *                    24                                            50
	//  *           /                 \                         /                      \
	//  *          21                 30                       46                      54
	//  *      /       \           /      \                /       \             /           \
	//  *     18       23        28        35            44         48         53             80
	//  *   /   \    /         /    \     /   \        /   \       /   \     /              /     \
	//  *  12   20  22        27    29  33    38     43    45    47    49   51             60      90
	//  *
	//  * */

	// ft_erase(mp, 24); // right != NULL; left != NULL
	// ft_erase(mp, 54); // right != NULL; left != NULL

	// /* After deleting 24 and 54, I would get:
	//  *                                      42
	//  *                     /                                            \
	//  *                    23                                            50
	//  *           /                 \                         /                      \
	//  *          21                 30                       46                      53
	//  *      /       \           /      \                /       \             /           \
	//  *     18       22        28        35            44         48         51             80
	//  *   /   \              /    \     /   \        /   \       /   \                    /     \
	//  *  12   20            27    29  33    38     43    45    47    49                  60      90
	//  *
	//  * */

	// ft_erase(mp, 22); // right == NULL; left == NULL
	// ft_erase(mp, 51); // right == NULL; left == NULL

	// ft_erase(mp, 21); // right == NULL; left != NULL
	// ft_erase(mp, 53); // right != NULL; left == NULL

	// /* After deleting 22, 51 and then 21, 53, I would get:
	//  *                                      42
	//  *                     /                                            \
	//  *                    23                                            50
	//  *           /                 \                         /                      \
	//  *          20                 30                       46                      80
	//  *      /                   /      \                /       \                /        \
	//  *     18                 28        35            44         48             60         90
	//  *   /                  /    \     /   \        /   \       /   \
	//  *  12                 27    29  33    38     43    45    47    49
	//  *
	//  * */

	// ft_erase(mp, 20); // right == NULL; left != NULL

	// /* After deleting 20, I would get:
	//  *                                      42
	//  *                     /                                            \
	//  *                    23                                            50
	//  *           /                 \                         /                      \
	//  *          18                 30                       46                      80
	//  *      /                   /      \                /       \                /        \
	//  *     12                 28        35            44         48             60         90
	//  *                      /    \     /   \        /   \       /   \
	//  *                     27    29  33    38     43    45    47    49
	//  *
	//  * */

	// ft_erase(mp, 23); // right != NULL; left != NULL

	// /* After deleting 23, I would get:
	//  *                                      42
	//  *                     /                                            \
	//  *                    18                                            50
	//  *           /                 \                         /                      \
	//  *          12                 30                       46                      80
	//  *                          /      \                /       \                /        \
	//  *                        28        35            44         48             60         90
	//  *                      /    \     /   \        /   \       /   \
	//  *                     27    29  33    38     43    45    47    49
	//  *
	//  * */

	// ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL

	// /* After deleting 42, I would get:
	//  *                                      38
	//  *                     /                                            \
	//  *                    18                                            50
	//  *           /                 \                         /                      \
	//  *          12                 30                       46                      80
	//  *                          /      \                /       \                /        \
	//  *                        28        35            44         48             60         90
	//  *                      /    \     /            /   \       /   \
	//  *                     27    29  33           43    45    47    49
	//  *
	//  * */

	// ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL

	// /* After deleting 38, I would get:
	//  *                                      35
	//  *                     /                                            \
	//  *                    18                                            50
	//  *           /                 \                         /                      \
	//  *          12                 30                       46                      80
	//  *                          /      \                /       \                /        \
	//  *                        28        33            44         48             60         90
	//  *                      /    \                  /   \       /   \
	//  *                     27    29               43    45    47    49
	//  *
	//  * */

	// ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL

	// /* After deleting 35, I would get:
	//  *                                      33
	//  *                     /                                            \
	//  *                    18                                            50
	//  *           /                 \                         /                      \
	//  *          12                 30                       46                      80
	//  *                          /                       /       \                /        \
	//  *                        28                      44         48             60         90
	//  *                      /    \                  /   \       /   \
	//  *                     27    29               43    45    47    49
	//  *
	//  * */

	// ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL

	// /* After deleting 33, I would get:
	//  *                                      30
	//  *                     /                                            \
	//  *                    18                                            50
	//  *           /                 \                         /                      \
	//  *          12                 28                       46                      80
	//  *                          /      \                /       \                /        \
	//  *                        27       29             44         48             60         90
	//  *                                              /   \       /   \
	//  *                                            43    45    47    49
	//  *
	//  * */

	return (0);
}