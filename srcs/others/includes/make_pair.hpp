#include "pair.hpp"
#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace ft
{
    template< class T1, class T2 >
    ft::pair<T1,T2> make_pair( T1 t, T2 u )
    {
        return (ft::pair<T1, T2>(t, u));
    }
}

#endif