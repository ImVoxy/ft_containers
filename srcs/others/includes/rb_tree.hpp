#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"

// using namespace std;

namespace ft
{
	template<class Key, class T>
	struct Node {
		ft::pair<const Key, T> *elem;
		int color; // 1 -> Red, 0 -> Black
		Node *parent;
		Node *left;
		Node *right;
		
	};

	

	template < class Key, class T, class Compare = std::less<Key>,              
			class Alloc = std::allocator<pair<const Key,T> > >
	class RBTree
	{
		protected:
			Alloc					_alloc;
			std::allocator<Node<Key, T> >	_allocn;
			Compare					_comp;

		public:
			typedef Key     key_type;
			typedef T       mapped_type;
			typedef Compare	key_compare;
			typedef Alloc   allocator_type;
			typedef Node<key_type, mapped_type> *NodePtr;

			RBTree(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_comp = comp;
				ft::pair<const key_type, mapped_type> *tmp;

				TNULL = _allocn.allocate(1);
				tmp = _alloc.allocate(1);
				TNULL->elem = tmp;
				_alloc.construct(TNULL->elem, ft::pair<const key_type, mapped_type>());

				TNULL->color = 0;
				TNULL->left = NULL;
				TNULL->right = NULL;
				root = TNULL;
			}
			~RBTree()
			{
				_alloc.deallocate(TNULL->elem, 1);
				_allocn.deallocate(TNULL, 1);
			}

			void preorder() {
				preOrderHelper(this->root);
			}

			void inorder() {
				inOrderHelper(this->root);
			}

			void postorder() {
				postOrderHelper(this->root);
			}

			NodePtr searchTree(int k) const {
				return searchTreeHelper(this->root, k);
			}

			NodePtr minimum(NodePtr node) {
				while (node->left != TNULL) {
					node = node->left;
				}
				return node;
			}

			NodePtr maximum(NodePtr node) {
				while (node->right != TNULL) {
					node = node->right;
				}
				return node;
			}

