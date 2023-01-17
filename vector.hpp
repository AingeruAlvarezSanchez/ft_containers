#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

#include <iostream>
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
		: _alloc(alloc), _array(0), _size(0), _capacity(0), _maxSize(0) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _size(n), _capacity(n), _maxSize(alloc.max_size()) {
			this->_array = this->_alloc.allocate(n);
			for (size_type i = 0; i < n ; i++)
				this->_alloc.construct(this->_array + i, val);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		: _alloc(alloc), _size(last - first), _capacity(_size), _maxSize(alloc.max_size()) {
			this->_array = this->_alloc.allocate(_size);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, *(first++));
		}

		/* Destructor */
		~vector() {
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(this->_array + i);
			this->_alloc.deallocate(this->_array, this->_capacity);
		}

		/* Overload of operator= */
		vector&	operator=(const vector& x) {
			this->_alloc = x._alloc;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_maxSize = x._maxSize;
			this->_array = this->_alloc.allocate(this->_capacity);
			for (value_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, x._array + i);
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

		//TODO resize

		size_type	capacity() const {
			return this->_capacity;
		}

		bool	empty() const {
			return this->_size == 0;
		}

		//TODO reserve

		/* Element access */ //TODO
		//TODO operator[]
		//TODO at
		//TODO front
		//TODO back
		//TODO data

		/* Modifiers */ //TODO
		//TODO assign
		//TODO push_back
		//TODO pop_back
		//TODO insert
		//TODO erase
		//TODO swap
		//TODO clear
		//TODO emplace

		/* Allocator */
		allocator_type	get_allocator() const {
			return this->_alloc;
		}
	};
	/* Non member */ //TODO
	//TODO operator==
	//TODO operator!=
	//TODO operator<
	//TODO operator<=
	//TODO operator>
	//TODO operator>=
	//TODO operator>=
	//TODO std::swap(std::vector)
}

#endif //VECTOR_HPP
