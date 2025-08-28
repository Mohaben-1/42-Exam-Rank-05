#ifndef EXAM_ASSIGNMENTS_BAG_HPP
#define EXAM_ASSIGNMENTS_BAG_HPP

class bag
{
public:
	virtual void insert(int) = 0;
	virtual void insert(int *, int)  = 0;
	virtual void print() const = 0;
	virtual void clear() = 0;
};

#endif
