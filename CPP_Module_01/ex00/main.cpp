/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:25 by rcortes-          #+#    #+#             */
/*   Updated: 2024/05/15 18:01:26 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zmb_heap = NULL;
	Zombie	zmb_stack;
	
	zmb_stack.randomChump("FooStack");
	zmb_heap = Zombie::newZombie("FooHeap");
	delete zmb_heap;
}
