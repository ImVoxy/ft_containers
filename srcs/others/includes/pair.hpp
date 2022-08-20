#ifndef PAIR_HPP
# define PAIR_HPP


int pair_test();

namespace ft
{
    template< class T1, class T2 >
    class pair
    {
        private:

        protected:
        public:
            T1 first;
            T2 second;

//  Constructors and destructors
            pair() : first(), second(){};
            pair( const T1& x, const T2& y ) : first(x), second(y){};
            template< class U1, class U2 >
            pair( const pair<U1, U2>& p ) : first(p.first), second(p.second){};
            // pair( const pair& p ) = default : first(p.first), second(p.second){}; //C++11
//  Member fonctions
            pair& operator=( const pair& other )
            {
                // if (other != *this)
                // {
                    first = other.first;
                    second = other.second;
                // }
                return (*this);
            }
    };

//  Non-member fuction overloads

    template <class A, class B>
    bool operator== (const pair<A,B>& lhs, const pair<A,B>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class A, class B>
    bool operator!= (const pair<A,B>& lhs, const pair<A,B>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class A, class B>
    bool operator<  (const pair<A,B>& lhs, const pair<A,B>& rhs)
    {
        return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
    }

    template <class A, class B>
    bool operator<= (const pair<A,B>& lhs, const pair<A,B>& rhs)
    {
        return (!(rhs<lhs));
    }

    template <class A, class B>
    bool operator>  (const pair<A,B>& lhs, const pair<A,B>& rhs)
    {
        return (rhs<lhs);
    }
        
    template <class A, class B>
    bool operator>= (const pair<A,B>& lhs, const pair<A,B>& rhs)
    {
        return (!(lhs<rhs));
    }

}

#endif