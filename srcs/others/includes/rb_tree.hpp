#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"

namespace ft
{
	template<class Key, class T>
	struct Node
	{
		ft::pair<const Key, T>	*elem;
		int						color;
		Node					*parent;
		Node 					*left;
		Node 					*right;
	};

	

	template < class Key, class T, class Compare = std::less<Key>,              
			class Alloc = std::allocator<pair<const Key,T> > >
	class RBTree
	{
		protected:
		public:
			typedef Key     					key_type;
			typedef T       					mapped_type;
			typedef Compare						key_compare;
			typedef Alloc   					allocator_type;
			typedef Node<key_type, mapped_type> *NodePtr;

			RBTree(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			{
				_alloc								= alloc;
				_comp								= comp;
				setSnode();
			}

			~RBTree()
			{
				root = NULL;
				SNODE->elem->first.~key_type();
				SNODE->elem->second.~mapped_type();
				_alloc.deallocate(SNODE->elem, 1);
				_allocn.deallocate(SNODE, 1);
			}

			void swap (RBTree& x)
			{
				std::swap(root, x.root);
            	std::swap(SNODE, x.SNODE);
			}

			void sentryNodeInsertChecker(NodePtr node)
			{
				if (SNODE->color == 1 || (_comp(SNODE->parent->elem->first, node->elem->first)))
					SNODE->parent = node;
				if (SNODE->color == 1)
					SNODE->color = 2;
			}

			void sentryNodeDeleteChecker(key_type key)
			{
				if (SNODE->parent->elem->first == key)
				{
					if (SNODE->parent->left->color != 2)
						SNODE->parent = SNODE->parent->left;
					else if (SNODE->parent->parent)
						SNODE->parent = SNODE->parent->parent;
					else
					{
						SNODE->parent = NULL;
						SNODE->color = 1;
					}
				}
			}

			NodePtr searchTree(key_type k) const
			{
				return searchTreeHelper(this->root, k);
			}

			NodePtr minimum(NodePtr node)
			{
				while (node->left != SNODE)
					node = node->left;
				return node;
			}

			NodePtr maximum(NodePtr node)
			{
				while (node->right != SNODE)
					node = node->right;
				return node;
			}

			NodePtr successor(NodePtr x)
			{
				if (x->right != SNODE)
					return minimum(x->right);
				NodePtr y = x->parent;
				while (y != SNODE && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x)
			{
				NodePtr y = x->parent;

				if (x->left != SNODE)
					return maximum(x->left);
				while (y != SNODE && x == y->left)
				{
					x = y;
					y = y->parent;
				}

				return y;
			}

			void leftRotate(NodePtr x)
			{
				NodePtr y = x->right;

				x->right = y->left;
				if (y->left != SNODE)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					this->root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void rightRotate(NodePtr x)
			{
				NodePtr y = x->left;

				x->left = y->right;
				if (y->right != SNODE)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					this->root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else 
					x->parent->left = y;
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
				sentryNodeInsertChecker(node);
				node->left = SNODE;
				node->right = SNODE;
				node->color = 1;

				NodePtr y = NULL;
				NodePtr x = this->root;

				while (x != SNODE)
				{
					y = x;
					if (_comp(node->elem->first, x->elem->first))
						x = x->left;
					else
						x = x->right;
				}

				node->parent = y;
				if (y == NULL)
					root = node;
				else if (_comp(node->elem->first, y->elem->first))
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

			void	setSnode()
			{
				ft::pair<const key_type, mapped_type> *tmp;

				tmp = _alloc.allocate(1);
				SNODE = _allocn.allocate(1);
				SNODE->elem = tmp;
				_alloc.construct(SNODE->elem, ft::pair<const key_type, mapped_type>());
				SNODE->color = 1;
				SNODE->left = NULL;
				SNODE->right = NULL;
				root = SNODE;
			}

			NodePtr getRoot(){return this->root;}
			NodePtr getSnode(){return this->SNODE;}
			const NodePtr getRoot() const {return this->root;}
			std::allocator<Node<Key, T> > get_allocator() const{return (this->_allocn);}

			void deleteNode(key_type key)
			{
				sentryNodeDeleteChecker(key);
				deleteNodeHelper(this->root, key);
				
			}

			// void prettyPrint() {
			// 	if (root) {
			// 		printHelper(this->root, "", true);
			// 	}
			// }

			int isin(const key_type i)
			{
				NodePtr tmp = this->root;

				while((tmp->right || tmp->left))
				{
					if (tmp->left && (_comp(i, tmp->elem->first)))
						tmp = tmp->left; 
					else if (tmp->right && (_comp(tmp->elem->first, i)))
						tmp	= tmp->right;
					else if (i == tmp->elem->first)
						return (1);
					else
						return (0);
				}
				return (0);
			}

		private:
			NodePtr 						root;
			NodePtr							SNODE;
			Alloc							_alloc;
			std::allocator<Node<Key, T> >	_allocn;
			Compare							_comp;

			void initializeNULLNode(NodePtr node, NodePtr parent) {
				node->elem->first	= 0;
				node->elem->second	= 0;
				node->parent		= parent;
				node->left			= NULL;
				node->right			= NULL;
				node->color			= 0;
			}

			NodePtr searchTreeHelper(NodePtr node, key_type key) const
			{
				if (node == SNODE || key == node->elem->first)
					return node;
				if (_comp(key, node->elem->first))
					return searchTreeHelper(node->left, key);
				return searchTreeHelper(node->right, key);
			}

			void fixDelete(NodePtr x) {
				NodePtr s;
				while (x != root && x->color == 0) {
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == 1) {
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color != 1 && s->right->color != 1)
						{
							if (s->color != 2)
								s->color = 1;
							x = x->parent;
						}
						else
						{
							if (s->right->color != 1)
							{
								if (s->left->color != 2)
									s->left->color = 0;
								if (s->color != 2)
									s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							} 
							if (s->color != 2)
								s->color = x->parent->color;
							if (s->parent->color != 2)
								x->parent->color = 0;
							if (s->right->color != 2)
								s->right->color = 0;
							leftRotate(x->parent);
							x = root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == 1)
						{
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color != 1)
						{
							if (s->color != 2)
								s->color = 1;
							x = x->parent;
						}
						else
						{
							if (s->left->color != 1)
							{
								if (s->color != 2)
									s->right->color = 0;
								if (s->color != 2)
									s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							} 
							if (s->color != 2)
								s->color = x->parent->color;
							x->parent->color = 0;
							if (s->left->color != 2)
								s->left->color = 0;
							rightRotate(x->parent);
							x = root;
						}
					} 
				}
				if (x->color != 2)
					x->color = 0;
			}


			void rbTransplant(NodePtr u, NodePtr v)
			{
				if (u->parent == NULL)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v->color != 2)
					v->parent = u->parent;
			}

			void deleteNodeHelper(NodePtr node, key_type key) {
				NodePtr z = SNODE;
				NodePtr x, y;

				while (node != SNODE)
				{
					if (node->elem->first == key)
						z = node;
					if (!(_comp(key, node->elem->first)))
						node = node->right;
					else 
						node = node->left;
				}
				if (z == SNODE)
					return;
				y = z;
				int y_original_color = y->color;
				
				if (z->left == SNODE)
				{
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == SNODE)
				{
					x = z->left;
					rbTransplant(z, z->left);
				}
				
				else
				{	
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z && x->color != 2)
						x->parent = y;
					else
					{
						rbTransplant(y, y->right);
						y->right = z->right;
						if (y->right->color != 2)
							y->right->parent = y;
					}
					rbTransplant(z, y);
					y->left = z->left;
					if (y->left->color != 2)
					{
						y->left->parent = y;
						y->color = z->color;
					}
				}
				z->elem->first.~key_type();
				z->elem->second.~mapped_type();
				_alloc.deallocate(z->elem, 1);
				_allocn.deallocate(z, 1);
				if (y_original_color == 0)
					fixDelete(x);
			}
			
			ft::pair<NodePtr, bool> fixInsert(NodePtr k)
			{
				NodePtr u;

				while (k->parent->color == 1)
				{
					if (k->parent == k->parent->parent->right)
					{
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

		// 	void printHelper(NodePtr root, std::string indent, bool last)
		// 	{
		// 		if (root != SNODE) {
		// 		std::cout<<indent;
		// 		if (last)
		// 		{
		// 			std::cout << "R----";
		// 			indent += "     ";
		// 		}
		// 		else
		// 		{
		// 			std::cout << "L----";
		// 			indent += "|    ";
		// 		}
					
		// 		std::string sColor = root->color ? "RED" : "BLACK";
		// 		std::cout << root->elem->first << "("<<sColor<<")" << std::endl;
		// 		printHelper(root->left, indent, false);
		// 		printHelper(root->right, indent, true);
		// 	}
		// }
	};
}

#endif