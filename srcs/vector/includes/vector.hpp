#include <memory>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include "../../others/includes/reverse_iterator.hpp"
#include "../../others/includes/standard_iterator.hpp"
#include "../../others/includes/utils.hpp"
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
                _alloc = alloc;
                _size = n;
                _capa = n;
                _cont = _alloc.allocate(n, 0);
                for (size_t i = 0; i < n; i++)
                    _alloc.construct(&_cont[i], val);
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type())
            {
                // InputIterator   tmp = first;
                // int             size = 0;

                // while (tmp + size != last)
                //     size++;
                _alloc = alloc;
                _size = 0;
                _capa = 0;
                _cont = NULL;
                this->assign(first, last);
            
            }

            vector (const vector& x)
            {
                _alloc = x.get_allocator();
                _size = 0;
                _capa = 0;
                _cont = NULL;
                *this = x;
            }

            virtual ~vector()
            {
                this->clear();
                _alloc.deallocate(_cont, _capa);
            }

            vector& operator= (const vector& x)
            {
                if (_cont)
                {
                    this->clear();
                    _alloc.deallocate(_cont, _capa);
                }
                _size = x.size();
                _capa = x.capacity();
                _cont = _alloc.allocate(_capa);
                for (size_type i = 0; i < _capa; i++)
                    _alloc.construct(&_cont[i], x[i]);
                return (*this);
            }
