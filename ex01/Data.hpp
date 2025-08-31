#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    Data();
    Data(const Data& other);
    Data& operator = (const Data& other);
    virtual ~Data();


    int value;
    //useless but for have a real struct ( no empty)
    //std::string remplissagePourNonEmpty;
};

#endif