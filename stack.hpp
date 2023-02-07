#ifndef DOCUMENTS_STACK_HPP
#define DOCUMENTS_STACK_HPP
#include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;
	protected:
		container_type	_underlyingContainer;
	public:
		/* Constructor */
		explicit stack(const container_type& ctnr = container_type()) : _underlyingContainer(ctnr) {}

		/* Destructor */
		~stack() {}

		/* Overload of operator= */
		stack&	operator=(const stack& other) {
			this->_underlyingContainer = other._underlyingContainer;
		}

		/* Member functions */
		bool	empty() const {
			return _underlyingContainer.empty();
		}

		size_type	size() const {
			return _underlyingContainer.size();
		}

		value_type&	top() {
			return _underlyingContainer[0];
		}

		const value_type&	top() const {
			return _underlyingContainer[0];
		}

		void	push(const value_type& val) {
			_underlyingContainer.insert(_underlyingContainer.begin(), val);
		}

		void pop() {
			_underlyingContainer.erase(_underlyingContainer.begin());
		}

	};

	/* Non member */
	//TODO
	/*template <class T, class Container>
	bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	}
	template <class T, class Container>
	bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	}
	template <class T, class Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	}
	template <class T, class Container>
	bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	}
	template <class T, class Container>
	bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	}
	template <class T, class Container>
	bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	}*/
}

#endif //DOCUMENTS_STACK_HPP
