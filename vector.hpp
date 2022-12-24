#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <stdexcept>
#include "Iterator.hpp"

namespace ft {
	template<class vector> class iterator : public Iterator<std::random_access_iterator_tag, typename vector::value_type> {
	public:
		typedef	typename vector::value_type			value_type;
		typedef	value_type*							pointer;
		typedef value_type&							reference;
		typedef	typename vector::difference_type	difference_type;
	public:
		iterator() : _ptr(0) {};

		iterator(const iterator &cpy) : _ptr(cpy._ptr) {};

		iterator(pointer ptr) : _ptr(ptr) {};

		const iterator	operator=(const iterator &cpy) {
			_ptr = cpy._ptr;
			return *this;
		}

		iterator&	operator++() {
			_ptr++;
			return *this;
		}
		iterator operator++(int) {
			iterator	it = *this;
			++(*this);
			return it;
		}
		bool	operator==(const iterator &it) {
			return _ptr == it._ptr ? 1 : 0;
		}
		bool	operator!=(const iterator &it) {
			return _ptr != it._ptr ? 1 : 0;
		}
		reference operator*() {
			return *_ptr;
		}
		reference operator->() {
			return _ptr;
		}
		iterator&	operator--() {
			_ptr--;
			return *this;
		}
		iterator operator--(int) {
			iterator	it = *this;
			--(*this);
			return it;
		}
		difference_type	operator-(iterator const &it) const {
			return this->_ptr - it._ptr;
		};
		iterator	operator-(const difference_type n) const {
			iterator tmp = *this;
			return tmp._ptr -= n;
		};
		difference_type	operator+(iterator const &it) const {
			return this->_ptr + it._ptr;
		};
		iterator	operator+(const difference_type n) const {
			iterator tmp = *this;
			return tmp._ptr += n;
		};
	private:
		pointer	_ptr;
	};

	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef	T											value_type;
		typedef Allocator									allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef const typename Allocator::pointer			const_pointer;
		typedef ft::iterator<vector<T> >					iterator;
		typedef ft::iterator<const vector<T> >				const_iterator;
		//typedef reverse_iterator //TODO reverse iterators
		//typedef const_reverse_iterator //TODO const reverse iterators
	private:
		allocator_type			_alloc;
		value_type				*_array;
		size_type				_size;
		size_type				_capacity;
		difference_type 		_maxSize;
	public:
		/* Member functions	*/
		/* Constructors, destructor and overload of '=' operator */
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(_alloc.allocate(0)), _size(0), _capacity(0), _maxSize(std::numeric_limits<difference_type>::max()) {};
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(_alloc.allocate(n)), _size(n), _capacity(n), _maxSize(std::numeric_limits<difference_type>::max()) {
			for (size_t i = 0; i < n; i++) {
				this->_array[i] = val;
			}
		};
		template <class InputIt>
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(_alloc.allocate(last - first)), _size(last - first), _capacity(last - first), _maxSize(std::numeric_limits<difference_type>::max()) {
			int i = 0;
			while (first != last) {
				this->_array[i++] = *first;
				first++;
			}
		};
		vector(const vector& x) {
			*this = x;
		};
		~vector() {
			this->_alloc.deallocate(this->_array, this->_capacity);
		};
		vector&	operator=(const vector& x) {
			this->_alloc = x._alloc;
			this->_array = _alloc.allocate(x.capacity());
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_maxSize = std::numeric_limits<difference_type>::max();
			for (size_t i = 0; i < x._size; i++) {
				this->_array[i] = x._array[i];
			}
			return *this;
		}
		/* Iterators */
		iterator	begin(void) {
			return	iterator(this->_array);
		}
		iterator	end(void) {
			return	iterator(this->_array + this->_size);
		}
		//TODO reverse iterators
		/* Capacity */
		size_type	size(void) const {
			return this->_size;
		};
		size_type	capacity(void) const {
			return this->_capacity;
		};
		bool	empty(void) const {
			if (!this->_size)
				return 1;
			return 0;
		};
		size_type	max_size(void) const {
			return sizeof(value_type) == 1 ? this->_maxSize : (this->_maxSize / (sizeof(value_type) / 2));
		};
		void	reserve(size_type new_cap) {
			if (new_cap > this->max_size())
				throw	std::length_error("vector");
			if (new_cap > this->_capacity) {
				ft::vector<value_type>	tmp;
				tmp._array = this->_alloc.allocate(this->_size);
				for (size_t i = 0; i < this->_size; i++) {
					tmp._array[i] = this->_array[i];
				}
				_alloc.deallocate(this->_array, this->_capacity);
				this->_array = _alloc.allocate(new_cap);
				for (size_t i = 0; i < this->_size; i++) {
					this->_array[i] = tmp._array[i];
				}
				this->_capacity = new_cap;
			}
		};
		/* Element access */
		reference at(size_type n) {
			if (n >= this->size())
				throw std::out_of_range("vector");
			return this->_array[n];
		};
		const_reference at(size_type n) const {
			if (n >= this->size())
				throw std::out_of_range("vector");
			return this->_array[n];
		};
		reference	operator[](size_type pos) {
			return this->_array[pos];
		};
		const_reference	operator[](size_type pos) const {
			return this->_array[pos];
		};
		reference	front(void) {
			return this->_array[0];
		};
		const_reference	front(void) const {
			return this->_array[0];
		};
		reference	back(void) {
			return this->_array[this->_size];
		};
		const_reference	back(void) const {
			return this->_array[this->_size];
		};
		value_type*	data(void) {
			return *this->_array;
		};
		const value_type*	data(void) const {
			return *this->_array;
		};
		/* Modifiers */
		void	push_back(const value_type& value) {
			if (this->_size + 1 < this->_capacity)
			{
				this->_array[_size] = value;
				this->_size++;
			}
			else {
				this->_capacity *= 2;
				if (!this->_capacity)
					this->_capacity++;
				ft::vector<value_type>	tmp;
				tmp._array = _alloc.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++) {
					tmp._array[i] = this->_array[i];
				}
				tmp._array[this->_size] = value;
				this->_alloc.deallocate(this->_array, this->_capacity / 2);
				this->_array = this->_alloc.allocate(this->_capacity);
				this->_size++;
				for (size_t i = 0; i < this->_size; i++) {
					this->_array[i] = tmp._array[i];
				}
			}
		};
		void	clear() {
			for (size_t i = 0; i < this->_size ;i++) {
				this->_alloc.destroy(this->_array + i);
			}
			this->_size = 0;
		};

		iterator	insert(iterator position, const value_type& val) {
			iterator		it;
			vector			tmp;
			difference_type pos = position - this->begin();
			if (this->_size + 1 > this->_capacity) {
				if (!this->_capacity)
					tmp.reserve(1);
				tmp.reserve(this->_capacity * 2);
			}
			else
				tmp.reserve(this->_capacity);
			for (iterator it = this->begin(); it != this->end(); it++)
				tmp._array[it - this->begin()] = this->_array[it - this->begin()];
			_alloc.deallocate(this->_array, this->_capacity);
			this->_array = _alloc.allocate(tmp.capacity());
			it = this->begin();
			while (it - this->begin() != pos) {
				this->_array[it - this->begin()] = tmp._array[it - this->begin()];
				it++;
			}
			*it++ = val;
			this->_size++;
			while (static_cast<size_type>(it - this->begin()) != this->_size) {
				this->_array[it - this->begin()] = tmp._array[(it - 1) - this->begin()];
				it++;
			}
			return position;
		}

		void	insert(iterator position, size_type n, const value_type& val) {
			vector		tmp;
			iterator	it;
			difference_type pos = position - this->begin();
			tmp._capacity = this->_capacity;
			if (this->_size + n > this->_capacity) {
				if (!tmp._capacity)
					tmp.reserve(1);
				while (this->_size + n > tmp._capacity)
					tmp.reserve(tmp._capacity * 2);
			}
			else
				tmp.reserve(tmp._capacity);
			tmp._size = this->_size;
			for (iterator it = this->begin(); it != this->end(); it++)
				tmp._array[it - this->begin()] = this->_array[it - this->begin()];
			_alloc.deallocate(this->_array, this->_capacity);
			this->_array = _alloc.allocate(tmp._capacity);
			it = this->begin();
			while (it - this->begin() != pos) {
				this->_array[it - this->begin()] = tmp._array[it - this->begin()];
				it++;
			}
			for (size_type i = 0; i < n; i++) {
				this->_array[it - this->begin()] = val;
				it++;
			}
			this->_size += n;
			while (static_cast<size_type>(it - this->begin()) != this->_size) {
				this->_array[it++ - this->begin()] = tmp._array[pos++];
			}
		}

		template<class InputIt> void insert(iterator position, InputIt first, InputIt last) {
			vector			toInsert;
			difference_type size = last - first;
			toInsert.reserve(size);
			difference_type initialPos = position - this->begin();
			for (iterator it = first; it != last; it++) {
				toInsert.push_back(this->_array[it - this->begin()]);
			}
			vector		tmp;
			for (iterator it = this->begin(); it != this->end(); it++) {
				tmp.push_back(*it);
			}
			this->clear();
			if (!this->_capacity)
				this->reserve(1);
			while (tmp.capacity() + size > this->_capacity)
				this->reserve(this->_capacity * 2);
			this->_size = tmp.size() + size;
			iterator	it = this->begin();
			while (it - this->begin() != initialPos) {
				this->_array[it - this->begin()] = tmp._array[it - this->begin()];
				it++;
			}
			difference_type i = 0;
			while (i < size) {
				this->_array[it - this->begin()] = toInsert._array[i++];
				it++;
			}
			while (static_cast<size_type>(it - this->begin()) != tmp.size() + size) {
				this->_array[it - this->begin()] = tmp._array[initialPos++];
				it++;
			}
		};

		void	pop_back(void) {
			_alloc.destroy(this->_array + this->_size);
			this->_size--;
		}

		iterator	erase(iterator pos) {
			iterator tmp = pos;
			while (tmp + 1 != this->end()) {
				this->at(tmp - this->begin()) = this->at((tmp + 1) - this->begin());
				tmp++;
			}
			this->pop_back();
			return pos;
		};
		iterator	erase(iterator first, iterator last) {
			vector	tmp = *this;
			tmp.clear();
			iterator it = this->begin();
			while (it != first) {
				tmp.push_back(this->at(it++ - this->begin()));
			}
			it = last;
			while (it != this->end())
				tmp.push_back(this->at(it++ - this->begin()));
			*this = tmp;
			return last;
		};
		//TODO resize
		//TODO swap
		/* Allocator */
		allocator_type get_allocator(void) const {
			return this->_alloc;
		};
		/* Non-member functions	*/
		//TODO operators
	};
}

#endif //VECTOR_HPP
