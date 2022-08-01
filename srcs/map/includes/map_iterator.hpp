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
			Node<typename Container::key_type, typename Container::mapped_type> *	_it;

		public:
			typedef Iterator                           iterator_type;
			typedef typename Container::key_type		key_type;
			typedef typename Container::mapped_type		mapped_type;
			typedef typename traits::iterator_category iterator_category;
			typedef typename traits::value_type        value_type;
			typedef typename traits::difference_type   difference_type;
			typedef typename traits::reference         reference;
			typedef typename traits::pointer           pointer;

//  Constructors and destructors
			map_iterator() : _it(Iterator()) {}
			explicit map_iterator(const Iterator& it) : _it(it) {}
			explicit map_iterator(Node<key_type, mapped_type> *it) : _it(it) {}
			template < typename T >
			map_iterator(const map_iterator< T,
					typename enable_if< is_same< T, typename Container::pointer >::value,
										Container >::type >& it): _it(it.base()) {}
			~map_iterator(){}
//  Access
			Node<key_type, mapped_type> *base() const { return _it; }
			reference operator*() const { return *_it; }
			Node<key_type, mapped_type> *operator->() const { return _it; }
			int operator[](difference_type ptr) const
			{
				// Node tmp;
		
				// tmp = searchTree(ptr);
				// return (tmp.val);
				return (_it->elem->second);
			}
			int getKey() const {return (_it->elem->first);};

//  Assignation
			map_iterator& operator++()
			{
				
				Node<key_type, mapped_type> *tmp = _it->parent;

				if ((_it->right->right || _it->right->left))
				{
					
					_it = _it->right;
					while (_it->left && (_it->left->right || _it->left->left))
						_it = _it->left;
				}
				else
				{
					if (tmp && tmp->right == _it)
						while (tmp->right == _it)
						{
							_it = tmp;
							tmp = _it->parent;
						}
					if (_it->right != tmp)
						_it = tmp;
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
				Node<key_type, mapped_type> *tmp = _it->parent;

				if (_it->left->right || _it->left->left)
				{
					_it = _it->left;
					while (_it->right->right || _it->right->left)
						_it = _it->right;
				}
				else
				{
					if (tmp->left == _it)
						while(tmp->left == _it)
						{
							_it = tmp;
							tmp = _it->parent;
						}
					if (_it->left != tmp)
						_it = tmp;
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