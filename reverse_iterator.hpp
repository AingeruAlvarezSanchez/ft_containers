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
		/* Constructors */
		reverse_iterator()
		: _base(0) {}

		explicit reverse_iterator(iterator_type it)
		: _base(it) {}

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it)
		: _base(rev_it._base) {}

		/* Base */
		iterator_type	base() const {
			return _base;
		}

		/* Operator overloads */
		reference	operator*() const {
			return *(this->_base - 1);
		}

		reverse_iterator	operator+(difference_type n) const {
			return reverse_iterator(this->_base - n);
		}

		reverse_iterator&	operator++() {
			this->_base--;
			return *this;
		}

		reverse_iterator	operator++(int) {
			reverse_iterator	tmp = *this;
			--this->_base;
			return tmp;
		}

		reverse_iterator&	operator+=(difference_type n) {
			this->_base -= n;
			return *this;
		}

		reverse_iterator	operator-(difference_type n) const {
			return reverse_iterator(this->_base + n);
		}

		reverse_iterator&	operator--() {
			this->_base++;
			return *this;
		}

		reverse_iterator	operator--(int) {
			reverse_iterator	tmp = *this;
			++this->_base;
			return tmp;
		}

		reverse_iterator&	operator-=(difference_type n) {
			this->_base += n;
			return *this;
		}

		pointer	operator->() const {
			return &this->operator*();
		}

		reference	operator[](difference_type n) const {
			return this->base()[- n - 1];
		}
	};

	/* Non member */ //TODO check if they all work correctly without ft::equal
	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return rev_it + n;
		//TODO check if it works correctly
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		lhs.base() - rhs.base();
		//TODO check if it works correctly
	}
}

#endif //REVERSE_ITERATOR_HPP
