#include "../include/Serializer.hpp"

Serializer::Serializer() {
    std::cout << "This class should not be instantiated\n";
}

Serializer::Serializer(Serializer &src) {
    (void)src;
    std::cout << "This class should not be instantiated\n";
}

Serializer &Serializer::operator=(Serializer &src) {
    (void)src;
    std::cout << "This class should not be instantiated\n";
    return *this;
}

Serializer::~Serializer() {
    std::cout << "This class should not be instantiated\n";
}

uintptr_t Serializer::serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    // Deserialize a uintptr_t to a Data pointer
Data* Serializer::deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }