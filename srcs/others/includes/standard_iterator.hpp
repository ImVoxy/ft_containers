#include "iterator_traits.hpp"
#include "enable_if.hpp"
#ifndef STANDARD_ITERATOR_HPP
# define STANDARD_ITERATOR_HPP

namespace ft
{

	template < typename Iterator, typename Container >
	class standard_iterator
	{
		typedef iterator_traits< Iterator > traits;

		private:
		protected:
			Iterator _it;

		public:
			typedef Iterator                           iterator_type;
			typedef typename traits::iterator_category iterator_category;
			typedef typename traits::value_type        value_type;
			typedef typename traits::difference_type   difference_type;
			typedef typename traits::reference         reference;
			typedef typename traits::pointer           pointer;

//  Constructors and destructors
			standard_iterator() : _it(Iterator()) {}
			explicit standard_iterator(const Iterator& it) : _it(it) {}
			template < typename T >
			standard_iterator(const standard_iterator< T,
					typename enable_if< std::is_same< T, typename Container::pointer >::value,
										Container >::type >& it): _it(it.base()) {}
			~standard_iterator(){}
//Access
			const Iterator& base() const { return _it; }
			reference operator*() const { return *_it; }
			pointer operator->() const { return _it; }
			reference operator[](difference_type ptr) const { return _it[ptr]; }
//Assignation
			standard_iterator& operator++()
			{
				++_it;
				return (*this);
			}
			standard_iterator operator++(int) { return standard_iterator(_it++); }
			standard_iterator& operator--()
			{
				--_it;
				return (*this);
			}
			standard_iterator operator--(int) { return standard_iterator(_it--); }
			standard_iterator& operator+=(difference_type ptr)
			{
				_it += ptr;
				return (*this);
			}
			standard_iterator operator+(difference_type ptr) const
			{return standard_iterator(_it + ptr);}
			standard_iterator& operator-=(difference_type ptr)
			{
				_it -= ptr;
				return (*this);
			}
			standard_iterator operator-(difference_type ptr) const
			{return (standard_iterator(_it - ptr));}
		};
//Relational operators
		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator==(const standard_iterator< IteratorL, Container >& lhs,
						const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() == rhs.base());}

		template < typename Iterator, typename Container >
		bool operator==(const standard_iterator< Iterator, Container >& lhs,
						const standard_iterator< Iterator, Container >& rhs)
		{return (lhs.base() == rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator!=(const standard_iterator< IteratorL, Container >& lhs,
						const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() != rhs.base());}

		template < typename Iterator, typename Container >
		bool operator!=(const standard_iterator< Iterator, Container >& lhs,
						const standard_iterator< Iterator, Container >& rhs)
		{return (lhs.base() != rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator<(const standard_iterator< IteratorL, Container >& lhs,
					const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() < rhs.base());}

		template < typename Iterator, typename Container >
		bool operator<(const standard_iterator< Iterator, Container >& lhs,
					const standard_iterator< Iterator, Container >& rhs)
		{return (lhs.base() < rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator>(const standard_iterator< IteratorL, Container >& lhs,
					const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() > rhs.base());}

		template < typename Iterator, typename Container >
		bool operator>(const standard_iterator< Iterator, Container >& lhs,
					const standard_iterator< Iterator, Container >& rhs)
		{return (lhs.base() > rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator<=(const standard_iterator< IteratorL, Container >& lhs,
						const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() <= rhs.base());}

		template < typename Iterator, typename Container >
		bool operator<=(const standard_iterator< Iterator, Container >& lhs,
						const standard_iterator< Iterator, Container >& rhs)
		{return (lhs.base() <= rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		bool operator>=(const standard_iterator< IteratorL, Container >& lhs,
						const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() >= rhs.base());}

		template < typename Iterator, typename Container >
		bool operator>=(const standard_iterator< Iterator, Container >& lhs,
						const standard_iterator< Iterator, Container >& rhs)
		{return (lhs.base() >= rhs.base());}

		template < typename IteratorL, typename IteratorR, typename Container >
		typename standard_iterator< IteratorL, Container >::difference_type
		operator-(const standard_iterator< IteratorL, Container >& lhs,
				const standard_iterator< IteratorR, Container >& rhs)
		{return (lhs.base() - rhs.base());}
}

#endif