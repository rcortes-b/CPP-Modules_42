#include "Zombie.hpp"

int main(void)
{
	Zombie	*zmb_heap = NULL;
	Zombie	zmb_stack;
	
	zmb_stack.randomChump("FooStack");
	zmb_heap = Zombie::newZombie("FooHeap");
	delete zmb_heap;
}