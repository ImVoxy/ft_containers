// #include "others/includes/rb_tree.hpp"
#include "map/includes/map.hpp"
#include "others/includes/make_pair.hpp"

int main()
{
	// RBTree bst._tree;
    ft::map<int, int> bst;


	bst.insert(ft::make_pair(8, 1));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(18, 2));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(5, 3));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(15, 4));
	bst._tree.prettyPrint();
    bst.insert(ft::make_pair(17, 5));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(25, 6));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(40, 7));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(80, 8));
    bst._tree.prettyPrint();
    bst.insert(ft::make_pair(42, 9));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(11, 10));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(8, 11));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(204, 12));
    bst._tree.prettyPrint();
	bst.insert(ft::make_pair(111, 13));
    bst._tree.prettyPrint();
	bst._tree.deleteNode(25);
	bst._tree.prettyPrint();
    bst._tree.deleteNode(5);
    bst._tree.prettyPrint();

    ft::map<int, int>::iterator it = bst.begin();
    ft::map<int, int>::iterator ite = bst.end();

    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
     std::cout << "end key = " << ite.getKey() << " val = " << bst[ite.getKey()] << std::endl ;

	return (0);
}