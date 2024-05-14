#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
		Contact _user[MAX_NUM_OF_CONTACTS];
		int		_max_contacts;

public:
		void	exit_msg(void);
		bool 	add_contact(void);
		void	sort_contacts(void);
		bool 	search(void);
		void	init_index();
		void	increment_index();
};

#endif