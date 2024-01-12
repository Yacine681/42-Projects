#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
    private:
    Contact _contact[8];
    int _index;
    int _size;
    public:
    PhoneBook();
    void    add();
    void    search();
};

#endif
