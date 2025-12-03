#include "../include/ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <iostream>
#include <cctype>

static bool char_status = 0;
static bool char_status_display = 0;
static bool int_status = 0;
static bool float_status = 0;
static bool double_status = 0;

void printAllType(char c, int i, float f, double d)
{
    std::cout << "char: ";
    if (char_status == 1)
        std::cout << "impossible" << std::endl;
    else if (char_status_display == 1)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "\'" << c << "\'" << std::endl;
    std::cout << "int: ";
    if (int_status == 1)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    std::cout << "float: ";
    if (float_status == 1)
        std::cout << "impossible" << std::endl;
    else
        std::cout << f << "f" << std::endl;
    std::cout << "double: ";
    if (double_status == 1)
        std::cout << "impossible" << std::endl;
    else
        std::cout << d << std::endl;
}

void convertFromChar(const std::string &str)
{
    char c = str[1];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    if (!std::isprint(c))
        char_status_display = 1;     
    printAllType(c, i, f, d);
}

// void convertFromInt(const std::string &str)
// {
//     errno = 0; 
//     char *endptr = NULL;
//     char c = '\0';
//     float f = 0.0f;
//     double d = 0.0;
//     long l = std::strtol(str.c_str(), &endptr, 10);
//     int i = static_cast<int>(l);
//     if (errno == ERANGE || *endptr != '\0' || l > INT_MAX || l < INT_MIN)
//     {
//         int_status = 1;
//         char_status = 1;
//         float_status = 1;
//         double_status = 1;
//     }
//     if (int_status == 0)
//     {
//         if (l > CHAR_MAX || l < CHAR_MIN)
//             char_status = 1;
//         else
//         {
//             c = static_cast<char>(l);
//             if (!std::isprint(c))
//                 char_status_display = 1;
//         }
//         f = static_cast<float>(i);
//         d = static_cast<double>(i);
//     }
//     printAllType(c, i, f, d);
// }

// void convertFromFloat(const std::string &str)
// {
//     errno = 0; 
//     char *endptr = NULL;
//     char c = '\0';
//     int i = 0;
//     double d = 0.0;
//     float f = std::strtof(str.c_str(), &endptr);
//     if (errno == ERANGE || *endptr != '\0')
//     {
//         int_status = 1;
//         char_status = 1;
//         float_status = 1;
//         double_status = 1;
//     }
//     if (std::isnan(f) || std::isinf(f))
//     {
//         int_status = 1;
//         char_status = 1;
//     }
//     if (int_status == 0)
//     {
//         if (f > INT_MAX || f < INT_MIN)
//             int_status = 1;
//         else
//             i = static_cast<int>(f);
//         if (f > CHAR_MAX || f < CHAR_MIN)
//             char_status = 1;
//         else
//         {
//             c = static_cast<char>(f);
//             if (!std::isprint(c))
//                 char_status_display = 1;
//         }
//     }
//     d = static_cast<double>(f);
    
//     printAllType(c, i, f, d);
// }

// void convertFromDouble(const std::string &str)
// {
//     errno = 0; 
//     char *endptr = NULL;
//     char c = '\0';
//     int i = 0;
//     float f = 0.0f;
//     double d = std::strtod(str.c_str(), &endptr);
//     if (errno == ERANGE || *endptr != '\0')
//     {
//         int_status = 1;
//         char_status = 1;
//         float_status = 1;
//         double_status = 1;
//     }
//     if (std::isnan(d) || std::isinf(d))
//     {
//         int_status = 1;
//         char_status = 1;
//     }
//     if (int_status == 0)
//     {
//         if (d > INT_MAX || d < INT_MIN)
//             int_status = 1;
//         else
//             i = static_cast<int>(d);
//         if (d > CHAR_MAX || d < CHAR_MIN)
//             char_status = 1;
//         else
//         {
//             c = static_cast<char>(d);
//             if (!std::isprint(c))
//                 char_status_display = 1;
//         }
//     }
//     f = static_cast<float>(d);
//     float_status = 1;
//     printAllType(c, i, f, d);
// }

