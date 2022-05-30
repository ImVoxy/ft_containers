#include <memory>
#include <cstddef>
#include <iterator>
#include "../../others/includes/reverse_iterator.hpp"
#include "../../others/includes/standard_iterator.hpp"
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
            typedef standard_iterator<pointer, vector>          iterator;
            typedef standard_iterator<const_pointer, vector>    const_iterator;
            typedef reverse_iterator<const_iterator>            const_reverse_iterator;
            typedef reverse_iterator<iterator>                  reverse_iterator;

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
                _alloc = alloc;
                _size = last - first + 1;
                _capa = last - first + 1;
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
                // _alloc.deallocate(_cont, _size);
            }

            vector& operator= (const vector& x)
            {
                _alloc = x.get_allocator();
                _size = x._size;
                _capa = x._capa;
                _cont = x._cont;
            }
//  Iterators
            iterator begin(){return (iterator(this->_cont));}
            const_iterator begin() const
            {
                const iterator it(this->_cont);
                return (it);
            }
            iterator end(){return (iterator(this->_cont + (this->_size - 1)));}
            const_iterator end() const
            {
                const iterator it(this->_cont + (this->_size - 1));
                return (it);
            }
            reverse_iterator rbegin(){return (reverse_iterator(end()));}
            const_reverse_iterator rbegin() const
            {
                const reverse_iterator it(end());
                return (it);
            }
            reverse_iterator rend(){return (reverse_iterator(begin()));}
            const_reverse_iterator rend() const
            {
                const reverse_iterator it(begin());
                return (it);
            }

//  Capacity
            size_type size() const{return (this->_size);}
            size_type max_size() const{return (_alloc.max_size());}
            void resize (size_type n, value_type val = value_type());
            size_type capacity() const{return (this->_capa);}
            bool empty() const
            {
                if (!(this->_size))
                    return (1);
                return (0);
            }

            void reserve (size_type n)
            {
                value_type tmp;

                tmp = this->_cont;
                if (n > this->_capa)
                {
                    if (n > max_size())
                        throw std::length_error("n is higher than max_size");
                    this->_cont = this->_alloc.allocate(n, 0);
                    for (int i = 0; i < n; i++)
                        _alloc.construct(&_cont[i], &tmp[i]);
                    for (int i = 0; i < this->_size; i++)
                        _alloc.destroy(&tmp[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = tmp;
                    this->_capa = n;
                }
            }

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
            void assign (InputIterator first, InputIterator last)
            {
                int n = last - first + 1;
                if (this->_capa < n)
                {
                    this->_capa = n;
                    for (int i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = this->_alloc.allocate(n, 0);
                    for (int i = 0; i < n; i++)
                    {
                        _alloc.construct(&_cont[i], first[i]);
                    }
                }
                else
                    for (size_type i = 0; i < n; i++)
                        this->_cont[i] = (*first.base() + i);
                this->_size = n;
            }
            void assign (int n, const value_type& val)
            {
                if (this->_capa < n)
                {
                    this->_capa = n;
                    for (int i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = this->_alloc.allocate(n, 0);
                    for (int i = 0; i < n; i++)
                        _alloc.construct(&_cont[i], val);
                }
                else
                    for (size_type i = 0; i < n; i++)
                        this->_cont[i] = val;
                this->_size = n;
            }
            void push_back (const value_type& val)
            {
                value_type tmp[this->_size];

                if (this->_capa > this->_size)
                    this->_cont[this->_size] = val;
                else if (this->_capa <= this->_size)
                {
                    this->_capa++;
                    for (int i = 0; i < this->_size; i++)
                        tmp[i] = this->_cont[i];
                    for (int i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = this->_alloc.allocate(this->_capa, 0);
                    for (int i = 0; i < this->_size; i++)
                        _alloc.construct(&_cont[i], tmp[i]);
                    _alloc.construct(&_cont[this->_size], val);
                }                
                this->_size++;
            }
            void pop_back()
            {
                _alloc.destroy(&this->_cont[this->_size - 1]);
                this->_size--;
            }
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (vector& x);
            void clear();
//  Allocator
            allocator_type get_allocator() const{return (this->_alloc);}
//  Non-member fuction overloads
            template <class A, class B>
            friend bool operator== (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            friend bool operator!= (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            friend bool operator< (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            friend bool operator<= (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            friend bool operator> (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            friend bool operator>= (const vector<A,B>& lhs, const vector<A,B>& rhs);
            template <class A, class B>
            void swap (vector<A,B>& lhs, vector<A,B>& rhs);
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
                return (0);
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