
#include "Row.hpp"

using namespace std;

/**
 * Default constructor
 */
Row::Row() {
//	cout << "Constructing row..." << endl;
}


/**
 * Adds a new slot to the row.
 */
void Row::add(Slot* slot) {
	slots.push_back(slot);
}


/**
 * Fetches the first free slot. Returns its index.
 */
int Row::getFirstFreeSlot() {
	int i=-1;
	while(slots[++i]->state != FREE);
	return i;
}


/**
 * Checks whether every cell to be occupied by `s' is free.
 */
bool Row::canPlace(Server* s, int i) {
	for(int j=i ; j<i+s->size ; ++j) {
		if(slots[j]->state != FREE) {
			return false;
		}
	}
	return true;
}


/**
 * Actually place a server in the row at pos i.
 */
bool Row::place(Server* s, int i) {
	if(!canPlace(s, i)) {
		return false;
	}
	
	for(int j=i ; j<i+s->size ; ++j) {
		slots[j]->server = s;
	}
	return true;
}
