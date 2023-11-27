//
//  Person.h
//

#ifndef Person_h
#define Person_h

#include <stdint.h>

// For simplicity sake we make everything public
class Person
{
public:
    Person(std::string  name,
           uint32_t     age,
           std::string  cake_or_cookie) :
    name(name), age(age), cake_or_cookie(cake_or_cookie)
    {
        
    }
    
    std::string name = std::string();
    uint32_t    age  = 0;
    std::string cake_or_cookie = std::string();
};


#endif /* Person_h */
