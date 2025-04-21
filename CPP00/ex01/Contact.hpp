#ifndef CONTACT_HPP
# define CONTACT_HPP

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