#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _index = 0;
    _size = 0;
}

void    PhoneBook::add()
{
    std::string information[5];

    std::cout << "FIRST NAME : ";
    std::getline(std::cin, information[0]);
    if (information[0].empty())
    {
        std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
    }
    _contact[_index].setFirstName(information[0]);

    std::cout << "LAST NAME : ";
    std::getline(std::cin, information[1]);
    if (information[1].empty())
    {
        std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
    }

    _contact[_index].setLastName(information[1]);

    std::cout << "PHONE NUMBER : ";
    std::getline(std::cin, information[2]);
    if (information[2].empty())
    {
        std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
    }
    _contact[_index].setPhoneNumber(information[2]);

    std::cout << "NICK NAME : ";
    std::getline(std::cin, information[3]);
    if (information[3].empty())
    {
        std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
    }
    _contact[_index].setDarkestSecret(information[3]);

    std::cout << "DARKEST SECRET : ";
    std::getline(std::cin, information[4]);
    if (information[4].empty())
    {
        std::cout << "The fields of a registered contact cannot be empty!" << std::endl;
        return ;
    }
    _contact[_index].setNickName(information[4]);

    _index++;
    if (_index == 8)
        _index = 0;
    if (_size < 8)
        _size++;
}

int check_index(std::string index)
{
    if (index == "1" || index == "2" || index == "3" || index == "4"
            || index == "5" || index == "6" || index == "7"
                || index == "8")
        return (stoi(index));
    else
        return (42);
}

void    PhoneBook::search()
{
    int i;

    i = 0;
    if (_size == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return ;
    }
    std::cout << "*----------*----------*----------*----------*" << std::endl;
    std::cout << "|INDEX     |FIRST NAME|LAST NAME |NICK NAME |" << std::endl;
    std::cout << "*----------*----------*----------*----------*" << std::endl;
     while (i < _size)
    {
        std::cout << "|" << std::setw(10) << i + 1;
        std::string fname = _contact[i].getFirstName();
        if (fname.size() > 10)
            fname = fname.substr(0, 9) + '.';
        std::cout << "|" << std::setw(10) << fname;
        std::string lname = _contact[i].getLastName();
        if (lname.size() > 10)
            lname = lname.substr(0, 9) + '.';
        std::cout << "|" << std::setw(10) << lname;
        std::string Nickname = _contact[i].getNickName();
        if (Nickname.size() > 10)
            Nickname = Nickname.substr(0, 9) + '.';
        std::cout << "|" << std::setw(10) << Nickname << "|";
        std::cout << std::endl;
        i++;
    }
    std::cout << "*----------*----------*----------*----------*" << std::endl;
    while (1)
    {
        std::cout << "Enter an index : ";
        std::string input;
        std::getline(std::cin, input);
        int j = check_index(input);
        if (j <= _size)
        {
            std::cout << "FIRST NAME : " << _contact[j - 1].getFirstName() << std::endl;
            std::cout << "LAST NAME : " << _contact[j - 1].getLastName() << std::endl;
            std::cout << "PHONE NUMBER :" << _contact[j - 1].getPhoneNumber() << std::endl;
            std::cout << "NICK NAME : " << _contact[j - 1].getNickName() << std::endl;
            std::cout << "DARKEST SECRET : " << _contact[j - 1].getDarkestSecret() << std::endl;
            break ;
        }
        else
            std::cout << "Invalid index!" << std::endl;
    }
}
