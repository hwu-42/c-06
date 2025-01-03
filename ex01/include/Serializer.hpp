#pragma once
#include <iostream>
#include <string>
#include <cassert>

typedef unsigned long uintptr_t;

// Non-empty Data structure
struct Data {
    int id;
    std::string name;
};


class Serializer {
private:
    Serializer();

public:
    // Serialize a Data pointer to uintptr_t
    static uintptr_t serialize(Data* ptr);

    // Deserialize a uintptr_t to a Data pointer
    static Data* deserialize(uintptr_t raw);
};