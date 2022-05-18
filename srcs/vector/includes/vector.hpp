#include <memory>
#include <cstddef>
#ifndef VECTOR_HPP
# define VECTOR_HPP

int vector_test();

namespace ft
{
    template< class T, class Allocator = std::allocator<T> >
    class vector
    {
//         typedef Allocator                       allocator_type;
//         typedef T                               value_type;
//         typedef allocator_type::reference       reference;
//         typedef allocator_type::const_reference const_reference;
//         typedef allocator_type::pointer         pointer;
//         typedef allocator_type::const_pointer   const_pointer;

//         private:
//             size_t      _size_type;
//             ptrdiff_t   _difference_type;
//         protected:
//         public:
// //  Constructors and destructors
//             explicit vector (const allocator_type& alloc = allocator_type()){};
//             explicit vector (size_type n, const value_type& val = value_type(),
//                     const allocator_type& alloc = allocator_type()) : _size_type(n){};	
//             template <class InputIterator>
//             vector (InputIterator first, InputIterator last,
//                     const allocator_type& alloc = allocator_type()){};	
//             vector (const vector& x){};
    };
}

#endif