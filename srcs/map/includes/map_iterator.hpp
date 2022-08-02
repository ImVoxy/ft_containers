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
			map_iterator() : _node(Iterator()), _it(_node->elem) {}
			explicit map_iterator(const Iterator& it) : _node(it), _it(_node->elem) {}
			explicit map_iterator(Node<key_type, mapped_type> *it) : _node(it), _it(_node->elem) {}
			template < typename T >
			map_iterator(const map_iterator< T,
					typename enable_if< is_same< T, typename Container::pointer >::value,
										Container >::type >& it): _node(it.getNode()), _it(_node->elem) {}
			~map_iterator(){}
//  Access
			// Node<key_type, mapped_type> *base() const { return _node; }
			const Iterator& base() const { return _node->elem; }
			reference operator*() const { return *_it; }
			// Node<key_type, mapped_type> *operator->() const { return _it; }
			pointer *operator->() const {return _node->elem;}
			mapped_type operator[](difference_type ptr) const
			{
				// Node tmp;
		
				// tmp = searchTree(ptr);
				// return (tmp.val);
				return (_node->elem->second);
			}
			Node<key_type, mapped_type> *getNode() const { return (_node); }
			key_type getKey() const {return (_node->elem->first);};

//  Assignation
			map_iterator& operator++()
			{
				
				Node<key_type, mapped_type> *tmp = _node->parent;

				if ((_node->right->right || _node->right->left))
				{
					
					_node = _node->right;
					while (_node->left && (_node->left->right || _node->left->left))
						_node = _node->left;
				}
				else
				{
					if (tmp && tmp->right == _node)
						while (tmp->right == _node)
						{
							_node = tmp;
							tmp = _node->parent;
						}
					if (_node->right != tmp)
						_node = tmp;
				}
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

				if (_node->left->right || _node->left->left)
				{
					_node = _node->left;
					while (_node->right->right || _node->right->left)
						_node = _node->right;
				}
				else
				{
					if (tmp->left == _node)
						while(tmp->left == _node)
						{
							_node = tmp;
							tmp = _node->parent;
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
			return (map_iterator<Iter, Cont>(it.base() + n));
		}


		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator==(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() == rhs.base());}

//  Relational operators
		template < typename Iterator, typename Container >
		bool operator==(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{return (lhs.base() == rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator!=(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() != rhs.base());}

		template < typename Iterator, typename Container >
		bool operator!=(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{return (lhs.base() != rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator<(const map_iterator< IteratorL, Container >& lhs,
					    const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() < rhs.base());}

		template < typename Iterator, typename Container >
		bool operator<(const map_iterator< Iterator, Container >& lhs,
					    const map_iterator< Iterator, Container >& rhs)
		{return (lhs.base() < rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator>(const map_iterator< IteratorL, Container >& lhs,
					    const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() > rhs.base());}

		template < typename Iterator, typename Container >
		bool operator>(const map_iterator< Iterator, Container >& lhs,
					    const map_iterator< Iterator, Container >& rhs)
		{return (lhs.base() > rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator<=(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() <= rhs.base());}

		template < typename Iterator, typename Container >
		bool operator<=(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{return (lhs.base() <= rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator>=(const map_iterator< IteratorL, Container >& lhs,
						const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() >= rhs.base());}

		template < typename Iterator, typename Container >
		bool operator>=(const map_iterator< Iterator, Container >& lhs,
						const map_iterator< Iterator, Container >& rhs)
		{return (lhs.base() >= rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		typename map_iterator< IteratorL, Container >::difference_type
		operator-(const map_iterator< IteratorL, Container >& lhs,
				const map_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() - rhs.base());}
}

#endif