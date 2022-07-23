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

    ft::map<int, int> test(it, ite);

    ft::map<int, int>::iterator it_test = test.begin();
    ft::map<int, int>::iterator ite_test = test.end();


    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
    it++;
    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
    it++;
    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
    it++;
    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
    it++;
    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
    it++;
    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;
    it++;
    std::cout << "begin key = " << it.getKey() << " val = " << it[it.getKey()] << std::endl ;

    ite--;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
    ite--;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
    ite--;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
    ite--;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
    ite--;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl ;
    ite--;
    std::cout << "end key = " << ite.getKey() << " val = " << ite[ite.getKey()] << std::endl << std::endl;

    test._tree.prettyPrint();

    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;
    it_test++;
    std::cout << "begin key = " << it_test.getKey() << " val = " << it_test[it_test.getKey()] << std::endl ;

    ite_test--;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
    ite_test--;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
    ite_test--;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
    ite_test--;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
    ite_test--;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite_test[ite_test.getKey()] << std::endl ;
    ite_test--;
    std::cout << "end key = " << ite_test.getKey() << " val = " << ite[ite_test.getKey()] << std::endl << std::endl;


    std::cout << "count existing        -> " << test.count(11) << std::endl;
    std::cout << "count not existing    -> " << test.count(500) << std::endl;

    std::cout << "find existing        -> " << test.find(11).getKey() << std::endl;
    std::cout << "find not existing    -> " << test.find(500).getKey() << std::endl;

    const ft::map<int, int>::iterator const_test = test.find(11);
    std::cout << "find existing        -> " << const_test.find(11).getKey() << std::endl;
    std::cout << "find not existing    -> " << const_test.find(500).getKey() << std::endl;

	return (0);
}