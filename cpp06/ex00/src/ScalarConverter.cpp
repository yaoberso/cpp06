#include "../include/ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <limits>

static bool char_status = 0;
static bool char_status_display = 0;
static bool int_status = 0;
static bool float_status = 0;
static bool double_status = 0;

void printAllType(char c, int i, float f, double d)
{
    std::cout << std::fixed << std::setprecision(1);

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
    else if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << f << "f" << std::endl;

    std::cout << "double: ";
    if (double_status == 1)
        std::cout << "impossible" << std::endl;
    else if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << d << std::endl;
}

void convertFromChar(const std::string &str)
{
    char c;
    if (str.length() == 3)
        c = str[1];
    else
        c = str[0];

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    
    if (!std::isprint(c))
        char_status_display = 1;     
        
    printAllType(c, i, f, d);
}

void convertFromInt(const std::string &str)
{
    errno = 0; 
    char *endptr = NULL;
    char c = '\0';
    float f = 0.0f;
    double d = 0.0;
    
    long l = strtol(str.c_str(), &endptr, 10);
    int i = static_cast<int>(l);

    if (errno == ERANGE || *endptr != '\0' || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
    {
        int_status = 1;
        char_status = 1;
        float_status = 1;
        double_status = 1;
    }
    
    if (int_status == 0)
    {
        if (l > std::numeric_limits<char>::max() || l < std::numeric_limits<char>::min())
            char_status = 1;
        else
        {
            c = static_cast<char>(l);
            if (!std::isprint(c))
                char_status_display = 1;
        }

        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    printAllType(c, i, f, d);
}

void convertFromFloat(const std::string &str)
{
    errno = 0; 
    char *endptr = NULL;
    char c = '\0';
    int i = 0;
    double d = 0.0;
    
    float f = strtof(str.c_str(), &endptr);

    if (errno == ERANGE || *endptr != '\0')
    {
        int_status = 1;
        char_status = 1;
        float_status = 1;
        double_status = 1;
    }
    
    if (std::isnan(f) || std::isinf(f))
    {
        int_status = 1;
        char_status = 1;
    }
    
    if (int_status == 0)
    {
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            int_status = 1;
        else
            i = static_cast<int>(f);
            
        if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
            char_status = 1;
        else
        {
            c = static_cast<char>(f);
            if (!std::isprint(c))
                char_status_display = 1;
        }
    }
    
    d = static_cast<double>(f);
    
    printAllType(c, i, f, d);
}


void convertFromDouble(const std::string &str)
{
    errno = 0; 
    char *endptr = NULL;
    char c = '\0';
    int i = 0;
    float f = 0.0f;
    
    double d = strtod(str.c_str(), &endptr);

    if (errno == ERANGE || *endptr != '\0')
    {
        int_status = 1;
        char_status = 1;
        float_status = 1;
        double_status = 1;
    }
    
    if (std::isnan(d) || std::isinf(d))
    {
        int_status = 1;
        char_status = 1;
    }

    if (int_status == 0)
    {
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            int_status = 1;
        else
            i = static_cast<int>(d);
            
        if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            char_status = 1;
        else
        {
            c = static_cast<char>(d);
            if (!std::isprint(c))
                char_status_display = 1;
        }
    }

    f = static_cast<float>(d);
    
    if (!std::isinf(d) && (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()))
        float_status = 1;
    
    printAllType(c, i, f, d);
}

void ScalarConvert::convert(const std::string &str)
{
    char_status = 0;
    char_status_display = 0;
    int_status = 0;
    float_status = 0;
    double_status = 0;
    
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
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}

type ScalarConvert::FindType(const std::string &str)
{
    if (str.length() == 1)
    {
        if (std::isprint(str[0]) && !std::isdigit(str[0]))
            return (CHAR);
    }
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