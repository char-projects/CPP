#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

class Identify
{
    public:
        static Base* generate();
        static void identify(Base* p);
};

#endif