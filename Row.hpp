

#ifndef _ROW_H
#define _ROW_H

#include <iostream>
#include <vector>

#include "Slot.hpp"

class Row {
public:
	std::vector<Slot*> slots;
	Row();

	void add(Slot* slot);
};

#endif

