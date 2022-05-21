#include<vector>
#ifndef STACK_HPP
# define STACK_HPP

int stack_test();

namespace ft
{
    template<class T, class Container = std::vector<T> > 
    class stack
    {
        typedef Container   container_type;
        typedef T           value_type;
        
        private:
        protected:
            container_type  _cont;
        public:
//  Constructors and destructors
            explicit stack(const container_type& ctnr = container_type()) : _cont(ctnr){};
            stack(const stack<value_type, container_type>& cont) : _cont(cont._cont){};
            ~stack(){};
//  Member fonctions
            bool empty(){return (_cont.empty());}
            int size(){return (_cont.size());}
            value_type top(){return (_cont.back());}
            void push(const T val){_cont.push_back(val);}
            void pop(){_cont.pop_back();}

            template <class A, class B>
            friend bool operator== (const stack<A,B>& lhs, const stack<A,B>& rhs);
            template <class A, class B>
            friend bool operator!= (const stack<A,B>& lhs, const stack<A,B>& rhs);
            template <class A, class B>
            friend bool operator< (const stack<A,B>& lhs, const stack<A,B>& rhs);
            template <class A, class B>
            friend bool operator<= (const stack<A,B>& lhs, const stack<A,B>& rhs);
            template <class A, class B>
            friend bool operator> (const stack<A,B>& lhs, const stack<A,B>& rhs);
            template <class A, class B>
            friend bool operator>= (const stack<A,B>& lhs, const stack<A,B>& rhs);
    };

//  Non-member fuction overloads

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs._cont == rhs._cont);
    }

    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs._cont != rhs._cont);
    }

    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs._cont < rhs._cont);
    }

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs._cont <= rhs._cont);
    }

    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs._cont > rhs._cont);
    }
        
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs._cont >= rhs._cont);
    }
}

#endif