#pragma once
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& s);

private:
    ScalarConverter();
    ScalarConverter(ScalarConverter &src);
    ScalarConverter &operator=(ScalarConverter &src);
    ~ScalarConverter();

};

