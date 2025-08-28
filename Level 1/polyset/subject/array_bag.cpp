#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() : data(0), size(0) {}

array_bag::array_bag(const array_bag &other) {
	this->data = new int[other.size];
	for (int i = 0; i < other.size; i++)
		this->data[i] = other.data[i];
	this->size = other.size;
}

array_bag &array_bag::operator=(const array_bag &other) {
	this->clear();
	this->data = new int[other.size];
	for (int i = 0; i < other.size; i++)
		this->data[i] = other.data[i];
	this->size = other.size;
	return *this;
}

array_bag::~array_bag() {
	delete this->data;
}

void array_bag::insert(int val) {
	int *tmp = new int[size + 1];
	for (int i = 0; i < size; i++)
		tmp[i] = this->data[i];
	tmp[this->size] = val;
	delete this->data;
	this->data = tmp;
	this->size++;
}

void array_bag::insert(int *a, int s) {
	for (int i = 0; i < s; i++)
		this->insert(a[i]);
}

void array_bag::print() const {
	for (int i = 0; i < this->size; i++)
		std::cout << this->data[i] << " ";
	std::cout << std::endl;
}

void array_bag::clear() {
	delete this->data;
	this->data = 0;
	this->size = 0;
}