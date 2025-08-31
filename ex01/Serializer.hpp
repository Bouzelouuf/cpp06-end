#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
    public:
        static unsigned __int64 serialize(Data *ptr);
        //unsigned long pour linux
        static Data* deserialize(unsigned __int64 raw);
};

#endif