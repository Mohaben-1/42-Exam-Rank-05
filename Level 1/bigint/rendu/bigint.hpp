#pragma once

#include <string>
#include <iostream>

class bigint
{
	private:
		std::string number;
		std::string addstr(const std::string& num1, const std::string& num2) const;
	public:
		bigint();
		bigint(size_t num);
		bigint(const std::string& str);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);

		friend std::ostream& operator<<(std::ostream& os, const bigint& b);

		bigint	operator+(const bigint& other) const;
		bigint	operator-(const bigint& other) const;
		bigint&	operator+=(const bigint& other);

		bigint&	operator++();
		bigint	operator++(int);
		bigint&	operator--();
		bigint	operator--(int);

		bigint	operator<<(size_t shift) const;
		bigint	operator>>(size_t shift) const;
		bigint&	operator<<=(size_t shift);
		bigint& operator>>=(size_t shift);
		bigint& operator>>=(const bigint& shift);

		bool	operator==(const bigint& other) const;
		bool	operator!=(const bigint& other) const;
		bool	operator<(const bigint& other) const;
		bool	operator>(const bigint& other) const;
		bool	operator<=(const bigint& other) const;
		bool	operator>=(const bigint& other) const;
};
