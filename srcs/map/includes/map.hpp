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

    template < class Key, class T, class Compare = std::less<Key>,              
           class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        
        private:        
        protected:
            Alloc           _alloc;
            size_t          _size;
            Node<Key, T>    *_cont;
            Compare         _comp;
            
            
        public:
            RBTree<Key, T, Compare, Alloc>                      _tree;

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
    
        class   value_compare
        { 
            friend class map;
            private:
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };

    //  Constructors and destructors

        explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
        {
            _size = 0;
            _alloc = alloc;
            _comp = comp;
            _cont = _tree.getRoot();
        }
	
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
        {
            _size = ft::it_diff(first, last);
            _alloc = alloc;
            _comp = comp;
            insert(first, last);
            insert(*last);
            _cont = _tree.getRoot();
        }

	    map (const map& x)
        {
            _size = x.size();
            _alloc = x.get_allocator();
            _comp = x.key_comp();
            if (_size)
            {
                const_iterator it = x.begin();
                const_iterator ite = x.end();
                while (it != ite)
                {
                    this->insert(ft::make_pair(it.getKey(), it[it.getKey()]));
                    it++;
                }
                this->insert(ft::make_pair(ite.getKey(), ite[ite.getKey()]));
                _cont = _tree.getRoot();
            }
        }

        ~map()
        {
            if (_size > 0)
                clear();
        }

        map& operator= (const map& x)
        {
            _size = x.size();
            _alloc = x.get_allocator();
            _comp = x.key_comp();
            if (_size)
            {
                const_iterator it = x.begin();
                const_iterator ite = x.end();
                while (it != ite)
                {
                    this->insert(ft::make_pair(it.getKey(), it[it.getKey()]));
                    it++;
                }
                this->insert(ft::make_pair(ite.getKey(), ite[ite.getKey()]));
                _cont = _tree.getRoot();
            }
            return (*this);
        }

    //  Iterators
        iterator begin()
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();

            if (it->left)
                while (it->left->left)
                    it = it->left;
            return (iterator(it));
        }

        const_iterator begin() const
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();
         
            while (it->left->left)    
                it = it->left;
            const iterator ret(it);
            return (ret);
        }
        
        iterator end()
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();
         
            if (it->right)
                while (it->right->right)
                    it = it->right;
            return (iterator(it));
        }

        const_iterator end() const
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();

            if (it->right)
                while (it->right->right)
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
            return (_tree.searchTree(k)->elem->second);
            // return (*((this->insert(k)).second));
        }
    //  Modifiers

        void erase (iterator position)
        {
            if (_tree.isin(position.getKey()))
            {
                _size--;
                _tree.deleteNode(position.getKey());
            }
        }

        size_type erase (const key_type& k)
        {
            if (_tree.isin(k))
            {
                _tree.deleteNode(k);
                _size--;
                return (1);
            }
            return (0);
        }

        void erase (iterator first, iterator last)
        {
            while (first != last)
            {
                if (_tree.isin(first.getKey()))
                {
                    _tree.deleteNode(first.getKey());
                    _size--;
                }
                first++;
            }
        }

        void clear()
        {
            while (erase(begin().getKey()))
            {}
            return;
        }

        void swap (map& x)
        {
            std::swap(_alloc, x._alloc);
            std::swap(_size, x._size);
            std::swap(_cont, x._cont);
            std::swap(_comp, x.key_comp);
            std::swap(_tree, x._tree);
        }

        pair<iterator, bool> insert (const value_type& val)
        {
            ft::pair<Node<key_type, mapped_type>*, bool> ret = _tree.insert(val);
            
            if (ret.second)
            {
                _size ++;
                _cont = _tree.getRoot();
            }
            return (ft::make_pair(iterator(ret.first), ret.second));
        }

        iterator insert (iterator position, const value_type& val)
        {
            return (iterator(insert(make_pair(position.getKey(), val))));
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                insert(*first);
                first++;
            }
        }

    //  Observers
        key_compare key_comp() const{return (_comp);}
        value_compare value_comp() const{return (_comp);}

    //  Operations
    
        size_type count (const key_type& k) const
        {
            Node<key_type, mapped_type> *tmp = _tree.searchTree(k);
            
            if (tmp && (tmp->right || tmp->left))
                return (1);
            return (0);
        }

        iterator find (const key_type& k)
        {
            Node<key_type, mapped_type> *tmp = _tree.searchTree(k);
            
            if (tmp && (tmp->right || tmp->left))
                return (iterator(tmp));
            return (end());
        }

        const_iterator find (const key_type& k) const
        {
            iterator ret(find(k));

            return (ret);
        }

        iterator upper_bound (const key_type& k)
        {
            iterator tmp = begin();
            iterator finish = end();

            while (tmp != finish)
            {
                if (_comp(k, tmp.getKey()))
                    break;
                tmp++;
            }
            return (tmp);
        }

        const_iterator upper_bound (const key_type& k) const
        {
            const_iterator tmp = end();
            const_iterator finish = begin();

            while (tmp != finish)
            {
                if (_comp(k, tmp.getKey()))
                    break;
                tmp--;
            }
            return (const_iterator (tmp));
        }

        iterator lower_bound (const key_type& k)
        {
            iterator tmp = end();
            iterator finish = begin();

            while (tmp != finish)
            {
                if (!_comp(tmp.getKey(), k))
                    break;
                tmp--;
            }
            return (tmp);
        }

        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator tmp = begin();
            const_iterator finish = end();

            while (tmp != finish)
            {
                if (!_comp(tmp.getKey(), k))
                    break;
                tmp++;
            }
            return (const_iterator (tmp));
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            const_iterator tmp = begin();
            const_iterator finish = end();

            if (_comp(end().getKey(), k))
                return (ft::make_pair(const_iterator(end()), const_iterator(end())));
            while (tmp != finish)
            {
                if (!_comp(tmp.getKey(), k))
                    break;
                tmp++;
            }
            return (ft::make_pair(const_iterator(tmp), const_iterator(tmp)));
        }
        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            iterator tmp = begin();
            iterator finish = end();

            if (_comp(end().getKey(), k))
                return (ft::make_pair(end(), end()));
            while (tmp != finish)
            {
                if (!_comp(tmp.getKey(), k))
                    break;
                tmp++;
            }
            ft::pair<iterator, iterator> test(tmp, tmp);
            return (test);
        }
    //  Allocator
        allocator_type get_allocator() const{return (this->_alloc);}
    };
}

#endif