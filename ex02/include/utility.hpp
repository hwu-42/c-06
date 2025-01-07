#pragma once
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time


Base* generate(void);
void identify(Base* p);
void identify(Base& p);