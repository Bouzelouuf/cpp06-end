#include "Serializer.hpp"

unsigned __int64 Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<unsigned __int64>(ptr));
}

Data* Serializer::deserialize(unsigned __int64 raw)
{
    return (reinterpret_cast<Data*>(raw));
}

//unsigned long pour linux 
//unsigned __int64 pour windows