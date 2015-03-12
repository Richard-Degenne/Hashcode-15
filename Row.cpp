
#include "Row.hpp"

using namespace std;

/**
 * Default constructor
 */
Row::Row() {
	cout << "Constructing row..." << endl;
}


/**
 * Adds a new slot to the row.
 */
void Row::add(Slot* slot) {
	slots.push_back(slot);
}
