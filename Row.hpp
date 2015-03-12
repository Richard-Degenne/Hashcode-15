

#ifndef _ROW_H
#define _ROW_H

#include <iostream>
#include <set>

#include "Slot.hpp"

class Row {
public:
	std::set<Slot*> slots;
	Row();

	void add(Slot* slot);
};

#endif

