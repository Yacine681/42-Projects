#include "contact.hpp"

    void    Contact::setFirstName(std::string first_Name)
    {
        firstName = first_Name;
    }
    
    void    Contact::setLastName(std::string last_Name)
    {
        lastName = last_Name;
    }
    
    void    Contact::setPhoneNumber(std::string phone_Number)
    {
        phoneNumber = phone_Number;
    }
    
    void    Contact::setDarkestSecret(std::string darkest_Secret)
    {
        darkestSecret = darkest_Secret;
    }

    void    Contact::setNickName(std::string nick_Name)
    {
        nickName = nick_Name;
    }
    
    std::string    Contact::getFirstName()
    {
        return (firstName);
    }
    
    std::string    Contact::getLastName()
    {
        return (lastName);
    }
    
    std::string    Contact::getPhoneNumber()
    {
        return (phoneNumber);
    }
    
    std::string    Contact::getDarkestSecret()
    {
        return (darkestSecret);
    }

    std::string    Contact::getNickName()
    {
        return (nickName);
    }