			NodePtr successor(NodePtr x) {
				if (x->right != TNULL) {
					return minimum(x->right);
				}

				NodePtr y = x->parent;
				while (y != TNULL && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) {
				if (x->left != TNULL) {
					return maximum(x->left);
				}

				NodePtr y = x->parent;
				while (y != TNULL && x == y->left) {
					x = y;
					y = y->parent;
				}

				return y;
			}

			void leftRotate(NodePtr x) {
				NodePtr y = x->right;
				x->right = y->left;
				if (y->left != TNULL) {
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->root = y;
				} else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			void rightRotate(NodePtr x) {
				NodePtr y = x->left;
				x->left = y->right;
				if (y->right != TNULL) {
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->root = y;
				} else if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			ft::pair<NodePtr, bool> insert(ft::pair<key_type, mapped_type> in)
			{
				ft::pair<const key_type, mapped_type> *tmp;
				if (isin(in.first))
					return (ft::make_pair(searchTree(in.first), 0));

				NodePtr node = _allocn.allocate(1);
				node->parent = NULL;
				tmp = _alloc.allocate(1);
				node->elem = tmp;
				_alloc.construct(node->elem, ft::pair<const key_type, mapped_type>(in.first, in.second));
				node->left = TNULL;
				node->right = TNULL;
				node->color = 1;

				NodePtr y = NULL;
				NodePtr x = this->root;

				while (x != TNULL)
				{
					y = x;
					if (node->elem->first < x->elem->first)
						x = x->left;
					else
						x = x->right;
				}

				node->parent = y;
				if (y == NULL)
					root = node;
				else if (node->elem->first < y->elem->first)
					y->left = node;
				else
					y->right = node;
				if (node->parent == NULL)
				{
					node->color = 0;
					return (ft::make_pair(node, true));
				}
				if (node->parent->parent == NULL)
					return (ft::make_pair(node, true));
				return (fixInsert(node));
			}

			NodePtr getRoot(){
				return this->root;
			}

			const NodePtr getRoot() const {
				return this->root;
			}

			void deleteNode(key_type key) {
				deleteNodeHelper(this->root, key);
			}

			void prettyPrint() {
				if (root) {
					printHelper(this->root, "", true);
				}
			}

			int isin(const key_type i)
			{
				NodePtr tmp = this->root;

				while(tmp->right || tmp->left)
				{
					if (tmp->left && i < tmp->elem->first)
						tmp = tmp->left; 
					else if (tmp->right && i > tmp->elem->first)
						tmp	= tmp->right;
					else if (i == tmp->elem->first)
						return (1);
					else
						return (0);
				}
				return (0);
			}

		private:
			NodePtr root;
			NodePtr TNULL;

			void initializeNULLNode(NodePtr node, NodePtr parent) {
				node->elem->first	= 0;
				node->elem->second	= 0;
				node->parent		= parent;
				node->left			= NULL;
				node->right			= NULL;
				node->color			= 0;
			}

			void preOrderHelper(NodePtr node) {
				if (node != TNULL) {
					std::cout << node->elem->first << " ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				} 
			}

			void inOrderHelper(NodePtr node) {
				if (node != TNULL) {
					inOrderHelper(node->left);
					std::cout << node->elem->first <<" ";
					inOrderHelper(node->right);
				} 
			}

			void postOrderHelper(NodePtr node) {
				if (node != TNULL) {
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout << node->elem->first <<" ";
				} 
			}

			NodePtr searchTreeHelper(NodePtr node, key_type key) const {
				if (node == TNULL || key == node->elem->first) {
					return node;
				}

				if (key < node->elem->first) {
					return searchTreeHelper(node->left, key);
				} 
				return searchTreeHelper(node->right, key);
			}

			void fixDelete(NodePtr x) {
				NodePtr s;
				while (x != root && x->color == 0) {
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == 1) {
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == 0 && s->right->color == 0) {
							s->color = 1;
							x = x->parent;
						} else {
							if (s->right->color == 0) {
								s->left->color = 0;
								s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							} 

							s->color = x->parent->color;
							x->parent->color = 0;
							s->right->color = 0;
							leftRotate(x->parent);
							x = root;
						}
					} else {
						s = x->parent->left;
						if (s->color == 1) {
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == 0 && s->right->color == 0) {
							s->color = 1;
							x = x->parent;
						} else {
							if (s->left->color == 0) {
								s->right->color = 0;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							} 

							s->color = x->parent->color;
							x->parent->color = 0;
							s->left->color = 0;
							rightRotate(x->parent);
							x = root;
						}
					} 
				}
				x->color = 0;
			}


			void rbTransplant(NodePtr u, NodePtr v){
				if (u->parent == NULL) {
					root = v;
				} else if (u == u->parent->left){
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			void deleteNodeHelper(NodePtr node, key_type key) {
				NodePtr z = TNULL;
				NodePtr x, y;
				while (node != TNULL){
					if (node->elem->first == key) {
						z = node;
					}

					if (node->elem->first <= key) {
						node = node->right;
					} else {
						node = node->left;
					}
				}

				if (z == TNULL) {
					// std::cout << "Couldn't find key in the tree" << std::endl;
					return;
				} 

				y = z;
				int y_original_color = y->color;
				if (z->left == TNULL) {
					x = z->right;
					rbTransplant(z, z->right);
				} else if (z->right == TNULL) {
					x = z->left;
					rbTransplant(z, z->left);
				} else {
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z) {
						x->parent = y;
					} else {
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				_alloc.deallocate(z->elem, 1);
				_allocn.deallocate(z, 1);
				if (y_original_color == 0){
					fixDelete(x);
				}
			}
			
			ft::pair<NodePtr, bool> fixInsert(NodePtr k)
			{
				NodePtr u;

				while (k->parent->color == 1)
				{
					if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left;
						if (u->color == 1)
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;

						if (u->color == 1)
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;	
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root)
						break;
				}
				root->color = 0;
				return (ft::make_pair(k, true));
			}

			void printHelper(NodePtr root, std::string indent, bool last)
			{
				if (root != TNULL) {
				std::cout<<indent;
				if (last)
				{
					std::cout << "R----";
					indent += "     ";
				}
				else
				{
					std::cout << "L----";
					indent += "|    ";
				}
					
				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->elem->first << "("<<sColor<<")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}
	};
}