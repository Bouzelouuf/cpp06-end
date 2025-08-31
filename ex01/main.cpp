#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;         // objet réel
    Data* dataPtr = &data;
    unsigned __int64  raw= Serializer::serialize(dataPtr);
    dataPtr->value = 0;
    

    unsigned __int64 raw = Serializer::serialize(dataPtr);
    std::cout << "Serialized: " << raw << std::endl;

    Data* data2 = Serializer::deserialize(raw);
    std::cout << "Original ptr: " << dataPtr << std::endl;
    std::cout << "Deserialized ptr: " << data2 << std::endl;

}