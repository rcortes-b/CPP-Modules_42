#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* a, unsigned int len, void (*f)(T&))
{
	if (!a || !f)
		return ;
	for (unsigned int i = 0; i < len; i++)
		f(a[i]);
}

#endif