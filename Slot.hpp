
#ifndef _SLOT_H
#define _SLOT_H

#include <iostream>

#include "Server.hpp"

#define	FREE	0
#define OCCUPIED	1
#define BROKEN	2

class Slot {
public:
	int state;//!< See above defines
	Server* server;

	Slot(int _state, Server* _server);
};

#endif

