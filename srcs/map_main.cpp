#include "others/includes/rb_tree.hpp"

int main()
{
	RBTree bst;

	bst.insert(8);
    bst.prettyPrint();
	bst.insert(18);
    bst.prettyPrint();
	bst.insert(5);
    bst.prettyPrint();
	bst.insert(15);
	bst.prettyPrint();
    bst.insert(17);
    bst.prettyPrint();
	bst.insert(25);
    bst.prettyPrint();
	bst.insert(40);
    bst.prettyPrint();
	bst.insert(80);
    bst.prettyPrint();
    bst.insert(42);
    bst.prettyPrint();
	bst.insert(11);
    bst.prettyPrint();
	bst.insert(8);
    bst.prettyPrint();
	bst.insert(204);
    bst.prettyPrint();
	bst.insert(111);
    bst.prettyPrint();
	bst.deleteNode(25);
	bst.prettyPrint();
    bst.deleteNode(5);
    bst.prettyPrint();

	return (0);
}