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

            
            virtual ~vector()
            {
                for (int i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                // _alloc.deallocate(_cont, _capa);
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
            void resize (size_type n, value_type val = value_type())
            {
                value_type tmp[n];

                if (n < this->_size)
                    for (int i = n; i < this->_size; i++)
                        _alloc.destroy(&_cont[i]);
                if (n > this->_size)
                {
                    if (n > this->_capa)
                    {
                        for (int i = 0; i < this->_size; i++)
                            tmp[i] = this->_cont[i];
                        for (int i = 0; i < this->_size; i++)
                            _alloc.destroy(&this->_cont[i]);
                        _alloc.deallocate(_cont, _size);
                        this->_cont = this->_alloc.allocate(this->_capa, 0);
                        for (int i = 0; i < this->_size; i++)
                            _alloc.construct(&_cont[i], tmp[i]);
                    }
                    for (int i = this->_size; i < n; i++)
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
                    for (int i = 0; i < this->_size; i++)
                        _alloc.construct(&tmp[i], _cont[i]);
                        // _alloc.construct(&_cont[i], &tmp[i]);
                    for (int i = 0; i < this->_size; i++)
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
            reference at (size_type n){return (_cont[n]);}
            const_reference at (size_type n) const{return (_cont[n]);}
            reference front(){return (_cont[0]);}
            const_reference front() const{return (_cont[0]);}
            reference back(){return (_cont[_size - 1]);}
            const_reference back() const{return (_cont[_size - 1]);}

// Modifiers
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                int n = last - first;
                std::cout<<"!!" << *first << std::endl;
                if (this->_capa < n)
                {
                    this->_capa = n;
                    for (int i = 0; i < this->_size; i++)
                        _alloc.destroy(&this->_cont[i]);
                    _alloc.deallocate(_cont, _size);
                    this->_cont = this->_alloc.allocate(n, 0);
                    for (int i = 0; i < n; i++)
                        _alloc.construct(&_cont[i], first[i]);
                }
                else
                {
                    
                    for (size_type i = 0; i < n; i++)
                        this->_cont[i] = first[i];
                }
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
                    _alloc.construct(&_cont[_size], val);
                }                
                this->_size++;
            }
            void pop_back()
            {
                _alloc.destroy(&this->_cont[this->_size - 1]);
                this->_size--;
            }

            iterator insert (iterator position, const value_type& val)
            {
                int         ind;
                int         j = 0;
                value_type  tmp[this->_size + 1];

                if (this->_capa <= this->_size)
                    this->_capa++;
                
                for (int i = 0; i < this->_size; i++)
                {
                    if (position == iterator(&_cont[i]) ||
                        (position < iterator(&_cont[i]) && i == 0))
                    {
                        if (i != 0)
                        {
                            tmp[i] = _cont[i];
                            i++;
                        }
                        tmp[i] = val;
                        ind = i;
                        j = 1;
                    }
                    if (i < this->_size)
                        tmp[i + j] = this->_cont[i];
                }
                for (int i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (int i = 0; i <= this->_size; i++)
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
                
                for (int i = 0; i < this->_size; i++)
                {
                    if (position == iterator(&_cont[i]) ||
                        (position < iterator(&_cont[i]) && i == 0))
                    {
                        if (i != 0)
                        {
                            tmp[i] = _cont[i];
                            i++;
                        }
                        for (int k = 0; k < n; k++)
                            tmp[i + k] = val;
                        ind = i;
                        j = n;
                    }
                    if (i < this->_size)
                        tmp[i + j] = this->_cont[i];
                }
                for (int i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (int i = 0; i < (this->_capa); i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size += n;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last)
            {
                difference_type n = last - first + 1;
                int             ind;
                int             j = 0;
                value_type      tmp[this->_size + n];

                if (this->_capa < this->_size + n)
                    this->_capa += n;
                for (int i = 0; i <= this->_size; i++)
                {
                    if (position == iterator(&_cont[i]) ||
                        (position < iterator(&_cont[i]) && i == 0))
                    {
                        if (i != 0)
                        {
                            tmp[i] = _cont[i];
                            i++;
                        }
                        for (int k = 0; k <= n; k++)
                            tmp[i + k] = *(first + k);
                        ind = i;
                        j = n;
                    }
                    if (i < this->_size)
                        tmp[i + j] = this->_cont[i];
                }
                for (int i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (int i = 0; i < (this->_size + n); i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size += n;
            }

            iterator erase (iterator position)
            {
                int         j;
                value_type  tmp[this->_size - 1];

                j = 0;
                for (int i = 0; i < _size; i++)
                {
                    if (position == iterator(&_cont[i]))
                        i++;
                    tmp[j] = _cont[i];
                    j++; 
                }
                for (int i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa - 1, 0);
                for (int i = 0; i < this->_size; i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size--;
                return (iterator(&_cont[0]));
            }

            iterator erase (iterator first, iterator last)
            {
                int             j;
                value_type      tmp[this->_size - 1];
                difference_type n = last - first;

                j = 0;
                for (int i = 0; i < _size; i++)
                {
                    if (first == iterator(&_cont[i]))
                    {
                        tmp[j] = _cont[i];
                        j++;
                        i += n + 1;
                    }
                    tmp[j] = _cont[i];
                    j++; 
                }
                for (int i = 0; i < this->_capa; i++)
                    _alloc.destroy(&this->_cont[i]);
                _alloc.deallocate(_cont, _size);
                this->_cont = this->_alloc.allocate(this->_capa, 0);
                for (int i = 0; i < this->_size - n; i++)
                    _alloc.construct(&_cont[i], tmp[i]);
                this->_size -= (n + 0);
                return (iterator(&_cont[0]));
            }

            void swap (vector& x)
            {
                Alloc tmp_a     = x.get_allocator();
                size_t tmp_s    = x._size;
                size_t tmp_c    = x._capa;
                T* tmp_cont     = x._cont;

                x._alloc    = this->_alloc;
                x._size     = this->_size;
                x._capa     = this->_capa;
                x._cont     = this->_cont;

                this->_alloc = tmp_a;
                this->_size = tmp_s;
                this->_capa = tmp_c;
                this->_cont = tmp_cont;
            }

            void clear()
            {
                for (int i = 0; i < this->_capa; i++)
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
        Alloc tmp_a     = y.get_allocator();
        size_t tmp_s    = y._size;
        size_t tmp_c    = y._capa;
        T* tmp_cont     = y._cont;

        y._alloc    = x.get_allocator();
        y._size     = x._size;
        y._capa     = x._capa;
        y._cont     = x._cont;

        x._alloc = tmp_a;
        x._size = tmp_s;
        x._capa = tmp_c;
        x._cont = tmp_cont;
    }

}

#endif