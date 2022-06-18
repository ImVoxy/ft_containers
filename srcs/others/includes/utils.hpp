#ifndef UTILS_HPP
# define UTILS_HPP
#include <list>

namespace ft
{
    template <class Iterator>
    size_t it_diff(Iterator first, Iterator last)
    {
        Iterator    tmp = first;
        size_t      i = 0;

        while (tmp != last)
        {
            tmp++;
            i++;
        }
        return (i);
    }
}

#endif