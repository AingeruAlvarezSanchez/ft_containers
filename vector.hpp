#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <stdexcept>

namespace ft {
	template<class T, class Allocator= std::allocator<T> >
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
		//typedef iterator;//TODO iterators
		//typedef const_iterator //TODO const iterators
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
				vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(_alloc.allocate(0)), _size(0), _capacity(0), _maxSize(std::numeric_limits<difference_type>::max()) {};
				explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(_alloc.allocate(n)), _size(n), _capacity(n), _maxSize(std::numeric_limits<difference_type>::max()) {
					for (size_t i = 0; i < n; i++) {
						this->_array[i] = val;
					}
				};
				/*template<class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {};*/ //TODO Need to create LegacyInputIterators
				vector(const vector& x) {
					*this = x;
				};
				~vector() {
					this->_alloc.deallocate(this->_array, this->_size);
				};
				vector&	operator=(const vector& x) {
					this->_alloc = x._alloc;
					this->_array = _alloc.allocate(x.capacity());
					this->_size = x._size;
					this->_capacity = x._capacity;
					this->_maxSize = std::numeric_limits<difference_type>::max();
					for (size_t i = 0; i < x._size; i++)
						this->_array[i] = x._array[i];
					return *this;
				}
			/* Iterators */
			/* Capacity */
				size_type	size(void) const {
					return this->_size;
				};
				size_type	capacity(void) const {
					return this->_capacity;
				};
				size_type	max_size(void) const {
					return sizeof(value_type) == 1 ? this->_maxSize : (this->_maxSize / (sizeof(value_type) / 2));
				};
			/* Element access */
				reference at(size_type n) {
					if (n >= this->size())
						throw std::out_of_range("vector");
					return this->_array[n];
				};
				/*const_reference at(size_type n) {
				};*/
			/* Modifiers */
			/* Allocator */
				allocator_type get_allocator(void) const {
					return this->_alloc;
				};
		/* Non-member functions	*/
	};
};

#endif //VECTOR_HPP
