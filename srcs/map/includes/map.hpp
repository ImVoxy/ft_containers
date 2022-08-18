#ifndef MAP_HPP
# define MAP_HPP

#include "../../others/includes/reverse_iterator.hpp"
#include "../../others/includes/standard_iterator.hpp"
#include "../../others/includes/pair.hpp"
#include "../../others/includes/utils.hpp"
#include "../../others/includes/rb_tree.hpp"
#include "../../vector/includes/vector.hpp"
#include "../../others/includes/make_pair.hpp"
#include "../../others/includes/lexicographical_compare.hpp"

#include "map_iterator.hpp"

namespace ft
{

    template < class Key, class T, class Compare = std::less<Key>,              
           class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        
        private:        
        protected:
            Alloc                           _alloc;
            size_t                          _size;
            Compare                         _comp;
            RBTree<Key, T, Compare, Alloc>  _tree;
            Node<Key, T>                    *_cont;

        public:
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
            _alloc = alloc;
            _comp = comp;
            _size = 0;
            insert(first, last);
            _cont = _tree.getRoot();
        }

	    map (const map& x)
        {
            
            _alloc = x.get_allocator();
            _comp = x.key_comp();
            _size = 0;
            if (x.size())
            {
                const_iterator it = x.begin();
                const_iterator ite = x.end();
                while (it != ite)
                {
                    this->insert(ft::make_pair(it.getKey(), it[it.getKey()]));
                    it++;
                }
                _cont = _tree.getRoot();
            }
            _size = x.size();
        }

        ~map()
        {
            if (_size > 0)
                clear();
        }

        map& operator= (const map& x)
        {
            this->clear();
            _alloc.deallocate(_tree.getSnode()->elem, 1);
            _tree.get_allocator().deallocate(_tree.getSnode(), 1);
            
            _tree.setSnode();
            _alloc = x.get_allocator();
            _comp = x.key_comp();
            if (x.size())
            {
                const_iterator it = x.begin();
                const_iterator ite = x.end();
                this->insert(it, ite);
                _cont = _tree.getRoot();

            }
            return (*this);
        }
        allocator_type get_allocator() const
        {return (_alloc);}

    //  Iterators
        iterator begin()
        {
           
            Node<key_type, mapped_type> *it = _tree.getRoot();

            if (it && it->left)
                while (it->left->left)
                    it = it->left;
            return (iterator(it));
        }

        const_iterator begin() const
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();

            if (it && it->left)
                while (it && it->left->color != 2)
                    it = it->left;
            const iterator ret(it);
            return (ret);
        }
        
        iterator end()
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();
         
            if (it && it->right)
                while (it->color != 2)
                    it = it->right;
            return (iterator(it));
        }

        const_iterator end() const
        {
            Node<key_type, mapped_type> *it = _tree.getRoot();

            if (it && it->right)
                while (it->color != 2)
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
        size_type max_size() const{return (_tree.get_allocator().max_size());}
        bool empty() const
        {
            if (_size == 0)
                return (1);
            return (0);
        }
    //  Element access
        mapped_type& operator[] (const key_type& k)
        {
            ((this->insert(ft::make_pair(k,mapped_type()))));
            return(_tree.searchTree(k)->elem->second);
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
            iterator tmp = first;

            while (first != last)
            {
                if (first.getNode()->color != 2 && _tree.isin(first.getKey()))
                {
                    tmp = first;
                    first++;
                    _tree.deleteNode(tmp.getKey());
                    _size--;
                }
            }
        }

        void clear()
        {
            while (erase(begin().getKey()))
            {}
            _size = 0;
            _cont = NULL;
            return;
        }

        void swap (map& x)
        {
            std::swap(_alloc, x._alloc);
            std::swap(_size, x._size);
            std::swap(_cont, x._cont);
            std::swap(_comp, x._comp);
            _tree.swap(x._tree);
        }

        pair<iterator, bool> insert (const value_type& val)
        {
            ft::pair<Node<key_type, mapped_type>*, bool> ret = _tree.insert(val);
            iterator test(ret.first);
            
            if (ret.second)
            {
                _size++;
                _cont = _tree.getRoot();
            }
            return (ft::pair<iterator, bool>(iterator(_tree.searchTree(val.first)), ret.second));
        }

        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            return (iterator(insert(val).first));
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
        value_compare value_comp() const{return (value_compare(_comp));}

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
            Node<key_type, mapped_type> *tmp = _tree.searchTree(k);
            
            if (tmp && (tmp->right || tmp->left))
                return (const_iterator(tmp));
            return (end());
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
            const_iterator finish = end();
            const_iterator tmp = begin();

            while (tmp != finish)
            {
                if (_comp(k, tmp.getKey()))
                    break;
                tmp++;
            }
            return (const_iterator(tmp));
        }

        iterator lower_bound (const key_type& k)
        {
            iterator finish = end();
            iterator tmp = begin();

            while (tmp != finish)
            {
                if (!(_comp(tmp.getKey(), k)))
                    return (tmp);
                tmp++;
            }
            return (tmp);
        }

        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator tmp = begin();
            const_iterator finish = end();

            while (tmp != finish)
            {
                if (!(_comp(tmp.getKey(), k)))
                    return (tmp);
                tmp++;
            }
            return (const_iterator(tmp));
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            const_iterator lower = lower_bound(k);
            const_iterator upper = upper_bound(k);

            return (ft::pair<const_iterator, const_iterator>(lower, upper));
        }
        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            iterator lower = lower_bound(k);
            iterator upper = upper_bound(k);

            return (ft::pair<iterator, iterator>(lower, upper));
        }
    //  Allocator
    };

        //  Relational operators
        template <class Key, class T, class Compare, class Alloc>
        bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
                            const map<Key,T,Compare,Alloc>& rhs )
        {
            typename ft::map<Key, T>::const_iterator rit = rhs.begin();
            typename ft::map<Key, T>::const_iterator lit = lhs.begin(); 
            typename ft::map<Key, T>::const_iterator rite = rhs.end();
            typename ft::map<Key, T>::const_iterator lite = lhs.end();

            if (lhs.size() != rhs.size())
                return (0);
            while ((rit != rite) && (lit != lite))
            {
                if (*rit != *lit)
                    return (0);
                rit++;
                lit++;
                
            }
            return (1);           
        }
        template <class Key, class T, class Compare, class Alloc>
        bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
                            const map<Key,T,Compare,Alloc>& rhs )
        {return (!(lhs == rhs));}
        template <class Key, class T, class Compare, class Alloc>
        bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
                            const map<Key,T,Compare,Alloc>& rhs )
        {return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
        template <class Key, class T, class Compare, class Alloc>
        bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
                            const map<Key,T,Compare,Alloc>& rhs )
        {return (!(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())));}
        template <class Key, class T, class Compare, class Alloc>
        bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
                            const map<Key,T,Compare,Alloc>& rhs )
        {return (!( lhs <= rhs));}
        template <class Key, class T, class Compare, class Alloc>
        bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
                            const map<Key,T,Compare,Alloc>& rhs )
        {return (!(lhs < rhs));}

        template <class Key, class T, class Compare, class Alloc>
        void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
        {
            x.swap(y);
        }
}

#endif