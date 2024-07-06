#include "includes/iter.hpp"
template <typename T>
void	sum1(T& a)
{
	if (!a)
		return ;
	a += 1;
}

int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};
	//Iter not applied
	for (int i = 0; i < 5; i++)
	{
		std::cout << "num: " << nums[i] << std::endl;
	}
	std::cout << std::endl;
	iter(nums, 5, sum1);
	//Iter applied
	for (int i = 0; i < 5; i++)
	{
		std::cout << "num: " << nums[i] << std::endl;
	}
	std::cout << std::endl;
/*///////////////////////////////////////////////////////*/
	char letters[4] = {'h', 'o', 'l', 'a'};
	//Iter not applied
	for (int i = 0; i < 4; i++)
	{
		std::cout << "letter: " << letters[i] << std::endl;
	}
	std::cout << std::endl;
	iter(letters, 4, sum1);
	//Iter applied
	for (int i = 0; i < 4; i++)
	{
		std::cout << "letter: " << letters[i] << std::endl;
	}
	std::cout << std::endl;

	return (0);
}

/* ex01.cpp
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
*/