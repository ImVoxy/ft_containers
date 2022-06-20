#ifndef MAP_HPP
# define MAP_HPP
#include "../../others/includes/reverse_iterator.hpp"
#include "../../others/includes/standard_iterator.hpp"
#include "../../others/includes/pair.hpp"
#include "../../others/includes/utils.hpp"
#include "../../others/includes/rb_tree.hpp"

namespace ft
{

    template < class Key,                                 // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           > class map;
    {
        
        private:        
        protected:
            Alloc           _alloc;
            size_t          _size;
            size_t          _capa;
            T*              _cont;        
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const key_type, mapped_type>           value_type;
            typedef Compare                                     key_compare;
            typedef Alloc                                       allocator_type;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef value_type*                                 pointer;
            typedef const value_type*                           const_pointer;
            typedef std::size_t                                 size_type;
            typedef std::ptrdiff_t                              difference_type;
            typedef map_iterator<pointer, vector>               iterator;
            typedef map_iterator<const_pointer, vector>         const_iterator;
            typedef reverse_iterator<const_iterator>            const_reverse_iterator;
            typedef reverse_iterator<iterator>                  reverse_iterator;
    
        template <class Key, class T, class Compare, class Alloc>
        class map<Key,T,Compare,Alloc>::value_compare
        {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class map;
            private:
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        }

    //  Constructors and destructors

        explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
        {}
	
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
        {}
	    map (const map& x)
        {}

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
    
    //  Element access
    
    //  Modifiers
    
    //  Observers
    
    //  Operations
    
    //  Allocator
        allocator_type get_allocator() const{return (this->_alloc);}
    }
}

#endif