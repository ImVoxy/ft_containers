#include <memory>
#include <cstddef>
#include <iterator>
#ifndef VECTOR_HPP
# define VECTOR_HPP

int vector_test();

namespace ft
{
    template< class T, class Alloc = std::allocator<T> >
    class vector
    {
        typedef Alloc                           allocator_type;
        typedef T                               value_type;
        typedef allocator_type::reference       reference;
        typedef allocator_type::const_reference const_reference;
        typedef allocator_type::pointer         pointer;
        typedef allocator_type::const_pointer   const_pointer;

        private:
            size_t                                             _size_type;
            ptrdiff_t                                          _difference_type;
            typedef standard_iterator< pointer, vector >       _iterator;
            typedef standard_iterator< const_pointer, vector > _const_iterator;
            typedef reverse_iterator< const_iterator >         _const_reverse_iterator;
            typedef reverse_iterator< iterator >               _reverse_iterator;
            
        protected:
        public:
//  Constructors and destructors
            explicit vector (const allocator_type& alloc = allocator_type()){};
            explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()){};	
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type()){};	
            vector (const vector& x){};
            ~vector(){};
//  Iterrators
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;
//  Capacity
            size_type size() const;
            size_type max_size() const;
            void resize (size_type n, value_type val = value_type());
            size_type capacity() const;
            bool empty() const;
            void reserve (size_type n);
//  Element access
            reference operator[] (size_type n);
            const_reference operator[] (size_type n) const;
            reference at (size_type n);
            const_reference at (size_type n) const;
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
            template <class InputIterator>
// Modifiers
            void assign (InputIterator first, InputIterator last);	
            void assign (size_type n, const value_type& val);
            void push_back (const value_type& val);
            void pop_back();
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (vector& x);
            void clear();
//  Allocator
            allocator_type get_allocator() const;
//  Non-member fuction overloads
            template <class A, class B>
            bool operator== (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            bool operator!= (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            bool operator< (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            bool operator<= (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            bool operator> (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            bool operator>= (const vector<A,B>& lhs, const vector<A,B>& rhs)
            template <class A, class B>
            void swap (vector<A,B>& lhs, vector<A,B>& rhs)
    };
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ();
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ();
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs > lhs));
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        
    }

}

#endif