#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include "integral_constant.hpp" //TODO check how it works, also check it works correctly

namespace ft {
	template <class T>
	struct is_integral: public ft::integral_constant<bool, false> {};
	template <>
	struct is_integral<char> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<signed char> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<short int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<long int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<long long int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned long long int> : public ft::integral_constant<bool, true> {};
}

#endif //IS_INTEGRAL_HPP
