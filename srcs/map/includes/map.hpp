#ifndef MAP_HPP
# define MAP_HPP
#include "../../others/includes/reverse_iterator.hpp"
#include "../../others/includes/standard_iterator.hpp"
#include "../../others/includes/pair.hpp"
#include "../../others/includes/utils.hpp"
#include "../../others/includes/rb_tree.hpp"
#include "../../vector/includes/vector.hpp"
#include "../../others/includes/make_pair.hpp"
#include "map_iterator.hpp"

namespace ft
{

    template < class Key, class T, class Compare = less<Key>,              
           class Alloc = allocator<pair<const Key,T> > >
    class map
    {
        
        private:        
        protected:
            Alloc           _alloc;
            size_t          _size;
            NodePtr         _cont;
            Compare         _comp;
            
        public:
            RBTree                                              _tree;
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef ft::pair<const key_type, mapped_type>       value_type;
            typedef Compare                                     key_compare;
            typedef Alloc                                       allocator_type;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef value_type*                                 pointer;
            typedef const value_type*                           const_pointer;
            typedef std::size_t                                 size_type;
            typedef std::ptrdiff_t                              difference_type;
            typedef map_iterator<pointer, map>                  iterator;
            typedef map_iterator<const_pointer, map>            const_iterator;
            typedef reverse_iterator<const_iterator>            const_reverse_iterator;
            typedef reverse_iterator<iterator>                  reverse_iterator;
    
        // template <class U, class V, class C, class A>
        // class map<U,T,Compare,Alloc>::value_compare
        // {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        //     friend class map;
        //     private:
        //     protected:
        //         C comp;
        //         value_compare (C c) : comp(c) {}  // constructed with map's comparison object
        //     public:
        //         typedef bool result_type;
        //         typedef value_type first_argument_type;
        //         typedef value_type second_argument_type;
        //         bool operator() (const value_type& x, const value_type& y) const
        //         {
        //             return comp(x.first, y.first);
        //         }
        // }

    //  Constructors and destructors

        explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
        {
            _size = 0;
            _alloc = alloc;
            _comp = comp;
            _tree = RBTree();
            _cont = _tree.getRoot();
        }
	
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
        {
            _size = it_diff(first, last);
            _alloc = alloc;
            _comp = comp;
            _tree = RBTree();
            //fill the map (insert ?)
        }

	    map (const map& x)
        {
            _size = x.size();
            _alloc = x.get_allocator();
            //aloc
            //comp cpy

        }

    //  Iterators
        iterator begin()
        {
            NodePtr it = _cont;
         
            while (it->left->left)
                it = it->left;
            return (iterator(it));
        }

        const_iterator begin() const
        {
            NodePtr it = _cont;
         
            while (it->left)    
                it = it->left;
            const iterator ret(it);
            return (ret);
        }
        
        iterator end()
        {
            NodePtr it = _cont;
         
            while (it->right->right)
                it = it->right;
            return (iterator(it));
        }

        const_iterator end() const
        {
            NodePtr it = _cont;

            while (it->right)
                it = it->right;
            const iterator ret(it);
            return (ret);
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
        size_type size() const {return (_size);}
        size_type max_size() const{return (_alloc.max_size());}
        bool empty() const
        {
            if (_size == 0)
                return (1);
            return (0);
        }
    //  Element access
        int& operator[] (const key_type& k)
        {
            return (_tree.searchTree(k)->val);
            // return (*((this->insert(k)).second));
        }
    //  Modifiers
        pair<iterator, bool> insert (const value_type& val)
        {
            ft::pair<Node*, bool> ret = _tree.insert(val);
            if (ret.second)
                _size ++;
            _cont = _tree.getRoot();
            return (ft::make_pair(iterator(ret.first), true));
        }

    //  Observers
        key_compare key_comp() const{return (_comp);}
        // value_compare value_comp() const{return (_comp);}

    //  Operations
    
    //  Allocator
        allocator_type get_allocator() const{return (this->_alloc);}
    };
}

#endif