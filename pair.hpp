#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
	public:
		typedef T1	first_type;
		typedef T2	second_type;
	public:
		first_type	_first;
		second_type	_second;
	public:
		/* Constructors */
		pair()
		: _first(0), _second(0) {}

		pair(const first_type& a, const second_type& b)
		: _first(a), _second(b) {}

		template<class U, class V>
		pair(const pair<U, V>& pr)
		: _first(pr._first), _second(pr._second){}

		/* Overload of operator= */
		pair&	operator=(const pair& pr) {
			this->_first = pr._first;
			this->_second = pr._second;
			return *this;
		}
	};

	/* Non member */
	//TODO I'm not sure if make_pair is a non member function, check
}

#endif //PAIR_HPP
