#include "bigint.hpp"
#include <algorithm>

bigint::bigint() : number("0") {}

bigint::bigint(size_t num) : number(std::to_string(num)) {}

bigint::bigint(const std::string& str) : number(str) {}

bigint::bigint(const bigint& other) : number(other.number) {}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		number = other.number;
	return (*this);
}

std::string bigint::addstr(const std::string& num1, const std::string& num2) const
{
	std::string result;
	int			carry = 0;
	int			sum = 0;
	int			i = num1.size() - 1;
	int			j = num2.size() - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += num1[i--] - '0';
		if (j >= 0)
			sum += num2[j--] - '0';
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
	}
	std::reverse(result.begin(), result.end());
	return (result);
}

bigint	bigint::operator+(const bigint& other) const
{
	return (bigint(addstr(number, other.number)));
}

bigint	bigint::operator-(const bigint& other) const
{
	(void)other;
	return (bigint(0));
}

bigint&	bigint::operator+=(const bigint& other)
{
	number = (std::string)addstr(number, other.number);
	return (*this);
}

bigint&	bigint::operator++()
{
	*this += bigint(1);
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint tmp = *this;
	++(*this);
	return (tmp);
}

bigint&	bigint::operator--()
{
	return (*this);
}

bigint	bigint::operator--(int)
{
	return (*this);
}

bigint	bigint::operator<<(size_t shift)const
{
	return (bigint(number + std::string(shift, '0')));
}

bigint	bigint::operator>>(size_t shift)const
{
	if (shift >= number.size())
		return (bigint(0));
	return (bigint(number.substr(0, number.size() - shift)));
}

bigint&	bigint::operator<<=(size_t shift)
{
	*this = *this << shift;
	return (*this);
}

bigint& bigint::operator>>=(size_t shift)
{
	*this = *this >> shift;
	return (*this);
}

bigint& bigint::operator>>=(const bigint& shift)
{
	return (*this >>= std::stoull(shift.number));
}

bool	bigint::operator==(const bigint& other) const
{
	return (number == other.number);
}

bool	bigint::operator!=(const bigint& other) const
{
	return (number != other.number);
}

bool	bigint::operator<(const bigint& other) const
{
	if (number.size() != other.number.size())
		return (number.size() < other.number.size());
	return (number < other.number);
}

bool	bigint::operator>(const bigint& other) const
{
	if (number.size() != other.number.size())
		return (number.size() > other.number.size());
	return (number > other.number);
}

bool	bigint::operator<=(const bigint& other) const
{
	return (!(*this > other));
}

bool	bigint::operator>=(const bigint& other) const
{
	return (!(*this < other));
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	os << b.number;
	return (os);
}