//  Iterators
            iterator begin(){return (iterator(this->_cont));}
            const_iterator begin() const
            {
                const iterator it(this->_cont);
                return (it);
            }
            iterator end(){return (iterator(this->_cont + (this->_size)));}
            const_iterator end() const
            {
                const iterator it(this->_cont + (this->_size));
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
            void resize (size_type n, value_type val = value_type())
            {
                value_type tmp[n];

                if (n < this->_size)
                    for (size_t i = n; i < this->_size; i++)
                        _alloc.destroy(&_cont[i]);
                if (n > this->_size)
                {
                    if (n > this->_capa)
                    {
                        this->_capa = n;
                        for (size_t i = 0; i < this->_size; i++)
                            tmp[i] = this->_cont[i];
                        for (size_t i = 0; i < this->_size; i++)
                            _alloc.destroy(&this->_cont[i]);
                        _alloc.deallocate(_cont, _size);
                        this->_cont = this->_alloc.allocate(this->_capa, 0);
                        for (size_t i = 0; i < this->_capa; i++)
                            _alloc.construct(&_cont[i], tmp[i]);
                    }
                    for (size_t i = this->_size; i < n; i++)
                        _alloc.construct(&_cont[i], val);
                }

                this->_size = n;
            }

            size_type capacity() const{return (this->_capa);}
            bool empty() const
            {
                if (!(this->_size))
                    return (1);
                return (0);
            }

            void reserve (size_type n)
            {
                value_type *tmp;

                // tmp = this->_cont;
                if (n > this->_capa)
                {
                    if (n > max_size())
                        throw std::length_error("n is higher than max_size");
                    tmp = this->_alloc.allocate(n, 0);
                    // this->_cont = this->_alloc.allocate(n, 0);
                    for (size_t i = 0; i < this->_size; i++)
                        _alloc.construct(&tmp[i], _cont[i]);
                        // _alloc.construct(&_cont[i], &tmp[i]);
                    for (size_t i = 0; i < this->_size; i++)
                        _alloc.destroy(&_cont[i]);
                        // _alloc.destroy(&tmp[i]);
                    _alloc.deallocate(_cont, _capa);
                    this->_cont = tmp;
                    this->_capa = n;
                }
            }

//  Element access
            reference operator[] (size_type n){return (_cont[n]);}
            const_reference operator[] (size_type n) const{return (_cont[n]);}
            reference at (size_type n)
            {
                if (n > _size)
                    throw(std::out_of_range("n is out of range"));
                return (_cont[n]);
            }
            const_reference at (size_type n) const
            {
                if (n > _size)
                    throw(std::out_of_range("n is out of range"));
                return (_cont[n]);
            }
            reference front(){return (_cont[0]);}
            const_reference front() const{return (_cont[0]);}
            reference back(){return (_cont[_size - 1]);}
            const_reference back() const{return (_cont[_size - 1]);}

//  Modifiers
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                difference_type n = it_diff(first, last);

                if (this->_capa < (size_t)n)
                {
                    this->_capa = n;
                    for (size_t i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _capa);
                    this->_cont = this->_alloc.allocate(n, 0);
                    for (int i = 0; i < n; i++)
                    {
                        _alloc.construct(&_cont[i], *(first));
                        first++;
                    }
                }
                else
                {
                    for (difference_type i = 0; i < n; i++)
                    {
                        this->_cont[i] = *first;
                        first++;
                    }
                }
                this->_size = n;
            }

            void assign (int n, const value_type& val)
            {
                if ((int)this->_capa < n)
                {
                    this->_capa = n;
                    for (size_t i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = this->_alloc.allocate(n, 0);
                    for (int i = 0; i < n; i++)
                        _alloc.construct(&_cont[i], val);
                }
                else
                    for (int i = 0; i < n; i++)
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
                    for (size_t i = 0; i < this->_size; i++)
                        tmp[i] = this->_cont[i];
                    for (size_t i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = this->_alloc.allocate(this->_capa, 0);
                    for (size_t i = 0; i < this->_size; i++)
                        _alloc.construct(&_cont[i], tmp[i]);
                    _alloc.construct(&_cont[_size], val);
                }                
                this->_size++;
            }

            void pop_back()
            {
                if (this->_size > 0)
                {
                    _alloc.destroy(&this->_cont[this->_size - 1]);
                    this->_size--;
                    this->_capa--;
                }
            }

            iterator insert (iterator position, const value_type& val)
            {
                int         ind;
                int         j = 0;
                value_type  tmp[this->_size + 1];

                if (this->_capa <= this->_size)
                    this->_capa++;
                
                for (size_t i = 0; i <= this->_size; i++)
                {
                    if (position == iterator(&_cont[i])||
                        (position < iterator(&_cont[i]) && i == 0))
                    {
                        tmp[i] = val;
                        ind = i;
                        j = 1;
                    }
                    if (i < this->_size)
                        tmp[i + j] = this->_cont[i];
                }
                for (size_t i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (size_t i = 0; i <= this->_size; i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size++;
                return (iterator(&_cont[ind]));
            }

            void insert (iterator position, int n, const value_type& val)
            {
                int         ind;
                int         j = 0;
                value_type  tmp[this->_size + n];

                if (this->_capa < this->_size + n)
                    this->_capa += n;
                
                for (size_t i = 0; i <= this->_size; i++)
                {
                    if (position == iterator(&_cont[i])  ||
                        (position < iterator(&_cont[i]) && i == 0))
                    {
                        for (int k = 0; k < n; k++)
                            tmp[i + k] = val;
                        ind = i;
                        j = n;
                    }
                    if (i < this->_size)
                        tmp[i + j] = this->_cont[i];
                }
                for (size_t i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (size_t i = 0; i < (this->_capa); i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size += n;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last)
            {
                difference_type n = it_diff(first, last) ;
                int             ind;
                int             j = 0;
                value_type      tmp[this->_size + n];

                if (this->_capa < this->_size + n && n > 0)
                    this->_capa += (n * 2);
                for (size_t i = 0; i <= this->_size; i++)
                {
                    if (position == iterator(&_cont[i]) ||
                        (position < iterator(&_cont[i]) && i == 0))
                    {
                        for (int k = 0; k < n; k++)
                        {
                            tmp[i + k] = *(first);
                            first++;
                        }
                        ind = i;
                        j = n;
                    }
                    if (i < this->_size)
                        tmp[i + j] = this->_cont[i];
                }
                for (size_t i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (size_t i = 0; i < (this->_size + n); i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size += n;
            }

            iterator erase (iterator position)
            {
                int         j;
                size_t      ret = 0;
                value_type  tmp[this->_size + 1];

                j = 0;
                for (size_t i = 0; i < _size; i++)
                {
                    if (position == iterator(&_cont[i]))
                    {
                        ret = i;
                        i++;
                    }
                        tmp[j] = _cont[i];
                        j++; 
                }
                for (size_t i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _capa);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                this->_size--;
                for (size_t i = 0; i < this->_size; i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                
                if (ret < 0)
                    ret = 0;
                return (iterator(&_cont[ret]));
            }

            iterator erase (iterator first, iterator last)
            {
                int             j;
                size_t          ret = 0;
                value_type      tmp[this->_size];
                difference_type n = it_diff(first, last);

                j = 0;
                for (size_t i = 0; i < _size; i++)
                {
                    if (first == iterator(&_cont[i]))
                    {
                        ret = i;
                        i += n;
                    }
                    if (i < _size)
                        tmp[j] = _cont[i];
                    j++; 
                }
                for (size_t i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (size_t i = 0; i < this->_size - n; i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size -= (n);
                return (iterator(&_cont[ret]));
            }

            void swap (vector& x)
            {
                std::swap(_alloc, x._alloc);
                std::swap(_size, x._size);
                std::swap(_capa, x._capa);
                std::swap(_cont, x._cont);
            }

            void clear()
            {
                for (size_t i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                this->_size = 0;
            }
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
        if (lhs._size != rhs._size)
            return (0);
        for (size_t i = 0; (i < lhs.size() && i < rhs.size()); i++)
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
        for (size_t i = 0; (i < lhs.size() && i < rhs.size()); i++)
        {
            if (rhs._cont[i] < lhs._cont[i])
                return (0);
            else if (lhs._cont[i] < rhs._cont[i])
                return (1);
        }
        if (lhs.size() < rhs.size())
            return (1);
        return (0);
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs > rhs));
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
        x.swap(y);
    }

}

#endif