void convertFromInt(const std::string &str)
{
    errno = 0; 
    char *endptr = NULL;
    char c = '\0';
    double d = 0.0;
    float f = 0.0f;
    int i = std::strtol(str.c_str(), &endptr, 10);
    if (i == -1)
            int_status = 1;
    if(i < 32 || i > 127)
    {
        if (i >= 0 && i <= 32)
            char_status_display = 1;
        else
            char_status = 1;
    }
    else
        c = static_cast<char>(i);
    f = static_cast<float>(i);
    if (f == -1)
            int_status = 1;
    d = static_cast<double>(i);
    if (d == -1)
            int_status = 1;
    printAllType(c, i, f, d);
}

void convertFromFloat(const std::string &str)
{
    errno = 0; 
    char *endptr = NULL;
    char c = '\0';
    int i = 0;
    double d = 0.0;
    float f = std::strtof(str.c_str(), &endptr);
    if (f == -1)
            int_status = 1;
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        int_status = 1;
        char_status = 1;
    }
    else
    {
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        if (i == -1)
            int_status = 1;
    }
    if(i < 32 || i > 127)
    {
        if (i >= 0 && i <= 32)
            char_status_display = 1;
        else
            char_status = 1;
    }
    d = static_cast<double>(f);
    if (d == -1)
            int_status = 1;
    printAllType(c, i, f, d);
}

void convertFromDouble(const std::string &str)
{
    errno = 0; 
    char *endptr = NULL;
    char c = '\0';
    int i = 0;
    float f = 0.0f;
    double d = std::strtod(str.c_str(), &endptr);
    if (d == -1)
            int_status = 1;
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        int_status = 1;
        char_status = 1;
    }
    else
    {
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        if (i == -1)
            int_status = 1;
    }
    if(i < 32 || i > 127)
    {
        if (i >= 0 && i <= 32)
            char_status_display = 1;
        else
            char_status = 1;
    }
    f = static_cast<float>(d);
    if (f == -1)
            int_status = 1;
    printAllType(c, i, f, d);
}

void ScalarConvert::convert(const std::string &str)
{
    type type = FindType(str);

    switch (type)
    {
        case CHAR:
            convertFromChar(str);
            break;
        case INT:
            convertFromInt(str);
            break;
        case FLOAT:
            convertFromFloat(str);
            break;
        case DOUBLE:
            convertFromDouble(str);
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
    }
}

type ScalarConvert::FindType(const std::string &str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return (CHAR);
    if (str == "nan" || str == "+inf" || str == "-inf")
        return (DOUBLE);
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return (FLOAT);

    int vcount = 0;
    bool has_f_suffix = false;
    size_t i = 0;

    if (str.length() > 0 && (str[0] == '+' || str[0] == '-'))
        i = 1;
    
    if (i == str.length())
        return (INVALIDE);

    for ( ; i < str.length(); ++i)
    {
        char c = str[i];
        
        if (c == '.') {
            if (vcount > 0 || has_f_suffix)
                return (INVALIDE);
            vcount++;
        }
        else if (c == 'f') {
            if (i != str.length() - 1)
                return (INVALIDE);
            has_f_suffix = true;
        }
        else if (!std::isdigit(c)) {
            return (INVALIDE);
        }
    }

    if (has_f_suffix)
    {
        if (i == 1 && has_f_suffix)
        {
            if (str.length() == 2 && (str[0] == '+' || str[0] == '-'))
                return (INVALIDE);
            if (str.length() == 1 && str[0] == 'f')
                return (INVALIDE);
        }
        
        return (FLOAT);
    }
    else if (vcount == 1)
    {
        return (DOUBLE);
    }
    else
    {
        return (INT);
    }
}
//atof pour double et float
//atoi pour int