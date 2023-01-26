#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator {
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
	private:
		iterator_type	_base;
	public:
		reverse_iterator() : _base(0) {}
		explicit reverse_iterator(iterator_type it) : _base(it) {}
		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it._base) {}

		//TODO base

		reference	operator*() const {
			return *(this->_base - 1);
		}

		//TODO operator+
		//TODO operator++
		//TODO operator+=
		//TODO operator-
		//TODO operator--
		//TODO operator-=
		//TODO operator->
		//TODO operator[]
	};
	//TODO operator==
	//TODO operator!=
	//TODO operator<
	//TODO operator<=
	//TODO operator>
	//TODO operator>=
	//TODO operator+
	//TODO operator-
}

#endif //REVERSE_ITERATOR_HPP
