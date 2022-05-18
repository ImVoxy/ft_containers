#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

int enable_if_test();

namespace ft
{
    template<bool Cond, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif