#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag&	bag;
	public:
		set(searchable_bag& _bag);
		set(const set& copy);
		// set&	operator=(const set& copy);
		~set();

		void	insert (int value);
		void	insert (int *arr , int size);
		void	print() const;
		void	clear();

		bool	has(int value) const;

		const searchable_bag& get_bag() const;
};