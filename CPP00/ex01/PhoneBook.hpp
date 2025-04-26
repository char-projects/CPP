#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define RED "\033[0;31m"
# define WHITE "\033[0;0m"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _id;
    
    public:
        PhoneBook(); // Constructor
        ~PhoneBook(); // Destructor
        void search();
        std::string validateInput(const std::string& prompt);
        void add();
};

#endif