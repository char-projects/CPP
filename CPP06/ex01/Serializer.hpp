#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
    int         value;
    std::string name;
} Data;

class Serializer
{
    private:
        Serializer();
    public:
        ~Serializer(); 
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif