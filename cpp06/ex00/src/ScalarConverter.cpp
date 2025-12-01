#include "../include/ScalarConverter.hpp"

ScalarConvert::ScalarConvert()
{

}

void ScalarConvert::convert(const std::string &str)
{

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