#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& copy) : tree_bag(copy) {}

searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag& copy)
{
	if (this != &copy)
		tree_bag::operator=(copy);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {}

bool	searchable_tree_bag::has(int value) const
{
	node	*current = tree;

	while (current)
	{
		if (current->value == value)
			return (true);
		else if (current->value > value)
			current = current->l;
		else
			current = current->r;
	}
	return (false);
}
