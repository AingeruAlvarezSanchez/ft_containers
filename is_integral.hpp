#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {
	template <class T>
	struct is_integral: public std::integral_constant<bool, false> {};
	template <>
	struct is_integral<char> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<char16_t> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<char32_t> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<wchar_t> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<signed char> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<short int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<long int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<long long int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned char> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned short int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned long int> : public std::integral_constant<bool, true> {};
	template <>
	struct is_integral<unsigned long long int> : public std::integral_constant<bool, true> {};
}

#endif //IS_INTEGRAL_HPP
