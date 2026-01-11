#pragma once

#include <string>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
struct Data
{
    std::string info;
};

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};