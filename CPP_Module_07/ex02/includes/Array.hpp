#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <math.h>

template <typename T>

class Array {
	private:
			T				*_array;
			unsigned int	_size;
	public:
			Array( void ) : _size(0) {
				std::cout << "Default Constructor" << std::endl;
				this->_array = new T[this->_size];
			}
			Array( unsigned int n ) : _size(n) {
				std::cout << "Param Constructor" << std::endl;
				this->_array = new T[this->_size];
			}
			Array( Array const &obj ) : _array(NULL) {
				std::cout << "Copy Constructor" << std::endl;
				std::cout << "obj size: " << obj._size << std::endl;
				*this = obj;
			}
			Array &operator=( Array const &obj ) {
				std::cout << "Assignment Operator" << std::endl;
				if (this->_array)
					delete [] this->_array;
				if (obj._size)
				{
					this->_size = obj._size;
					this->_array = new T[this->_size];
					for (unsigned int i = 0; i < this->_size; i++)
						this->_array[i] = obj._array[i];
				}
				return (*this);
			}
			~Array( void ) {
				std::cout << "Default Destructor" << std::endl;
				if (this->_array)
					delete [] this->_array;
			}

			unsigned int	size( void ) {
				return (this->_size);
			}

			T	&operator[](unsigned int index) {
				if (this->_size <= index || !this->_array)
					throw Array<T>::OOBException();
				return (this->_array[index]);
			}

			class	OOBException : public std::exception {
				public:
						virtual const char* what( void ) const throw() {
							return ("Error: Invalid array or index");
						}
			};
};


#endif