#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* a, int len, T (*f)(T& a))
{
	for (int i = 0; i < len; i++)
		a[i] = f(a[i]);
}

#endif