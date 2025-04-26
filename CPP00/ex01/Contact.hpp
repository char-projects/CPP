#ifndef CONTACT_HPP
# define CONTACT_HPP

/*
You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards. Otherwise, your grade will
be 0.
*/

# include <string>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        std::string getFirstName() const;
        void setFirstName (std::string input);
        std::string getLastName() const;
        void setLastName (std::string input);
        std::string getNickname() const;
        void setNickname (std::string input);
        std::string getPhoneNumber() const;
        void setPhoneNumber (std::string input);
        std::string getDarkestSecret() const;
        void setDarkestSecret (std::string input);
};

#endif