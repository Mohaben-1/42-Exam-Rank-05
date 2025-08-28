//
// Created by citron on 01/03/23.
//

#ifndef EXAM_ASSIGNMENTS_SORTABLE_HPP
#define EXAM_ASSIGNMENTS_SORTABLE_HPP
#include "bag.hpp"

class searchable_bag : virtual public bag {
public:
	virtual bool has(int) const = 0;
};


#endif //EXAM_ASSIGNMENTS_SORTABLE_HPP
