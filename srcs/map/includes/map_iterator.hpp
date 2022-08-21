#include "map.hpp"
#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft
{

	template < typename Iterator, typename Container >
	class map_iterator
	{
		typedef iterator_traits< Iterator > traits;

		private:
		protected:
			Node<typename Container::key_type, typename Container::mapped_type> *_node;
			Iterator	_it;



		public:
			typedef Iterator                          	iterator_type;
			typedef typename Container::key_type		key_type;
			typedef typename Container::mapped_type		mapped_type;
			typedef typename traits::iterator_category	iterator_category;
			typedef typename traits::value_type       	value_type;
			typedef typename traits::difference_type  	difference_type;
			typedef typename traits::reference        	reference;
			typedef typename traits::pointer          	pointer;

//  Constructors and destructors
			map_iterator() : _node(NULL), _it(NULL) {}
			explicit map_iterator(const Iterator& it) : _node(it), _it(_node->elem) {}
			explicit map_iterator(Node<key_type, mapped_type> *it) : _node(it), _it(_node->elem) {}
			template < typename T >
			map_iterator(const map_iterator< T,
					typename enable_if< is_same< T, typename Container::pointer >::value,
										Container >::type >& it): _node(it.getNode()), _it(_node->elem) {}
			~map_iterator(){}
//  Access
			const Iterator& base() const { return _node->elem; }
			reference operator*() const { return (*(_node->elem)); }
			pointer operator->() const {return _node->elem;}
			mapped_type operator[](difference_type ptr) const
			{
				(void)ptr;
				return (_node->elem->second);
			}
			Node<key_type, mapped_type> *getNode() const { return (_node); }
			key_type getKey() const {return (_node->elem->first);}

//  Assignation
			map_iterator& operator++()
			{
				Node<key_type, mapped_type> *tmp = _node->parent;

				if (_node->color != 2)
				{
					if (_node->right->parent == _node && _node->right->color == 2)
					{
						_node = _node->right;
						return *this;
					}
					if (_node->right->color != 2)
					{
						_node = _node->right;
						while (_node->left->color != 2)
							_node = _node->left;
					}
					else
					{
						if (tmp && tmp->right == _node)
							while (tmp && tmp->right == _node)
							{
								_node = tmp;
								tmp = _node->parent;
							}
						if (tmp->color != 2 && _node->right != tmp)
						{
							_node = tmp;
						}
					}
				}
				else
				_node = tmp;
				
				return (*this);
			}
			map_iterator operator++(int)
			{ 
				map_iterator tmp = *this;
				++*this;
				return (tmp);
			}
			map_iterator& operator--()
			{
				Node<key_type, mapped_type> *tmp = _node->parent;

				if (_node->color == 2)
				{						
					_node = _node->parent;
					return (*this);
				}
				if (_node->left->color != 2)
				{
					_node = _node->left;
					while (_node->right->color != 2)
					{
						_node = _node->right;
					}
				}
				else
				{
					if (tmp->color != 2 && tmp->left == _node)
						while(tmp->color != 2 && tmp->left == _node)
						{
							_node = tmp;
							if (_node->parent)
								tmp = _node->parent;
							else 
							{
								while (_node->color != 2)
									_node = _node->right;
								return (*this);
							}
						}
					if (_node->left != tmp)
						_node = tmp;
				}
				return (*this);
			}
			map_iterator operator--(int)
			{
				map_iterator tmp = *this;
				--*this;
				return (tmp);
			}
			map_iterator& operator+=(difference_type ptr)
			{
				while (ptr--)
					this++;
				return (*this);
			}
			map_iterator operator+(difference_type ptr) const
			{
				map_iterator tmp = *this;
				while (ptr--)
					tmp++;
				return (tmp);
			}

			map_iterator& operator-=(difference_type ptr)
			{
				while (ptr--)
					this--;
				return (*this);
			}
			map_iterator operator-(difference_type ptr) const
			{
				map_iterator tmp = *this;
				while (ptr--)
					tmp--;
				return (tmp);
			}
		};

		template <class Iter, class Cont>
    	typename ft::map_iterator<Iter, Cont> operator+ (
                                    typename map_iterator<Iter, Cont>::difference_type n,
                                    const map_iterator<Iter, Cont>& it)
		{
			return (map_iterator<Iter, Cont>(it.getKey() + n));
		}


		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator==(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{
			if (lhs.getNode() == NULL || rhs.getNode() == NULL)
			{
				if (lhs.getNode() != NULL || rhs.getNode() != NULL)
				{
					return (0);
				}
				else
					return (1);
			}
			return (*(lhs.getNode()->elem) == *(rhs.getNode()->elem));
		}

//  Relational operators
		template < typename Iterator, typename Container >
		bool operator==(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{
			if (lhs.getNode() == NULL || rhs.getNode() == NULL)
			{
				if (lhs.getNode() != NULL || rhs.getNode() != NULL)
				{
					return (0);
				}
				else
					return (1);
			}
			return (lhs.getNode()->elem == rhs.getNode()->elem);
		}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator!=(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{
			return (!(rhs == lhs));
		}

		template < typename Iterator, typename Container >
		bool operator!=(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{
			return (!(rhs == lhs));
		}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator<(const map_iterator< IteratorL, Container >& lhs,
					    const map_iterator< IteratorR, Container >& rhs)
		{return (*(lhs.getNode()->elem) < *(rhs.getNode()->elem));}

		template < typename Iterator, typename Container >
		bool operator<(const map_iterator< Iterator, Container >& lhs,
					    const map_iterator< Iterator, Container >& rhs)
		{return (*(lhs.getNode()->elem) < *(rhs.getNode()->elem));}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator>(const map_iterator< IteratorL, Container >& lhs,
					    const map_iterator< IteratorR, Container >& rhs)
		{return (*(lhs.getNode()->elem) > *(rhs.getNode()->elem));}

		template < typename Iterator, typename Container >
		bool operator>(const map_iterator< Iterator, Container >& lhs,
					    const map_iterator< Iterator, Container >& rhs)
		{return (*(lhs.getNode()->elem) > *(rhs.getNode()->elem));}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator<=(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{return (*(lhs.getNode()->elem <= rhs.getNode()->elem));}

		template < typename Iterator, typename Container >
		bool operator<=(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{return (*(lhs.getNode()->elem <= rhs.getNode()->elem));}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator>=(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{return (*(lhs.getNode()->elem) >= *(rhs.getNode()->elem));}

		template < typename Iterator, typename Container >
		bool operator>=(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{return (*(lhs.getNode()->elem) >= *(rhs.getNode()->elem));}

		template < typename IteratorL, typename IteratorR, typename Container >
		typename map_iterator< IteratorL, Container >::difference_type
		operator-(const map_iterator< IteratorL, Container >& lhs,
				const map_iterator< IteratorR, Container >& rhs)
		{return (*(lhs.getNode()->elem) - *(rhs.getNode()->elem));}
}

#endif