// #include "others/includes/rb_tree.hpp"
#include "map/includes/map.hpp"

int main()
{
	// RBTree bst._tree;
    ft::map<int, int> bst;


	bst.insert(8);
    bst._tree.prettyPrint();
	bst.insert(18);
    bst._tree.prettyPrint();
	bst.insert(5);
    bst._tree.prettyPrint();
	bst.insert(15);
	bst._tree.prettyPrint();
    bst.insert(17);
    bst._tree.prettyPrint();
	bst.insert(25);
    bst._tree.prettyPrint();
	bst.insert(40);
    bst._tree.prettyPrint();
	bst.insert(80);
    bst._tree.prettyPrint();
    bst.insert(42);
    bst._tree.prettyPrint();
	bst.insert(11);
    bst._tree.prettyPrint();
	bst.insert(8);
    bst._tree.prettyPrint();
	bst.insert(204);
    bst._tree.prettyPrint();
	bst.insert(111);
    bst._tree.prettyPrint();
	bst._tree.deleteNode(25);
	bst._tree.prettyPrint();
    bst._tree.deleteNode(5);
    bst._tree.prettyPrint();

    ft::map<int, int>::iterator it = bst.begin();
    ft::map<int, int>::iterator ite = bst.end();

    std::cout << "begin = " << it._it->data << std::endl ;
     std::cout << "end = " << ite._it->data << std::endl ;

	return (0);
}