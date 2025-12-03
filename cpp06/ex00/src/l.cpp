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
    char c = str[1];
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
    long l = std::strtol(str.c_str(), &endptr, 10);
    int i = static_cast<int>(l);
    if (errno == ERANGE || *endptr != '\0' || l > INT_MAX || l < INT_MIN)
    {
        int_status = 1;
        char_status = 1;
        float_status = 1;
        double_status = 1;
    }
    if (int_status == 0)
    {
        if (l > CHAR_MAX || l < CHAR_MIN)
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
    float f = std::strtof(str.c_str(), &endptr);
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
        if (f > INT_MAX || f < INT_MIN)
            int_status = 1;
        else
            i = static_cast<int>(f);
        if (f > CHAR_MAX || f < CHAR_MIN)
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
    double d = std::strtod(str.c_str(), &endptr);
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
        if (d > INT_MAX || d < INT_MIN)
            int_status = 1;
        else
            i = static_cast<int>(d);
        if (d > CHAR_MAX || d < CHAR_MIN)
            char_status = 1;
        else
        {
            c = static_cast<char>(d);
            if (!std::isprint(c))
                char_status_display = 1;
        }
    }
    f = static_cast<float>(d);
    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
        float_status = 1;
    
    printAllType(c, i, f, d);
}