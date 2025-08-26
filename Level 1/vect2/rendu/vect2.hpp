#pragma once

#include <string>
#include <iostream>

class vect2
{
	private:
		int	x;
		int	y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2& copy);
		vect2&	operator=(const vect2& copy);

		int&	operator[](int i);
		int		operator[](int i) const;

		vect2&	operator++();
		vect2	operator++(int);
		vect2&	operator--();
		vect2	operator--(int);

		vect2&	operator+=(const vect2& v);
		vect2&	operator-=(const vect2& v);
		vect2&	operator*=(int s);
		vect2	operator+(const vect2& v) const;
		vect2	operator-(const vect2& v) const;
		vect2	operator*(int s) const;
		friend vect2	operator*(int s, const vect2& v);

		vect2	operator-() const;

		bool	operator==(const vect2& v) const;
		bool	operator!=(const vect2& v) const;

		friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};
