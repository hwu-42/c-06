#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <limits>
#include "../include/ScalarConverter.hpp"
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INF 5
#define NAN 6
#define INVALID 7



ScalarConverter::ScalarConverter() {
    std::cout << "This class should not be instantiated\n";
}

ScalarConverter::ScalarConverter(ScalarConverter &src) {
    (void)src;
    std::cout << "This class should not be instantiated\n";
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src) {
    (void)src;
    std::cout << "This class should not be instantiated\n";
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "This class should not be instantiated\n";
}

void ScalarConverter::convert(const std::string& str) {
    char cv;
    int iv;
    float fv;
    double dv;
    int type;

    if (str.length() == 0)
        type = INVALID;
    else if (str.length() == 1) {
        if (str[0] < '0' || str[0] > '9') {
            type = CHAR;
            cv = str[0];
        }
        else {
            type = INT;
            iv = str[0] - '0';
        }
    }
    else if (str == "+inff" || str == "-inff" || str == "+inf" || str == "-inf" || str == "inf" || str == "inff")
        type = INF;
    else if (str == "nanf" || str == "nan")
        type = NAN;
    else {
        std::istringstream iss(str);
        iss >> iv;
        if (!iss.fail() && iss.eof())
            type = INT;
        else {
            if (str.find('.') == std::string::npos || !std::isdigit(str[str.find('.') + 1]))
                type = INVALID;
            else if (str[str.size() -1] == 'f') {
                std::string str2(str);
                str2.erase(str.size() - 1);
                //std::cout << str2 << std::endl;
                iss.str(str2);
                iss.clear();
                //std::cout << "iss.fail:" << iss.fail() << std::endl;
                iss >> fv;
                //std::cout << "iss.fail:" << iss.fail() << std::endl;
                if (!iss.fail() && iss.eof())
                    type = FLOAT;
                else
                    type = INVALID;

            }
            else {
                iss.str(str);
                iss.clear();
                iss >> dv;
                if (!iss.fail() && iss.eof())
                    type = DOUBLE;
                else
                    type = INVALID;
            }
        }
    }
    std::cout << "type is " << type << std::endl;
    /*print*/
    if (type == CHAR) {
        std::cout << "char: " << cv << std::endl;
        std::cout << "int: " << static_cast<int>(cv) << std::endl;
        std::cout << "float: " << static_cast<float>(cv) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(cv) << ".0" <<  std::endl;
        return;
    }
    if (type == INT) {
        if (iv < std::numeric_limits<char>::min() || iv > std::numeric_limits<char>::max())
            std::cout << "char: impossible"<< std::endl;
        else if (!std::isprint(iv))
            std::cout << "char: Non displayable"<< std::endl;
        else
            std::cout << "char: " << static_cast<char>(iv) << std::endl;
        std::cout << "int: " << iv << std::endl;
        std::cout << "float: " << static_cast<float>(iv) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(iv) << ".0" <<  std::endl;
        return;
    }
    if (type == FLOAT) {
        if (fv < std::numeric_limits<char>::min() || fv > std::numeric_limits<char>::max()) {
            std::cout << "int: impossible"<< std::endl;
        }
        else {
            if (!std::isprint(static_cast<char>(fv)))
                std::cout << "char: Non displayable"<< std::endl;
            else
                std::cout << "char: " << static_cast<char>(fv) << std::endl;
        }
        if (fv < std::numeric_limits<int>::min() || fv > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible"<< std::endl;
        }
        else {
            std::cout << "int: " << static_cast<int>(fv) << std::endl;
        }
        std::cout << "float: " << static_cast<float>(fv) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(fv) <<  std::endl;
        return;
    }
    if (type == DOUBLE) {
        if (dv < std::numeric_limits<char>::min() || dv > std::numeric_limits<char>::max()) {
            std::cout << "int: impossible"<< std::endl;
        }
        else {
            if (!std::isprint(static_cast<char>(dv)))
                std::cout << "char: Non displayable"<< std::endl;
            else
                std::cout << "char: " << static_cast<char>(dv) << std::endl;
        }

        if (dv < std::numeric_limits<int>::min() || dv > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible"<< std::endl;
        }
        else {
            std::cout << "int: " << static_cast<int>(dv) << std::endl;
        }

        if (dv < std::numeric_limits<float>::min() || dv > std::numeric_limits<float>::max()) {
            std::cout << "float: impossible"<< std::endl;
        }
        else {
            std::cout << "float: " << static_cast<float>(dv) << std::endl;
        }
        std::cout << "double: " << dv <<  std::endl;
        return;
    }
    if (type == INF) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str[0] == '+' || str[0] == 'i') {
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" <<  std::endl;
        }
        else {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" <<  std::endl;
        }
        return;
    }
    if (type == NAN) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" <<  std::endl;
        return;
    }
    if (type == INVALID) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" <<  std::endl;
        return;
    }
}