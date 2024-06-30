#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	MutantStack(void) {};
	MutantStack(MutantStack const &obj)
	{
		*this = obj;
	};
	MutantStack &operator=(MutantStack const &obj)
	{
		*this = obj;
		return (*this);
	};
	~MutantStack(void) {};
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void)
	{
		return (std::stack<T>::c.begin());
	};
	iterator end(void)
	{
		return (std::stack<T>::c.end());
	};
};

#endif