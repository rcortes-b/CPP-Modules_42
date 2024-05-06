#include "class.hpp"

int Contact::get_index()
{
    return (this->_index);
}

std::string Contact::get_fname()
{
    return (this->_first_name);
}

std::string Contact::get_lname()
{
    return (this->_last_name);   
}

std::string Contact::get_nickname()
{
    return (this->_nickname);
}

std::string Contact::get_phone_number()
{
    return (this->_phone_number);
}

std::string Contact::get_dsecret()
{
    return (this->_dsecret);
}
