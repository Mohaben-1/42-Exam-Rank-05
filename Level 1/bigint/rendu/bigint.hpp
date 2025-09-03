#pragma once

#include <iostream>
#include <string>
#include <vector>

class	bigint
{
	private:
		std::vector<int>	digits;
		void	trim();
		int		to_int() const;
	public:
		bigint();
		bigint(unsigned long long n);
		bigint(const std::string& s);
		bigint(const bigint& copy);
		bigint&	operator=(const bigint& copy);
		~bigint();

		friend std::ostream&	operator<<(std::ostream& os, const bigint& b);

		bigint&	operator++();
		bigint	operator++(int);

		bigint	operator+(const bigint& b) const;

		bigint&	operator+=(const bigint& b);

		bigint	operator<<(int shift) const;
		bigint	operator<<(const bigint& b) const;

		bigint	operator>>(int shift) const;
		bigint	operator>>(const bigint& b) const;

		bigint&	operator<<=(int shift);
		bigint&	operator<<=(const bigint& b);

		bigint&	operator>>=(int shift);
		bigint&	operator>>=(const bigint& b);

		bool	operator<(const bigint& b) const;
		bool	operator>(const bigint& b) const;
		bool	operator<=(const bigint& b) const;
		bool	operator>=(const bigint& b) const;
		bool	operator==(const bigint& b) const;
		bool	operator!=(const bigint& b) const;
};
