/**
 * \file	main.cpp
 * \author	Richard Degenne
 *
 * \date	Thu Mar 12 13:42:21 CET 2015
 */

#include <iostream>
#include "Datacenter.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "==== The Fellowship of the Toguyen_Ring ====" << endl << endl;

	Datacenter d(argv[1]);
	d.print();
	d.solve1();
	d.print();
	d.out();
	return 0;
}
