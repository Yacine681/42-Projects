#include "PhoneBook.hpp"

int main(void)
{
    std::string command;
    PhoneBook  phonebook;

    while(1)
    {
        std::getline(std::cin, command); 
        if (command == "EXIT")
            exit(0);
        else if (command == "ADD")
           phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else
            std::cout << "Invalid Command!" << std::endl;
    }
    return (0);
}
