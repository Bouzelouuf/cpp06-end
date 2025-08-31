#include "Base.hpp"
#include <iostream>

Base* generate()
{
    // Base baseRandom;
    int randValue = rand() % 3;
    if (randValue == 0)
        return (new A);
    if (randValue == 1)
        return (new B);   
    return (new C);
}
void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A"<<std::endl;
        return;
    }
    catch (std::bad_cast &e)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B"<<std::endl;
            return;
        }
        catch (std::bad_cast &e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C"<<std::endl;
                return;
            }
            catch (std::bad_cast &e)
            {
                std::cout << "type inconnu" << std::endl;
            }
        }
    }
}

//dynamic_cast echoue : pointeur , il renvois nullptr
//                      reference, ne peut pas etre null si echoue , une exception et catch 

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {        
        std::cout << "it's a A!" << std::endl;
        return;
    }    
    if (dynamic_cast<B*>(p))
    {
        std::cout << "it's a B!" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "it's a C!" << std::endl;
        return;
    }
    std<<cout << "je sais pas ce que c'est !" << std::endl;
}
