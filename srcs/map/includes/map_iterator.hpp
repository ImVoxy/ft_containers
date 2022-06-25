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
			Node*	_it;

		public:
			typedef Iterator                           iterator_type;
			typedef typename traits::iterator_category iterator_category;
			typedef typename traits::value_type        value_type;
			typedef typename traits::difference_type   difference_type;
			typedef typename traits::reference         reference;
			typedef typename traits::pointer           pointer;

//  Constructors and destructors
			map_iterator() : _it(Iterator()) {}
			explicit map_iterator(const Iterator& it) : _it(it) {}
			template < typename T >
			map_iterator(const map_iterator< T,
					typename enable_if< is_same< T, typename Container::pointer >::value,
										Container >::type >& it): _it(it.base()) {}
			~map_iterator(){}
//  Access
			const Iterator& base() const { return _it; }
			reference operator*() const { return *_it; }
			pointer operator->() const { return _it; }
			reference operator[](difference_type ptr) const { return _it[ptr]; }
//  Assignation
			map_iterator& operator++()
			{
				
				return (*this);
			}
			map_iterator operator++(int) { return map_iterator(_it++); }
			map_iterator& operator--()
			{
				if (_it->left)
					_it = _it->left;
				else if (_it->parent &&_it == _it->parent->right)
					_it = _it->parent;
				else if (_it->parent && _it->parent->parent && _it == _it->parent->left)
					_it = _it->parent->parent;
				return (*this);
			}
			map_iterator operator--(int) { return map_iterator(_it--); }
			map_iterator& operator+=(difference_type ptr)
			{
				_it += ptr;
				return (*this);
			}
			map_iterator operator+(difference_type ptr) const
			{
				return (map_iterator(_it + ptr));
			}

			map_iterator& operator-=(difference_type ptr)
			{
				_it -= ptr;
				return (*this);
			}
			map_iterator operator-(difference_type ptr) const
			{return (map_iterator(_it - ptr));}
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