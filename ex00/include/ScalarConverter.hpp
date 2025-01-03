#pragma once
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& s);

private:
    ScalarConverter();
    static char cv;
    static int iv;
    static float fv;
    static double dv;
    static int type;
};

