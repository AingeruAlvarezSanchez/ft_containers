#ifndef INTEGRAL_CONSTANT_HPP
#define INTEGRAL_CONSTANT_HPP

namespace ft {
	template <typename T, T v>
	struct integral_constant {
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		static const T value = v;
		operator	T() {
			return value;
		}
	};
}

#endif //INTEGRAL_CONSTANT_HPP
