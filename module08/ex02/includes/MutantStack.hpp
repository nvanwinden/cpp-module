#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

	MutantStack( void ) {};
	MutantStack( MutantStack const & src ) : std::stack<T>(src) {};
	~MutantStack( void ) {};

	MutantStack &	operator=( MutantStack const & rhs ) {
		
		std::stack<T>::operator=(rhs);
		return (*this);
	};

	typedef typename Container::iterator				iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator				begin() { return std::stack<T>::c.begin(); }
	iterator 				end() { return std::stack<T>::c.end(); }
	reverse_iterator 		rbegin() { return std::stack<T>::c.rbegin(); }
	reverse_iterator 		rend() { return std::stack<T>::c.rend(); }

	const_iterator 			cbegin() const { return std::stack<T>::c.cbegin(); }
	const_iterator 			cend() const { return std::stack<T>::c.cend(); }
	const_reverse_iterator 	crbegin() const { return std::stack<T>::c.crbegin(); }
	const_reverse_iterator 	crend() const { return std::stack<T>::c.crend(); }

};

#endif
