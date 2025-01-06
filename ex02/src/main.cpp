#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/utility.hpp"
#include <iostream>
#include <unistd.h> // Include this header for sleep function

// Main function to test the implementation
int main() {
    Base* obj;
    int i = 0;
    while (i < 20) {
        obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
        sleep (1);
        i++;
    }
    return 0;
}