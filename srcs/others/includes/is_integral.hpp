#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

int is_integral_test();

namespace ft
{
    template< class T, T v >
    struct integral_constant
    {
        typedef T value_type;
        typedef integral_constant type;
        enum {value = v};
    };

    typedef integral_constant<bool, false> false_type;
    typedef integral_constant<bool, true> true_type;

    template < class T > struct remove_cv { typedef T type; };
    template < class T > struct remove_cv< const T > { typedef T type; };
    template < class T > struct remove_cv< volatile T > { typedef T type; };
    template < class T > struct remove_cv< const volatile T > { typedef T type; };

    template<typename T>
    struct is_integral_base : public false_type{};

    template<typename T>
    struct is_integral : public is_integral_base<typename remove_cv<T>::type>::type{};

    template<>
    struct is_integral_base<bool> : public true_type
    {
        typedef bool value;
    };

    template<>
    struct is_integral_base<char> : public true_type
    {
        typedef char value;
    };

    template<>
    struct is_integral_base<unsigned int> : public true_type
    {
        typedef unsigned int value;
    };

    template<>
    struct is_integral_base<unsigned long> : public true_type
    {
        typedef unsigned long value;
    };

    template<>
    struct is_integral_base<wchar_t> : public true_type
    {
        typedef wchar_t value;
    };

    template<>
    struct is_integral_base<short> : public true_type
    {
        typedef short value;
    };

    template<>
    struct is_integral_base<int> : public true_type
    {
        typedef int value;
    };

    template<>
    struct is_integral_base<long> : public true_type
    {
        typedef long value;
    };

    template<>
    struct is_integral_base<long long> : public true_type
    {
        typedef long long value;
    };
}

#endif