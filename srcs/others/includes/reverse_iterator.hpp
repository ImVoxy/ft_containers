#include "iterator_traits.hpp"

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

int reverse_iterator_test();

namespace ft
{

    template< class Iter >
    class reverse_iterator
    {
        private:
        protected:
            Iter _it;
        public:
            typedef Iter                                                iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference;
    //  Constructors and destructors
            reverse_iterator() : _it(Iter()){};
            explicit reverse_iterator( iterator_type it ) : _it(it){};
            template< class U >
            reverse_iterator( const reverse_iterator<U>& rev_it ) : _it(rev_it.base()){};

    //  Member fonctions
            iterator_type base() const
            {
                return (_it);
            }
            
            reference operator*() const
            {
                Iter tmp;
                tmp = _it;
                return (*(--tmp));
            }
            
            reverse_iterator operator+ (difference_type n) const
            {
                return (reverse_iterator(_it - n));
            }

            reverse_iterator operator- (difference_type n) const
            {
                return (reverse_iterator(_it + n));
            }

            reverse_iterator& operator+= (difference_type n)
            {
                for (int i = 0; i < n; i++)
                    ++(*this);
                return (*this);
            }

            reverse_iterator& operator-= (difference_type n)
            {
                for (int i = 0; i < n; i++)
                    --(*this);
                return (*this);
            }

            reverse_iterator& operator++()
            {
                --_it;
                return (*this);
            }

            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp = *this;
                --_it;
                return (tmp);
            }

            reverse_iterator& operator--()
            {
                ++_it;
                return (*this);
            }

            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp = *this;
                ++_it;
                return (tmp);
            }

            pointer operator->() const
            {
                return &(operator*());
            }

            reference operator[] (difference_type n) const
            {
                return(*(*this + n));
            }

            template <class A, class B>
            friend bool operator==  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<B>& rhs);
            template <class A, class B>
            friend bool operator!=  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<B>& rhs);
            template <class A, class B>
            friend bool operator<   (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<B>& rhs);
            template <class A, class B>
            friend bool operator<=  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<B>& rhs);
            template <class A, class B>
            friend bool operator>   (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<B>& rhs);
            template <class A, class B>
            friend bool operator>=  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<B>& rhs);
            // template <class A>
            // friend typename reverse_iterator<A>::difference_type operator- (
            //                         const reverse_iterator<A>& lhs,
            //                         const reverse_iterator<A>& rhs);

    };

//  Non-member fuction overloads
    template <class Iter1, class Iter2>
    bool operator== (const reverse_iterator<Iter1>& lhs,
                    const reverse_iterator<Iter2>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iter1, class Iter2>
    bool operator!= (const reverse_iterator<Iter1>& lhs,
                    const reverse_iterator<Iter2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class Iter1, class Iter2>
    bool operator<  (const reverse_iterator<Iter1>& lhs,
                    const reverse_iterator<Iter2>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iter1, class Iter2>
    bool operator<= (const reverse_iterator<Iter1>& lhs,
                    const reverse_iterator<Iter2>& rhs)
    {
        return (!(lhs > rhs));
    }

    template <class Iter1, class Iter2>
    bool operator>  (const reverse_iterator<Iter1>& lhs,
                    const reverse_iterator<Iter2>& rhs)
    {
        return (rhs < lhs);
    }
        
    template <class Iter1, class Iter2>
    bool operator>= (const reverse_iterator<Iter1>& lhs,
                    const reverse_iterator<Iter2>& rhs)
    {
        return (!(lhs < rhs));
    }

    // template <class Iter>
    // typename reverse_iterator<Iter>::difference_type operator- (
    //                                 const reverse_iterator<Iter>& lhs,
    //                                 const reverse_iterator<Iter>& rhs)
    // {
    //     return (rhs.base() - lhs.base());
    // }

    // template <class Iter>
    // typename reverse_iterator<Iter>::difference_type operator+ (
    //                                 typename reverse_iterator<Iter>::difference_type n,
    //                                 const reverse_iterator<Iter>& it)
    // {
    //     return (reverse_iterator<Iter>(it.base() - n));
    // }

    	template <class Iter>
    	typename ft::reverse_iterator<Iter> operator+ (
                                    typename reverse_iterator<Iter>::difference_type n,
                                    const reverse_iterator<Iter>& it)
		{
			return (reverse_iterator<Iter>(it.base() - n));
		}

        template < typename IteratorL, typename IteratorR>
		typename reverse_iterator< IteratorL >::difference_type
		operator-(const reverse_iterator< IteratorL>& lhs,
				const reverse_iterator< IteratorR>& rhs)
		{return (rhs.base() - lhs.base());}
        // template <class Iter>
    	// typename ft::reverse_iterator<Iter> operator- (
        //                             typename reverse_iterator<Iter>::difference_type n,
        //                             const reverse_iterator<Iter>& it)
		// {
		// 	return (reverse_iterator<Iter>(it.base() - n));
		// }

        // template <class Iter1, class Iter2>
    	// typename ft::reverse_iterator<Iter1> operator- (
        //                             typename reverse_iterator<Iter1>& it1,
        //                             typename reverse_iterator<Iter2>& it2)
		// {
		// 	return (reverse_iterator<Iter1>(it1.base() - it2.base()));
		// }
}

#endif