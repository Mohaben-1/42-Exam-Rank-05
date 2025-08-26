#include "set.hpp"

set::set(searchable_bag& _bag) : bag(_bag) {}

set::set(const set& copy) : bag(copy.bag) {}

// set&	set::operator=(const set& copy) {}

set::~set() {}

void	set::insert (int value)
{
	if (!bag.has(value))
		bag.insert(value);
}

void	set::insert (int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!bag.has(arr[i]))
			bag.insert(arr[i]);
	}
}

void	set::print() const
{
	bag.print();
}

void	set::clear()
{
	bag.clear();
}

bool	set::has(int value) const
{
	return (bag.has(value));
}

const searchable_bag& set::get_bag() const
{
	return (bag);
}
