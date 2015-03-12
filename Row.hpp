

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
	int getFirstFreeSlot();
	bool canPlace(Server* s, int i);
	bool place(Server* s, int i);
};

#endif

