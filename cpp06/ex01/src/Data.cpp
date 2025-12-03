#include "../include/Data.hpp"

Data::Data(): data(0){}

Data::Data(int nb): data(nb){}

Data &Data::operator=(Data &other)
{
	this->data = other.data;
	return (*this);
}

Data::~Data(){}

int Data::get_data()
{
	return(this->data);
}