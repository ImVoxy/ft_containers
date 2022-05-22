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
        
        private:        
        protected:
            Alloc           _alloc;
            size_t          _size;
            size_t          _capa;
            T*              _cont;        
        public:
            typedef Alloc                                       allocator_type;
            typedef T                                           value_type;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef value_type*                                 pointer;
            typedef const value_type*                           const_pointer;
            typedef std::size_t                                 size_type;
            typedef std::ptrdiff_t                              difference_type;
            typedef standard_iterator< pointer, vector >        iterator;
            typedef standard_iterator< const_pointer, vector >  const_iterator;
            typedef reverse_iterator< const_iterator >          const_reverse_iterator;
            typedef reverse_iterator< iterator >                reverse_iterator;

//  Constructors and destructors
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _size = 0;
                _capa = 0;
                _cont = NULL;
            }

            explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type())
            {
                pointer tmp;
                _alloc = alloc;
                _size = n;
                _capa = n;
                _cont = alloc.allocate(n, 0);
                for (int i = 0; i < n; i++)
                    alloc.construct(&_cont[i], val[i]);
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type())
            {
                pointer tmp;
                _alloc = alloc;
                _size = last - first;
                _capa = last - first;
                _cont = alloc.allocate(_size, 0);
            
            }

            vector (const vector& x)
            {
                _alloc = x.get_allocator();
                _size = x._size;
                _capa = x._capa;
                _cont = x._cont;
            }

            ~vector()
            {
                allocator.deallocate(_cont, size);
            }

            vector& operator= (const vector& x)
            {
                _alloc = x.get_allocator();
                _size = x.size;
                _capa = x._capa;
                _cont = x._cont;
            }
//  Iterators
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;
//  Capacity
            size_type size() const{return (*this->_size);}
            size_type max_size() const;
            void resize (size_type n, value_type val = value_type());
            size_type capacity() const{return (*this->_capa);}
            bool empty() const
            {
                if (_cont)
                    return (0);
                return (1);
            }
            void reserve (size_type n);
//  Element access
            reference operator[] (size_type n){return (_cont[n]);}
            const_reference operator[] (size_type n) const{return (_cont[n]);}
            reference at (size_type n){return (&_cont[n]);}
            const_reference at (size_type n) const{return (&_cont[n]);}
            reference front(){return (&_cont[_size]);}
            const_reference front() const{return (&_cont[_size]);}
            reference back(){return (&_cont[0]);}
            const_reference back() const{return (&_cont[0]);}

// Modifiers
            template <class InputIterator>
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
        if (lhs._size == rhs._size)
            for (int i = 0; (i < lhs._size && i < rhs._size); i++)
                if (rhs._cont[i] != lhs._cont[i])
                    return (0);
        return (1);
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        for (int i = 0; i < lhs._size; i++)
        {
            if (i == rhs._size || rhs._cont < lhs._cont)
                return (0)
            else if (lhs._cont < rhs._cont)
                return (1);
        }
        return (0);
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