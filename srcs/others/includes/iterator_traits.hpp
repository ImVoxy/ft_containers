#include <cstddef>
#include <iterator>
#include "is_integral.hpp"
#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

int iterator_test();

namespace ft
{
    template<class Iter>
    class iterator_traits
    {
        private:
        protected:
        public:
            typedef typename Iter::difference_type   difference_type;
            typedef typename Iter::value_type        value_type;
            typedef typename Iter::pointer           pointer;
            typedef typename Iter::reference         reference;
            typedef typename Iter::iterator_category iterator_category;
    };

    template<class T>
    class iterator_traits<T*>
    {
        private:
        protected:
        public:
            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    class iterator_traits<const T*>
    {
        private:
        protected:
        public:
            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef std::random_access_iterator_tag iterator_category;
    };
}

#endif