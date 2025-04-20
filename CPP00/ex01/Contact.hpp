#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "phonebook.h"

class Contact
{
    private:
        char *FirstName;
        char *LastName;
        char *Nickname;
        char *PhoneNumber;
        char *DarkestSecret;

    public:
        char *getFirstName();
        void setFirstName (char *input);
        char *getLastName();
        void setLastName (char *input);
        char *getNickname();
        void setNickname (char *input);
        char *getPhoneNumber();
        void setPhoneNumber (char *input);
        char *getDarkestSecret();
        void setDarkestSecret (char *input);
};

#endif