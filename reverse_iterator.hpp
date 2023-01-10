#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft {
	template < class Iter > class reverse_iterator {
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
	public:
		reverse_iterator() : it(0) {};
		explicit reverse_iterator(iterator_type x) : it(x) {};
		//Operator= overload
		//base
		//operator * overload
		//operator -> overload
		//operator[]
		//operator++
		//operator++(int)
		//operator+=
		//operator+
		//operator--
		//operator--(int)
		//operator-=
		//operator-
		//TODO non member
		//operator==
		//operator!=
		//operator<
		//operator<=
		//operator>
		//operator>=
	protected:
		iterator_category	it;
	};
}

#endif
