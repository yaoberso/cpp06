#include "../include/ScalarConverter.hpp"

void convertFromChar(const std::string &str)
{
    char c = str[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    printAllType(c, i, f, d);
}

void convertFromInt(std::string str)
{
    int i = atoi(str.c_str());
    if(i > 127 || i < 0)
        char_status = 1;
    else
        char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printAllType(c, i, f, d);
}

void convertFromFloat(std::string str)
{
    float f = std::stof(str);
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        int_status = 1;
        char_status = 1;
        char c = c;
        int i = 1;
    }
    else
    {
        char c = static_cast<char>(f);
        int i = static_cast<int>(f);
    }
    double d = static_cast<double>(f);
    printAllType(c, i, f, d);
}

void convertFromDouble(std::string str)
{
    double d = std::stod(str);
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        int_status = 1;
        char_status = 1;
        char c = c;
        int i = 1;
    }
    else
    {
        char c = static_cast<char>(d);
        int i = static_cast<int>(d);
    }
    float f = static_cast<float>(d);
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