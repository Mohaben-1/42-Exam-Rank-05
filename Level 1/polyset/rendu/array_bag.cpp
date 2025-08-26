#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() : data(0), size(0) {}

array_bag::array_bag(const array_bag &oth)
{
	this->data = new int[oth.size];
	for (int i = 0; i < oth.size; i++)
		this->data[i] = oth.data[i];
	this->size = oth.size;
}

array_bag &array_bag::operator=(const array_bag &oth)
{
	this->clear();
	this->data = new int[oth.size];
	for (int i = 0; i < oth.size; i++)
		this->data[i] = oth.data[i];
	this->size = oth.size;
	return *this;
}

array_bag::~array_bag()
{
	delete this->data;
}

void array_bag::insert(int val)
{
	int *tmp = new int[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = this->data[i];
	}
	tmp[this->size] = val;
	delete this->data;
	this->data = tmp;
	this->size++;
}

void array_bag::insert(int *a, int s)
{
	for (int i = 0; i < s; i++)
		this->insert(a[i]);	
}

void array_bag::print() const
{
	for (int i = 0; i < this->size; i++)
		std::cout << this->data[i] << " ";
	std::cout << std::endl;
}

void array_bag::clear()
{
	delete this->data;
	this->data = 0;
	this->size = 0;
}
