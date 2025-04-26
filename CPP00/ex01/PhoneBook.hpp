#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/*
You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards. Otherwise, your grade will
be 0.
*/

# include "Contact.hpp"
# include <string>
# define RED "\033[0;31m"
# define PURPLE "\033[0;35m"
# define GREEN "\033[0;32m"

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