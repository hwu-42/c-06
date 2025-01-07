#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <stdint.h>

// Non-empty Data structure
struct Data {
    int id;
    std::string name;
};


class Serializer {
private:
    Serializer();
    Serializer(Serializer &src);
    Serializer &operator=(Serializer &src);
    ~Serializer();

public:
    // Serialize a Data pointer to uintptr_t
    static uintptr_t serialize(Data* ptr);

    // Deserialize a uintptr_t to a Data pointer
    static Data* deserialize(uintptr_t raw);
};