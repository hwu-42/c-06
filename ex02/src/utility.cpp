#include "../include/utility.hpp"
#include <typeinfo> // Include this header for std::bad_cast

// Function to randomly generate an instance of A, B, or C
Base* generate(void) {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator
    int randomChoice = rand() % 3;        // Generate a random number between 0 and 2

    switch (randomChoice) {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }
    return NULL; // Should never reach here
}

// Function to identify the type using a pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// Function to identify the type using a reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::bad_cast&) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}