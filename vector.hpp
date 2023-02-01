#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <stdexcept>
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft {
	template <class vector>
	class iterator {
	public:
		typedef ptrdiff_t									difference_type;
		typedef typename vector::value_type					value_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename std::random_access_iterator_tag	iterator_category;
	private:
		pointer	_ptr;
	public:
		/* Constructors */
		iterator() : _ptr(0) {}

		explicit iterator(pointer ptr) : _ptr(ptr) {}

		iterator(const iterator& x) : _ptr(x._ptr) {}

		/* Destructor */
		~iterator() {}

		/* Overload of operator= */
		iterator&	operator=(const iterator& x) {
			if (*this == &x)
				return *this;
			this->_ptr = x._ptr;
			return *this;
		}

		/* Operator overloads */
		bool	operator==(const iterator& other) const {
			return this->_ptr == other._ptr;
		}

		bool	operator!=(const iterator& other) const {
			return !(*this == other);
		}

		reference	operator*() {
			return *this->_ptr;
		}

		reference	operator->() {
			return this->_ptr;
		}

		//TODO operator* =

		iterator&	operator++() {
			this->_ptr++;
			return *this;
		}

		iterator	operator++(int) {
			iterator	tmp = *this;
			++(*this);
			return (tmp);
		}

		iterator&	operator--() {
			this->_ptr--;
			return *this;
		}

		iterator	operator--(int) {
			iterator	tmp = *this;
			--(*this);
			return (tmp);
		}

		iterator	operator+(difference_type n) const {
			iterator	tmp(this->_ptr + n);
			return	tmp;
		}

		iterator	operator-(difference_type n) const {
			iterator	tmp(this->_ptr - n);
			return	tmp;
		}

		difference_type	operator-(iterator &it) {
			return this->_ptr - it._ptr;
		}

		bool	operator<(const iterator& r) {
			return this->_ptr < r._ptr;
		}

		bool	operator>(const iterator& r) {
			return this->_ptr > r._ptr;
		}

		bool	operator<=(const iterator& r) {
			return this->_ptr <= r._ptr;
		}

		bool	operator>=(const iterator& r) {
			return this->_ptr >= r._ptr;
		}

		iterator&	operator+=(difference_type n) {
			this->_ptr += n;
			return *this;
		}

		iterator&	operator-=(difference_type n) {
			this->_ptr -= n;
			return *this;
		}

		reference	operator[](int index) {
			return *(this->_ptr + index);
		}
	};

	template <typename T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::iterator<vector>					iterator;
		typedef typename ft::iterator<const vector>				const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>			difference_type;
		typedef size_t 											size_type;
	private:
		allocator_type	_alloc;
		pointer			_array;
		size_type		_size;
		size_type		_capacity;
		size_type		_maxSize;
	public:
		/* Constructors */
		explicit vector(const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _array(0), _size(0), _capacity(0), _maxSize(alloc.max_size()) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _size(n), _capacity(n), _maxSize(alloc.max_size()) {
			this->_array = this->_alloc.allocate(n);
			for (size_type i = 0; i < n ; i++)
				this->_alloc.construct(this->_array + i, val);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		: _alloc(alloc), _size(last - first), _capacity(_size), _maxSize(alloc.max_size()) {
			this->_array = this->_alloc.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, *(first++));
		}

		vector(const vector& x)
		: _alloc(x._alloc), _size(x._size), _capacity(x._capacity), _maxSize(x._maxSize) {
			this->_array = this->_alloc.allocate(this->_capacity);
			for (unsigned long i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, *(x._array + i));
		}

		/* Destructor */
		~vector() {
			this->clear();
			this->_alloc.deallocate(this->_array, this->_capacity);
		}

		/* Overload of operator= */
		vector&	operator=(const vector& x) {
			vector tmp(x);
			this->swap(tmp);
			return *this;
		}

		/* Iterators */
		iterator	begin() {
			return iterator(this->_array);
		}

		iterator	end() {
			return iterator(this->_array + this->_size);
		}

		reverse_iterator	rbegin() {
			return reverse_iterator(this->end());
		}

		reverse_iterator	rend() {
			return reverse_iterator(this->begin());
		}

		/* Capacity */
		size_type	size() const {
			return this->_size;
		};

		size_type	max_size() const {
			return sizeof(value_type) == 1 ? (this->_maxSize / 2) : this->_maxSize;
			//TODO check all data types just in case
		}

		void	resize(size_type n, value_type val = value_type()) {
			if (this->_size + n > this->max_size())
				throw	std::length_error("vector");
			if (n <= this->_size) {
				for (unsigned long i = n + 1; i < this->_size; i++)
					this->_alloc.destroy(this->_array + i);
				this->_size = n;
			}
			else {
				vector	tmp = *this;
				this->clear();
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_array = this->_alloc.allocate(n);
				for (unsigned long i = 0; i < tmp._size; i++)
					this->_alloc.construct(this->_array + i, *(tmp._array + i));
				for (unsigned long i = tmp._size; i < n; i++)
					this->_alloc.construct(this->_array + i, val);
				this->_capacity = n;
				this->_size = n;
			}
			//TODO check more cases, including limit cases, pending
		}

		size_type	capacity() const {
			return this->_capacity;
		}

		bool	empty() const {
			return this->_size == 0;
		}

		void	reserve(size_type n) {
			if (n > this->max_size())
				throw	std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			vector	tmp = *this;
			this->clear();
			this->_size = tmp._size;
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = n;
			this->_array = this->_alloc.allocate(this->_capacity);
			for (unsigned long i = 0; i < tmp._size; i++)
				this->_alloc.construct(this->_array + i, *(tmp._array + i));
			//TODO check more cases, including limit cases, pending
		}

		/* Element access */
		reference	operator[](size_type n) {
			return *(this->_array + n);
		}

		const_reference	operator[](size_type n) const {
			return *(this->_array + n);
		}

		reference	at(size_type n) {
			if (n >= this->size())
				throw	std::out_of_range("vector");
			return *(this->_array + n);
		}

		const_reference	at(size_type n) const {
			if (n >= this->size())
				throw	std::out_of_range("vector");
			return *(this->_array + n);
		}

		reference	front() {
			return *(this->_array);
		}

		const_reference	front() const {
			return *(this->_array);
		}

		reference	back() {
			return *(this->_array + this->_size - 1);
		}

		const_reference	back() const {
			return *(this->_array + this->_size - 1);
		}

		value_type*	data() {
			return this->_array;
		}

		const value_type*	data() const {
			return this->_array;
		}

		/* Modifiers */

		/*template<class InputIterator>
		void	assign(InputIterator first, InputIterator last) {
			//TODO
		}*/

		void	assign(size_type n, const value_type& val) {
			this->resize(n);
			for (unsigned long i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, val);
		}
		//TODO assign

		void	push_back(const value_type& val) {
			if (this->_size + 1 > this->max_size())
				throw std::length_error("vector");
			if (this->_size + 1 > this->_capacity) {
				if (!this->_capacity)
					this->reserve(1);
				else {
					this->reserve(this->_capacity * 2);
				}
			}
			this->_alloc.construct(this->_array + this->_size, val);
			this->_size++;
			//TODO check if it works in every case (?)
		}

		void	pop_back() {
			this->_alloc.destroy(this->_array + this->_size);
			*(this->_array + this->_size) = 0;
			--this->_size;
		}

		//TODO insert

		/*iterator	erase(iterator position) {
			//TODO
		}*/

		/*iterator	erase(iterator first, iterator last) {
		 * //TODO
		}*/
		//TODO erase

		void	swap(vector& x) {
			vector	tmp(x);
			x.clear();
			x._alloc.deallocate(x._array, x._capacity);
			x._size = this->_size;
			x._maxSize = this->_maxSize;
			x._capacity = this->_capacity;
			x._alloc = this->_alloc;
			x._array = x._alloc.allocate(x._capacity);
			for (unsigned long i = 0; i < this->_size; i++)
				x._alloc.construct(x._array + i, *(this->_array + i));
			this->clear();
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_size = tmp._size;
			this->_maxSize = tmp._maxSize;
			this->_capacity = tmp._capacity;
			this->_alloc = tmp._alloc;
			this->_array = this->_alloc.allocate(this->_capacity);
			for (unsigned long i = 0; i < tmp._size; i++)
				this->_alloc.construct(this->_array + i, *(tmp._array + i));
		}

		void	clear() {
			for (unsigned long i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_array + i);
			this->_size = 0;
		}

		/* Allocator */
		allocator_type	get_allocator() const {
			return this->_alloc;
		}
	};

	/* Non member */
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc>& rhs) {
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc>& rhs) {
		return !(rhs < lhs); //TODO CHECK
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc>& rhs) {
		return !(lhs < rhs); //TODO CHECK
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
		x.swap(y);
	}
}

#endif //VECTOR_HPP
