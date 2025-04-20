#include "phonebook.h"

char *Contact::getFirstName() {
    return FirstName;
}
void Contact::setFirstName (char *input){
    char *FirstName = input;
};

char *Contact::getLastName() {
    return LastName;
}

void Contact::setLastName (char *input){
    char *LastName = input;
};

char *Contact::getNickname() {
    return Nickname;
}

void Contact::setNickname (char *input) {
    char *Nickname = input;
};

char *Contact::getPhoneNumber() {
    return PhoneNumber;
}

void Contact::setPhoneNumber (char *input){
    char *PhoneNumber = input;
};

char *Contact::getDarkestSecret() {
    return DarkestSecret;
}

void Contact::setDarkestSecret (char *input){
    char *DarkestSecret = input;
};
