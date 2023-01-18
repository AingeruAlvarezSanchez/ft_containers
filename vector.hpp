#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <stdexcept>
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft {
	template <typename T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		//TODO iterators
		//typedef typename ft::iterator_traits<iterator>		difference_type; //TODO need iterators first
		typedef size_t 										size_type;
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
		//TODO begin
		//TODO end
		//TODO rbegin
		//TODO rend
		//TODO have in mind that constant versions of the iterator functions were implemented on C++11

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
				for (unsigned long i = this->_size; i < n; i++)
					this->push_back(val);
			}
		}

		size_type	capacity() const {
			return this->_capacity;
		}

		bool	empty() const {
			return this->_size == 0;
		}

		void	reserve(size_type n) {
			if (n > this->max_size())
				throw	std::length_error("vector"); //TODO check the message of the original
			vector	tmp = *this;
			this->clear();
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = n;
			this->_array = this->_alloc.allocate(this->_capacity);
			for (unsigned long i = 0; i < tmp._size; i++)
				this->push_back(*(tmp._array + i));
			//TODO before correction check if push_back is better enough than construct
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

		const_reference	back() const /*noexcept*/ { //TODO noexcept??
			return *(this->_array + this->_size - 1);
		}

		value_type*	data() /*noexcept*/ { //TODO noexcept??
			return this->_array;
		}

		const value_type*	data() const /*noexcept*/ {
			//TODO if size is 0 it may or not may return nullptr, check with original
			return this->_array;
		}

		/* Modifiers */

		//TODO assign

		void	push_back(const value_type& val) {
			if (this->_size + 1 > this->max_size())
				throw std::length_error("vector");
			if (this->_size + 1 > this->_capacity) {
				vector	tmp = *this;
				this->_capacity *= 2;
				if (this->_capacity != 0) {
					this->clear();
					this->_alloc.deallocate(this->_array, tmp._capacity);
					this->_array = this->_alloc.allocate(this->_capacity);
					this->_size = tmp._size;
					for (unsigned long i = 0; i < tmp._size; i++)
						this->_alloc.construct(this->_array + i, *(tmp._array + i));
				}
				else {
					this->_array = this->_alloc.allocate(1);
					this->_capacity = 1;
				}
			}
			this->_alloc.construct(this->_array + this->_size, val);
			++this->_size;
			//TODO check if it works in every case (?)
		}

		void	pop_back() {
			this->_alloc.destroy(this->_array + this->_size);
			*(this->_array + this->_size) = 0;
			--this->_size;
		}

		//TODO insert
		//TODO erase

		void	swap(vector& x) {
			//TODO can we swap the array without temporary? with number variables its possible
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

		//TODO emplace // What the hell is this function declaration?? va_args??

		/* Allocator */
		allocator_type	get_allocator() const {
			return this->_alloc;
		}
	};

	/* Non member */
	//TODO operator== //ft::equal required
	//TODO operator!=
	//TODO operator<
	//TODO operator<=
	//TODO operator>
	//TODO operator>=
	//TODO operator>=
	//TODO std::swap(std::vector) //ask, i need to change private parameters from each vector, should i make it friend??
}

#endif //VECTOR_HPP
