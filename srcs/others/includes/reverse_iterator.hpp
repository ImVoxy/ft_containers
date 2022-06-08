#include "iterator_traits.hpp"

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

int reverse_iterator_test();

namespace ft
{

    template< class Iter >
    class reverse_iterator
    {
        typedef Iter                                                iterator_type;
        typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iter>::value_type          value_type;
        typedef typename iterator_traits<Iter>::difference_type     difference_type;
        typedef typename iterator_traits<Iter>::pointer             pointer;
        typedef typename iterator_traits<Iter>::reference           reference;

        private:
        protected:
            Iter _it;
        public:
    //  Constructors and destructors
            reverse_iterator() : _it(Iter()){};
            explicit reverse_iterator( iterator_type it ) : _it(it){};
            template< class U >
            reverse_iterator( const reverse_iterator<U>& rev_it ) : _it(rev_it._it){};

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
                // reverse_iterator tmp = *this;
                // for (int i = 0; i < n; i++)
                //     ++tmp;
                // return (tmp);
                return (reverse_iterator(_it - n));
            }

            reverse_iterator operator- (difference_type n) const
            {
                // reverse_iterator tmp = *this;
                // for (int i = 0; i < n; i++)
                //     --tmp;
                // return (tmp);
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
                // ++(*this);
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
                // --(*this);
                return (tmp);
            }

            pointer operator->() const
            {
                return &(operator*());
            }

            reference operator[] (difference_type n) const
            {
                // Iter tmp;
                // tmp = _it;
                // for (int i = 0; i < n; i++)
                //     tmp--;
                // return (*tmp);
                return(*(*this + n));
            }

            template <class A>
            friend bool operator==  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
            template <class A>
            friend bool operator!=  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
            template <class A>
            friend bool operator<   (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
            template <class A>
            friend bool operator<=  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
            template <class A>
            friend bool operator>   (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
            template <class A>
            friend bool operator>=  (const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
            template <class A>
            friend typename reverse_iterator<A>::difference_type operator- (
                                    const reverse_iterator<A>& lhs,
                                    const reverse_iterator<A>& rhs);
                                    template <class A>
            friend typename reverse_iterator<A>::difference_type operator+ (
                                    typename reverse_iterator<A>::difference_type n,
                                    const reverse_iterator<A>& rev_it);
    };

//  Non-member fuction overloads
    template <class Iter>
    bool operator== (const reverse_iterator<Iter>& lhs,
                    const reverse_iterator<Iter>& rhs)
    {
        return (lhs._it == rhs._it);
    }

    template <class Iter>
    bool operator!= (const reverse_iterator<Iter>& lhs,
                    const reverse_iterator<Iter>& rhs)
    {
        return (lhs._it != rhs._it);
    }

    template <class Iter>
    bool operator<  (const reverse_iterator<Iter>& lhs,
                    const reverse_iterator<Iter>& rhs)
    {
        return (lhs._it > rhs._it);
    }

    template <class Iter>
    bool operator<= (const reverse_iterator<Iter>& lhs,
                    const reverse_iterator<Iter>& rhs)
    {
        return (lhs._it >= rhs._it);
    }

    template <class Iter>
    bool operator>  (const reverse_iterator<Iter>& lhs,
                    const reverse_iterator<Iter>& rhs)
    {
        return (lhs._it < rhs._it);
    }
        
    template <class Iter>
    bool operator>= (const reverse_iterator<Iter>& lhs,
                    const reverse_iterator<Iter>& rhs)
    {
        return (lhs._it <= rhs._it);
    }

    template <class Iter>
    typename reverse_iterator<Iter>::difference_type operator- (
                                    const reverse_iterator<Iter>& lhs,
                                    const reverse_iterator<Iter>& rhs)
    {
        return (rhs.base() - lhs.base());
    }

    template <class Iter>
    typename reverse_iterator<Iter>::difference_type operator+ (
                                    typename reverse_iterator<Iter>::difference_type n,
                                    const reverse_iterator<Iter>& it)
    {
        return (reverse_iterator<Iter>(it.base() - n));
    }
}

#endif